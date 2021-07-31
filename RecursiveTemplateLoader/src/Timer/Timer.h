#pragma once

#include <chrono>
#include <iostream>

/// <summary>
/// {
///		Timer();
///		//TODO
///		~Timer();// << cout durationTime
/// }
/// </summary>
/// 
class Timer
{
public:
	Timer();
	~Timer();
private:
	std::chrono::steady_clock::time_point startTime, endTime;
};

