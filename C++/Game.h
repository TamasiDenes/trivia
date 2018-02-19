#pragma once

#include "CurrentPlayers.h"
#include "QuestionCategoryContainer.h"

class Game {

private:
	CurrentPlayers players;
	QuestionCategoryContainer questions;
	
	void askQuestion();
	bool didPlayerWin();

public:
	Game( unsigned DiceSideNumber );
	
	const unsigned diceSideNum;
	
	bool isPlayable();
	void addPlayer(string playerName);

	bool roll();
	bool answerIt( unsigned hitRatio = 10)
	{
		return (rand() % 100 < hitRation );
	}
	void NextPlayer() { players.NextPlayer(); };
	bool correctAnswer();
	void wrongAnswer();
};

