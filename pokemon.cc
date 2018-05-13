#include "pokemon.h"

Pokemon::Pokemon()
{
}

Pokemon::Pokemon(Type type, int vida)
{
    o_type = type;
    o_vida = vida;
}

Pokemon::Pokemon(Type type, int vida, vector<Move> moves) : Pokemon(type, vida)
{
    o_moves = moves;
}

bool Pokemon::set_moves(vector<Type> type_moves, int power, double acc)
{
    vector<Move> moves;
    Move temp;
    int n = type_moves.size();

    if (n == 0)
        return false;

    for (int i = 0; i < n; i++)
    {
        temp.set(type_moves[i], power, acc);
        moves.push_back(temp);
    }

    o_moves = moves;

    return true;
}