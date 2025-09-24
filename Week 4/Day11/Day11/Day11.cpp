// Day11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Car.h"
#include <vector>
#include <fstream>
#include "Console.h"
#include "Input.h"

int main()
{
    std::cout << "Gone in 60 Seconds!\n";//https://carbuzz.com/features/beyond-eleanor-gone-in-60-seconds-car-names#:~:text=The%20Complete%20List%20Of%20Gone%20In%2060%20Seconds,8%201961%20Porsche%20Speedster%20-%20%22Natalie%22%20More%20items

    Car myRide(1967, "Ford", "Shelby Mustang GT500");
    //1) open the file
    std::string fileName = "myGarage.csv";
    std::ofstream file(fileName);
    char delimiter = '^';
    if (file.is_open())
    {
        //2) write to the file
        myRide.SerializeCSV(file, delimiter);
    }
    else
    {
        std::cout << fileName << " could not be opened.\n";
    }
    //3) close the file
    file.close();

    std::ifstream inFile(fileName);
    if (inFile.is_open())
    {
        //2) read from the file
        std::string line;
        std::getline(inFile, line);
        Car car(line, delimiter);
        std::cout << car.vehicleInformation() << "\n";
    }
    else
    {
        std::cout << fileName << " could not be opened.\n";
    }
    //3) close the file
    inFile.close();


    Car todaysRide("1967,Ford,Shelby Mustang GT500", ',');

    std::vector<Car> garage;
    garage.push_back(Car(1967, "Ford", "Shelby Mustang GT500"));
    garage.push_back(Car(1956, "Ford", "T Bird"));
    garage.push_back(Car(1961, "Porsche", "Speedster"));
    garage.push_back(Car(1965, "Pontiac", "GTO"));
    garage.push_back(Car(1969, "Plymouth", "Hemi Cuda"));

    file.open(fileName);
    if (file.is_open())
    {
        //2) write to the file
        bool notFirst = false;
        for (const auto& car : garage)
        {
            if(notFirst)
                file << "\n";
            car.SerializeCSV(file, delimiter);
            notFirst = true;
        }
    }
    else
    {
        std::cout << fileName << " could not be opened.\n";
    }
    //3) close the file
    file.close();

    //open the file
    //read all the lines to create a new vector holding the cars
    //after reading all the cars, loop over the new vector and print the vehicle information
    inFile.open(fileName);
    std::vector<Car> loadedCars;
    if (inFile.is_open())
    {
        while (not inFile.eof())
        {
            //2) read from the file
            std::string line;
            std::getline(inFile, line);
            Car car(line, delimiter);
            loadedCars.push_back(car);
        }

        std::cout << "\n\nLoaded Cars...\n";
        for (auto& car : loadedCars)
        {
            std::cout << car.vehicleInformation() << "\n";
        }
    }
    else
    {
        std::cout << fileName << " could not be opened.\n";
    }
    //3) close the file
    inFile.close();

    /*
        ╔═════════════╗
        ║ Serializing ║
        ╚═════════════╝

        Saving the state (data) of objects

        Lecture Code: serialize the vector of Cars to a file.
            Data Format:
                separates cars. EX: car1|car2|car3
                separates data inside a car. EX: 1967;Ford;Shelby Mustang GT500

    */



    /*
        ╔═══════════════╗
        ║ Deserializing ║
        ╚═══════════════╝

        Recreating the objects from the saved state (data) of objects

        Lecture Code:
            Open the file
            Read in each line
            split each line to get each car
            split each car to get the car details

    */
}