#include "game.h"
#include <ctime>


game::game(const std::vector<std::string>& names)
{      
	for (auto name : names) {
		players.push_back(player(name));
	}

	srand(time(NULL));
	d.createDeck();
	d.shuffle();
}

game::~game()
{}

void game::play()
{
	//deal first 2 cards to everyone
	std::vector<player>::iterator player;
	for (int i = 0; i < 2; i++) {
		for (player = players.begin(); player != players.end(); player++) {
			d.deal(*player);
		}
		d.deal(dealer);
	}

	dealer.flipFirstCard(); //hide dealer's first card

	//display everyone's hand
	for (player = players.begin(); player != players.end(); player++) {
		std::cout << *player << std::endl;
	}
	std::cout << dealer << std::endl;

	//deal additional cards to players
	for (player = players.begin(); player != players.end(); player++) {
		d.additionalCards(*player);
	}

	dealer.flipFirstCard(); //show house's first card
	std::cout << std::endl << dealer;
	d.additionalCards(dealer); //deal additional cards to dealer

	if (dealer.isBusted()) {
		//everyone who still playing wins
		for (player = players.begin(); player != players.end(); player++) {
			if (!(player->isBusted())) player->win();
		}
	}
	else {
		//compare each player still playing to dealer
		for (player = players.begin(); player != players.end(); player++) {
			if (!(player->isBusted())) {
				if (player->getTotal() > dealer.getTotal()) player->win();
				else if (player->getTotal() < dealer.getTotal())player->lose();
				else {
					player->tie();
				}
			}
		}

	}

	//remove everyone's cards
	for (player = players.begin(); player != players.end(); player++) player->clear();
	dealer.clear();
}
