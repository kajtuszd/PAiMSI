#pragma once
#include <iostream>
#include <ctime>
using namespace std;



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


void Timer::end()
{
	current_time = float(clock()-this->rounds)/CLOCKS_PER_SEC;
}

void Timer::convertSecToMin()
{
	int minutes = 0; 
	while(this->time>60)
	{
		minutes ++;
		this->time = this->time - 60;
	}
	if (minutes == 0)
		cout << this->time << " seconds"; 
	else
		if(minutes == 1)
			cout << minutes << " minute "<< this->time << " seconds";
		else
			cout << minutes << " minutes "<< this->time << " seconds";
}




