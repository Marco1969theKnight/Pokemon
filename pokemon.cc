#include "pokemon.h"

Pokemon::Pokemon()
{
    setType(Type::Element::NORMAL);
    setLife(0);
}

Pokemon::Pokemon(NomPok name)
{
    setPokName(name);
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

void Pokemon::setPokName(NomPok name)
{
    switch (name)
    {
    case NomPok::CHARMANDER:
        o_vida = 309;
        o_type = Type::Element::FIRE;
        o_name = "Charmander";
        break;
    case NomPok::CHARIZARD:
        o_vida = 534;
        o_type = Type::Element::FIRE;
        o_name = "Charizard";
        break;
    case NomPok::ARTICUNO:
        o_vida = 580;
        o_type = Type::Element::ICE;
        o_name = "Articuno";
        break;
    case NomPok::PIDGEY:
        o_vida = 251;
        o_type = Type::Element::WIND;
        o_name = "Pidgey";
        break;
    case NomPok::PIDGEOT:
        o_vida = 469;
        o_type = Type::Element::WIND;
        o_name = "Pidgeot";
        break;
    case NomPok::BULBASAUR:
        o_vida = 318;
        o_type = Type::Element::EARTH;
        o_name = "Bulbasaur";
        break;
    case NomPok::VENUSAUR:
        o_vida = 525;
        o_type = Type::Element::EARTH;
        o_name = "Venusaur";
        break;
    case NomPok::ZAPDOS:
        o_vida = 580;
        o_type = Type::Element::THUNDER;
        o_name = "Zapdos";
        break;
    case NomPok::PIKACHU:
        o_vida = 300;
        o_type = Type::Element::THUNDER;
        o_name = "Pikachu";
        break;
    case NomPok::SQUIRTLE:
        o_vida = 314;
        o_type = Type::Element::WATER;
        o_name = "Squirtle";
        break;
    case NomPok::BLASTOISE:
        o_vida = 530;
        o_type = Type::Element::WATER;
        o_name = "Blastoise";
        break;
    case NomPok::PORYGON:
        o_vida = 395;
        o_type = Type::Element::NORMAL;
        o_name = "Porygon";
        break;
    case NomPok::EEVEE:
        o_vida = 325;
        o_type = Type::Element::NORMAL;
        o_name = "Eevee";
        break;
    }
}

int Pokemon::tipo() const
{
    return o_type.tipo;
}

int Pokemon::vida() const
{
    return o_vida;
}

string Pokemon::name() const
{
    return o_name;
}