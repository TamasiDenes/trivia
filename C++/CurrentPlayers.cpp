#include "stdafx.h"
#include "CurrentPlayers.h"

using namespace std;

CurrentPlayers::CurrentPlayers()
{
}


CurrentPlayers::~CurrentPlayers()
{
}

void CurrentPlayers::NextPlayer()
{
	currentPlayerIndex = currentPlayerIndex == (*this).size() - 1 ? 0 : currentPlayerIndex + 1;
}