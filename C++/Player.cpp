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

void Player::SetPlace(unsigned roll)
{
	place += roll;
	if (place > 11) place -= 12;
}