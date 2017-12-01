#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Point.h"
#include "Window.h"
#include "sorcerer.cpp"

using namespace Graph_lib;

//------------------------------------------------------------------------------

int main()
try {
  if(H112 != 201708L)error("Error: incorrect std_lib_facilities_5.h version ", H112);

  Oasis win(Point(0,0),500,700,"Main");

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
