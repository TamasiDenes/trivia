#pragma once

#include "CurrentPlayers.h"
#include "QuestionCategoryContainer.h"

class Game {

private:
	CurrentPlayers players;
	QuestionCategoryContainer questions;

	const unsigned diceSideNumber;
	const unsigned mapSize;

	void askQuestion();
	bool didPlayerWin();

public:
	Game(unsigned DiceSideNumber = 6, unsigned MapSize = 3);

	bool isPlayable();
	void addPlayer(std::string playerName);

	bool roll();
	bool answerIt(int hitRatio = 90)
	{
		return (std::rand() % 100 < hitRatio);
	}
	void NextPlayer() { players.NextPlayer(); };
	bool correctAnswer();
	void wrongAnswer();
};
