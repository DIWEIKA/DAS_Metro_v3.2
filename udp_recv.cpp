#include "udp_recv.h"

UDP_Recv::UDP_Recv(MainWindow* mainwindow):
    mainWindow(mainwindow),
    net_pack_size(0),
    isStartFrame(0),
    Freq(mainWindow->GetFreq()), //采样率
    peakNum(mainWindow->GetPeakNum()), //峰值点数
    lenoRecv(1024), //接受一帧的数据长度
    lenoRecvHEX(lenoRecv*2),
    LenoUDP(Freq*peakNum*4*4*1000),//一个存储容器的大小: 采样率 * 峰值点数 * 4通道 * 4个char转化为一个float(1s数据量) * 200
    pack_count(0),
    pack_HEX_32(new char[32*1024*2]),
    pack_HEX_Display(new char[32*1024*2])
{
    sockVersion = MAKEWORD(2,2);
    if(WSAStartup(sockVersion, &wsaData) != 0)
    {
        printf("winsock initialization FAILED.");
    }
    echo_socket_WIN = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if(echo_socket_WIN == INVALID_SOCKET)
    {
        printf("winsocket error !");
    }
    addr_WIN.sin_family = AF_INET;
    addr_WIN.sin_port = htons(7000);
    addr_WIN.sin_addr.S_un.S_addr = INADDR_ANY;
    if(::bind(echo_socket_WIN, (sockaddr *)&addr_WIN, sizeof(addr_WIN)) == SOCKET_ERROR)
    {
        printf("bind error !");
        closesocket(echo_socket_WIN);
    }
    // set socket buffer size
    int optVal = 0;
    int optLen = sizeof(optVal);
    optVal = 4*1024*100000;
    setsockopt(echo_socket_WIN, SOL_SOCKET, SO_RCVBUF, (char*)&optVal, optLen);

    //预先申请存储空间
    p_echo_net_pack_array.reserve(1024);
    p_echo_net_pack_HEX.reserve(2048);
    //    pack_HEX_32.reserve(32*2048);

    CHdata1 = make_shared<CirQueue<unsigned char>>(LenoUDP); //存放用于解调的数据
}

UDP_Recv::~UDP_Recv()
{
    FreeMemory();
     delete mainWindow;
}


void UDP_Recv::FreeMemory()
{
    delete[] pack_HEX_32;
    delete[] pack_HEX_Display;

}

void UDP_Recv::run()
{
    while(1)
    {
        isStart = mainWindow->GetIsStart();

        if(isStart){

            net_pack_size = 0;

            //define a new char[]
            p_echo_net_pack[0] = '\0';

            net_pack_size = recvfrom(echo_socket_WIN, (char*)p_echo_net_pack, lenoRecvHEX, 0, (sockaddr *)&src_addr_WIN, &src_addr_len);

//            qDebug()<<"Reciving net_pack_size = "<< net_pack_size <<endl;

            //clear QByteArray
            p_echo_net_pack_array.clear();
            p_echo_net_pack_HEX.clear();

            //char* 转 QByteArray
            p_echo_net_pack_array = QByteArray(p_echo_net_pack,lenoRecvHEX);

            p_echo_net_pack_HEX = p_echo_net_pack_array.toHex().toUpper();

            //                qDebug()<<p_echo_net_pack_HEX[0]<<p_echo_net_pack_HEX[1]<<p_echo_net_pack_HEX[2]<<p_echo_net_pack_HEX[3]<<endl;

            const char X = '6';
            const char Y = '0';

            //判断32帧数据的帧头，从而定位起点位置.
            //若某帧第9~24位分别是6666666666666666，则该帧是起点帧
            if((p_echo_net_pack_HEX[8]== X) && (p_echo_net_pack_HEX[9]== X) && (p_echo_net_pack_HEX[10]== X) && (p_echo_net_pack_HEX[11]== X)
                    && (p_echo_net_pack_HEX[12]== X) && (p_echo_net_pack_HEX[13]== X) && (p_echo_net_pack_HEX[14]== X) && (p_echo_net_pack_HEX[15]== X)
                    && (p_echo_net_pack_HEX[16]== X) && (p_echo_net_pack_HEX[17]== X) && (p_echo_net_pack_HEX[18]== X) && (p_echo_net_pack_HEX[19]== X)
                    && (p_echo_net_pack_HEX[20]== X) && (p_echo_net_pack_HEX[21]== X) && (p_echo_net_pack_HEX[22]== X) && (p_echo_net_pack_HEX[23]== X) && (p_echo_net_pack_HEX[24]== Y))
                isStartFrame = 1;

            /*---------------Mode I: 将脉冲波形显示出来------------*/
            if((mainWindow->GetAcqMode() == 1) && isStartFrame){

                //p_echo_net_pack_HEX >> pack_HEX_32[]
                for(int k = 2*pack_count; k<(2*pack_count + 2048) ; k++ )
                    pack_HEX_32[k] = p_echo_net_pack_HEX[k-2*pack_count];

                //计数收到的包次数
                pack_count = pack_count + 1024;

                //每收到32个包时，称为一个事件
                if(pack_count>=1024*32){
                    isStartFrame = 0;
                    pack_count = 0;

                    //pack_HEX_32[] >> pack_HEX_Display[]
                    memcpy(pack_HEX_Display,pack_HEX_32,sizeof(char)*2048*32);

                    memset(pack_HEX_32,'\0',sizeof(char)); //清空数组
                }
            }

            /*---------------Mode II: 将数据收到的数据置于待解调缓冲池里------------*/
            if(mainWindow->GetAcqMode() == 2){

                for(int i=0; i<lenoRecvHEX; i++) {
                    unsigned char usCHDATA =(unsigned char)p_echo_net_pack_HEX[i];
                    CHdata1->push(usCHDATA);
                }//end for

            }//end if

        } //end if
    }
}
