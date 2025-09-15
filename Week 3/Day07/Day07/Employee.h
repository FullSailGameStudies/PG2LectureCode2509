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

private:
	std::string jobTitle_;
	int yearsWorking_;
};

