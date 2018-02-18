// GameRunner.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <ctime>

#include "Game.h"

int main()
{
	Game aGame;
	bool isAWinner = false;

	aGame.addPlayer("Chet");
	aGame.addPlayer("Pat");
	aGame.addPlayer("Sue");

	srand(time(nullptr));

	do
	{
		if (aGame.roll(rand() % 6 + 1))
		{
			if (rand() % 9 == 7)
				aGame.wrongAnswer();
			else
				isAWinner = aGame.correctAnswer();
		}
		aGame.NextPlayer();
	} while (!isAWinner);

}
