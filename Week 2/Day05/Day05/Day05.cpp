// Day05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Console.h"
#include "Input.h"
#include <iomanip>//used to format with cout

enum class Weapon
{
    Sword, Axe, Spear, Mace
};

const int NOT_FOUND = -1;

int LinearSearch(const std::vector<int>& nummies, int searchNumber)
{
    int result = NOT_FOUND;
    for (int i = 0; i < nummies.size(); i++)
    {
        if (nummies[i] == searchNumber)
        {
            result = i;
            break;
        }
    }
    return result;
}

void PrintGrades(const std::map<std::string, double>& course)
{
    std::cout << "\n\nPG2 2509\n";
    for (auto& [student,grade] : course)
    {
        std::cout << std::setw(15) << std::left << student << " ";
        Console::SetForegroundColor(
            //ternary operator
            (grade < 59.5) ? ConsoleColor::Red :
            (grade < 69.5) ? ConsoleColor::Yellow :
            (grade < 79.5) ? ConsoleColor::Blue :
            (grade < 89.5) ? ConsoleColor::Magenta :
            ConsoleColor::Green
        );
        std::cout << std::setw(7) << std::right << grade << "\n";
        Console::Reset();
    }
}

int main()
{
    /*
        ╔═════════╗
        ║Searching║
        ╚═════════╝

        There are 2 ways to search a vector: linear search or binary search

        CHALLENGE:

            write a method to linear search the numbers list.
                The method should take 2 parameters: vector of ints to search, int to search for.
                The method should return -1 if NOT found or the index if found.

            The algorithm:
                1) start at the beginning of the vector
                2) compare each item in the vector to the search item
                3) if found, return the index
                4) if reach the end of the vector, return -1 which means not found

    */
    std::vector<int> numbers = { 0,1,2,3,4,5,6 };
    int searchNumber = 15;
    int index = LinearSearch(numbers, searchNumber);
    if (index == NOT_FOUND)
    {
        std::cout << searchNumber << " was not found.\n";
    }
    else
    {
        std::cout << searchNumber << " was found at index " << index << "\n";
    }



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Creating a map  ]

        map<TKey, TValue>  - an associative collection.
            TKey is a placeholder for the type of the keys.
            TValue is a placeholder for the type of the values.

        When you want to create a map variable,
            1) replace TKey with whatever type of data you want to use for the keys
            2) replace TValue with the type you want to use for the values


        [  Adding items to a map  ]

        There are 2 ways to add items to a map:
        1) using the insert method.
        2) using [key] = value
    */
    std::map<Weapon, int> dorasBackpack;//will store the counts of each kind of weapon

    //returns an iterator and a bool. 
    //if the key is already in the map, it will NOT insert it -- the bool will be false.
    auto inserted = dorasBackpack.insert(std::make_pair(Weapon::Sword, 5));
    if (inserted.second == false) //meaning not inserted
        std::cout << "The key was already in the map. It was not inserted.\n";
    else
        std::cout << "The key was inserted in the map.\n";

    dorasBackpack[Weapon::Axe] = 3;
    dorasBackpack[Weapon::Axe] = 7;//simply overwrites the value if the key is already in the map


    /*
        CHALLENGE:

            Create a map that stores names (string) and grades. Call the variable grades.
            Add students and grades to your map.

    */


    std::map<std::string, float> menu;

    //add data to the map
    //1) (easy way)  map[key] = value;
    menu["potatoes"] = 0.65f;
    menu["chicken parmesan"] = 12.99f;
    menu["chicken alfredo"] = 11.99f;
    menu["slice pizza"] = 4.99f;
    menu["slice pizza"] = 8.99f;//overwrites the value

    //2) (the "hard" way) map.insert(keyValuePair);
    std::pair<std::string, float> pairToAdd =
        std::make_pair("ice cream", 4.99f);
    menu.insert(pairToAdd); 
    pairToAdd = std::make_pair("ice cream", 6.99f);
    auto wasInserted =  menu.insert(pairToAdd);//will NOT overwrite
    //pair objects have 2 items: first, second
    if (wasInserted.second)
    {
        std::cout << "item was inserted\n";
    }
    else
    {
        std::cout << "item was NOT inserted\n";
    }

    std::cout << "\n\nPG2 Cafe\n";
    //looping over a map
    //1) (easy way) foreach loop
    for (auto& pair : menu)
    {
        //setw(number) - forces the next thing printed to fit into that number of spaces
        //left - left align the next thing printed
        //right - right align the next thing printed
        std::cout << std::setw(18) << std::left << pair.first << " ";//the key
        std::cout << std::setw(7) << std::right << pair.second << "\n";//the value
    }

    std::cout << "\n\nPG2 Cafe\n";
    //foreach w/ structured binding
    for (const auto& [itemName,itemPrice] : menu)
    {
        std::cout << itemName << " ";//the key
        std::cout << itemPrice << "\n";//the value
    }

    std::cout << "\n\nPG2 Cafe\n";
    //2) ("hard" way) iterator loop
    //begin() - iterator to the first item
    //end() - iterator to the item after the last item
    //iterator++ - moves to the next item
    for (auto it = menu.begin(); it != menu.end(); it++)
    {
        std::cout << it->first << " ";//the key
        std::cout << it->second << "\n";//the value
    }
    std::cout << "\n\n";

    std::string itemToFind = "chicken parmesan";
    auto wasFound = menu.find(itemToFind);
    if (wasFound == menu.end())
        std::cout << itemToFind << " is not on the menu. Try McDonald's!\n";
    else
    {
        std::cout << itemToFind << " used to costs " << wasFound->second << "\n";
        //ways to update
        //map[key] = newValue; overwrite the old value
        //iterator->second = newValue;
        //if you have the iterator, use the iterator. do NOT lookup the key again.
        wasFound->second *= 1.1f;
        std::cout << "Now it costs " << wasFound->second << "! Thanks Putin!!\n";
    }
    std::cout << "\n\n";

    menu.erase("potatoes");//requires a lookup
    wasFound = menu.find("chicken alfredo");
    if (wasFound != menu.end())
        menu.erase(wasFound);





    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Looping over a map  ]

        You should use a ranged-based for loop when needing to loop over the entire map.

    */
    for (auto const& [key, val] : dorasBackpack) //requires C++ 20
    {
        switch (key)
        {
        case Weapon::Sword:
            std::cout << "Sword: ";
            break;
        case Weapon::Axe:
            std::cout << "Axe: ";
            break;
        case Weapon::Spear:
            std::cout << "Spear: ";
            break;
        case Weapon::Mace:
            std::cout << "Mace: ";
            break;
        default:
            break;
        }
        std::cout << val << "\n";
    }


    /*
        CHALLENGE:

            Loop over your grades map and print each student name and grade.

    */



    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Checking for a key in a map  ]

        use the find method to check if the key is in the map

        will return map.end() if NOT found.

    */
    std::map<Weapon, int>::iterator foundIter = dorasBackpack.find(Weapon::Mace);
    if (foundIter == dorasBackpack.end()) //meaning it was NOT found
    {
        std::cout << "Dora did not find any maces.\n";
    }
    else
    {
        //can safely grab the value for the key
        std::cout << "Dora found " << foundIter->second << " Maces\n";
    }



    /*
        CHALLENGE:

            look for a specific student in the map.
            If the student is found, print out the student's grade
            else print out a message that the student was not found

    */




    /*
        ╔═══════════════════╗
        ║ map<TKey, TValue> ║
        ╚═══════════════════╝

        [  Updating a value for a key in a map  ]

        To update an exisiting value in the map, use the [ ]


    */
    dorasBackpack[Weapon::Axe] = 1;//updates the count for the axe



    /*
        CHALLENGE:

            Pick any student and curve the grade (add 5) that is stored in the grades map

    */

    std::vector<std::string> students = {
        "Garrett", "Davyael", "Dai", "Kristoffer","Juno","Daniel","T.K.", "Deven", "Thomas", "Haru", "Christopher"
    };
    std::map<std::string, double> grades;
    srand(time(NULL));
    for (auto& student : students)
    {
        grades[student] = rand() % 10001 / 100.0;
    }

    do
    {
        PrintGrades(grades);
        std::string studentToCurve = Input::GetString("Student to curve: ");
        if (studentToCurve.empty()) break;

        auto studentFound = grades.find(studentToCurve);
        if (studentFound != grades.end())
        {
            studentFound->second = std::min<double>(100, studentFound->second + 5);
            std::cout << "Grade curved to " << studentFound->second << "\n";
        }
        else
            std::cout << studentToCurve << " is not in the course.\n";
    } while (true);


    do
    {
        PrintGrades(grades);
        std::string studentToCurve = Input::GetString("Student to drop: ");
        if (studentToCurve.empty()) break;

        auto studentFound = grades.find(studentToCurve);
        if (studentFound != grades.end())
        {
            grades.erase(studentFound);
        }
        else
            std::cout << studentToCurve << " is not in the course.\n";
    } while (true);
}