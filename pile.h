#ifndef pile_h
#define pile_h

#include "defs.h"
#include "card.h"
#include "deck.h"
#include "game.h"

class Pile: public Deck {
public:
  Pile(int X, int Y, State s);
  void draw_first();
  void random_card();
  //  Card * give_joker_black();
private:
  int handle(int event);
};

#else
#endif
