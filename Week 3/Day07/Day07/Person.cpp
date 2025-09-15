#include "Person.h"

//initialize the fields of the object using the parameters
//preferred way: use the member initialization list
Person::Person(const std::string& name, int age) :
	name_(name),
	age_(age),
	height_(""),
	weight_(0),
	SSN_("--")
{
	//name_ = name;
	//age_ = age;
}

Person::Person(const std::string& name, int age, const std::string& height, 
			   float weight, const std::string& SSN) :
	name_(name),
	age_(age),
	height_(height),
	weight_(weight),
	SSN_(SSN)
{
}
