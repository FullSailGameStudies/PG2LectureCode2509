#pragma once
#include <string>
#include <vector>

class Menu
{
public:
	//declarations
	std::string GetName();
	void SetName(std::string name);

	void AddMenuItem(std::string itemToAdd);

	//add a method for printing the menu
	void PrintMenu();
private:
	std::string restaurantName;
	std::vector<std::string> menuItems;
};

