#include "defs.h"
#include "arena.h"
#include "hand.h"
#include "card.h"
#include "deck.h"

using namespace std;

Card::Card(int X, int Y, int W, int H) : Fl_Box(X,Y,W,H) {
  // Nothing to report here!
}

Card::Card(): Fl_Box(200,200,151,220) { 
  card_image = new Fl_JPEG_Image("Unsuited/j_black.jpg"); 
  suit = 's';
  number = 0;
}

Card::Card(int X, int Y, char suit, int number,State s,Deck * d,int index): Fl_Box(X,Y,151,220) {

  w_main = s.w; // pointing to the window.
  state = s;
  this_deck = d;
  this_index = index;
  
  // This stringstream method is from http://www.cplusplus.com/forum/articles/9645/
  stringstream temp_convert;
  temp_convert << number;
  string filename;
  string ext = ".jpg"; // to make it easier to change to png later.
  
  if(suit == 'h') filename = "Hearts/" + temp_convert.str() + ext.c_str();
  if(suit == 'c') filename = "Clubs/" + temp_convert.str() + ext.c_str();
  if(suit == 's') filename = "Spades/" + temp_convert.str() + ext.c_str();
  if(suit == 'd') filename = "Diamonds/" + temp_convert.str() + ext.c_str();
  
  card_image = new Fl_JPEG_Image(filename.c_str());
  back_card_image = new Fl_JPEG_Image("Unsuited/back.jpg");
  
  // By default, the card is not shown. This is to allow for flexibility with decks.
}

void Card::face_up() { this->image(card_image); }
void Card::face_down() { this->image(back_card_image); }

void Card::move_card(int X, int Y) {
  this->position(X,Y);
}

char Card::get_suit() {
  // returns suit
  return suit;
}

int Card::get_no() {
  // retuns number
  return number;
}

void Card::change_hand(Deck * d, int i) {
  this_deck = d;
  this_index = i;
}
  
int Card::handle(int event) {
  
  static int startpos[2] = {0,0};
  static int offset[2] = {-75,-112};
  static int card_no;
  
 
  switch(event) {
  case FL_PUSH:
    // Recording start position, will mean that the card will be dragged
    // by the point it was clicked.
    startpos[0] = x();
    startpos[1] = y();
    
    // This is to make the card on the top layer (so the user can see it)
    w_main->add(this);
    
    return 1;
  case FL_DRAG:
    // TODO offset will allow the card to be dragged by the point you pick it at.
    position(Fl::event_x() + offset[0], Fl::event_y() + offset[1]);
    w_main -> redraw();
    return 1;
  case FL_RELEASE: 
    // TODO this vv
    // find() where the card is in hand_vector
    // Once found, hand it over to the only pile the player can ever put it in: the arena
    // TODO fix it for multiple hands

    Hand * temp_hand = (Hand *)this_deck;
    fprintf(stderr, "I'm about to...");
    Card * temp_card = this_deck->give_card();
    fprintf(stderr, "I'm about to... ");
    state.a->take_card(temp_card);
    fprintf(stderr, "I'm about to...\n");
    temp_hand->draw_hand();
    return 1; } //end of switch
}
