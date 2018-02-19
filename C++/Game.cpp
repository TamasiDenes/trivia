#include "stdafx.h"
#include "Game.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

Game::Game( unsigned DiceSideNumber = 6)
	: diceSideNumber(DiceSideNumber)
{
	questions.push_back("Pop");
	questions.push_back("Science");
	questions.push_back("Sports");
	questions.push_back("Rock");
}

void Game::addPlayer(string playerName) 
{
	players.push_back(playerName);

	cout << playerName << " was added" << endl;
	cout << "They are player number " << players.size() << endl;
}

bool Game::roll(unsigned roll)
{
	if (roll > 6) 
		roll = roll % 6 + 1;

	cout << players.GetCurrentPlayer().GetName() << " is the current player" << endl;
	
	cout << "They have rolled a " << roll << endl;

	bool didPlayerGetQuestion = false;

	bool inPenalty = players.GetCurrentPlayer().IsInPenaltyBox();
	if ( !inPenalty || roll % 2 != 0 )
	{
		if (inPenalty)
		{
			cout << players.GetCurrentPlayer().GetName() << " is getting out of the penalty box" << endl;
			players.GetCurrentPlayer().SetPenaltyBox(false);
		}

		unsigned newPlace = (players.GetCurrentPlayer().GetPlace() + roll);
		if( newPlace >= 3 * questions.size() )
			newPlace -= 3 * question.size();
			
		players.GetCurrentPlayer().SetPlace(newPlace);

		int placeOfCurrentPlayer = players.GetCurrentPlayer().GetPlace();

		cout << players.GetCurrentPlayer().GetName() << "'s new location is " << placeOfCurrentPlayer << endl;
		cout << "The category is " << questions.GetCurrentQuestionCategoryName( placeOfCurrentPlayer % questions.size()) << endl;
		
		askQuestion();
		didPlayerGetQuestion = true;
	}
	else
		cout << players.GetCurrentPlayer().GetName() << " is not getting out of the penalty box" << endl;

	return didPlayerGetQuestion;
}

void Game::askQuestion()
{
	int categoryIndex = players.GetCurrentPlayer().GetPlace() % questions.size();
	cout << questions.PopNextQuestion( categoryIndex ) << endl;
}


bool Game::correctAnswer()
{
	cout << "Answer was corrent!!!!" << endl;
	
	players.GetCurrentPlayer().AddPurse();
	
	cout << players.GetCurrentPlayer().GetName()
		<< " now has "
		<< players.GetCurrentPlayer().GetPurse()
		<< " Gold Coins." << endl;

	return didPlayerWin();
}

void Game::wrongAnswer()
{
	cout << "Question was incorrectly answered" << endl;

	cout << players.GetCurrentPlayer().GetName() + " was sent to the penalty box" << endl;

	players.GetCurrentPlayer().SetPenaltyBox(true);
}


bool Game::didPlayerWin()
{
	return players.GetCurrentPlayer().GetPurse() == 6;
}
