#pragma once
//cannot create instances of abstract classes
//they ONLY serve as base classes to other classes
class Animal
{
public:
	virtual void MakeSound() = 0;//make it a pure virtual function
	//this makes Animal an abstract BASE class
};

