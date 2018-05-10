#include "type.h"

Type::Type() { }

Type::Type( Element name){
    switch (name) {
        case Element::FIRE:
            tipo = 1;
            break;
        case Element::ICE:
            tipo = 2;
            break;
        case Element::WIND:
            tipo = 3;
            break;
        case Element::EARTH:
            tipo = 4;
            break;
        case Element::THUNDER:
            tipo = 5;
            break;
        case Element::WATER:
            tipo = 6;
    }
}