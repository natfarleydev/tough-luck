#ifndef hand_h
#define hand_h

#include "defs.h"
#include "card.h"
#include "deck.h"

class Hand: public Deck{
 public:
  Hand(int X, int Y, int H, int W, Fl_Double_Window * w);
  void draw_hand();
};

#else
#endif
