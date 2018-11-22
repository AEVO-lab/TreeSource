//
// Created by Manuel on 2018-11-21.
//

#ifndef DIV_TIMER_H
#define DIV_TIMER_H


#include <map>
#include <chrono>
#include <thread>

using namespace std;

class Timer {
public:
    static Timer* Instance()
    {
        static Timer instance;

        return &instance;
    }



    void StartTiming(string key)
    {
        clocks[key] = std::chrono::high_resolution_clock::now();
    }

    long long int StopTimingMicros(string key)
    {
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

        long long int duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - clocks[key] ).count();
        return duration;
    }

    long long int StopTimingMillis(string key)
    {
        std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();

        long long int duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - clocks[key] ).count();
        return duration;
    }


    void SleepMillis(int millis)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(millis));
    }

private:
    map<string, std::chrono::high_resolution_clock::time_point> clocks;
};


#endif //DIV_TIMER_H
