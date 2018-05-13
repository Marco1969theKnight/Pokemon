#include "pokemon.h"

Pokemon::Pokemon()
{
    setType(Type::Element::NORMAL);
    setLife(0);
}

Pokemon::Pokemon(Type type, int vida)
{
    setType(type);
    setLife(vida);
}

Pokemon::Pokemon(int type, int vida)
{
    setType(type);
    setLife(vida);
}

void Pokemon::setType(Type type)
{
    o_type = type;
}

void Pokemon::setLife(int vida)
{
    o_vida = vida;
}