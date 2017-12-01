// DIFFICULTY LEVEL WINDOW

#include "Graph.h"
#include "GUI.h"
#include "Point.h"
#include "std_lib_facilities_5.h"
#include "Window.h"
#include "FL/Fl_JPEG_Image.H"
#include "initials.cpp"

using namespace Graph_lib;

struct Difficulty_window : Graph_lib::Window {
	Difficulty_window(Point xy, int w, int h, const string& title);
	void wait_for_button()
		{
			// Wait for one of the buttons to be pressed before exiting the window
		while (!button_pushed) Fl::wait();
			button_pushed = false;
			hide();
		};

private: // Initializing variables and buttons
	Button diff1_button;
	Button diff2_button;
	Button diff3_button;
	Button diff4_button;
	Button quit_button;
	Text prompt;
	int difficultyLevel;
	bool button_pushed = false;
	void diff1();
	void diff2();
	void diff3();
	void diff4();
	void quit();

};


Difficulty_window::Difficulty_window(Point xy, int w, int h, const string& title) // Initializing buttons locations and callbacks
	:Window{ xy,w,h,title },
	diff1_button{ Point{ 150,100 },200,100,"Novice (10 Moves)", [](Address,Address pw) {reference_to<Difficulty_window>(pw).diff1(); } },
	diff2_button{ Point{ 150,220 },200,100,"Pro (20 Moves)", [](Address,Address pw) {reference_to<Difficulty_window>(pw).diff2(); } },
	diff3_button{ Point{ 150,340 },200,100,"Veteran (40 Moves)", [](Address,Address pw) {reference_to<Difficulty_window>(pw).diff3(); } },
	diff4_button{ Point{ 150,460 },200,100,"Expert (80 Moves)", [](Address,Address pw) {reference_to<Difficulty_window>(pw).diff4(); } },
	quit_button{ Point{ x_max() - 70,0 }, 70, 20, "Quit", [](Address, Address pw) {reference_to<Difficulty_window>(pw).quit(); } },
	prompt{ Point{ 185,50 }, "Select a Difficulty!" }
{
	//attaching the difficulty selection buttons
	attach(diff1_button);
	attach(diff2_button);
	attach(diff3_button);
	attach(diff4_button);
	attach(quit_button);
	attach(prompt);
}

//hides the window to quit
void Difficulty_window::quit() {
	hide();
}

//The difficulty windows give the next window the difficulty level to be then
//used with the sorcerer.cpp class Oasis in order to display the correct game
void Difficulty_window::diff1() {
	difficultyLevel = 1;
	button_pushed = true;
	hide();
	Initials_window win4 (Point(100,100), 500,700, "Enter your initials");
	win4.diff = 1;
	win4.wait_for_button();
}
void Difficulty_window::diff2() {
	difficultyLevel = 2;
	button_pushed = true;
	hide();
	Initials_window win4(Point(100, 100), 500, 700, "Enter your initials");
	win4.diff = 2;
	win4.wait_for_button();
}
void Difficulty_window::diff3() {
	difficultyLevel = 3;
	button_pushed = true;
	hide();
	Initials_window win4(Point(100, 100), 500, 700, "Enter your initials");
	win4.diff = 3;
	win4.wait_for_button();
}
void Difficulty_window::diff4() {
	difficultyLevel = 4;
	button_pushed = true;
	hide();
	Initials_window win4(Point(100, 100), 500, 700, "Enter your initials");
	win4.diff = 4;
	win4.wait_for_button();
}
