#include "Menu.h"
#include <iostream>

//definitions
std::string Menu::GetName()
{
	return restaurantName;
}

void Menu::SetName(std::string name)
{
	restaurantName = name;
}

void Menu::AddMenuItem(std::string itemToAdd)
{
	//don't use emplace_back!
	menuItems.push_back(itemToAdd);//add an item to the end of the vector
}

void Menu::PrintMenu()
{
	std::cout << "\n\n" << restaurantName << "\n---------------\n";

	//for loop
	for (int i = 0; i < menuItems.size(); i++)
	{
		std::cout << menuItems[i] << "\n";
	}

	//range-based for loop (foreach loop)
	std::cout << "\n\n";
	for (auto menuItem : menuItems)
	{
		std::cout << menuItem << "\n";
	}
	std::cout << "\n\n";

	menuItems.erase(menuItems.begin() + 5);//erase the item at index 5

	//iterator loop
	for (auto i = menuItems.begin(); i != menuItems.end(); i++)
	{
		//use *iterator to access the item in the vector
		std::cout << *i << "\n";
	}
	std::cout << "\n\n";

}
