// initials.cpp


#include "Graph.h"
#include "GUI.h"
#include "Point.h"
//#include "difficulty.cpp"
#include "sorcerer.cpp"
#include "std_lib_facilities_5.h"
#include "Window.h"
#include "FL/Fl_JPEG_Image.H"

using namespace Graph_lib;

struct Initials_window: Graph_lib:: Window{
	Initials_window(Point xy, int w, int h, const string& title);
	int diff = 0;
	bool wait_for_button();
	string initials;
	int gogo = 0;
private: // initialize buttons and in box
	Button enter_button;
	Button exit_button;
	Button clear_button;
	In_box initial_box;
	bool button_pushed = false;
	void enter();
	void exit();
	void clear();
};

Initials_window::Initials_window(Point xy, int w, int h, const string& title) // initialize the buttons' locations and callbacks
	:Window{ xy,w,h,title },
	enter_button{Point{ 400,350 },100,50,"Enter", [](Address,Address pw) {reference_to<Initials_window>(pw).enter(); } },
	exit_button{Point{ 150,400 },100,50,"Exit", [](Address,Address pw) {reference_to<Initials_window>(pw).exit(); } },
	clear_button{Point{ 250,400 },100,50,"Clear", [](Address,Address pw) {reference_to<Initials_window>(pw).clear(); } },
	initial_box{Point{ 150,350 },200,50,"Enter your initials"}
	{
	// attach each widget
	attach(enter_button);
	attach(exit_button);
	attach(clear_button);
	attach(initial_box);
	}
	
void Initials_window::exit() {
	// hide closes the program
	hide();
}

void Initials_window::enter() {
	// enter command sends user to next window
	string initials = initial_box.get_string();
	button_pushed = true;
	int gogo = 1;
	hide();
	Oasis win5(Point(0, 0), 500, 700, "Main Game");
	cout << diff;
	win5.diffLev = diff;
	win5.checklevel();
	win5.show();
	//win5.wait_for_button();
	gui_main();
}

void Initials_window::clear() {
	// redraws page to clear any previous inputs
	redraw();
}
bool Initials_window::wait_for_button()
{
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
#endif
    return button_pushed;
}

