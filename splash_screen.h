//Austin Offill
//CSCE 121-518
//

#ifndef SIMPLE_WINDOW_GUARD
#define SIMPLE_WINDOW_GUARD 1

#include "GUI.h"
#include "Graph.h"

using namespace Graph_lib;

//------------------------------------------------------------------------------

struct Simple_window : Graph_lib::Window {
    Simple_window(Point xy, int w, int h, const string& title );

    bool wait_for_button();

private:
	Image pic01;
	Image pic02;
	Image pic03;
	Image pic04;
	Image pic05;
	Image pic06;
	Image pic07;
	Image pic08;
	Image pic09;
	Image pic10;
	Image pic11;
	Image pic12;
	int i;
	double t;
	Rectangle r1;
	Rectangle r2;
	Rectangle rquit;
	Rectangle start;
	Button quit_button;
    Button next_button;
	Text tquit;
	Text tstart;
	Text team_name;
	Text team_mems;
	Text game_name;
	bool button_pushed;

    static void cb_next(Address, Address);
	static void cb_quit(Address, Address);
    void next();
	void quit();

};

//------------------------------------------------------------------------------

#endif 