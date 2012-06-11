#include "defs.h"
#include "deck.h"

Deck::Deck(int X, int Y, int W, int H, bool show_flag, string type_of_deck) : Fl_Box(X,Y,W,H) {
  back_card_image = new Fl_JPEG_Image("Unsuited/back.jpg");
  
  char suit[4] = {'h','d','s','c'};
  
  if(type_of_deck=="standard") {
    
    // Create cards in order of number, then in order of suit[]
    for(int i = 2; i < 15; i++){
      for(int j = 0; j < 4; j++) {
	card_vector.push_back(new Card(X,Y,suit[j],i));
      }
    }

    // Put all the cards face up and hide them
    for(int i = 0; i < card_vector.size(); i++) {
      card_vector[i]->face_up();
      card_vector[i]->hide();
    }
  }
  else if(type_of_deck=="none") {
    // Nothing in here; fill this deck with nothing.
  }
  else {
    fl_message("WARNING\nNo cards were created in the deck!\
\nOther features may not work... (possible FLTK bugs?)");
  }
  
  // If we want the deck to have a visible box
  if(show_flag==True) this->image(back_card_image);
  
  // Either way, show the box so we can click on it.
  this->show();
}
