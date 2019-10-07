#include "dealer.h"

dealer::dealer(const std::string& name) : genericPlayer(name)
{}

dealer::~dealer()
{}

bool dealer::isHitting() const
{
	return (getTotal() <= 16);
}

void dealer::flipFirstCard()
{
	if (!(cards.empty())) cards[0]->flip();
}

