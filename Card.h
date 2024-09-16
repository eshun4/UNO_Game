#pragma once
#include <iostream>
#include "/C++ Projects/UNO_Game/CardColorEnum.h"
#include "/C++ Projects/UNO_Game/CardType.h"

class Card
{
private:
    CardColorEnum color;
    int number; // Used for numbered cards only
    CardType type;

public:
    Card();
    Card(CardColorEnum color, int number, CardType type); // No default arguments here
    std::string toString() const;
    ~Card();
};
