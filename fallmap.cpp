#include "fallmap.h"

fallmap::fallmap(demowave* _demowave, int _fallmapFlashTime) :
  m_demowave(_demowave)
  ,peakNum(m_demowave->PeakNum())
  ,fallmapFlashTime(_fallmapFlashTime)
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

void fallmap::Judgement(vector<float>& max_data, vector<int>& max_data_index)
{
    /*---------------寻找当前测区位置-------------------*/
    //select the region index of max amplitude in all regions
    auto iterator_max_all = std::max_element(max_data.begin(),max_data.end());

    present_region = iterator_max_all - max_data.begin() + 1; //the region with max amplitude

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

//    m_fault_detection = new Fault_detection(strain_data,2*strainRange);
//    if(!m_fault_detection->isRunning()) m_fault_detection->start();

    /*---------------当前测区是否异常判断-------------------*/
//    IsFault = m_fault_detection->GetIsFault();

//    max_amplitude_all = *iterator_max_all; //max amplitude of all regions
//    if(max_amplitude_all > 4) IsNormal = false; //statement detection
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

void fallmap::run()
{
    qDebug() <<"Fallmap Thread responsed !"<<endl;

    //copy the data of the last vector to the present vector
    for(int i=Nf1-1; i>0; --i){
        std::copy(FallmapDataVec[i-1].begin(),FallmapDataVec[i-1].end(),FallmapDataVec[i].begin());
    }

    //select the max result of every N1 length of data to display
    int len = m_demowave->Freq() * fallmapFlashTime / 1000; //length of data in one flash

    vector<float> max_data(peakNum); //max results of data of every region
    vector<int> max_data_index(peakNum); //the index of max results of data of every region

    SelectMax(max_data, max_data_index, len);

    //copy into the first vector
    std::copy(max_data.begin(), max_data.end(), FallmapDataVec[0].begin());

    Judgement(max_data, max_data_index);

    PreProcess();

    QJsonArray PresentRegion_json, IsNormal_json;
    present_region = 25;
    PresentRegion_json.push_back(present_region);
    IsNormal_json.push_back(IsFault);
    judgement_obj.insert("present_region",PresentRegion_json);
    judgement_obj.insert("IsNormal",IsNormal_json);
}
