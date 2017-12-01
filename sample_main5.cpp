//Austin Offill
//CSCE 121-518
//Due: October 31, 2017
//

#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"

int main()
try {
  if(H112 != 201708L)error("Error: incorrect std_lib_facilities_5.h version ",
		  	   H112);
  Simple_window win1(Point(100,200),420,420,"Game");
  //
  /*Line gh1(Point(50, 0), Point(50,400));
  Line gv2(Point(0, 200), Point(800, 200));*/
  //
  //Rectangle rec0(Point(0, 0), Point(400, 400));
  //
  //Circle r1(Point(75, 25), 20);
  //
  //Closed_polyline tri1;
  //tri1.add(Point(30, 135));
  //tri1.add(Point(50, 60));
  //tri1.add(Point(69, 135));
  //
  //Image im1(Point(0, 200), "space.jpg");
  //
  //Rectangle rec0(Point(0, 0), Point(600, 300));
  //rec0.set_fill_color(Color::black);

  //Circle b(Point(100, 100), 80);
  //b.set_style(Line_style(Line_style::solid, 5));
  //b.set_color(Color::blue);
  
  
  //
  
  //
  //win1.attach(gh1);
  //
  //Color moss(fl_rgb_color(95, 105, 7));
  //Color cherry(fl_rgb_color(255, 183, 197));
  //
  //win1.attach(rec0);
  //rec0.set_fill_color(moss);
  //rec0.set_color(moss);


 
  
  
  
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