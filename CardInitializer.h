#pragma once
#include <iostream>
#include <vector>
#include "Card.h"
#include "/C++ Projects/UNO_Game/Constants.h"


class CardInitializer : public Card
{
private:
    Card* cards;
    int numberOfCards;
    Constants* constant; // Pointer to Constants

public:
    CardInitializer();

    // Constructor with Constants* parameter
    CardInitializer(Constants* constant);

    ~CardInitializer();
    
    void displayCards() const;

    void createCards(Constants* constant = new Constants());

};
