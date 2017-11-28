// initials.cpp
// Clark Snider
// 825004646
// This code is intended to make a window that appears after the player
// selects their difficulty level. The initials are intended to be saved
// as a indicator for the player's score at the end of the game.

#include "fltk.h"
#include "Graph.h"
#include "GUI.h"
#include "Point.h"
#include "Simple_window.h"
#include "std_lib_facilities_5.h"
#include "Window.h"
#include "FL/Fl_JPEG_Image.H"

using namespace Graph_lib;

struct Initials_window: Graph_lib:: Window{
	Initials_window(Point xy, int w, int h, const string& title);
	void wait_for_button()
	{
	while (!button_pushed) Fl::wait(); // wait for enter button to be pressed
		button_pushed = false;         // before exiting the window...
		hide();
	};
	
private: // initialize buttons and in box
	Button enter_button;
	Button exit_button;
	Button clear_button;
	In_box initial_box;
	
	void enter();
	void exit();
	void clear();
	
};

int main()
try {
		Initials_window win{ Point{ 0,0 },500,700,"Enter your intials" };
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
	enter_button{Point{ 400,350 },100,50,"Enter", [](Address,Address pw) {reference_to<Initials_window>(pw).enter(); } },
	exit_button{Point{ 150,400 },100,50,"Exit", [](Address,Address pw) {reference_to<Initials_window>(pw).exit(); } },
	clear_button{Point{ 250,400 },100,50,"Clear", [](Address,Address pw) {reference_to<Initials_window>(pw).clear(); } },
	Initials_box_box{Point{ 150,350 },200,50,"Enter your initials":}
	{
	// attach each widget
	attach(enter_button);
	attach(exit_button);
	attach(clear_button);
	attach(Initials_box_box);
	}
	
void Initials_window::exit() {
	// hide closes the program
	hide();
}

void Initials_window::enter() {
	// enter command sends user to next window //
	string initials = initial_box.get_string();
	hide();
}

void Initials_window::clear() {
	// redraws page to clear any previous inputs
	redraw();
}



