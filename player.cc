#include"player.h"

#include<iostream>

	player::player()
	{
	}

	player::player(vector < Pokemon > pok, vector < Item > it)
	{
		set_Pokemon(pok);
		set_Items(it);
	}
		
	void player::set_Pokemon(vector < Pokemon > pok)
	{
		pokemones=pok;
		return;
	}
		
	void player::set_Items(vector < Item > it)
	{
		items=it;
		return;
	}	

	void player::ver_Pokemon()
	{
		std::cout<<pokemones.size()<<endl;
	}

	void player::ver_Items()
	{
		std::cout<<items.size()<<endl;
	}
