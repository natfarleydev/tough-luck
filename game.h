#ifndef game_h
#define game_h

#include "defs.h"
#include "card.h"
#include "deck.h"
#include "pile.h"
#include "hand.h"

class Game {
 public:
  Game(int w, int h);
  void begin();
  Fl_Double_Window * get_w_main();
 

  Fl_Double_Window * w_main;
  int w_main_w, w_main_h;
  vector<Hand*> hand_vector;
  Pile * pile;
  Fl_Box * main_area;
  Fl_Button * surrender;
  Fl_Menu_Bar * b_menu;
  Fl_JPEG_Image * background_image;
  int menu_height;

};

#else
#endif
