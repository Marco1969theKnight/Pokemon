#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "pokemon.h"
#include "item.h"

class Player
{
	protected:
		vector <Pokemon> pokemones;
		vector <Item> items;


	public:
		Player();
		Player(vector<Pokemon>,vector<Item>);
		void set_Pokemon(vector<Pokemon>);
		void set_Items(vector<Item>);
		void ver_Pokemon();
		void ver_Items();
};

#endif
