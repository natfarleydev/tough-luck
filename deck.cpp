#include "defs.h"
#include "deck.h"

Deck::Deck(int X, int Y, int W, int H, bool show_flag, string type_of_deck, Fl_Double_Window * w) : Fl_Box(X,Y,W,H) {
  
  w_main = w;
  back_card_image = new Fl_JPEG_Image("Unsuited/back.jpg");
  
  char suit[4] = {'h','d','s','c'};
  
  if(type_of_deck=="standard") {
    
    // Create cards in order of number, then in order of suit[]
    for(int i = 2; i < 15; i++){
      for(int j = 0; j < 4; j++) {
	card_vector.push_back(new Card(X,Y,suit[j],i,w_main));
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

void Deck::take_card(Card * card) {
  // This function gives the deck it's card, but does not show it.
  card_vector.push_back(card);
}

Card * Deck::give_card(int i) {
  // Another proof of concept function, so we know what we're handing over.
  // Note, this is an overloaded function
  char suit_temp = card_vector[i]->get_suit();
  int number_temp = card_vector[i]->get_no();
  fprintf(stderr,"I'm about to give the card %c and %d.\n", suit_temp, number_temp);

  Card * card_temp = card_vector[i];
  card_vector.erase(card_vector.begin()+i);
  return card_temp;
}


Card * Deck::give_card() {
  int i = rand() % card_vector.size();
  fprintf(stderr,"lololol");
  give_card(i);
}
