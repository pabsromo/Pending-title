
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"    // for Simple_window only (doesn't really belong in Window.h)
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop

private:
	Rectangle r1;
	Rectangle r2;
	Rectangle r3;
	Rectangle r4;
	Rectangle r5;
	Rectangle r6;
	Rectangle r7;
	Rectangle r8;
	Rectangle rquit;
	Rectangle start;
	Button quit_button;
    Button next_button;     // the "next" button
	Text tquit;
	Text tstart;
	bool button_pushed;

    static void cb_next(Address, Address);
	static void cb_quit(Address, Address);// callback for next_button
    void next();            // action to be done when next_button is pressed
	void quit();

};

//------------------------------------------------------------------------------

#endif // SIMPLE_WINDOW_GUARD