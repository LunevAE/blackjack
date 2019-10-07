#pragma once
#include <iostream>

class card
{
public:
	enum rank {
		ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
		JACK, QUEEN, KING
	};
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	friend std::ostream& operator<<(std::ostream& os, const card& c);
	card(rank r = ACE, suit s = SPADES, bool ifu = true);
	int getValue() const;
	void flip();
private:
	rank r;
	suit s;
	bool isFaceUp;
};
