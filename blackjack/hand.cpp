#include "hand.h"



hand::hand()
{
	cards.reserve(7);
}

hand::~hand()
{
	clear();
}

void hand::add(card* c)
{
	cards.push_back(c);
}

void hand::clear()
{
	for (auto iter : cards) {
		delete iter;
	}
	cards.clear();
}

int hand::getTotal() const
{
	if (cards.empty()) return 0;

	if (cards[0]->getValue() == 0) return 0;

	//add up card values, ace equals 1
	int total = 0;
	for (auto iter : cards) {
		total += iter->getValue();
	}

	//determine if hand contains ace
	bool containsAce = false;
	for (auto iter : cards) {
		if (iter->getValue() == card::ACE) containsAce = true;
	}

	//if hand contains ace and total is less than 11, ace equals 11
	if (containsAce && total <= 11) {
		//add only 10 because we've already added 1
		total += 10;
	}

	return total;
}
