#pragma once

#include <chrono>
#include <thread>

/*
*
* Problem: I hate using the chrono cpp header in practice. 
*   all these namespaces, templates, and constructors when all I want to know is how many seconds has passed between two points in time.
* Solution: Create a wrapper function around that uses the chrono api to get the time. Lol
*
*/

namespace TimerApi {

struct LabeledTime {
	const char* label;
	float time;
};

constexpr size_t      maxTimerCount = 50;
extern    size_t      labeledTimerCount;
extern    LabeledTime labeledTimes[maxTimerCount];

// @return seconds since the start of the program.
float getTime();
void sleepFor(float seconds);

float& getTimerById(const char* id); 

class _ScopedTimer {
public:

	_ScopedTimer(const char* timerID);
	~_ScopedTimer();

private:

	const char* m_TimerID; 
	std::chrono::high_resolution_clock::time_point m_StartTime; 

};

}

// id must follow the naming rules of normal variables...
#define scopedTimer(id) TimerApi::_ScopedTimer id(#id)