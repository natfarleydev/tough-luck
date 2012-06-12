#include "defs.h"
#include "card.h"
#include "deck.h"
#include "hand.h"

Hand::Hand(int X, int Y, int H, int W, Fl_Double_Window * w): Deck(X,Y,W,H,False,"none",w) {
  // Empty...
}

void Hand::draw_hand() {
  // TODO show the cards in order.
  for(int i = 0; i<card_vector.size(); i++) {
    // distance from left edge of hand per card
    //      card_vector.sort(); // TODO make this function sort the cards in order.
    int dflpc = floor( (double)w()/(double)card_vector.size() );
    card_vector[i]->position(x()+i*dflpc,y());
    card_vector[i]->show();
    w_main->add(card_vector[i]);
  }
  w_main->redraw();
}

