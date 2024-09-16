#include <iostream>
#include "/C++ Projects/UNO_Game/Card.h"
#include "/C++ Projects/UNO_Game/CardInitializer.h"
#include "/C++ Projects/UNO_Game/Constants.h"

int main() {
    Constants constants;
    CardInitializer cardInitializer(&constants);
    cardInitializer.createCards();
    cardInitializer.displayCards();
	return 0;
}