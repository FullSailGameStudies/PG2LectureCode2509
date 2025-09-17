#include "Manager.h"
#include <iostream>

void Manager::DoWork(int numberOfHours)
{
	//overriding:
	//  Full override: do NOT call the base method
	//  extension override: call the base method
	std::cout << "Going to meetings, bossing people around, doing " << numberOfHours - 5 << " hours of work.\n";
}