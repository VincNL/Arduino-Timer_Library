#include "Arduino.h"
#include "Timer.h."

Timer::Timer() {
	
}

void Timer::startT() {
	if (tRun == 0) {
		pMillis = millis();
		tRun = 1;
	}
}

unsigned long Timer::checkT() {
	cMillis = millis();
	if (tRun == 1) {
		return (cMillis - pMillis);
	}
}

void Timer::resetT() {
	pMillis = 0;
	tRun = 0;
}

bool Timer::stopClock(int a) {
	if (timerLap(a)) {
		resetT();
		return true;
	}
	else
		return false;
}

bool Timer::timerLap(int a) {
	startT();
	if (checkT() == a) {
		return true;
	}
	else if (checkT() > a) {
		return false;
	}
	else
		return false;
}

void Timer::help() {
	Serial.println("startT(): \nvoid function - starts the timer\n");
	Serial.println("checkT(): \nunsigned long function \n- returns the time passed since the timer started - mili seconds\n");
	Serial.println("resetT(): \nvoid function - resets the timer and stops it\n");
	Serial.println("stopClock(int miliSeconds): \nbool function \n- starts the timer and when it gets to the value you entered it resets the timer and returns true\n");
	Serial.println("timerLap(int miliSeconds): \nbool function \n- starts the timer and when it gets to the value you entered it returns true and continue on running\n");
}