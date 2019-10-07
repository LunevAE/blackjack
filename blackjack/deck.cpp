#include "deck.h"
#include <random>
#include <iostream>


deck::deck()
{
	cards.reserve(52);
	createDeck();
}

deck::~deck()
{}

void deck::createDeck()
{
	clear();
	for (int s = card::CLUBS; s <= card::SPADES; s++)
	{
		for (int r = card::ACE; r <= card::KING; r++)
		{
			add(new card(static_cast<card::rank>(r),
				static_cast<card::suit>(s)));
		}
	}
}

void deck::shuffle()
{
	random_shuffle(cards.begin(), cards.end());
}

void deck::deal(hand& h)
{
	if (!cards.empty()) {
		h.add(cards.back());
		cards.pop_back();
	}
	else {
		std::cout << "Out of cards. Unable to deal.";
	}
}

void deck::additionalCards(genericPlayer& gp)
{
	std::cout << std::endl;
	while (!(gp.isBusted()) && gp.isHitting()) {
		deal(gp);
		std::cout << gp << std::endl;

		if (gp.isBusted()) gp.bust();
	}
}
