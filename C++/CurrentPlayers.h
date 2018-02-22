#pragma once

#include "Player.h"

#include <vector>


class CurrentPlayers : public std::vector<Player>
{
	int currentPlayerIndex;

public:
	CurrentPlayers();
	~CurrentPlayers();

	void NextPlayer();

	Player& GetCurrentPlayer() { return (*this)[currentPlayerIndex]; };
};

