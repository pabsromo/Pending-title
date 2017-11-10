//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//
// use images and have it change images
#include "Simple_window.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	next_button(Point((x_max()/2)-50, (y_max()/2)-15), 100, 30, "Start", cb_next),
	quit_button(Point(x_max() - 70, 0), 70, 20, "QUIT", cb_quit),
	button_pushed(false),
	r1(Point(0, 0), Point(x_max() / 3, y_max() / 3)),
	r2(Point(x_max() / 3, 0), Point(2*x_max() / 3, y_max() / 3)),
	r3(Point(2*x_max() / 3, 0), Point(x_max(), y_max() / 3)),
	r4(Point(0, y_max() / 3), Point(x_max() / 3, 2*y_max() / 3)),
	r5(Point(x_max()/3, y_max() / 3), Point(2*x_max() / 3, 2*y_max() / 3)),
	r6(Point(2*x_max() / 3, y_max() / 3), Point(x_max(), 2*y_max() / 3)),
	r7(Point(0, 2*y_max() / 3), Point(x_max() / 3, y_max())),
	r8(Point(x_max() / 3, 2*y_max() / 3), Point(2*x_max() / 3, y_max())),
	rquit(Point(x_max() - 70, 0), Point(x_max(), 20)),
	start(Point((x_max() / 2) - 50, (y_max()/2)-15), Point((x_max() / 2) + 50, (y_max() / 2) + 15)),
	tquit(Point(x_max()-60,15),"QUIT"),
	tstart(Point((x_max()/2)-20,(y_max()/2)+5),"START")
{
	attach(r1);
	r1.set_fill_color(Color::cyan);
	attach(r2);
	r2.set_fill_color(Color::red);
	attach(r3);
	r3.set_fill_color(Color::yellow);
	attach(r4);
	r4.set_fill_color(Color::green);
	attach(r5);
	r5.set_fill_color(Color::blue);
	attach(r6);
	r6.set_fill_color(Color::magenta);
	attach(r7);
	r7.set_fill_color(Color::white);
	attach(r8);
	r8.set_fill_color(Color::black);
	attach(rquit);
	rquit.set_fill_color(Color::dark_cyan);
	attach(start);
	start.set_fill_color(Color::dark_cyan);
	attach(tquit);
	attach(tstart);

	attach(next_button);
	attach(quit_button);
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
// modified event loop:
// handle all events (as per default), quit when button_pushed becomes true
// this allows graphics without control inversion
// put do code in here
{
    show();
    button_pushed = false;
	
#if 1
    // Simpler handler
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    // To handle the case where the user presses the X button in the window frame
    // to kill the application, change the condition to 0 to enable this branch.
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void Simple_window::cb_next(Address, Address pw)
// call Simple_window::next() for the window located at pw
{  
    reference_to<Simple_window>(pw).next();    
}

//------------------------------------------------------------------------------

void Simple_window::cb_quit(Address, Address pw)
// call Simple_window::next() for the window located at pw
{
	reference_to<Simple_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
    button_pushed = true;
    hide();
	//open next window here
}

//------------------------------------------------------------------------------

void Simple_window::quit()
{
	button_pushed = true;
	hide();
}

//------------------------------------------------------------------------------