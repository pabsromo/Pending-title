//Austin Offill
//CSCE 121-518
//

#include "rules.h"
#include "splash_screen.h"
#include <chrono>
#include <thread>

using namespace Graph_lib;
using namespace std::this_thread;
using namespace std::chrono;

//------------------------------------------------------------------------------

Simple_window::Simple_window(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	next_button(Point((x_max() / 2) - 50, (y_max() / 2) - 15), 100, 30, "Start", cb_next),
	quit_button(Point(x_max() - 70, 0), 70, 20, "QUIT", cb_quit),
	button_pushed(false),
	i(0),
	t(3),
	pic01(Point(0, 50), "starter-img/pic-01.jpg"),
	pic02(Point(0, 50), "starter-img/pic-02.jpg"),
	pic03(Point(0, 50), "starter-img/pic-03.jpg"),
	pic04(Point(0, 50), "starter-img/pic-04.jpg"),
	pic05(Point(0, 50), "starter-img/pic-05.jpg"),
	pic06(Point(0, 50), "starter-img/pic-06.jpg"),
	pic07(Point(0, 50), "starter-img/pic-07.jpg"),
	pic08(Point(0, 50), "starter-img/pic-08.jpg"),
	pic09(Point(0, 50), "starter-img/pic-09.jpg"),
	pic10(Point(0, 50), "starter-img/pic-10.jpg"),
	pic11(Point(0, 50), "starter-img/pic-11.jpg"),
	pic12(Point(0, 50), "starter-img/pic-12.jpg"),
	r1(Point((x_max() / 2) - 50, (y_max() / 2) - 15), Point((x_max() / 2) + 50, (y_max() / 2) + 15)),
	r2(Point(x_max() - 70, 0), Point(x_max(), 20)),
	rquit(Point(x_max() - 70, 0), Point(x_max(), 20)),
	start(Point((x_max() / 2) - 50, (y_max() / 2) - 15), Point((x_max() / 2) + 50, (y_max() / 2) + 15)),
	tquit(Point(x_max() - 60, 15), "QUIT"),
	tstart(Point((x_max() / 2) - 20, (y_max() / 2) + 5), "START"),
	team_name(Point(0, 15), "Team 40 'Bits Please'"),
	team_mems(Point(0,40),"Pablo Romo, Austin Offill, Mason Stacker, Clark Snider"),
	game_name(Point((x_max() / 2) - 20,15),"Serepico")
{
	attach(team_mems);
	attach(team_name);
	attach(game_name);
	attach(pic01);
	
	attach(tquit);
	attach(tstart);

	attach(r1);
	attach(r2);
	r1.set_fill_color(Color::white);
	r2.set_fill_color(Color::white);
	attach(next_button);
	attach(quit_button);
	
}

//------------------------------------------------------------------------------

bool Simple_window::wait_for_button()
{
    show();
    button_pushed = false;
	
#if 1
	while (!button_pushed) { 
		detach(r1);
		detach(r2);
		detach(tquit);
		detach(tstart);
		if (i == 1) {
			attach(pic02);
			detach(pic01);
		}
		if (i == 2) {
			attach(pic03);
			detach(pic02);
		}
		if (i == 3) {
			attach(pic04);
			detach(pic03);
		}
		if (i == 4) {
			attach(pic05);
			detach(pic04);
		}
		if (i == 5) {
			attach(pic06);
			detach(pic05);
		}
		if (i == 6) {
			attach(pic07);
			detach(pic06);
		}
		if (i == 7) {
			attach(pic08);
			detach(pic07);
		}
		if (i == 8) {
			attach(pic09);
			detach(pic08);
		}
		if (i == 9) {
			attach(pic10);
			detach(pic09);
		}
		if (i == 10) {
			attach(pic11);
			detach(pic10);
		}
		if (i == 11) {
			attach(pic12);
			detach(pic11);
		}
		if (i == 12) {
			attach(pic11);
			detach(pic12);
		}
		if (i == 13) {
			attach(pic10);
			detach(pic11);
		}
		if (i == 14) {
			attach(pic09);
			detach(pic10);
		}
		if (i == 15) {
			attach(pic08);
			detach(pic09);
		}
		if (i == 16) {
			attach(pic07);
			detach(pic08);
		}
		if (i == 17) {
			attach(pic06);
			detach(pic07);
		}
		if (i == 18) {
			attach(pic05);
			detach(pic06);
		}
		if (i == 19) {
			attach(pic04);
			detach(pic05);
		}
		if (i == 20) {
			attach(pic03);
			detach(pic04);
		}
		if (i == 21) {
			attach(pic02);
			detach(pic03);
		}
		if (i == 22) {
			attach(pic01);
			detach(pic02);
			i = 0;
		}

		attach(r1);
		attach(r2);
		attach(tquit);
		attach(tstart);
		++i;
		Fl::redraw();
		Fl::wait(t);
		sleep_for(seconds(1));
		

	}
    Fl::redraw();
#else
    Fl::run();
#endif
    return button_pushed;
}

//------------------------------------------------------------------------------

void Simple_window::cb_next(Address, Address pw)
{  
    reference_to<Simple_window>(pw).next();    
}

//------------------------------------------------------------------------------

void Simple_window::cb_quit(Address, Address pw)
{
	reference_to<Simple_window>(pw).quit();
}

//------------------------------------------------------------------------------

void Simple_window::next()
{
    button_pushed = true;
    hide();
	Rule_window win2(Point(100, 200), 720, 100, "Objective");
	win2.wait_for_button();
}

//------------------------------------------------------------------------------

void Simple_window::quit()
{
	button_pushed = true;
	hide();
}

//------------------------------------------------------------------------------