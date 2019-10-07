#pragma once
#include <string>
#include "genericPlayer.h"

class dealer : public genericPlayer
{
public:
	dealer(const std::string& name = "Dealer");
	~dealer();
	virtual bool isHitting() const; //dealer always hits on 16 or less
	void flipFirstCard();
};
