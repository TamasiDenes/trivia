#pragma once

#include "Player.h"

#include <vector>
#include <string>

using namespace std;

class CurrentPlayers : public vector<Player>
{
	int currentPlayerIndex;

public:
	CurrentPlayers();
	~CurrentPlayers();

	void NextPlayer();

	Player& GetCurrentPlayer() { return (*this)[currentPlayerIndex]; };
};

