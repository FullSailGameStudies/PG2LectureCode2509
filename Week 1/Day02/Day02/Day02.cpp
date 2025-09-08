#include <iostream>
#include <string>
#include <vector>
#include "FullSailCourse.h"

//RULE:
// for parameters, 
//      if it is a class, pass by reference
//      if it is a container of other items, pass by reference
//      want to grant a method access to a variable in a different scope
// 
//pass by reference:
//  1) prevents a copy. copies are "expensive"
//  2) gives access to a variable in a different scope
//  3) effectively pass back multiple return values
bool postFix(std::string& hero)//pass by REFERENCE (alias)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    //size() - # of items in the vector
    //capacity() - length of the internal array
    //size <= capacity
    //in general, what happens when size == capacity and I push_back a new value?
    //  it "resizes" the internal array and adds the new item
    //      resize means 
    //          1) creates a new bigger array 
    //          2) copies the old array to the new array
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

int main()
{
    //postFix("Batman");
    std::string myHero = "Aquaman";
    postFix(myHero);

    int n = 5;
    int n2 = n; //copy the value of n into n2. they are separate variables
    n2++;
    int& n3 = n;//giving n a new name, n3
    n3 = n2;//copies the value of n2 to n3 (and n)
    //int& n5 = 5;
    n3--;
    std::cout << n << "," << n2 << "\n";
    std::cout << n << "," << n3 << "\n";


    /*

        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector

    */
    std::vector<float> grades;
    FullSailCourse pg2;
    pg2.SetName("PG2 2509");
    pg2.GetGrades(grades);
    pg2.PrintGrades(grades);
    pg2.EraseGrades(grades);
    pg2.PrintGrades(grades);

    const float pi = 3.14F;

    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    std::vector<int> highScores;
    highScores.reserve(10);
    printInfo(highScores);//size: 0?  capacity: 0?
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);


    std::vector<int> scores2 = highScores;//copies the vector
    std::vector<int> scores3(highScores);//copies the vector
    std::vector<int> scores4;
    scores4.reserve(highScores.size());
    for (int i = 0; i < highScores.size(); i++)
    {
        scores4.push_back(highScores[i]);
    }
    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500

    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}