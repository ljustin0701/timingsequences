#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include "timer.h"

const int SECONDS_PER_MINUTE = 60;
const int MINUTES_PER_HOUR = 60;

Timer::Timer(std::string s) : running(false), start_time(0), stop_time(0), duration(0), timer_name(s) {}

void Timer::start(){
	if(running){
		std::ostringstream oss;
		oss << "Timer cannot start because it is still running." << "\n";
		throw oss.str();
	}
	running = true;
	start_time = clock();
}

void Timer::stop(){
	if(!running){
		std::ostringstream oss;
		oss << "Timer cannot stop because it is not even running." << "\n";
		throw oss.str();
	}
	running = false;
	stop_time = clock();
	duration = stop_time - start_time; 
	stop_time = start_time = 0;
}

std::string Timer::getName() {return timer_name;}
int Timer::ticks() const {return duration % CLOCKS_PER_SEC;}
int Timer::seconds() const {return duration / CLOCKS_PER_SEC % SECONDS_PER_MINUTE;}
int Timer::minutes() const {return duration / CLOCKS_PER_SEC / SECONDS_PER_MINUTE % MINUTES_PER_HOUR;}
int Timer::hours() const {return duration / CLOCKS_PER_SEC / SECONDS_PER_MINUTE / MINUTES_PER_HOUR;}

