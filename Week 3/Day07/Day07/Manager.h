#pragma once
#include "Employee.h"
class Manager : public Employee
{
public:
	Manager(const std::string& name, int age, const std::string& jobTitle, int yrs) :
		Employee(name,age,jobTitle,yrs)
	{ }
	void DoWork(int numberOfHours) override;//override is optional but highly recommended
private:
	int numberOfEmployees;
};

