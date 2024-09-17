#include <iostream>
#include "/C++ Projects/UNO_Game/Card.h"
#include "/C++ Projects/UNO_Game/CardInitializer.h"
#include "/C++ Projects/UNO_Game/Constants.h"
#include "/C++ Projects/UNO_Game/External/SFML/include/SFML/Graphics.hpp"




int main() {
   /* Constants constants;
    CardInitializer cardInitializer(&constants);
    cardInitializer.createCards();
    cardInitializer.displayCards();*/

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

	return 0;
}