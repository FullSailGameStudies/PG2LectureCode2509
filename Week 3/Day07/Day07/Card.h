#pragma once
#include <string>
class Card
{
public:
	Card(const std::string& face, const std::string& suit);
	std::string Face() const { return face_; }
	void Face(const std::string& face)
	{
		if (face.size() > 0)
			face_ = face;
	}
	std::string Suit() const { return suit_; }
	void Suit(const std::string& suit)
	{
		if (suit.size() > 0)
			suit_ = suit;
	}

	void Print() const;
	int Value() const;

private:
	std::string face_, suit_;
};

