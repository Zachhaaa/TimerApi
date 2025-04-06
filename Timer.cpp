#include "Timer.hpp"

using namespace std::chrono;

high_resolution_clock::time_point appStartTime = high_resolution_clock::now();

// TimerApi funcs: 

namespace TimerApi {

size_t      labeledTimerCount = 0; 
LabeledTime labeledTimes[maxTimerCount]{};

float getTime() {

	high_resolution_clock::time_point now = high_resolution_clock::now();
	return duration<float, std::chrono::seconds::period>(now - appStartTime).count(); 

}

void sleepFor(float seconds) { 
	if (seconds <= 0.0) 
		return; 
	std::this_thread::sleep_for(std::chrono::nanoseconds(uint64_t(seconds * 1e9))); 
}

float& getTimerById(const char* id) {
	for (size_t i = 0; i < labeledTimerCount; i++) {
		for (size_t j = 0; labeledTimes[i].label[j] == id[j]; j++) {
			if (id[j] == '\0') return labeledTimes[i].time;
		}
	}
	size_t timerIndex = labeledTimerCount; 
	labeledTimerCount++; 
	labeledTimes[timerIndex] = { id, -1.0 };
	
	return labeledTimes[timerIndex].time;
}


_ScopedTimer::_ScopedTimer(const char* timerID) : m_TimerID(timerID) {
	m_StartTime = high_resolution_clock::now(); 
}
_ScopedTimer::~_ScopedTimer() {
	high_resolution_clock::time_point now = high_resolution_clock::now();
	float elapsedTime = duration<float, std::chrono::seconds::period>(now - m_StartTime).count();
	getTimerById(m_TimerID) = elapsedTime; 
}

}
