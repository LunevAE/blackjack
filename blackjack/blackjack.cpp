#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include "game.h"

std::ostream& operator<<(std::ostream& os, const card& c)
{
	const std::string ranks[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
							"10", "J", "Q", "K" };
	const std::string suits[] = { "c", "d", "h", "s" };

	if (c.isFaceUp) os << ranks[c.r] << suits[c.s];
	else os << "XX";

	return os;
}
std::ostream& operator<<(std::ostream& os, const genericPlayer& gp)
{
	os << gp.name << ":\t";

	if (!gp.cards.empty()) {
		for (auto card : gp.cards){
			os << *card << "\t";
		}

		if (gp.getTotal() != 0) std::cout << "(" << gp.getTotal() << ")";
	}
	else {
		os << "empty";
	}

	return os;
}

int main()
{
	std::cout << "\t\tWelcome to Blackjack!\n\n";

	int numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7) {
		std::cout << "How many players? (1 - 7): ";
		std::cin >> numPlayers;
	}

	std::vector<std::string> names;
	std::string name;
	for (int i = 0; i < numPlayers; i++) {
		std::cout << "Enter player name: ";
		std::cin >> name;
		names.push_back(name);
	}
	std::cout << std::endl;

	//game loop        
	game g(names);
	char again = 'y';
	while (again != 'n' && again != 'N') {
		g.play();
		std::cout << "\nDo you want to play again? (y/n): ";
		std::cin >> again;
	}

	return 0;
}
