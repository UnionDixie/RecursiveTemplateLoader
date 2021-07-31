#include "Timer.h"

Timer::Timer()
{
    startTime = std::chrono::steady_clock::now();
}

Timer::~Timer()
{
    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = endTime - startTime;
    std::cout << "Elapsed time: " << elapsed_seconds.count() << "s\n";
}
