#ifndef hand_h
#define hand_h

#include "defs.h"
#include "card.h"
#include "deck.h"

class Hand: public Deck{
 public:
  Hand(int X, int Y, int H, int W, State s);
  void draw_hand();
  int size();
  Card * get_card(int i);
};

#else
#endif
