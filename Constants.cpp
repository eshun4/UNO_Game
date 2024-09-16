#include "Constants.h"
#include <iostream>


Constants::~Constants() {};

Constants::Constants() {};

int Constants::getTotalCards() const
{
		return TOTALCARDS;
}

int Constants::getBlueCards() const
{
	return BLUE;
};

int Constants::getGreenCards() const
{
	return GREEN;
};

int Constants::getRedCards() const
{
	return RED;
};

int Constants::getYellowCards() const 
{
	return YELLOW;
};

