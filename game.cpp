#include "defs.h"
#include "card.h"
#include "deck.h"
#include "pile.h"
#include "hand.h"
#include "game.h"
#include "arena.h"

State::State(Fl_Double_Window * wx, vector<Hand*>::iterator hvx, Pile * px, Arena * ax) {
  w = wx;
  hv = hvx;
  p = px;
  a = ax;
}

State::State() {
  // Do nothing, just here to stop g++ complaining
  // TODO find out why Game::Game tries to call this function.
}

Game::Game(int w, int h) {
  w_main_w = w;
  w_main_h = h;
  w_main = new Fl_Double_Window(w,h,"Tough Luck");

  background_image = new Fl_JPEG_Image("pikachu_small.jpg");

  main_area = new Fl_Box(0,0,w_main_w,w_main_h);
  //  main_area->image(background_image);

  menu_height = 25;

  // Menu bar
  // Maybe make a menu class, to define all these functions in it.
  b_menu = new Fl_Menu_Bar(0,0,w_main_w,menu_height);
  b_menu->add("&File/&New Game",0,null);
  b_menu->add("&File/S&tats",0,null);
  b_menu->add("&File/&Options",0,null);
  b_menu->add("&File/&Quit Game",0,menu_quit,w_main,0);
  b_menu->add("&Help/&Rules",0,null);
  b_menu->add("&Help/&Guide",0,null);
  b_menu->add("&Help/&About",0,about_dialog);

  // Note that hand_vector's address iterator is given, so that people can refer to the actuall hand_vector rather than a copy.

  vector<Hand*>::iterator it = hand_vector.begin();
  state = State(w_main,it,pile,arena);
  
  w_main->show();
}

void Game::begin() {

  pile = new Pile(0,0+menu_height,state);
  hand_vector.push_back(new Hand(0,300,151,220,state));
  w_main->add(pile);

  arena = new Arena(300,100+menu_height,state);
  w_main->add(arena);
  // state.a = arena;

  // arena->new_state(state);
  // hand_vector[0]->new_state(state);
  // pile->new_state(state);

  // TODO remember to make this for all hands
  for(int i = 0; i<7; i++) {
    hand_vector[0]->take_card(pile->give_card());
  }
  hand_vector[0]->draw_hand();
  
}


Fl_Double_Window * Game::get_w_main() {
  return w_main;
}
