#include "Car.h"

std::string Car::vehicleInformation()
{
	return std::to_string(mModelYear) + " " + mMake + " " + mModel;
}

void Car::SerializeCSV(std::ofstream& outFile, char delimiter) const
{
	//should NOT open the file
	//should NOT close the file
	//should write to the file
	outFile << mModelYear << delimiter << mMake << delimiter << mModel;
}

void Car::DeserializeCSV(const std::string& csvData, char delimiter)
{
	//use stringstream + getline to parse the string
	std::string data;
	std::stringstream csvStream(csvData);
	std::getline(csvStream, data, delimiter);
	mModelYear = std::stoi(data);
	std::getline(csvStream, mMake, delimiter);
	std::getline(csvStream, mModel, delimiter);
}
