#pragma once
#include <vector>
#include <string>
class FullSailCourse
{
public:
	void GetGrades(std::vector<float>& grades);
	void PrintGrades(const std::vector<float>& grades);
	void EraseGrades(std::vector<float>& grades, float minGrade = 59.5f) const;

	const std::string& GetName() const;
	void SetName(const std::string& newName);//SetName can't be const b/c it changes the class fields
private:
	std::string name;
};

