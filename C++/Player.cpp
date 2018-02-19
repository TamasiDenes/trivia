#include "stdafx.h"
#include "Player.h"
#include <string>

Player::Player(std::string Name)
	: name(Name)
	, isInPenalty(false)
	, place(0)
	, purse(0)
{}


Player::~Player()
{
}

void Player::SetPlace(unsigned newPlace)
{
	place = newPlace;
}
