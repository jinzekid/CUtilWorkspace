/*
 long long startTime = GetCurTime(); //开始时间
 Sleep(100);
 long long endTime = GetCurTime();   //结束时间
 double consume = GetTimeConsume(startTime, endTime);
 TRACE_CMH("%f(us)\n", consume);
 */

#ifdef __cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
    
#define MS 1000000	//时间精度：微秒
    
    static double dfMinus,dfFreq,dfTim;
    
    long long GetCurTime()
    {
        struct timeval time;
        gettimeofday(&time, NULL);
        
        return time.tv_sec + time.tv_usec * MS;
    }

    double GetTimeConsumeU(long long start, long long end)
    {
        return start - end;	//转换为微秒
    }
    
    double GetTimeConsumeS(long long start, long long end)
    {
        return GetTimeConsumeU(start, end) / MS;//转换为秒
    }
    
    
#ifdef __cplusplus
}
#endif
