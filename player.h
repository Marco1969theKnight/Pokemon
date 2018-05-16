#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "pokemon.h"
#include "item.h"
#include <string>

using namespace std;

class Player
{
protected:
	vector<Pokemon> pokemones;
	vector<Item> items;
	string name;

public:
	Player();
	Player(vector<Pokemon>, vector<Item>, string name);
	void set_Pokemon(vector<Pokemon>);
	void set_Items(vector<Item>);
	void set_name(string name);
	int num_Pokemon();
	int num_Items();

	string name_poke(int n);
	string name_item(int n);
	string ver_nombre(Player p);
};

#endif
