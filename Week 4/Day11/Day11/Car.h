#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

class Car
{
private:
	int mModelYear;
	std::string mModel;
	std::string mMake;

public:

	std::string vehicleInformation();

	Car() :mModelYear(0), mMake(""), mModel("") { }
	Car(int modelYear, std::string make, std::string model) :
		mModelYear(modelYear), mMake(make), mModel(model)
	{}
	Car(const std::string& csvData, char delimiter)
	{
		DeserializeCSV(csvData, delimiter);
	}

	void SerializeCSV(std::ofstream& outFile, char delimiter) const;

	//Deserializing...
	//1) create a Deserialize method
	//2) create a constructor that calls Deserialize

	//parse the data from the string
	//set the fields using the data
	void DeserializeCSV(const std::string& csvData, char delimiter);

	int ModelYear() const  //const says the method can't modify anything
	{ 
		return mModelYear;  //provides access to the field's value
	}

	void ModelYear(int modelYear)
	{
		mModelYear = modelYear;
	}

	const std::string& Make() const
	{
		return mMake;
	}
	void Make(std::string make)
	{
		mMake = make;
	}

	const std::string& Model() const
	{
		return mModel;
	}
	void Model(std::string model)
	{
		mModel = model;
	}
};

