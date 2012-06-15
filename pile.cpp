#include "defs.h"
#include "pile.h"
#include "card.h"
#include "deck.h"

Pile::Pile(int X, int Y, State s) : Deck(X,Y,151,220,True,"standard",s) {
  fprintf(stderr, "A Pile was created\n");
}

void Pile::draw_first() {
  card_vector[0]->face_up();
  fl_message("you should see a card now...");
}

void Pile::random_card() {
  fl_message("This function may eventually give a random card and return a card");
}

// Card * Pile::give_joker_black() {
//   // This function is a proof of concept, that get_suit and get_no work
//   char suit_temp = joker_black->get_suit();
//   int number_temp = joker_black->get_no();
//   fprintf(stderr, "I'm about to give you a joker, which has the values %c and %d.\n", suit_temp, number_temp);
//   joker_black->face_up();
//   joker_black->show();
//   return joker_black;
// }

int Pile::handle(int event) {
  switch(event) {
  case FL_PUSH: random_card(); return 1;
    //    case FL_PUSH: fl_message("You have pressed the top of the deck."); return 1;
  case FL_DRAG: return 0;
  case FL_RELEASE: return 0;
  }
}
