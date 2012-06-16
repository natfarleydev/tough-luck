#include "defs.h"
#include "card.h"
#include "deck.h"
#include "pile.h"
#include "hand.h"
#include "game.h"

using namespace std;

// Naughty naughty... global variables, the only way to get FTLK to behave...
// Hand * hand;
// Fl_Double_Window * w_main;

void null(Fl_Widget* q , void* a) {
    // Void function to give to the menubar
    fl_message("This part isn't done yet!");
  }

void about_dialog(Fl_Widget*, void*) {
  fl_message("Tough Luck Designed by\n\
Ben Bradnick, Dan Cross and Nathanael Farley\n\
(c) us, GPL'd appropriately.");
}

void menu_quit (Fl_Widget* w, void* data) {
  if(fl_choice("Are you sure you want quit?", "&No", "&Yes", "&Cancel")==1) ((Fl_Window*)data)->hide();
}

int main() {

  // Random Seed
  srand(time(NULL));

  Game game=Game(800,600);

  game.begin();
  
  return Fl::run();
}
