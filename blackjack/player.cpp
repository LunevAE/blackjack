#include "player.h"

player::player(const std::string& name) : genericPlayer(name)
{}

player::~player()
{}

bool player::isHitting() const
{
	std::cout << name << ", do you want a hit? (y/n): ";
	char response;
	std::cin >> response;
	return (response == 'y' || response == 'Y');
}

void player::win() const
{
	std::cout << name << " wins.\n";
}

void player::lose() const
{
	std::cout << name << " loses.\n";
}

void player::tie() const
{
	std::cout << name << " tie.\n";
}
