#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "move.h"
#include "pokemon.h"
#include "type.h"
#include "player.h"
#include "item.h"

using namespace std;

int atack(Pokemon* a, Pokemon* b, Move atac)
{
    int estado=0;
    Type typea,typeb;
    typea = a -> tipo();
    typeb = b -> tipo();

    int ta = typea.tipo;
    int tb = typeb.tipo;

    float por=1;
    
    if(typea.weakness==tb)
    {
        por=0.5;
        estado=1;
    }   
    else
    {
        if(typea.stronger==tb)
        {
            por=1.5;
            estado=2;
        }
    } 

    int acurracy = atac.m_acc*100;
    int at = atac.m_power;


    srand (time(NULL));
    int r = rand() % 100 + 1;

    if(r>acurracy)
    {
        return 4;
    }

    at*=por;

    int vida = b -> vida();

    vida-=at;

    b -> setLife(vida);

    return estado;
}

int main()
{

    Player j1,j2;
    int turno=0,jugada;
    vector<Pokemon>pok;

    for(int z=0;z<2;z++)
    {
        
        cout<<"Elige los Pokemones del jugador "<<z+1<<endl;
        for(int i=0;i<5;i++)
        {
            cout<<"Qué Pokemon quieres?"<<endl;
            cout<<"1. CHARMANDER\n2. CHARIZARD\n3. ARTICUNO\n4. PIDGEY\n5. PIDGEOT\n6. BULBASAUR\n7. VENUSAUR\n8. ZAPDOS\n9. PIKACHU\n10. SQUIRTLE\n11. BLASTOISE\n12. PORYGON\n13. EEVEE"<<endl;
            int num;
            cin>>num;

            switch(num)
            {
                case 1:
                    pok.push_back(Pokemon(Pokemon::NomPok::CHARMANDER));
                break;
                case 2: pok.push_back(Pokemon(Pokemon::NomPok::CHARIZARD));
                break;
                case 3: pok.push_back(Pokemon(Pokemon::NomPok::ARTICUNO));
                break;
                case 4: pok.push_back(Pokemon(Pokemon::NomPok::PIDGEY));
                break; 
                case 5: pok.push_back(Pokemon(Pokemon::NomPok::PIDGEOT));
                break;
                case 6: pok.push_back(Pokemon(Pokemon::NomPok::BULBASAUR));
                break;
                case 7: pok.push_back(Pokemon(Pokemon::NomPok::VENUSAUR));
                break;
                case 8: pok.push_back(Pokemon(Pokemon::NomPok::ZAPDOS));
                break;
                case 9: pok.push_back(Pokemon(Pokemon::NomPok::PIKACHU));
                break;
                case 10: pok.push_back(Pokemon(Pokemon::NomPok::SQUIRTLE));
                break;
                case 11: pok.push_back(Pokemon(Pokemon::NomPok::BLASTOISE));
                break;
                case 12: pok.push_back(Pokemon(Pokemon::NomPok::PORYGON));
                break;
                case 13: pok.push_back(Pokemon(Pokemon::NomPok::EEVEE));
                break;
            }
        }
        if(!z)
        {
            j1.set_Pokemon(pok);
            pok.clear();
        }
        else
        {
            j2.set_Pokemon(pok);
            pok.clear();
        }
    }

    j1.set_Alive(5);
    j2.set_Alive(5);

    Pokemon act1,act2;
    int posact1,posact2;
    bool ver1[] = {0,0,0,0,0},ver2[] = {0,0,0,0,0};

    pok = j1.get_Pokemones();
    for(int i=0;i<2;i++)
    {
        cout<<"Jugador "<<i+1<<" escoje un pokemon\n";
        int opc;
        for(int j=0;j<5;j++)
        {
            cout<<j+1<<". "<<pok[j].name()<<endl;    
        }
        cin>>opc;
        if(!i)
        {
            act1 = pok[opc-1];
            posact1 = opc-1;
            pok = j2.get_Pokemones();
        }
        else
        {
            act2 = pok[opc-1];
            posact2 = opc-1;
        }
    }
    pok.clear();

    while(j1.get_Alive()&&j2.get_Alive())
    {
        cout<<"¿Que quieres hacer jugador "<<turno+1<<"?\n1. Atacar\n2. Usar Objeto\n3. Cambiar Pokemon\n";
        cin>>jugada;
        vector<Move> mov;
        if(!turno)
        {
            if(jugada==1)
            {
                mov = act1.get_Moves();
                int opca;
                cout<<"Cual ataque quieres hacer?\n";
                for(int i=0;i<4;i++)
                {
                    cout<<i+1<<". "<<mov[i].name()<<endl;
                }
                cin>>opca;
                Move ataque = mov[opca - 1];
                int a = atack(&act1,&act2,ataque);
                switch(a)
                {
                    case 1: cout<<"El ataque no hizo mucho daño"<<endl;
                        break;
                    case 2: cout<<"El ataque fue super efectivo"<<endl;
                        break;
                    case 4: cout<<"El ataque no hizo ningun daño"<<endl;
                        break;            
                }
                
                pok = j2.get_Pokemones();
                pok[posact2] = act2;
                j2.set_Pokemon(pok);

                if(act2.vida() <= 0)
                {
                    ver2[posact2] = 1;
                    cout<<"Murio "<<act2.name()<<endl;
                    int v = j2.get_Alive();
                    v--;
                    j2.set_Alive(v);

                    if(v>0)
                    {
                        cout<<"Jugador 2 Escoge un nuevo Pokemon\n"<<endl;
                        int opc;
                        for(int i=0;i<5;i++)
                        {
                            if(!ver2[i])
                            {
                                cout<<i+1<<pok[i].name()<<endl;
                            }
                        }
                        cin>>opc;
                        act2 = pok[opc - 1];
                        posact2 = opc - 1;

                    }
                    else
                    {
                        cout<<"Gano el jugador 1"<<endl;
                        break;
                    }

                }

            }
            if(jugada==2)
            {

            }
            if(jugada==3)
            {
                pok = j1.get_Pokemones();
                cout<<"Jugador 1 Escoge un nuevo Pokemon\n"<<endl;
                int opc;
                for(int i=0;i<5;i++)
                {
                    if(!ver1[i])
                    {
                        cout<<i+1<<pok[i].name()<<endl;
                    }
                }
                cin>>opc;
                act1 = pok[opc - 1];
                posact1 = opc - 1;

            }
            turno++;
        }
        else
        {
            if(jugada==1)
            {
                mov = act2.get_Moves();
                int opca;
                cout<<"Cual ataque quieres hacer?\n";
                for(int i=0;i<4;i++)
                {
                    cout<<i+1<<". "<<mov[i].name()<<endl;
                }
                cin>>opca;
                Move ataque = mov[opca - 1];
                int a = atack(&act2,&act1,ataque);
                switch(a)
                {
                    case 1: cout<<"El ataque no hizo mucho daño"<<endl;
                        break;
                    case 2: cout<<"El ataque fue super efectivo"<<endl;
                        break;
                    case 4: cout<<"El ataque no hizo ningun daño"<<endl;
                        break;            
                }
                
                pok = j1.get_Pokemones();
                pok[posact1] = act1;
                j1.set_Pokemon(pok);

                if(act1.vida() <= 0)
                {
                    ver1[posact1] = 1;
                    cout<<"Murio "<<act1.name()<<endl;
                    int v = j1.get_Alive();
                    v--;
                    j1.set_Alive(v);

                    if(v>0)
                    {
                        cout<<"Jugador 1 Escoge un nuevo Pokemon\n"<<endl;
                        int opc;
                        for(int i=0;i<5;i++)
                        {
                            if(!ver1[i])
                            {
                                cout<<i+1<<pok[i].name()<<endl;
                            }
                        }
                        cin>>opc;
                        act1 = pok[opc - 1];
                        posact1 = opc - 1;

                    }
                    else
                    {
                        cout<<"Gano el jugador 2"<<endl;
                        break;
                    }

                }

            }
            if(jugada==2)
            {

            }
            if(jugada==3)
            {
                pok = j2.get_Pokemones();
                cout<<"Jugador 2 Escoge un nuevo Pokemon\n"<<endl;
                int opc;
                for(int i=0;i<5;i++)
                {
                    if(!ver2[i])
                    {
                        cout<<i+1<<pok[i].name()<<endl;
                    }
                }
                cin>>opc;
                act2 = pok[opc - 1];
                posact2 = opc - 1;

            }
            turno=0;
        }
    }
    
    return 0;
}