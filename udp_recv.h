#ifndef UDP_RECV_H
#define UDP_RECV_H

#include <QThread>
#include <winsock2.h>
#include <mainwindow.h>

class UDP_Recv : public QThread
{
    Q_OBJECT
public:
    UDP_Recv(MainWindow* mainwindow);
    ~UDP_Recv();
    void FreeMemory();
    bool GetIsStart() const {return isStart;};
    shared_ptr<CirQueue<unsigned char>> GetCHdata1() const {return CHdata1;};
    char* GetPack_HEX_Display() const {return pack_HEX_Display;};

private:
    MainWindow* mainWindow;

    //winSocket API
    WSADATA wsaData;
    WORD sockVersion;
    SOCKET echo_socket_WIN;
    sockaddr_in addr_WIN;
    sockaddr_in src_addr_WIN;
    int src_addr_len = sizeof(src_addr_WIN);
    int net_pack_size;
    QByteArray p_echo_net_pack_HEX;
    QByteArray p_echo_net_pack_array;
    char p_echo_net_pack[1024];
    bool isStart;
    bool isStartFrame;
    int Freq;
    int peakNum;
    QHostAddress clientAddr;
    quint16 clientPort;
    int lenoRecv;
    int lenoRecvHEX;
    int LenoUDP;
    int pack_count;
    char* pack_HEX_32; //用于存放32帧数据
    char* pack_HEX_Display; //用于显示的32帧数据

    shared_ptr<CirQueue<unsigned char>> CHdata1; //存放待解调数据的缓冲池

protected:
    void run();

signals:

};

#endif // UDP_RECV_H
