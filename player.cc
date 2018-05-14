#include "player.h"

#include <iostream>

Player::Player()
{
}

Player::Player(vector<Pokemon> pok, vector<Item> it)
{
	set_Pokemon(pok);
	set_Items(it);
}

void Player::set_Pokemon(vector<Pokemon> pok)
{
	pokemones = pok;
	return;
}

void Player::set_Items(vector<Item> it)
{
	items = it;
	return;
}

void Player::ver_Pokemon()
{
	std::cout << pokemones.size() << endl;
}

void Player::ver_Items()
{
	std::cout << items.size() << endl;
}
