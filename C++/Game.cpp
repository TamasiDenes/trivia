#include "Game.h"

#include <iostream>
#include <sstream>
#include <ctime>

Game::Game(unsigned DiceSideNumber, unsigned MapSize)
	: diceSideNumber(DiceSideNumber)
	, mapSize(MapSize)
{
	std::srand(std::time(nullptr));

	questions.push_back("Pop");
	questions.push_back("Science");
	questions.push_back("Sports");
	questions.push_back("Rock");
}

void Game::addPlayer(std::string playerName)
{
	players.push_back(playerName);

	std::cout << playerName << " was added" << std::endl;
	std::cout << "They are player number " << players.size() << std::endl;
}

bool Game::roll()
{
	unsigned roll = std::rand() % diceSideNumber + 1;

	std::cout << players.GetCurrentPlayer().GetName() << " is the current player" << std::endl;

	std::cout << "They have rolled a " << roll << std::endl;

	bool didPlayerGetQuestion = false;

	bool inPenalty = players.GetCurrentPlayer().IsInPenaltyBox();
	if (!inPenalty || roll % 2 != 0)
	{
		if (inPenalty)
		{
			std::cout << players.GetCurrentPlayer().GetName() << " is getting out of the penalty box" << std::endl;
			players.GetCurrentPlayer().SetPenaltyBox(false);
		}

		unsigned numberOfPlaces = mapSize * questions.size();
		unsigned realSteps = roll % numberOfPlaces;
		unsigned newPlace = (players.GetCurrentPlayer().GetPlace() + realSteps) % numberOfPlaces;

		players.GetCurrentPlayer().SetPlace(newPlace);

		int placeOfCurrentPlayer = players.GetCurrentPlayer().GetPlace();

		std::cout << players.GetCurrentPlayer().GetName() << "'s new location is " << placeOfCurrentPlayer << std::endl;
		std::cout << "The category is " << questions.GetCurrentQuestionCategoryName(placeOfCurrentPlayer % questions.size()) << std::endl;

		askQuestion();
		didPlayerGetQuestion = true;
	}
	else
		std::cout << players.GetCurrentPlayer().GetName() << " is not getting out of the penalty box" << std::endl;

	return didPlayerGetQuestion;
}

void Game::askQuestion()
{
	int categoryIndex = players.GetCurrentPlayer().GetPlace() % questions.size();
	std::cout << questions.PopNextQuestion(categoryIndex) << std::endl;
}


bool Game::correctAnswer()
{
	std::cout << "Answer was corrent!!!!" << std::endl;

	players.GetCurrentPlayer().AddPurse();

	std::cout << players.GetCurrentPlayer().GetName()
		<< " now has "
		<< players.GetCurrentPlayer().GetPurse()
		<< " Gold Coins." << std::endl;

	return didPlayerWin();
}

void Game::wrongAnswer()
{
	std::cout << "Question was incorrectly answered" << std::endl;

	std::cout << players.GetCurrentPlayer().GetName() + " was sent to the penalty box" << std::endl;

	players.GetCurrentPlayer().SetPenaltyBox(true);
}


bool Game::didPlayerWin()
{
	return players.GetCurrentPlayer().GetPurse() == 6;
}
