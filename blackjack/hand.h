#pragma once
#include <vector>
#include "card.h"

class hand
{
public:
	hand();
	~hand();
	void add(card* c); //adds card to the hand
	void clear(); //clears hand of all cards
	int getTotal() const;
protected:
	std::vector<card*> cards;
};
