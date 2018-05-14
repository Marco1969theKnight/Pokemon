#include<iostream>
#include<vector>
#include "move.h"
#include "pokemon.h"
#include "type.h"
#include "player.h"
#include "item.h"


using namespace std;

int main(){
    
    vector<Move> movimientos;

    for(int i = 0; i < 6; i++){
        movimientos.push_back(Move(Type(i), 100, 2.3));
    } 

    Pokemon lokochongo(Type::Element::THUNDER, 100, movimientos);

    vector<Pokemon> pok;
    pok.push_back(lokochongo);
    vector<Item> it;
    
    Item item1;
    item1.nombre="pokebola";
    item1.usos=4;
    it.push_back(item1);


    Player jugador1(pok,it);

    jugador1.ver_Pokemon();
    jugador1.ver_Items();

    return 0;
}