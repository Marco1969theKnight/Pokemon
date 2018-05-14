#ifndef _MOVE_H_
#define _MOVE_H_

#include "type.h"

class Move
{
protected:
  Type m_type;
  int m_power;
  float m_acc;

public:
  Move();
  Move(Type type, int power, float acc);
  Move(int type, int power, float acc);

  void set(Type type, int power, float acc);
};

#endif