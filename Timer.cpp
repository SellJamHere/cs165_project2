#include "Timer.h"

#include <iostream>

//Tried importing cTimer.h, but ended up with a nightmare of linker errors
#ifndef C_TIMER_C_
#define C_TIMER_C_
#include "cTimer.c"
#endif

Timer globalTimer;

Timer::Timer()
{
    start_timer();
}

Timer::~Timer()
{
    //iterate through each map entry
    for (map<string, FunctionTimeData>::iterator mapIt = functionMap.begin(); 
         mapIt != functionMap.end(); 
         mapIt++)
    {

    }
}

void Timer::beginFunction(string functionName)
{
    cout << "Begin " << functionName << endl;
    FunctionTimeData funcTime;
    funcTime.startTime = user_time();
}

void Timer::endFunction(string functionName)
{
    FunctionTimeData funcTime = functionMap[functionName];
    double endTime = user_time();
    funcTime.totalTime += (endTime = funcTime.startTime);
    funcTime.count++;
    cout << "End " << functionName << endl;
}

double Timer::averageTimeForFunction(string functionName)
{
    FunctionTimeData funcTime = functionMap[functionName];
    return funcTime.averageTime();
}

ostream& operator<<(ostream &os, Timer &timer)
{
    //iterate through each map entry
    for (map<string, FunctionTimeData>::iterator mapIt = timer.functionMap.begin(); 
         mapIt != timer.functionMap.end(); 
         mapIt++)
    {
        os << mapIt->first << " average time: " << timer.averageTimeForFunction(mapIt->first) << endl;
    }

    return os;
}
