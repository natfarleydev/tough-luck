#include "defs.h"
#include "deck.h"
#include "card.h"
#include "arena.h"

Arena::Arena(int X, int Y, State s): Deck(X,Y,151,220,True,"none",s) {
  empty_arena_image = new Fl_JPEG_Image("Unsuited/emtpy_arena.jpg");
  this->image(empty_arena_image);
  state = s;
}

bool Arena::is_card_valid(Card* card) {
  vector<Card*>::iterator it;

  if(card_vector.empty()) return True;
  else if( card->get_no() >= card_vector.back()->get_no() ) return True;

  // If the function gets to this point, it doesn't match.
  return False;
}
