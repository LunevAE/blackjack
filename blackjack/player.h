#pragma once
#include "genericPlayer.h"

class player : public genericPlayer
{
public:
	player(const std::string& name = "");
	~player();       
	virtual bool isHitting() const;
	void win() const;
	void lose() const;
	void tie() const;
};
