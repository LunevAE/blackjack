#pragma once
#include <vector>
#include "dealer.h"
#include "deck.h"
#include "player.h"

class game
{
public:
	game(const std::vector<std::string>& names);
	void play(); //plays a round of blackjack 
	~game();
private:
	deck d;
	dealer dealer;
	std::vector<player> players;
};
