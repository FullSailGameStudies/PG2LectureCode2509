﻿// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */

    std::string fileName = "2509.csv";
    std::string path = "C:/temp/2509/";
    std::string fullPath = path + fileName;

    //1. Open the file
    //  1.1  check if the file is open
    //       print an error message if NOT
    //the path MUST exists before trying to open the file
    char delimiter = '$';
    std::ofstream outFile(fullPath);
    if (outFile.is_open())
    {
        //2. write to the file
        // use '<<' to write to the file
        // '<<' insertion operator
        // must write a delimiter between each piece of data to be in CSV format
        outFile << "Batman is #1" << delimiter 
                << 5 << delimiter 
                << 13.7 << delimiter 
                << true << delimiter 
                << "Aquaman is #536";
    }
    else
    {
        std::cout << fullPath << " could not be opened.\n";
    }

    //3. CLOSE the file
    //      close the file as soon as possible!
    outFile.close();


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */

    //1. open the file
    //  1.1  check if the file is open
    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        //2. READ the file
        std::string line;
        //use getline to read the file
        //read 1 line from the file
        //  stops when it hits a '\n' OR reaches the end of the file
        std::getline(inFile, line); 

        //PARSE the string for each piece of data
        //  use getline to read the string
        //  getline can ONLY read from STREAMS (cin, ifstream, stringstream)
        std::stringstream lineStream(line);
        std::string data;
        //  stops when it hits a delimiter OR reaches the end of the stream
        std::getline(lineStream, data, delimiter);
        std::cout << data << "\n";

        //try-catch block
        //  put the code inside the try block
        //  add catches to handle the exceptions that might be thrown
        try
        {
            std::getline(lineStream, data, delimiter);
            int iData = std::stoi(data);
            std::cout << iData << "\n";

            std::getline(lineStream, data, delimiter);
            double dData = std::stod(data);
            std::cout << dData << "\n";

            std::getline(lineStream, data, delimiter);
            bool bData = std::stoi(data);
            std::cout << bData << "\n";

            std::getline(lineStream, data, delimiter);
            std::cout << data << "\n";
        }
        //handle the exception
        catch (const std::exception& ex)
        {
            std::cout << "Invalid file format.\n" << ex.what() << "\n";
        }
    }
    else
    {
        std::cout << fullPath << " could not be opened.\n";
    }

    //3. CLOSE the file
    //      close the file as soon as possible!
    inFile.close();


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        1) Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        2) separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';

    std::stringstream multiStream(multi);
    while (not multiStream.eof())
    {
        std::string hero;
        std::getline(multiStream, hero, collectionSeparator);

        std::stringstream heroStream(hero);
        std::string name, identity, ageStr;
        int age;

        std::getline(heroStream, name, objectSeparator);
        std::getline(heroStream, identity, objectSeparator);
        std::getline(heroStream, ageStr, objectSeparator);
        try
        {
            age = std::stoi(ageStr);
        }
        catch (const std::exception&)
        {
            std::cout << "Error reading age data: " << ageStr << "\n";
        }

        std::cout << "Hello citizen! I am " << name << " (aka " << identity << "). ";
        std::cout << "And I am " << age << " years old.\n";
    }
}