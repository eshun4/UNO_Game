#include "CardInitializer.h"

// Constructor to initialize the base class and a single card
CardInitializer::CardInitializer() {}

// Constructor with Constants* parameter
CardInitializer::CardInitializer(Constants* constant) : constant(constant), cards(nullptr), numberOfCards(0) {}

// Define the method to return the vector of initialized cards
void CardInitializer::displayCards() const
{
    if (cards != nullptr) {
        for (int i = 0; i < numberOfCards; ++i) {
            std::cout << cards[i].toString() << std::endl;
        }
        std::cout << numberOfCards << std::endl;
    }
    else {
        std::cout << "No cards to display." << std::endl;
    }
}

void CardInitializer::createCards(Constants* constant) {
    if (constant == nullptr) {
        std::cerr << "Constants pointer is null" << std::endl;
        return;
    }

    // Calculate the total number of cards
    numberOfCards = constant -> getTotalCards(); // Standard Uno deck size plus additional cards
    cards = new Card[numberOfCards];

    int index = 0;

    // Initialize number cards (0-9)
    for (int color = 0; color < 4; ++color) {
        cards[index++] = Card(static_cast<CardColorEnum>(color), 0, CardType::Number); // One 0 card per color
        for (int i = 1; i < 10; ++i) {
            cards[index++] = Card(static_cast<CardColorEnum>(color), i, CardType::Number); // Two of each 1-9 card per color
            cards[index++] = Card(static_cast<CardColorEnum>(color), i, CardType::Number);
        }
    }

    // Initialize Draw Two, Reverse, and Skip cards
    for (int color = 0; color < 4; ++color) {
        for (int i = 0; i < 2; ++i) {
            cards[index++] = Card(static_cast<CardColorEnum>(color), -1, CardType::DrawTwo);
            cards[index++] = Card(static_cast<CardColorEnum>(color), -1, CardType::Reverse);
            cards[index++] = Card(static_cast<CardColorEnum>(color), -1, CardType::Skip);
        }
    }

    // Initialize Wild cards
    for (int i = 0; i < 4; ++i) {
        cards[index++] = Card(CardColorEnum::WILD, -1, CardType::Wild);
        cards[index++] = Card(CardColorEnum::WILD, -1, CardType::WildDrawFour);
    }

    // Initialize Wild Shuffle Hands card
    cards[index++] = Card(CardColorEnum::WILD, -1, CardType::WildShuffleHand);

    // Initialize Wild Customizable cards
    for (int i = 0; i < 3; ++i) {
        cards[index++] = Card(CardColorEnum::WILD, -1, CardType::WildCustomizable);
    }

    // Check if the index matches the number of cards
    if (index != numberOfCards) {
        std::cerr << "Error: Mismatch in the number of cards created. Expected " << numberOfCards << ", but got " << index << std::endl;
    }
}



// Defined Destructor
CardInitializer::~CardInitializer()
{
    delete[] cards; // Deallocate memory if allocated
}
