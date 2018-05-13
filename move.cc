#include "move.h"

Move::Move()
{
    m_type = Type::Element::NORMAL;
    m_power = 0;
    m_acc = 0;
}

Move::Move(Type type, int power, float acc)
{
    set( type,  power, acc);
}

void Move::set(Type type, int power, float acc){
    m_type = type;
    m_power = power;
    m_acc = acc;
}

Move::Move(int type, int power, float acc)
{
    m_type = type;
    m_power = power;
    m_acc = acc;
}