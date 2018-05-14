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

Pokemon::Pokemon(Type type, int vida, vector<Move> moves) : Pokemon(type, vida)
{
    setMoves(moves);
}

void Pokemon::setType(Type type)
{
    o_type = type;
}

void Pokemon::setLife(int vida)
{
    o_vida = vida;
}

void Pokemon::setMoves(vector<Move> moves)
{
    o_moves = moves;
}

Type Pokemon::tipo() const
{
    return o_type;
}

int Pokemon::vida() const
{
    return o_vida;
}