#include "Timer.h"



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
		std::cout << this->time << " seconds"; 
	else
		if(minutes == 1)
			std::cout << minutes << " minute "<< this->time << " seconds";
		else
			std::cout << minutes << " minutes "<< this->time << " seconds";
}

