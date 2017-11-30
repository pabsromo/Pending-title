
//
//Austin Offill
//CSCE 121-518
//

#include "std_lib_facilities_5.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Point.h"
#include "Window.h"
#include "GUI.h"


using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Rule_window : Graph_lib::Window {
    Rule_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop

private:
	    // the "next" button
	Text rules;
	bool button_pushed;
	Button quit_button;
	Button next_button;

    static void cb_next(Address, Address);
	static void cb_quit(Address, Address);// callback for next_button
    void next();            // action to be done when next_button is pressed
	void quit();

};
