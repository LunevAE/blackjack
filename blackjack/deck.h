#pragma once
#include "hand.h"
#include "genericPlayer.h"

class deck : public hand
{
public:
	deck();
	~deck();
	void createDeck(); //create deck of 52 cards
	void shuffle();
	void deal(hand& h); 
	void additionalCards(genericPlayer& gp);
};
