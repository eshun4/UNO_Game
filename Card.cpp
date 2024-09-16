#include "Card.h"
#include <string>

// Default constructor
Card::Card() : color(CardColorEnum::BLUE), number(-1), type(CardType::Number) {}

// Constructor with parameters
Card::Card(CardColorEnum color, int number, CardType type)
    : color(color), number(number), type(type) {}

// Destructor
Card::~Card() {}

// Convert card details to string
std::string Card::toString() const {
    std::string colorStr;
    std::string typeStr;

    // Convert color to string
    switch (color) {
        case CardColorEnum::BLUE: colorStr = "Blue"; break;
        case CardColorEnum::GREEN: colorStr = "Green"; break;
        case CardColorEnum::RED: colorStr = "Red"; break;
        case CardColorEnum::YELLOW: colorStr = "Yellow"; break;
        case CardColorEnum::WILD: colorStr = "Wild"; break;
    }

    // Convert type to string
    switch (type) {
        case CardType::Number: typeStr = std::to_string(number); break;
        case CardType::DrawTwo: typeStr = "Draw Two"; break;
        case CardType::Reverse: typeStr = "Reverse"; break;
        case CardType::Skip: typeStr = "Skip"; break;
        case CardType::Wild: typeStr = ""; break; // No need to append "Wild" again
        case CardType::WildDrawFour: typeStr = "Wild Draw Four"; break;
        case CardType::WildShuffleHand: typeStr = "Wild Shuffle Hand"; break;
        case CardType::WildCustomizable: typeStr = "Wild Customizable"; break;
    default: typeStr = "Unknown"; break; // Handle any unexpected types
    }

    // For non-number cards, avoid showing -1
    if (type == CardType::Number && number < 0) {
        return colorStr + " " + typeStr; // Just show color and type
    }

    return colorStr + (typeStr.empty() ? "" : " " + typeStr);
}
