#pragma once
#include <iostream>
#include <ctime>



class Timer
{
	clock_t rounds;
	float current_time;
	float time;

public:

	void start(){this->rounds = clock();};
	void end();
	void convertSecToMin();
	Timer(){this->current_time = 0; this->time = 0;};
	void reset(){this->time = 0; this->current_time = 0;};
	void round(){this->time = this->time + this->current_time;};
	float getTime(){return this->time;};
};



