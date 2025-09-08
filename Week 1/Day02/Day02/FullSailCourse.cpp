#include "FullSailCourse.h"
#include <iostream>

void FullSailCourse::GetGrades(std::vector<float>& grades)
{
	for (int i = 0; i < 20; i++)
	{
		grades.push_back(rand() % 10001 / 100.0f);
	}
}

void FullSailCourse::PrintGrades(const std::vector<float>& grades)
{
	std::cout << "\n\n" << name << "\n";
	for (auto& grade : grades)
	{
		std::cout << grade << "\n";
	}
	std::cout << "\n\n";
}

void FullSailCourse::EraseGrades(std::vector<float>& grades, float minGrade) const
{
	for (int i = 0; i < grades.size(); i++)
	{
		if (grades[i] < minGrade)
		{
			grades.erase(grades.begin() + i);
			i--;
		}
	}
	//OR...
	for (int i = 0; i < grades.size(); )
	{
		if (grades[i] < minGrade)
		{
			grades.erase(grades.begin() + i);
		}
		else
		{
			i++;
		}
	}
	//OR...
	for (int i = grades.size() - 1; i >= 0; i--)
	{
		if (grades[i] < minGrade)
		{
			grades.erase(grades.begin() + i);
		}
	}
}

const std::string& FullSailCourse::GetName() const
{
	return name;
}

void FullSailCourse::SetName(const std::string& newName)
{
	name = newName;
}
