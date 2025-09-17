#pragma once
#include "Person.h"

//inheritance modes:
//	control the access modifier that gets applied to the parent members
//	public: the access modifiers in the base stay the same
//  protected: public members of the base are now protected in the derived
//  private: public and protected members of the base are now private in the derived
//     private is the default

//everything in Person is now part of Employee
class Employee : public Person
{
public:
	Employee(const std::string& name, int age, const std::string& jobTitle, int yrs);

	//
	// OVERRIDING:
	//   step 1: mark the base method as virtual
	//		virtual tells the compiler that this method MIGHT be overridden by any child class
	//	 step 2: override it in the child class
	//		create a method with the same signature in the child
	virtual void DoWork(int numberOfHours);
private:
	std::string jobTitle_;
	int yearsWorking_;
};

