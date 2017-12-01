// endscreen.cpp

#include "Graph.h"
#include "GUI.h"
#include "Point.h"

#include "std_lib_facilities_5.h"
#include "Window.h"
#include "FL/Fl_JPEG_Image.H"

using namespace Graph_lib;

struct Endscreen_window: Graph_lib:: Window{  // window opens if no remaining moves
	Endscreen_window(Point xy, int w, int h, const string& title);
	bool wait_for_button();
	int gogogo = 0;
	string score_one, score_two, score_three, score_four, score_five, score_six;
	int total_moves;
	int correct_tiles;
	int diff;
private: // initialize buttons and in box

	Button replay_button;
	Button exit_button;
	Text first;
	Text second;
	Text third;
	Text fourth;
	Text fifth;
	Text current;
	Out_box box_1, box_2, box_3, box_4, box_5;
	bool button_pushed = false;

	void replay();
	void exit();

};

Endscreen_window::Endscreen_window(Point xy, int w, int h, const string& title) // initialize the buttons' locations and callbacks
	:Window{ xy,w,h,title },
	replay_button{Point{ 200,525 },100,50,"Enter", [](Address,Address pw) {reference_to<Endscreen_window>(pw).replay(); } },
	exit_button{Point{ 200,600 },100,50,"Exit", [](Address,Address pw) {reference_to<Endscreen_window>(pw).exit(); } },
	first  {Point{ 100,50  }, score_one },
	second {Point{ 100,125 }, score_two },
	third  {Point{ 100,200 }, score_three},
	fourth {Point{ 100,275 }, score_four},
	fifth  {Point{ 100,350 }, score_five},
	current{Point{ 100,425 }, score_six},
	box_1(Point(100,50),100,20,""),
	box_2(Point(100,125),100,20,""),
	box_3(Point(100,200),100,20,""),
	box_4(Point(100,275),100,20,""),
	box_5(Point(100,350),100,20,"")

	{
	// attach each widget
	attach(replay_button);
	attach(exit_button);
	attach(first);
	attach(second);
	attach(third);
	attach(fourth);
	attach(fifth);
	attach(box_1);
	attach(box_2);
	attach(box_3);
	attach(box_4);
	attach(box_5);

	ostringstream oss1,oss2,oss3,oss4,oss5;
  oss1 << "QJB - 960";
	oss2 << "PBG - 720";
	oss3 << "TLG - 480";
	oss4 << "AJO - 24";
	oss5 << "PXR - 140";
  box_1.put(oss1.str());
  box_2.put(oss2.str());
	box_3.put(oss3.str());
	box_4.put(oss4.str());
	box_5.put(oss5.str());
  redraw();
	}

void Endscreen_window::replay() {
	// This function needs to restart the program from the first window
	button_pushed = true;
	gogogo = 1;
	hide();
}

void Endscreen_window::exit() {
	// hide closes the program
	button_pushed = true;
	hide();
}
bool Endscreen_window::wait_for_button(){
#if 1
    // Simpler handler
	while (!button_pushed) Fl::wait(1);
		Fl::redraw();
#else
#endif
    return button_pushed;
}
