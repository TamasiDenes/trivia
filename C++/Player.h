#pragma once

#include <string>

class Player
{
	std::string name;
	bool isInPenalty;
	int place;
	int purse;

public:
	Player(std::string Name);
	~Player();
	std::string GetName() { return name; };

	int GetPlace() { return place; };
	void SetPlace(unsigned roll);

	int GetPurse() { return purse; };
	void AddPurse() { purse++; };

	bool IsInPenaltyBox() { return isInPenalty; };
	void SetPenaltyBox(bool inPenalty) { isInPenalty = inPenalty; };
};
