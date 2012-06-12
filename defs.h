#ifndef defs_h
#define defs_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>


// FLTK Libraries
#include <Fl/Fl.H>
#include <Fl/Fl_Window.H>
#include <Fl/Fl_Button.H>
#include <Fl/Fl_Radio_Button.H>
#include <FL/Fl_Round_Button.H>
#include <Fl/Fl_Light_Button.H>
#include <Fl/Fl_Menu_Bar.H>
#include <Fl/Fl_Value_Output.H>
#include <Fl/fl_draw.H>
#include <Fl/Fl_Shared_Image.H>
#include <Fl/Fl_JPEG_Image.H>
#include <Fl/Fl_Box.H>
#include <Fl/Fl_Text_Display.H>
#include <Fl/Fl_Text_Buffer.H>
#include <Fl/Fl_Double_Window.H>
#include <Fl/Fl_File_Chooser.H>
#include <Fl/fl_ask.H>
#include <Fl/Fl_Tabs.H>
#include <Fl/Fl_Scroll.H>
#include <Fl/Fl_Tile.H>

using namespace std;

class Hand; // Needed for the special global variables
class Card;
// TODO sort it to get rid of as many globals as possible.

// This is declaring that this will be a global variable.
extern Fl_Double_Window * w_main;
extern Hand * hand;
extern Card * joker_black; //, joker_red;

void null(Fl_Widget* q , void* a);
void about_dialog(Fl_Widget*, void*);
void menu_quit (Fl_Widget* w, void* data);



#else
#endif
