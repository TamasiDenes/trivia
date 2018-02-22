// GameRunner.cpp : Defines the entry point for the console application.
//

#include "Game.h"

int main()
{
	Game aGame;
	bool isAWinner = false;

	aGame.addPlayer("Chet");
	aGame.addPlayer("Pat");
	aGame.addPlayer("Sue");

	do
	{
		if (aGame.roll())
		{
			if (aGame.answerIt())
				isAWinner = aGame.correctAnswer();
			else
				aGame.wrongAnswer();
		}
		aGame.NextPlayer();
	} while (!isAWinner);

}
