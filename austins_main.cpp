//Austin Offill
//CSCE 121-518
//
//Due: 
//

#include "std_lib_facilities_5.h"
#include "splash_screen.cpp"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"


int main()
try {
  if(H112 != 201708L)error("Error: incorrect std_lib_facilities_5.h version ",
		  	   H112);
  Simple_window win1(Point(100,200),400,450,"Start Screen");
  win1.wait_for_button();

  return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}