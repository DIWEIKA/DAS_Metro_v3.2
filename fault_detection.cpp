#include "fault_detection.h"

Fault_detection::Fault_detection(std::vector<float>& _strain_data, int _lenoStrainData)
    :lenoStrainData(_lenoStrainData),
      strain_data(_strain_data),
      fft_result(std::vector<float>(N1/2))

{

}

Fault_detection::~Fault_detection()
{

}

void Fault_detection::run()
{
    memset(xreal,0,sizeof(float)*N1);
    memset(ximag,0,sizeof(float)*N1);

    for(int i=0; i<lenoStrainData; i++){
        xreal[i] = strain_data[i];
        ximag[i] = 0;
    }

    FFT_t (xreal, ximag, N1);
    int N11 = N1/2;
    float xAbs[128];
    memset(xAbs,0,sizeof(float)*N11);

    for(int s=1; s<(N11+1); ++s){
        xAbs[s-1] = sqrt(pow((xreal[s]/N1),2)+pow((ximag[s]/N1),2)) * 2;
    }

    std::copy(std::begin(xAbs),std::end(xAbs), fft_result.begin());

    /*---------------根据特征频率对故障检测----------------*/
    auto it = std::max_element(fft_result.begin(), fft_result.end());
    peakFreq = (it - fft_result.begin()) * freq/N1; //频率 = 采样点位置 * 分度值； 分度值 = 采样率/FFT长度

    //峰值频率 >= 特征频率时 判定为故障
    if(peakFreq >= featureFreq) isFault = true;
    else isFault = false;
}


void Fault_detection::FFT_t(float xreal [], float ximag [], int n)
{
    // 快速傅立叶变换，将复数 x 变换后仍保存在 x 中，xreal, ximag 分别是 x 的实部和虚部
    float wreal[N1/2], wimag[N1 / 2], treal, timag, ureal, uimag, arg;
    int m, k, j, t, index1, index2;

    bitrp (xreal, ximag, n);

    // 计算 1 的前 n / 2 个 n 次方根的共轭复数 W'j = wreal [j] + i * wimag [j] , j = 0, 1, ... , n / 2 - 1
    arg = - 2 * M_PI / n;
    treal = cos (arg);
    timag = sin (arg);
    wreal [0] = 1.0;
    wimag [0] = 0.0;
    for (j = 1; j < n / 2; j ++)
    {
        wreal [j] = wreal [j - 1] * treal - wimag [j - 1] * timag;
        wimag [j] = wreal [j - 1] * timag + wimag [j - 1] * treal;
    }

    for (m = 2; m <= n; m *= 2)
    {
        for (k = 0; k < n; k += m)
        {
            for (j = 0; j < m / 2; j ++)
            {
                index1 = k + j;
                index2 = index1 + m / 2;
                t = n * j / m;    // 旋转因子 w 的实部在 wreal [] 中的下标为 t
                treal = wreal [t] * xreal [index2] - wimag [t] * ximag [index2];
                timag = wreal [t] * ximag [index2] + wimag [t] * xreal [index2];
                ureal = xreal [index1];
                uimag = ximag [index1];
                xreal [index1] = ureal + treal;
                ximag [index1] = uimag + timag;
                xreal [index2] = ureal - treal;
                ximag [index2] = uimag - timag;
            }
        }
    }
}

void Fault_detection::IFFT_t(float xreal[], float ximag[], int n)
{
    // 快速傅立叶逆变换
    float wreal [N1 / 2], wimag [N1 / 2], treal, timag, ureal, uimag, arg;
    int m, k, j, t, index1, index2;

    bitrp (xreal, ximag, n);

    // 计算 1 的前 n / 2 个 n 次方根 Wj = wreal [j] + i * wimag [j] , j = 0, 1, ... , n / 2 - 1
    arg = 2 * M_PI / n;
    treal = cos (arg);
    timag = sin (arg);
    wreal [0] = 1.0;
    wimag [0] = 0.0;
    for (j = 1; j < n / 2; j ++)
    {
        wreal [j] = wreal [j - 1] * treal - wimag [j - 1] * timag;
        wimag [j] = wreal [j - 1] * timag + wimag [j - 1] * treal;
    }

    for (m = 2; m <= n; m *= 2)
    {
        for (k = 0; k < n; k += m)
        {
            for (j = 0; j < m / 2; j ++)
            {
                index1 = k + j;
                index2 = index1 + m / 2;
                t = n * j / m;    // 旋转因子 w 的实部在 wreal [] 中的下标为 t
                treal = wreal [t] * xreal [index2] - wimag [t] * ximag [index2];
                timag = wreal [t] * ximag [index2] + wimag [t] * xreal [index2];
                ureal = xreal [index1];
                uimag = ximag [index1];
                xreal [index1] = ureal + treal;
                ximag [index1] = uimag + timag;
                xreal [index2] = ureal - treal;
                ximag [index2] = uimag - timag;
            }
        }
    }

    for (j=0; j < n; j ++)
    {
        xreal [j] /= n;
        ximag [j] /= n;
    }
}

void Fault_detection::swap(float &a, float &b)
{
    float t;
    t = a;
    a = b;
    b = t;
}

void Fault_detection::bitrp(float xreal[], float ximag[], int n)
{
    // 位反转置换 Bit-reversal Permutation
    int i, j, a, b, p;

    for (i = 1, p = 0; i < n; i *= 2)
    {
        p ++;
    }
    for (i = 0; i < n; i ++)
    {
        a = i;
        b = 0;
        for (j = 0; j < p; j ++)
        {
            b = (b << 1) + (a & 1);    // b = b * 2 + a % 2;
            a >>= 1;        // a = a / 2;
        }
        if ( b > i)
        {
            swap (xreal [i], xreal [b]);
            swap (ximag [i], ximag [b]);
        }
    }
}
