#pragma once

/*
*
* Problem: I hate using the chrono cpp header in practice. 
*   all these namespaces, templates, and constructors when all I want to know is how many seconds has passed between two points in time.
* Solution: Create a wrapper function around that uses the chrono api to get the time. Lol
*
*/

// @return seconds since the start of the program.
double getTime();