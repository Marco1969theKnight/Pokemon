#ifndef _POKEMON_H_
#define _POKEMON_H_

#include "type.h"
#include "move.h"
#include <vector>
#include <string>

using namespace std; 

class Pokemon
{
  protected:
    int o_vida;
    Type o_type;
    vector<Move> o_moves;
    
  public:
    Pokemon();
    Pokemon(Type type, int vida);
    Pokemon(Type type, int vida, vector<Move> moves);

    bool set_moves(vector<Type> type_moves, int power, double acc);


};

#endif
