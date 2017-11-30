#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Point.h"
#include "Window.h"
#include "sorcerer.cpp"
#include "difficulty.cpp"
#include "begin.h"
#include "begin.cpp"


using namespace Graph_lib;

//------------------------------------------------------------------------------

int main()
try {
  if(H112 != 201708L)error("Error: incorrect std_lib_facilities_5.h version ", H112);

  beginwin win1(Point(100,200),420,420,"Game");
  Difficulty_window dwin(Point(100,100),500,700,"Select a Difficulty");
  Oasis gwin(Point(0,0),500,700,"Main");
  dwin.hide();
  gwin.hide();
  win1.wait_for_button();
  if(win1.go == 1)
  {
    dwin.show();
    dwin.wait_for_button();
    if(dwin.difficultyLevel != 0)
    {
      gwin.diffLev = dwin.difficultyLevel;
      gwin.checklevel();
      gwin.show();
    }
  }

  return gui_main();
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
