#ifndef _POKEMON_H_
#define _POKEMON_H_

using namespace std;

#include "type.h"
#include <vector>

class Pokemon
{
  protected:
    int o_vida;
    Type o_type;
    
  public:
    Pokemon();
    Pokemon(Type type, int vida);
};

#endif
