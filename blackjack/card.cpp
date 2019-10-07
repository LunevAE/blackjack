#include "card.h"

card::card(rank r, suit s, bool ifu) : r(r), s(s), isFaceUp(ifu)
{}

int card::getValue() const
{
	int value = 0;
	if (isFaceUp) {
		value = r;
		if (value > 10) value = 10;
	}
	return value;
}

void card::flip()
{
	isFaceUp = !isFaceUp;
}
