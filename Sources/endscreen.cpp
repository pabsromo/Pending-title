// endscreen.cpp
// Clark Snider
// 825004646
// This is intended to display a screen after the tiles out of place reaches zero

#include "fltk.h"
#include "Graph.h"
#include "GUI.h"
#include "Point.h"
#include "Simple_window.h"
#include "std_lib_facilities_5.h"
#include "Window.h"
#include "FL/Fl_JPEG_Image.H"

using namespace Graph_lib;

struct Endscreen_window: Graph_lib:: Window{
	Endscreen_window(Point xy, int w, int h, const string& title);
	void wait_for_button()
	{
	while (!button_pushed) Fl::wait(); // wait for enter button to be pressed
		button_pushed = false;         // before exiting the window...
		hide();
	};
	
private: // initialize buttons and in box
	Button replay_button;
	Button exit_button;
		
	void replay();
	void exit();
	
	
};

int main()
try {
		Endscreen_window win{ Point{ 0,0 },500,700,"Endscreen" };
		win.wait_for_button();

		return gui_main();

	//  return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}



Initials_window::Initials_window(Point xy, int w, int h, const string& title) // initialize the buttons' locations and callbacks
	:Window{ xy,w,h,title },
	replay_button{Point{ 200,525 },100,50,"Enter", [](Address,Address pw) {reference_to<Initials_window>(pw).enter(); } },
	exit_button{Point{ 200,600 },100,50,"Exit", [](Address,Address pw) {reference_to<Initials_window>(pw).exit(); } },
	{
	// attach each widget
	attach(replay_button);
	attach(exit_button);
	}
	
void Endscreen_window::replay() {
	// This function needs to restart the program from the first window
	hide();
}

void Endscreen_window::exit() {
	// hide closes the program
	hide();
}




