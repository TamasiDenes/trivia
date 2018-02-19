#pragma once

#include "CurrentPlayers.h"
#include "QuestionCategoryContainer.h"

class Game {

private:
	CurrentPlayers players;
	QuestionCategoryContainer questions;

public:
	Game();
	bool isPlayable();
	void addPlayer(string playerName);

	bool roll(unsigned newPlace);
	void NextPlayer() { players.NextPlayer(); };

private:
	void askQuestion();

public:
	bool correctAnswer();
	void wrongAnswer();

private:
	bool didPlayerWin();
};

