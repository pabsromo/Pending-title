//Austin Offill
//CSCE 121-518
//

#include "rules.h"
//#include "difficulty.cpp"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Rule_window::Rule_window(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	next_button(Point((x_max()/2)-50, (y_max()/2)+20), 100, 30, "Start", cb_next),
	quit_button(Point(x_max() - 70, 0), 70, 20, "QUIT", cb_quit),
	button_pushed(false),
	rules(Point(0, 50), "The object of the puzzle is to place the tiles in order by making sliding moves that use the empty space.")
	
{
	
	attach(rules);

	attach(next_button);
	attach(quit_button);
}

//------------------------------------------------------------------------------

bool Rule_window::wait_for_button()
{
    show();
    button_pushed = false;
	
#if 1
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void Rule_window::cb_next(Address, Address pw)
{  
    reference_to<Rule_window>(pw).next();    
}

//------------------------------------------------------------------------------

void Rule_window::cb_quit(Address, Address pw)
{
	reference_to<Rule_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Rule_window::next()
{
    button_pushed = true;
    hide();
	//Difficulty_window win3{ Point{ 100,100 },500,700,"Select a Difficulty" };
	//win3.wait_for_button();
}

//------------------------------------------------------------------------------

void Rule_window::quit()
{
	button_pushed = true;
	hide();
}

//------------------------------------------------------------------------------