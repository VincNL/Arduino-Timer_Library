#ifndef Timer_h
#define Timer_h

class Timer {

public:
	Timer ();
	void startT();
	unsigned long checkT();
	void resetT();
	bool stopClock(int a);
	bool timerLap(int a);
	void help();

private:
	unsigned long pMillis, cMillis;
	bool tRun;
};

#endif