#ifndef deck_h
#define deck_h

#include "defs.h"
#include "card.h"

class Deck: public Fl_Box {
  
 public:
  Deck(int X, int Y, int W, int H, bool show_flag, string type_of_deck, Fl_Double_Window * w);
  Card * give_card(int i);  
  Card * give_card();
  void take_card(Card * card);

 protected:
  vector<Card*> card_vector;
  Fl_JPEG_Image * back_card_image;
  Fl_Double_Window * w_main;

 private:
  string type_of_deck;
};


#else
#endif
