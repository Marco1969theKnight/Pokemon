#ifndef _POKEMON_H_
#define _POKEMON_H_

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
    Pokemon(int type, int vida);
    void setType(Type type);
    void setLife(int vida);
};

#endif
