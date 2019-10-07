#pragma once
#include <iostream>
#include <string>
#include "hand.h"

class genericPlayer : public hand
{
	friend std::ostream& operator<<(std::ostream& os, const genericPlayer& gp);
public:
	genericPlayer(const std::string& name = "");
	~genericPlayer();
	virtual bool isHitting() const = 0; //indicates whether or not generic player wants to keep hitting
	bool isBusted() const; //is generic player has a total greater than 21
	void bust() const;
protected:
	std::string name;
};
