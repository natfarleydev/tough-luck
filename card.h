#ifndef card_h
#define card_h

using namespace std;

class Card: public Fl_Box {
 public:
  Card(int X, int Y, int W, int H);
  Card();
  Card(int,int,char,int,State,Deck *,int);
  void face_up();
  void face_down();
  void move_card(int X,int Y);
  char get_suit();
  int get_no();
  void change_hand(Deck *,int);

 private:
  int handle(int event);
  
  char suit;
  int number;
  Fl_JPEG_Image * card_image;
  Fl_JPEG_Image * back_card_image;
  Fl_Double_Window * w_main;
  State state;
  Deck * this_deck;
  int this_index;


};

#else
#endif
