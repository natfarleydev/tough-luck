#ifndef arena_h
#define arena_h

#include "defs.h"
#include "deck.h"
#include "card.h"

class Arena: public Deck {
 public:
  Arena(int X, int Y, State s);
  bool is_card_valid(Card* card);
 private:
  Fl_JPEG_Image * empty_arena_image;
};
#else
#endif
