#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

class Timer {
	friend std::ostream &operator<<(std::ostream &os, const Timer timer){
		if(timer.running){
			std::ostringstream oss;
			oss << "Cannot print time because the timer is still running.\n";
			throw oss.str();
		}
		os << std::setfill('0') << std::setw(2) << timer.hours() << ":" << std::setw(2) 
			<< timer.minutes() << ":" << std::setw(2) << timer.seconds() << ":" << timer.ticks();
		return os;
	}
	
	private : 
		bool running;
		std::string timer_name;
		clock_t duration, start_time, stop_time;
	public :
		Timer(std::string s);
		
		std::string getName();	
		void start();
		void stop();
		int ticks() const;
		int seconds() const;
		int minutes() const;
		int hours() const;
};

#endif
