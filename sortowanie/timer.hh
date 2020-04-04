#include <iostream>
#include <ctime>
using namespace std;



class Timer
{
	clock_t rounds;
	float current_time;
	float time;

public:

	void start(){rounds = clock();};
	void end();
	void convertSecToMin();
	Timer(){current_time = 0; time = 0;};
	void reset(){time = 0; current_time = 0;};
	void round(){time = time + current_time;};
	float getTime(){return time;};
};


void Timer::end()
{
	current_time = float(clock()-rounds)/CLOCKS_PER_SEC;
}

void Timer::convertSecToMin()
{
	int minutes = 0; 
	while(time>60)
	{
		minutes ++;
		time = time - 60;
	}
	if (minutes == 0)
		cout << time << " seconds"; 
	else
		if(minutes == 1)
			cout << minutes << " minute "<< time << " seconds";
		else
			cout << minutes << " minutes "<< time << " seconds";
}




