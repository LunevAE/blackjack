#include "genericPlayer.h"


genericPlayer::genericPlayer(const std::string& name) : name(name)
{}

genericPlayer::~genericPlayer()
{}

bool genericPlayer::isBusted() const
{
	return (getTotal() > 21);
}

void genericPlayer::bust() const
{
	std::cout << name << " busts.\n";
}
