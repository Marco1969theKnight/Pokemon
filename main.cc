#include<iostream>
#include<vector>
#include "move.h"
#include "pokemon.h"
#include "type.h"


using namespace std;

int main(){
    vector<Move> movimientos;

    for(int i = 0; i < 6; i++){
        movimientos.push_back(Move(Type(i), 100, 2.3));
    } 

    Pokemon lokochongo(Type::Element::THUNDER, 100, movimientos);

    return 0;
}