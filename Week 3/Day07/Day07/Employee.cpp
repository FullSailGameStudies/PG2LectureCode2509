#include "Employee.h"

//call the base constructor in the member initialization list
Employee::Employee(const std::string& name, int age, const std::string& jobTitle, int yrs) :
	Person(name,age), //call the base ctor
	jobTitle_(jobTitle),
	yearsWorking_(yrs)
{
}
