#include <chrono>

using namespace std::chrono;

high_resolution_clock::time_point appStartTime = high_resolution_clock::now();

float getTime() {

	high_resolution_clock::time_point now = high_resolution_clock::now();
	return duration<float, std::chrono::seconds::period>(now - appStartTime).count(); 

}