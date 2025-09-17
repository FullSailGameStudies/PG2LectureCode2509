#pragma once
#include <string>
#include "Animal.h"

//what the class can DO (methods)
//	job, eat, sleep
//what describes the class (data)
//	height, weight, name, age, SSN
class Person : public Animal
{
	//shared variable for ALL Person objects
	static int numberOfPeople;



	//ACCESS modifiers: who has access to the class parts
	//  you can have any number of these sections
	//  they can be in any order
	// 
public: //ALL code can see it, use it, change it
	void MakeSound() override;

	//static methods:
	//  they do NOT have a 'this' parameter
	//	can ONLY access static members (static fields and static methods)
	static void Report()
	{
		std::cout << numberOfPeople << " people in the world!\n";
	}

	//constructors (ctor): special methods to initialize our object
	//  MUST be called to create an object of the class
	//		IF you do not create a ctor, the compiler gives you a default ctor
	//			DEFAULT ctor: no parameters
	//		IF you DO create a ctor, the compiler's ctor is not longer created
	//	MUST follow these RULES: 
	//		MUST be named the same as the class
	//		CANNOT have any return type (not even void)
	//Person(); //default ctor
	Person(const std::string& name, int age);
	Person(const std::string& name, int age, const std::string& height, float weight, const std::string& SSN);

	//getters/setters are the GATEKEEPERS of your data
	//they control the access
	//	exception: they can be DEFINED in the header

	//getters (accessors)
	//	general rules: 
	//		no parameters, 
	//		const
	//		return type matches the type of the field
	//		returns the field
	std::string GetName() const { return name_; }
	//Non-static methods:
	//  there is a hidden parameter called 'this'
	//	non-static methods can access BOTH non-static AND static members
	int Age() const 
	{ 
		//"this" is a pointer to the current object
		return this->age_; //how does this get the correct age for an object?
	}

	//setters (mutators)
	//	general rules:
	//		1 parameter that matches the type of the field
	//		NOT const
	//		void return type
	//		good place for validation
	void SetName(const std::string& name)
	{
		if (name.size() > 0 && name.size() < 32)
		{
			name_ = name;
		}
	}
	void Age(int age)
	{
		if (age >= 0 && age <= 120)
			age_ = age;
	}

protected: //this class AND all descendent classes

private: //(DEFAULT) ONLY* this class can see it, use it, etc

	//FIELDS: data of your class
	//  most of the time, make them PRIVATE
	//  to protect the data of your object
	//	naming convections:
	//		camelCasingNamingConvention
	//		add m_ or m or _
	//		be consistent
	//		why? to have a visual difference between fields and other variables\
	//			so you know the impact of changing a variable
	//			parameters vs local variables vs fields
	// 
	//non-static means every instance of Person has their own set of these variables
	std::string SSN_;
	std::string height_;
	float weight_;
	std::string name_;
	int age_;

	void Sample(int param)
	{
		//ONLY use this-> to eliminate ambiguity
		//	this is a pointer to the current object
		
		int local;
		local = 5;//local change
		param = 10;//could impact a variable in a different scope
		SSN_ = "12121221";//changes the OBJECT
	}
};

