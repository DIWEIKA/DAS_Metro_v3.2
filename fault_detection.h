#ifndef FAULT_DETECTION_H
#define FAULT_DETECTION_H

#include <QThread>
#include <qmath.h>

#define N1 256 //��fft�ĳ��� Ϊ2����������
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
    int peakFreq; //�ź���ǿƵ��
    int freq = 1000; //������
    const int featureFreq = 25; //����Ƶ��
    bool isFault = false; //�Ƿ����

protected:
    void run();

};

#endif // FAULT_DETECTION_H
