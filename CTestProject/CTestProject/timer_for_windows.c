///**************************************************************************
// *  @Copyright (c) 2014, ChenMH, All rights reserved.
// 
// *  @file     : Tag_PCI_9054.cpp
// *  @version  : ver 1.0
// 
// *  @author   : ChenMH
// *  @date     : 2014/09/09 09:57
// *  @brief    : Windows平台下的高精度计时器，可以精确到微秒级！
// **************************************************************************/
//#ifdef __cplusplus
//extern "C" {
//#endif
//    
//#include <stdio.h>
//#include <Windows.h>
//
//#define MS 1000000;	//时间精度：微秒
//    
//    static LARGE_INTEGER litmp;
//    static double dfMinus,dfFreq,dfTim;
//    
//    /********************************************************
//     *  @function :  GetCurTime
//     *  @brief    :  获取定时器的当前计数值
//     *  @author   :  ChenMH  2014/08/18 10:29
//     ********************************************************/
//    long long GetCurTime()
//    {
//        //如果硬件支持，获取当前计数值
//        if(QueryPerformanceFrequency(&litmp))
//            QueryPerformanceCounter(&litmp);
//        else
//            return 0;
//        
//        return litmp.QuadPart;
//    }
//    
//    /********************************************************
//     *  @function :  GetTimeConsume
//     *  @brief    :  通过开始和结束的两个计数值，来计算时间消耗。
//     *  @author   :  ChenMH  2014/08/18 10:39
//     ********************************************************/
//    double GetTimeConsume(long long start, long long end)
//    {
//        QueryPerformanceFrequency(&litmp);
//        dfFreq = (double)litmp.QuadPart;	//定时器的频率
//        
//        dfMinus = (double)(end - start);
//        dfTim = (dfMinus/dfFreq);	//转换为秒
//        
//        return dfTim * MS;	//转换为微秒
//    }
//    
//#ifdef __cplusplus
//}
//#endif
//
//
//
//
