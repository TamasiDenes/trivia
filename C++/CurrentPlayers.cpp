#include "CurrentPlayers.h"


CurrentPlayers::CurrentPlayers()
{
	currentPlayerIndex = 0;
}


CurrentPlayers::~CurrentPlayers()
{
}

void CurrentPlayers::NextPlayer()
{
	currentPlayerIndex = currentPlayerIndex == (*this).size() - 1 ? 0 : currentPlayerIndex + 1;
}