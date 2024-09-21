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

// @return seconds since the start of the program.
float getTime();
inline void sleepFor(float seconds) { if(seconds <= 0.0) return; std::this_thread::sleep_for(std::chrono::nanoseconds(uint64_t(seconds * 1e9))); }

class _ScopedTimer {
public:

	_ScopedTimer(float* pTimeVariable) : elapsedTime(pTimeVariable) { startTime = getTime(); }
	~_ScopedTimer() { *elapsedTime = getTime() - startTime; }

private:

	float* elapsedTime;
	float  startTime;

};

#ifndef DISABLE_SCOPEDTIMER

#define scopedTimer(id, pTimeVariable) _ScopedTimer id(pTimeVariable)

#else 

#define scopedTimer(id, pTimeVariable) ((void)0)

#endif