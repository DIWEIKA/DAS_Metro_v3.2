#ifndef FAULT_DETECTION_H
#define FAULT_DETECTION_H

#include <QThread>
#include <qmath.h>

#define N1 256 //做fft的长度 为2的整数次幂
//#define M_PI 3.1415926

class Fault_detection : public QThread
{
    Q_OBJECT
public:
    explicit Fault_detection(std::vector<float>& _strain_data, int _lenoStrainData);
    ~Fault_detection();

    void FFT_t(float xreal [], float ximag [], int n);
    void IFFT_t(float xreal[], float ximag[], int n);
    void swap(float &a, float &b);
    void bitrp(float xreal[], float ximag[], int n);
    bool GetIsFault() const {return isFault;}

signals:
private:
    float xreal[N1],ximag[N1];
    int lenoStrainData;
    std::vector<float> strain_data;
    std::vector<float> fft_result;
    int peakFreq; //信号最强频率
    int freq = 1000; //采样率
    const int featureFreq = 25; //特征频率
    bool isFault = false; //是否故障

protected:
    void run();

};

#endif // FAULT_DETECTION_H
