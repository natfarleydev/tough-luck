#include "defs.h"
#include "card.h"
#include "deck.h"
#include "hand.h"

Hand::Hand(int X, int Y, int H, int W, State s): Deck(X,Y,W,H,False,"none",s) {
  // Empty...
}

void Hand::draw_hand() {
  //  TODO show the cards in order.
  // I think this would work... if get_no worked properly...
  // for(int j = 0; j < 2*card_vector.size(); j++) {
  //   for(int k = card_vector.size() - 2; k > 0; k--) {
  //     if(card_vector[k]->get_no()>card_vector[k+1]->get_no()) {
  // 	Card* card_temp;
  // 	card_temp = card_vector[k];
  // 	card_vector[k] = card_vector[k+1];
  // 	card_vector[k+1] = card_temp;
  // 	fprintf(stderr, "whatever...");
  //     }
  //   }
  // }
  for(int i = 0; i<card_vector.size(); i++) {
    // distance from left edge of hand per card
    //      card_vector.sort(); // TODO make this function sort the cards in order.
    int dflpc = floor( (double)w()/(double)card_vector.size() );
    card_vector[i]->position(x()+i*dflpc,y());
    card_vector[i]->show();

    // add a sorting algorithm here...

    card_vector[i]->change_hand((Deck *)this,i);
    w_main->add(card_vector[i]);
  }
  w_main->redraw();
}

int Hand::size() {
  return card_vector.size();
}

Card* Hand::get_card(int i) {
  return card_vector[i];
}

