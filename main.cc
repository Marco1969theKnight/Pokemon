#include <iostream>
#include <vector>
#include "move.h"
#include "pokemon.h"
#include "type.h"
#include "player.h"
#include "item.h"

using namespace std;

int main()
{

    vector<Move> movimientos;
    vector<Move> movis;
    vector<Pokemon> pokes;

    movimientos.push_back(Move(Move::NameMove::THRASH));
    movimientos.push_back(Move(Move::NameMove::THUNDERSHOCK));
    movimientos.push_back(Move(Move::NameMove::THUNDER));

    movis.push_back(Move(Move::NameMove::FIRE_BLAST));
    movis.push_back(Move(Move::NameMove::FLAMETHROWER));
    movis.push_back(Move(Move::NameMove::SKULL_BASH));

    Pokemon pk1(Pokemon::NomPok::PIKACHU);
    Pokemon pk2(Pokemon::NomPok::CHARMANDER);

    pk1.setMoves(movimientos);
    pk2.setMoves(movis);

    pokes.push_back(pk1);
    pokes.push_back(pk2);

    Item pkb1, pkb2, pkb3;
    pkb1.nombre = "Poke ball";
    pkb2.nombre = "Superball";
    pkb3.nombre = "Masterball";

    pkb1.usos = 3;
    pkb2.usos = 2;
    pkb1.usos = 1;

    vector<Item> pokebolas;

    pokebolas.push_back(pkb1);
    pokebolas.push_back(pkb2);
    pokebolas.push_back(pkb3);

    string name = "Yo Mero El Mero Mero";

    Player YoMero(pokes, pokebolas, name);

    cout << "Jugador: " << YoMero.ver_nombre(YoMero) << endl;
    cout << "Pokemons: " << endl;
    for (int i = 0; i < YoMero.num_Pokemon(); i++)
    {
        cout << "\t" << i + 1 << ": " << YoMero.name_poke(i) << endl;
    }
    cout << "Items: " << endl;
    for (int i = 0; i < YoMero.num_Items(); i++)
    {
        cout << "\t" << i + 1 << ": " << YoMero.name_item(i) << endl;
    }

    return 0;
}