#ifndef TIMER_H_
#define TIMER_H_

#include <map>
#include <vector>
#include <string>

using namespace std;

typedef struct
{
    //set starttime when function starts.
    double startTime;

    //inc count at the end of each function call
    int count;
    double totalTime;

    inline double averageTime() {return (double)totalTime / count;}
} FunctionTimeData;

class Timer
{
public:
    Timer();
    ~Timer();

    void beginFunction(string functionName);
    void endFunction(string functionName);

    double averageTimeForFunction(string functionName);

    friend ostream & operator<<(ostream &os, Timer &timer); 

private:
    map<string, FunctionTimeData> functionMap;
};


//Global Timer. Normally globals are a big No-No, but
//I want one timer for everything, sooo...
extern Timer globalTimer;

#endif