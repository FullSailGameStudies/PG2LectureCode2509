#include "Card.h"
#include <iostream>

Card::Card(const std::string& face, const std::string& suit) :
	face_(face),
	suit_(suit)
{
}

void Card::Print() const
{
	std::cout << face_ << " " << suit_ << "\n";
}

int Card::Value() const
{
	int val = 0;
	if (face_ == "A") val = 1;
	else if (face_ == "2") val = 2;
	else if (face_ == "3") val = 3;
	else if (face_ == "4") val = 4;
	else if (face_ == "5") val = 5;
	else if (face_ == "6") val = 6;
	else if (face_ == "7") val = 7;
	else if (face_ == "8") val = 8;
	else if (face_ == "9") val = 9;
	else if (face_ == "10") val = 10;
	else if (face_ == "J") val = 11;
	else if (face_ == "Q") val = 12;
	else val = 13;
	return val;
}
