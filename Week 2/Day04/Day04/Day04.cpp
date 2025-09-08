﻿// Day04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <string_view>
#include "Console.h"
#include "Input.h"


std::string toUpper(const std::string& original)
{
	std::string copy = original;
	for (auto& c : copy)
		c = toupper(c);
	return copy;
}

void recursiveLoop(int N)
{
	recursiveLoop(N + 1);
}

unsigned long factorial(unsigned int N)
{
	if (N <= 1) return 1; //here's the exit condition!
	return N * factorial(N - 1);
}

/*
	╔═══════╗
	║Sorting║
	╚═══════╝

	Sorting is used to order the items in a vector/array is a specific way

	CHALLENGE 2:

		Convert this BubbleSort pseudo-code into a method

		procedure bubbleSort(A : list of sortable items)
		  n := length(A)
		  repeat
			  swapped := false
			  for i := 1 to n - 1 inclusive do
				  if A[i - 1] > A[i] then
					  swap(A, i - 1, i)
					  swapped = true
				  end if
			  end for
			  n := n - 1
		  while swapped
		end procedure

*/
void bubbleSort(std::vector<std::string>& A)
{
	//n := length(A)
	int n = A.size();
	bool swapped;
	do  //repeat
	{
		//swapped := false
		swapped = false;

		//for i := 1 to n - 1 inclusive do
		for (int i = 1; i <= n - 1; i++)
		{
			//if A[i - 1] > A[i] then
			if (A[i - 1] > A[i])
			{
				//swap(A, i - 1, i)  //TODO: figure this out later!!
				//OG: 
				//std::string temp = A[i - 1];
				//A[i - 1] = A[i];
				//A[i] = temp;
				//OR...
				std::swap(A[i - 1], A[i]);

				//swapped = true
				swapped = true;
			}//end if
		}//end for
		//n := n - 1
		n = n - 1; //--n  n-- n-=1
	} while (swapped); //while swapped
}//end procedure

void Simple(int n)
{
	if (n >= 10) return;

	std::cout << "n=" << n << "\n";
	Simple(n + 1);//recursive call
	std::cout << "n=" << n << "\n";

}//the return line

void Bats(int i = 0)
{
	if (i >= 100) return;
	{
		std::cout << (char)78 << (char)65 << ' ';
		//i++ post-increment
		//++i pre-increment (slightly better performance)
		Bats(++i);
	}
}

void ReverseWord(const std::string& word, int index = 0)
{
	if (index < word.size() - 1)
	{
		ReverseWord(word, index + 1);
	}
	std::cout << word[index];
}

int main()
{
	ReverseWord("Batman");
	std::cout << "\n\n";
	Simple(0);
	for (int i = 0; i < 10; i++)
	{
		Simple(i);
	}
	std::vector<std::string> names = { "Wonder Woman", "Superman", "Batman", "Flash", "Aquaman" };
	//call your BubbleSort on the names vector.

	Console::WriteLine("--UNSORTED--", ConsoleColor::Yellow);
	//print the sorted vector.
	for (auto& name : names)
		std::cout << name << "\n";

	//call BubbleSort
	bubbleSort(names);

	Console::WriteLine("--SORTED--", ConsoleColor::Yellow);
	//print the sorted vector.
	for (auto& name : names)
		std::cout << name << "\n";


	/*
		╔═════════╗
		║Recursion║
		╚═════════╝

		Recursion happens when a method calls itself. This creates a recursive loop.

		All recursive methods need an exit condition, something that prevents the loop from continuing.

	*/
	int N = 0;
	//recursiveLoop(N);


	/*
		CHALLENGE 1:

			convert this for loop to a recursive method called Bats.
			Call Bats here in Main.

			for(int i = 0;i < 100;i++)
			{
				std::cout << (char)78 << (char)65 << ' ';
			}
	*/
	//call Bats here.
	Bats();

	char c[] = { '\n', 66, 65, 84, 77, 65, 78, 33, 33 };
	for (auto ch : c) std::cout << ch;



	/*
		╔═════════════════╗
		║  Swapping Items ║
		╚═════════════════╝

		add #include <string_view>
		make sure the project is using C++17 or greater.

	*/
	std::cout << "\n\n---SWAPPING ITEMS---\n";
	std::vector<int> nums = { 1,2,3,4,5 };
	for (auto i : nums)
		std::cout << i << " ";
	std::cout << " (original)\n";

	//write code to swap 2 items in the vector

	std::cout << " (after swapping)\n";
	for (auto i : nums)
		std::cout << i << " ";

	/*
		╔═════════════════╗
		║Comparing Strings║
		╚═════════════════╝

		the compare functions return an int that will tell you
		how the strings compare to each other.
		< 0 means s1 is LESS THAN (or comes before) s2
		  0 means s1 is EQUAL TO s2
		> 0 means s1 is GREATER THAN (or comes after) s2

		_stricmp: case-insensitive string comparison.
			The methods needs pointers to char arrays therefore
			you need to call c_str on the std::string

		std::string::compare:  case-sensitive string comparison
			If you want to ignore case, you can convert the strings
			to all uppercase/lowercase

	*/
	std::string s1 = "Batman", s2 = "Aquaman";
	int compResult = _stricmp(s1.c_str(), s2.c_str());
	//OR...
	int compareResult = toUpper(s1).compare(toUpper(s2));





}