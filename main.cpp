#include "defs.h"
#include "card.h"
#include "deck.h"
#include "pile.h"

using namespace std;

// Naughty naughty... global variables, the only way to get FTLK to behave...
Hand * hand;
//Card * joker_black, joker_red;
Card * joker_black = new Card();
Fl_Double_Window * w_main;



class Hand: public Deck{
public:
  Hand(int X, int Y, int H, int W): Deck(X,Y,W,H,False,"none") {}
  
  void take_card(Card * card) {
    // This function gives the hand it's card, but does not show it.
    card_vector.push_back(card);
  }
  void draw_hand() {
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
};


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

  // Declare variables (for those that are not already global.)
  Fl_Box * main_area;
  Fl_Button * surrender;
  Fl_Menu_Bar * b_menu;
  Fl_JPEG_Image * background_image;
  int window_dim[2]; // 0 is x, 1 is y
  int menu_height;
  cout << "Setting up main window\n";
  window_dim[0] = 800;
  window_dim[1] = 600;
  menu_height = 25;
  background_image = new Fl_JPEG_Image("pikachu_small.jpg");    
  w_main = new Fl_Double_Window(window_dim[0],window_dim[1],"Tough Luck");
  
  main_area = new Fl_Box(0,0,window_dim[0],window_dim[1]);
  main_area->image(background_image);
  
  Pile * pile;
  pile = new Pile(0,0+menu_height);


  hand = new Hand(0,300,151,220);

  hand->take_card(pile->give_card());
  hand->take_card(pile->give_card());
  hand->take_card(pile->give_card());
  hand->take_card(pile->give_card());
  hand->take_card(pile->give_card());
  hand->take_card(pile->give_card());
  hand->take_card(pile->give_card());
  //  hand->take_card(pile->give_joker_black());
  hand->draw_hand();

  // Menu bar
  // Maybe make a menu class, to define all these functions in it.
  b_menu = new Fl_Menu_Bar(0,0,window_dim[0],menu_height);
  b_menu->add("&File/&New Game",0,null);
  b_menu->add("&File/S&tats",0,null);
  b_menu->add("&File/&Options",0,null);
  b_menu->add("&File/&Quit Game",0,menu_quit,w_main,0);
  b_menu->add("&Help/&Rules",0,null);
  b_menu->add("&Help/&Guide",0,null);
  b_menu->add("&Help/&About",0,about_dialog);
  
  w_main->show();
  
  return Fl::run();
}
