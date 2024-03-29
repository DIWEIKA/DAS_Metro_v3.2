#include "fallmap.h"

fallmap::fallmap(demowave* _demowave, int _fallmapFlashTime) :
  m_demowave(_demowave)
  ,peakNum(m_demowave->PeakNum())
  ,fallmapFlashTime(_fallmapFlashTime)
  ,lenoTime(m_demowave->Freq() * fallmapFlashTime / 1000)//length of data in one flash
  ,FallmapDataVec(vector<vector<float>>(Nf1))
  ,FallmapData1(vector<float>(peakNum,0))
  ,FallmapData2(vector<float>(peakNum,0))
  ,FallmapData3(vector<float>(peakNum,0))
  ,FallmapData4(vector<float>(peakNum,0))
  ,FallmapData5(vector<float>(peakNum,0))
  ,FallmapData6(vector<float>(peakNum,0))
  ,FallmapData7(vector<float>(peakNum,0))
  ,FallmapData8(vector<float>(peakNum,0))
  ,FallmapData9(vector<float>(peakNum,0))
  ,FallmapData10(vector<float>(peakNum,0))
  ,FallmapData11(vector<float>(peakNum,0))
  ,FallmapData12(vector<float>(peakNum,0))
  ,FallmapData13(vector<float>(peakNum,0))
  ,FallmapData14(vector<float>(peakNum,0))
  ,FallmapData15(vector<float>(peakNum,0))
  ,FallmapData16(vector<float>(peakNum,0))
  ,FallmapData17(vector<float>(peakNum,0))
  ,FallmapData18(vector<float>(peakNum,0))
  ,FallmapData19(vector<float>(peakNum,0))
  ,FallmapData20(vector<float>(peakNum,0))
  ,FallmapData21(vector<float>(peakNum,0))
  ,FallmapData22(vector<float>(peakNum,0))
  ,FallmapData23(vector<float>(peakNum,0))
  ,FallmapData24(vector<float>(peakNum,0))
  ,FallmapData25(vector<float>(peakNum,0))
  ,FallmapData26(vector<float>(peakNum,0))
  ,FallmapData27(vector<float>(peakNum,0))
  ,FallmapData28(vector<float>(peakNum,0))
  ,FallmapData29(vector<float>(peakNum,0))
  ,FallmapData30(vector<float>(peakNum,0))
  ,FallmapData31(vector<float>(peakNum,0))
  ,FallmapData32(vector<float>(peakNum,0))
  ,FallmapData33(vector<float>(peakNum,0))
  ,FallmapData34(vector<float>(peakNum,0))
  ,FallmapData35(vector<float>(peakNum,0))
  ,FallmapData36(vector<float>(peakNum,0))
  ,FallmapData37(vector<float>(peakNum,0))
  ,FallmapData38(vector<float>(peakNum,0))
  ,FallmapData39(vector<float>(peakNum,0))
  ,FallmapData40(vector<float>(peakNum,0))
  ,FallmapData41(vector<float>(peakNum,0))
  ,FallmapData42(vector<float>(peakNum,0))
  ,FallmapData43(vector<float>(peakNum,0))
  ,FallmapData44(vector<float>(peakNum,0))
  ,FallmapData45(vector<float>(peakNum,0))
  ,FallmapData46(vector<float>(peakNum,0))
  ,FallmapData47(vector<float>(peakNum,0))
  ,FallmapData48(vector<float>(peakNum,0))
  ,FallmapData49(vector<float>(peakNum,0))
  ,FallmapData50(vector<float>(peakNum,0))
  ,FallmapData51(vector<float>(peakNum,0))
  ,FallmapData52(vector<float>(peakNum,0))
  ,FallmapData53(vector<float>(peakNum,0))
  ,FallmapData54(vector<float>(peakNum,0))
  ,FallmapData55(vector<float>(peakNum,0))
  ,FallmapData56(vector<float>(peakNum,0))
  ,FallmapData57(vector<float>(peakNum,0))
  ,FallmapData58(vector<float>(peakNum,0))
  ,FallmapData59(vector<float>(peakNum,0))
  ,FallmapData60(vector<float>(peakNum,0))
    ,judge_q(deque<int>(5,0))
{
    FallmapDataVec[0] = FallmapData1;
    FallmapDataVec[1] = FallmapData2;
    FallmapDataVec[2] = FallmapData3;
    FallmapDataVec[3] = FallmapData4;
    FallmapDataVec[4] = FallmapData5;
    FallmapDataVec[5] = FallmapData6;
    FallmapDataVec[6] = FallmapData7;
    FallmapDataVec[7] = FallmapData8;
    FallmapDataVec[8] = FallmapData9;
    FallmapDataVec[9] = FallmapData10;
    FallmapDataVec[10] = FallmapData11;
    FallmapDataVec[11] = FallmapData12;
    FallmapDataVec[12] = FallmapData13;
    FallmapDataVec[13] = FallmapData14;
    FallmapDataVec[14] = FallmapData15;
    FallmapDataVec[15] = FallmapData16;
    FallmapDataVec[16] = FallmapData17;
    FallmapDataVec[17] = FallmapData18;
    FallmapDataVec[18] = FallmapData19;
    FallmapDataVec[19] = FallmapData20;
    FallmapDataVec[20] = FallmapData21;
    FallmapDataVec[21] = FallmapData22;
    FallmapDataVec[22] = FallmapData23;
    FallmapDataVec[23] = FallmapData24;
    FallmapDataVec[24] = FallmapData25;
    FallmapDataVec[25] = FallmapData26;
    FallmapDataVec[26] = FallmapData27;
    FallmapDataVec[27] = FallmapData28;
    FallmapDataVec[28] = FallmapData29;
    FallmapDataVec[29] = FallmapData30;
    FallmapDataVec[30] = FallmapData31;
    FallmapDataVec[31] = FallmapData32;
    FallmapDataVec[32] = FallmapData33;
    FallmapDataVec[33] = FallmapData34;
    FallmapDataVec[34] = FallmapData35;
    FallmapDataVec[35] = FallmapData36;
    FallmapDataVec[36] = FallmapData37;
    FallmapDataVec[37] = FallmapData38;
    FallmapDataVec[38] = FallmapData39;
    FallmapDataVec[39] = FallmapData40;
    FallmapDataVec[40] = FallmapData41;
    FallmapDataVec[41] = FallmapData42;
    FallmapDataVec[42] = FallmapData43;
    FallmapDataVec[43] = FallmapData44;
    FallmapDataVec[44] = FallmapData45;
    FallmapDataVec[45] = FallmapData46;
    FallmapDataVec[46] = FallmapData47;
    FallmapDataVec[47] = FallmapData48;
    FallmapDataVec[48] = FallmapData49;
    FallmapDataVec[49] = FallmapData50;
    FallmapDataVec[50] = FallmapData51;
    FallmapDataVec[51] = FallmapData52;
    FallmapDataVec[52] = FallmapData53;
    FallmapDataVec[53] = FallmapData54;
    FallmapDataVec[54] = FallmapData55;
    FallmapDataVec[55] = FallmapData56;
    FallmapDataVec[56] = FallmapData57;
    FallmapDataVec[57] = FallmapData58;
    FallmapDataVec[58] = FallmapData59;
    FallmapDataVec[59] = FallmapData60;
}

void fallmap::InitState()
{
    QJsonArray IsBegin_json;
    IsBegin_json.push_back(Begin);
    judgement_obj.insert("IsBegin",IsBegin_json);
}

void fallmap::Begin_State_Judge(const int present_region, const vector<float>& max_data)
{
    judge_q.pop_front();
    judge_q.push_back(present_region);
    if(judge_q.size() == 5){
        Begin = (std::equal(judge_q.begin() + 1, judge_q.end(), judge_q.begin()) == true) ? 1 : 0;
        InitState();
    }

    //qDebug()<<"Begin = " << Begin <<endl;
}

void fallmap::run()
{
//    qDebug() <<"Fallmap Thread responsed !"<<endl;

    //select the max result of every N1 length of data to display
    vector<float> max_data(peakNum); //max results of data of every region
    vector<int> max_data_index(peakNum); //the index of max results of data of every region

    SelectMax(max_data, max_data_index, lenoTime);

    Load_Fallmap(max_data);

    Judgement(max_data, max_data_index);

    PreProcess();
}

fallmap::~fallmap()
{
    delete m_demowave;
}

//reverse matrix
float **fallmap::reverse(float **_array)
{
    float temp;
    for(int i=0; i<peakNum; ++i){
        for(int j=0; j<Nf1; ++j){
            temp = _array[i][j];
            _array[i][j] = _array[j][i];
            _array[j][i] = temp;
        }
    }
    return _array;
}

void fallmap::SelectMax(vector<float>& max_data, vector<int>& max_data_index, int len)
{
    for(int i=0; i<peakNum; ++i){
        auto iterator_max = std::max_element(m_demowave->GetDemodataArray()[i], m_demowave->GetDemodataArray()[i]+len);
        max_data[i] = *iterator_max; //某测区的最大值
        max_data_index[i] = iterator_max - m_demowave->GetDemodataArray()[i]; //某测区最大值对应的位置
    }
//    return max_data;
}

void fallmap::Judgement(const vector<float>& max_data, const vector<int>& max_data_index)
{
    /*---------------寻找当前测区位置-------------------*/
    Find_Present_Region(max_data);

    /*---------------初始态判断-------------------*/
    Begin_State_Judge(present_region, max_data);

    /*---------------故障检测-------------------*/
//    Fault_Detection(present_region, max_data);
    Fault_Detection(present_region, lenoTime);


//    m_fault_detection = new Fault_detection(strain_data,2*strainRange);
//    if(!m_fault_detection->isRunning()) m_fault_detection->start();

}


void fallmap::Load_Fallmap(vector<float>& max_data)
{
    //copy the data of the last vector to the present vector
    for(int i=Nf1-1; i>0; --i){
        std::copy(FallmapDataVec[i-1].begin(),FallmapDataVec[i-1].end(),FallmapDataVec[i].begin());
    }
    //copy into the first vector
    std::copy(max_data.begin(), max_data.end(), FallmapDataVec[0].begin());
}

void fallmap::Find_Present_Region(const vector<float>& max_data)
{
    //select the region index of max amplitude in all regions
    auto iterator_max_all = std::max_element(max_data.begin(),max_data.end());

    if(*iterator_max_all > BASE) //only if max result > BASE, finding the present region
        present_region = iterator_max_all - max_data.begin() + 1;

//    //let region changes contineuiously
//    if(present_region == temp_region+1/* || present_region == temp_region-1 */|| present_region == temp_region-13)
//        temp_region = present_region;
    temp_region = present_region;

    m_demowave->regionIndex = temp_region-1;

    QJsonArray PresentRegion_json;
//    present_region = 25; //test
    PresentRegion_json.push_back(temp_region);

    judgement_obj.insert("present_region",PresentRegion_json);
}

void fallmap::Fault_Detection(const int present_region, const vector<float>& max_data)
{
    /*---------方式一：时域幅值的阈值检测-----------*/
    // If time domain max amplitude of the present region is large than 6 rad,
    // we assume the region is FAULT
    if(abs(max_data[present_region-1]) > LIMIT) IsLineFault = 1;
    else IsLineFault = 0;
//    IsLineFault = 0; //test
    QJsonArray IsLineFault_json;
    IsLineFault_json.push_back(IsLineFault);
    judgement_obj.insert("IsLineFault",IsLineFault_json);

}

void fallmap::Fault_Detection(const int present_region, int len)
{
    /*---------方式二：时域峰值点数的阈值检测-----------*/
    std::vector<float> temp(len,0); //save time domain of demowave of the present region
    std::copy(m_demowave->GetDemodataArray()[present_region-1],m_demowave->GetDemodataArray()[present_region-1]+len, temp.begin());
    for(int i=0; i<len; ++i){
        if(temp[i] < PEAKLIMIT) temp[i] = 0;
    }
    std::vector<size_t> temp_index = findPeaks(temp,0); //get the index of peaks

    temp_peak_num = temp_index.size();
//    if(++peak_cnt == 2){
//        real_peak_num = temp_peak_num; //get the number of peaks
//        qDebug()<<"Demowave peak number is: "<<real_peak_num<<endl;
//        temp_peak_num = 0;
//        peak_cnt = 0;
//    }


    IsLineFault = 0;
    region_cnt++;

    switch (present_region) {
    case 1:{ if(temp_peak_num > REGION1)
        {
        // train_fault_cnt++;
         line_cnt_1++;
         if(line_cnt_1 >=LINEFAULTLIMIT ){
             IsLineFault = 1;
             line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
             qDebug()<<"---------REGION 1 of Line is Fault !!----------"<<endl;
         }
        }
        if(temp_peak_num>TRAIN){
           train_fault_cnt++;
       }
        qDebug()<<"REGION 1 peak number is: "<<temp_peak_num<<endl; break;}

    case 2:{ if(temp_peak_num > REGION2)
        {
           // train_fault_cnt++;
            line_cnt_2++;
            if(line_cnt_2 >=LINEFAULTLIMIT ){
                IsLineFault = 1;
                line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
                qDebug()<<"---------REGION 2 of Line is Fault !!----------"<<endl;
            }
        }
        if(temp_peak_num>TRAIN){
            train_fault_cnt++;
        }
        qDebug()<<"REGION 2 peak number is: "<<temp_peak_num<<endl; break;}

    case 3:{ if(temp_peak_num > REGION3)
        {
            //train_fault_cnt++;
            line_cnt_3++;
            if(line_cnt_3 >=LINEFAULTLIMIT ){
                IsLineFault = 1;
                line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
                qDebug()<<"---------REGION 3 of Line is Fault !!----------"<<endl;
            }
        }
        if(temp_peak_num>TRAIN){
            train_fault_cnt++;
        }
        qDebug()<<"REGION 3 peak number is: "<<temp_peak_num<<endl; break;}

    case 4:{ if(temp_peak_num > REGION4)
        {
           //train_fault_cnt++;
            line_cnt_4++;
           if(line_cnt_4 >=LINEFAULTLIMIT ){
               IsLineFault = 1;
               line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
               qDebug()<<"---------REGION 4 of Line is Fault !!----------"<<endl;
           }
        }
        if(temp_peak_num>TRAIN){
            train_fault_cnt++;
        }
        qDebug()<<"REGION 4 peak number is: "<<temp_peak_num<<endl; break;}

    case 5:{ if(temp_peak_num > REGION5)
        {
           //train_fault_cnt++;
            line_cnt_5++;
           if(line_cnt_5 >=LINEFAULTLIMIT ){
               IsLineFault = 1;
               line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
               qDebug()<<"---------REGION 5 of Line is Fault !!----------"<<endl;
           }
        }
        if(temp_peak_num>TRAIN){
            train_fault_cnt++;
        }
        qDebug()<<"REGION 5 peak number is: "<<temp_peak_num<<endl; break;}

    case 6:{ if(temp_peak_num > REGION6)
        {
          // train_fault_cnt++;
            line_cnt_6++;
           if(line_cnt_6 >=LINEFAULTLIMIT ){
               IsLineFault = 1;
               line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
               qDebug()<<"---------REGION 6 of Line is Fault !!----------"<<endl;
           }
        }
        if(temp_peak_num>TRAIN){
            train_fault_cnt++;
        }
        qDebug()<<"REGION 6 peak number is: "<<temp_peak_num<<endl; break;}

    case 7:{ if(temp_peak_num > REGION7)
        {
          // train_fault_cnt++;
            line_cnt_7++;
           if(line_cnt_7 >=LINEFAULTLIMIT ){
               IsLineFault = 1;
               line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
               qDebug()<<"---------REGION 7 of Line is Fault !!----------"<<endl;
           }
        }
        if(temp_peak_num>TRAIN){
            train_fault_cnt++;
        }
        qDebug()<<"REGION 7 peak number is: "<<temp_peak_num<<endl; break;}

    case 8:{ if(temp_peak_num > REGION8)
        {
          // train_fault_cnt++;
            line_cnt_8++;
           if(line_cnt_8 >=LINEFAULTLIMIT ){
               IsLineFault = 1;
               line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
               qDebug()<<"---------REGION 8 of Line is Fault !!----------"<<endl;
           }
        }
        if(temp_peak_num>TRAIN){
            train_fault_cnt++;
        }
        qDebug()<<"REGION 8 peak number is: "<<temp_peak_num<<endl; break;}

    case 9:{ if(temp_peak_num > REGION9)
        {
          // train_fault_cnt++;
            line_cnt_9++;
           if(line_cnt_9 >=LINEFAULTLIMIT ){
               IsLineFault = 1;
               line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
               qDebug()<<"---------REGION 9 of Line is Fault !!----------"<<endl;
           }
        }
        if(temp_peak_num>TRAIN){
            train_fault_cnt++;
        }
        qDebug()<<"REGION 9 peak number is: "<<temp_peak_num<<endl; break;}

    }
  /*  if(pre_region==present_region)
        pre_region_cnt++;
    pre_region = present_region;*/
     //如果经过8个测区（一圈）且测区故障数大于5时，判定为列车故障
   if(region_cnt == 8){
       //Begin = 1;
       if(train_fault_cnt >= 5){
             IsTrainFault = 1;
             region_cnt = 0;
             if(pre_train_fault_cnt == train_fault_cnt){
                 train_fault_cnt = 0;
                 line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
                 IsTrainFault = 0;
            }
              pre_train_fault_cnt = train_fault_cnt;
//        train_fault_cnt = 0;
//        line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
             IsLineFault = 0; //如果列车故障时，轨道必正常
                qDebug()<<"--------The Train is Fault !!!--------: "<<endl;
    }
        if(train_fault_cnt < 5){
            IsTrainFault = 0;
            region_cnt = 0;
            train_fault_cnt = 0;
        }
    }
   if(Begin==1){
       line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;}
  /* if(region_cnt == 8){
      // Begin = 0;
       if(train_fault_cnt >= 5){
             IsTrainFault = 1;
             region_cnt = 0;
             if(pre_train_fault_cnt == train_fault_cnt){
                 train_fault_cnt = 0;
                 line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
                 IsTrainFault = 0;
            }
              pre_train_fault_cnt = train_fault_cnt;
//        train_fault_cnt = 0;
//        line_cnt_1 = 0;line_cnt_2 = 0;line_cnt_3 = 0;line_cnt_4 = 0;line_cnt_5 = 0;line_cnt_6 = 0;line_cnt_7 = 0;line_cnt_8 = 0;line_cnt_9 = 0;
             IsLineFault = 0; //如果列车故障时，轨道必正常
                qDebug()<<"--------The Train is Fault !!!--------: "<<endl;
    }
        if(train_fault_cnt < 5){
            IsTrainFault = 0;
            region_cnt = 0;
            train_fault_cnt = 0;
        }
    }*/
    //如果8s内number总数大于某一值，判定为列车故障
 /*   if(region_cnt<8){
        all_num+=temp_peak_num;
    }
    if(region_cnt==8){
        qDebug()<<"all_num is : "<<all_num<<endl;
        region_cnt = 0;
        all_num = 0;
    }*/



    QJsonArray IsLineFault_json;
    IsLineFault_json.push_back(IsLineFault);
    judgement_obj.insert("IsLineFault",IsLineFault_json);
    QJsonArray IsTrainFault_json;
    IsTrainFault_json.push_back(IsTrainFault);
    judgement_obj.insert("IsTrainFault",IsTrainFault_json);
}

void fallmap::Find_Range()
{
    //    /*---------------寻找当前测区的应变时区-------------------*/
    //    //将当前测区的应变最大值的位置前后strainRange个采样点作为应变时区存入strain_data
    //    const int strainRange = 100;
    //    //在合适的位置，不能越界
    //    if(max_data_index[present_region] >= strainRange && max_data_index[present_region] <= (max_data_index.size() - strainRange)){
    //        std::copy
    //         (
    //         m_demowave->GetDemodataArray()[present_region] + max_data_index[present_region] - strainRange,
    //         m_demowave->GetDemodataArray()[present_region] + max_data_index[present_region] + strainRange,
    //         strain_data.begin()
    //         );
    //    }
    //    else qDebug()<<"max_data_index is too front or too behind !!!"<<endl;
}


void fallmap::PreProcess()
{
    /*--------------瀑布图显示预处理---------------*/
    QJsonArray fallmap_json1;
    QJsonArray fallmap_json2;
    QJsonArray fallmap_json3;
    QJsonArray fallmap_json4;
    QJsonArray fallmap_json5;
    QJsonArray fallmap_json6;
    QJsonArray fallmap_json7;
    QJsonArray fallmap_json8;
    QJsonArray fallmap_json9;
    QJsonArray fallmap_json10;
    QJsonArray fallmap_json11;
    QJsonArray fallmap_json12;
    QJsonArray fallmap_json13;
    QJsonArray fallmap_json14;
    QJsonArray fallmap_json15;
    QJsonArray fallmap_json16;
    QJsonArray fallmap_json17;
    QJsonArray fallmap_json18;
    QJsonArray fallmap_json19;
    QJsonArray fallmap_json20;
    QJsonArray fallmap_json21;
    QJsonArray fallmap_json22;
    QJsonArray fallmap_json23;
    QJsonArray fallmap_json24;
    QJsonArray fallmap_json25;
    QJsonArray fallmap_json26;
    QJsonArray fallmap_json27;
    QJsonArray fallmap_json28;
    QJsonArray fallmap_json29;
    QJsonArray fallmap_json30;
    QJsonArray fallmap_json31;
    QJsonArray fallmap_json32;
    QJsonArray fallmap_json33;
    QJsonArray fallmap_json34;
    QJsonArray fallmap_json35;
    QJsonArray fallmap_json36;
    QJsonArray fallmap_json37;
    QJsonArray fallmap_json38;
    QJsonArray fallmap_json39;
    QJsonArray fallmap_json40;
    QJsonArray fallmap_json41;
    QJsonArray fallmap_json42;
    QJsonArray fallmap_json43;
    QJsonArray fallmap_json44;
    QJsonArray fallmap_json45;
    QJsonArray fallmap_json46;
    QJsonArray fallmap_json47;
    QJsonArray fallmap_json48;
    QJsonArray fallmap_json49;
    QJsonArray fallmap_json50;
    QJsonArray fallmap_json51;
    QJsonArray fallmap_json52;
    QJsonArray fallmap_json53;
    QJsonArray fallmap_json54;
    QJsonArray fallmap_json55;
    QJsonArray fallmap_json56;
    QJsonArray fallmap_json57;
    QJsonArray fallmap_json58;
    QJsonArray fallmap_json59;
    QJsonArray fallmap_json60;

    for(int i = 0; i < peakNum; i++) fallmap_json1.push_back(FallmapDataVec[0][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json2.push_back(FallmapDataVec[1][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json3.push_back(FallmapDataVec[2][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json4.push_back(FallmapDataVec[3][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json5.push_back(FallmapDataVec[4][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json6.push_back(FallmapDataVec[5][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json7.push_back(FallmapDataVec[6][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json8.push_back(FallmapDataVec[7][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json9.push_back(FallmapDataVec[8][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json10.push_back(FallmapDataVec[9][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json11.push_back(FallmapDataVec[10][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json12.push_back(FallmapDataVec[11][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json13.push_back(FallmapDataVec[12][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json14.push_back(FallmapDataVec[13][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json15.push_back(FallmapDataVec[14][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json16.push_back(FallmapDataVec[15][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json17.push_back(FallmapDataVec[16][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json18.push_back(FallmapDataVec[17][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json19.push_back(FallmapDataVec[18][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json20.push_back(FallmapDataVec[19][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json21.push_back(FallmapDataVec[20][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json22.push_back(FallmapDataVec[21][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json23.push_back(FallmapDataVec[22][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json24.push_back(FallmapDataVec[23][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json25.push_back(FallmapDataVec[24][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json26.push_back(FallmapDataVec[25][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json27.push_back(FallmapDataVec[26][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json28.push_back(FallmapDataVec[27][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json29.push_back(FallmapDataVec[28][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json30.push_back(FallmapDataVec[29][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json31.push_back(FallmapDataVec[30][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json32.push_back(FallmapDataVec[31][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json33.push_back(FallmapDataVec[32][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json34.push_back(FallmapDataVec[33][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json35.push_back(FallmapDataVec[34][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json36.push_back(FallmapDataVec[35][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json37.push_back(FallmapDataVec[36][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json38.push_back(FallmapDataVec[37][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json39.push_back(FallmapDataVec[38][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json40.push_back(FallmapDataVec[39][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json41.push_back(FallmapDataVec[40][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json42.push_back(FallmapDataVec[41][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json43.push_back(FallmapDataVec[42][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json44.push_back(FallmapDataVec[43][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json45.push_back(FallmapDataVec[44][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json46.push_back(FallmapDataVec[45][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json47.push_back(FallmapDataVec[46][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json48.push_back(FallmapDataVec[47][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json49.push_back(FallmapDataVec[48][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json50.push_back(FallmapDataVec[49][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json51.push_back(FallmapDataVec[50][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json52.push_back(FallmapDataVec[51][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json53.push_back(FallmapDataVec[52][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json54.push_back(FallmapDataVec[53][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json55.push_back(FallmapDataVec[54][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json56.push_back(FallmapDataVec[55][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json57.push_back(FallmapDataVec[56][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json58.push_back(FallmapDataVec[57][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json59.push_back(FallmapDataVec[58][i]);
    for(int i = 0; i < peakNum; i++) fallmap_json60.push_back(FallmapDataVec[59][i]);

    fallmap_obj.insert("fallmap_data_1",fallmap_json1);
    fallmap_obj.insert("fallmap_data_2",fallmap_json2);
    fallmap_obj.insert("fallmap_data_3",fallmap_json3);
    fallmap_obj.insert("fallmap_data_4",fallmap_json4);
    fallmap_obj.insert("fallmap_data_5",fallmap_json5);
    fallmap_obj.insert("fallmap_data_6",fallmap_json6);
    fallmap_obj.insert("fallmap_data_7",fallmap_json7);
    fallmap_obj.insert("fallmap_data_8",fallmap_json8);
    fallmap_obj.insert("fallmap_data_9",fallmap_json9);
    fallmap_obj.insert("fallmap_data_10",fallmap_json10);
    fallmap_obj.insert("fallmap_data_11",fallmap_json11);
    fallmap_obj.insert("fallmap_data_12",fallmap_json12);
    fallmap_obj.insert("fallmap_data_13",fallmap_json13);
    fallmap_obj.insert("fallmap_data_14",fallmap_json14);
    fallmap_obj.insert("fallmap_data_15",fallmap_json15);
    fallmap_obj.insert("fallmap_data_16",fallmap_json16);
    fallmap_obj.insert("fallmap_data_17",fallmap_json17);
    fallmap_obj.insert("fallmap_data_18",fallmap_json18);
    fallmap_obj.insert("fallmap_data_19",fallmap_json19);
    fallmap_obj.insert("fallmap_data_20",fallmap_json20);
    fallmap_obj.insert("fallmap_data_21",fallmap_json21);
    fallmap_obj.insert("fallmap_data_22",fallmap_json22);
    fallmap_obj.insert("fallmap_data_23",fallmap_json23);
    fallmap_obj.insert("fallmap_data_24",fallmap_json24);
    fallmap_obj.insert("fallmap_data_25",fallmap_json25);
    fallmap_obj.insert("fallmap_data_26",fallmap_json26);
    fallmap_obj.insert("fallmap_data_27",fallmap_json27);
    fallmap_obj.insert("fallmap_data_28",fallmap_json28);
    fallmap_obj.insert("fallmap_data_29",fallmap_json29);
    fallmap_obj.insert("fallmap_data_30",fallmap_json30);
    fallmap_obj.insert("fallmap_data_31",fallmap_json31);
    fallmap_obj.insert("fallmap_data_32",fallmap_json32);
    fallmap_obj.insert("fallmap_data_33",fallmap_json33);
    fallmap_obj.insert("fallmap_data_34",fallmap_json34);
    fallmap_obj.insert("fallmap_data_35",fallmap_json35);
    fallmap_obj.insert("fallmap_data_36",fallmap_json36);
    fallmap_obj.insert("fallmap_data_37",fallmap_json37);
    fallmap_obj.insert("fallmap_data_38",fallmap_json38);
    fallmap_obj.insert("fallmap_data_39",fallmap_json39);
    fallmap_obj.insert("fallmap_data_40",fallmap_json40);
    fallmap_obj.insert("fallmap_data_41",fallmap_json41);
    fallmap_obj.insert("fallmap_data_42",fallmap_json42);
    fallmap_obj.insert("fallmap_data_43",fallmap_json43);
    fallmap_obj.insert("fallmap_data_44",fallmap_json44);
    fallmap_obj.insert("fallmap_data_45",fallmap_json45);
    fallmap_obj.insert("fallmap_data_46",fallmap_json46);
    fallmap_obj.insert("fallmap_data_47",fallmap_json47);
    fallmap_obj.insert("fallmap_data_48",fallmap_json48);
    fallmap_obj.insert("fallmap_data_49",fallmap_json49);
    fallmap_obj.insert("fallmap_data_50",fallmap_json50);
    fallmap_obj.insert("fallmap_data_51",fallmap_json51);
    fallmap_obj.insert("fallmap_data_52",fallmap_json52);
    fallmap_obj.insert("fallmap_data_53",fallmap_json53);
    fallmap_obj.insert("fallmap_data_54",fallmap_json54);
    fallmap_obj.insert("fallmap_data_55",fallmap_json55);
    fallmap_obj.insert("fallmap_data_56",fallmap_json56);
    fallmap_obj.insert("fallmap_data_57",fallmap_json57);
    fallmap_obj.insert("fallmap_data_58",fallmap_json58);
    fallmap_obj.insert("fallmap_data_59",fallmap_json59);
    fallmap_obj.insert("fallmap_data_60",fallmap_json60);
}
