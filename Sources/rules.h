
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
	Text rules;
	Text leaders;
	Text s1;
	Text s2;
	Text s3;
	Text s4;
	Text s5;
	int diff;
	bool button_pushed;
	Button quit_button;
	Button next_button;

    static void cb_next(Address, Address);
	static void cb_quit(Address, Address);// callback for next_button
    void next();            // action to be done when next_button is pressed
	void quit();
	//get score from file
	string returnScoresTxt(int diffLevel); string returnInitTxt(int diffLevel);
	vector<int> sortScoreVector(); vector<string> sortInitialVector();
	//assign score 
	string AssignLeader1();   string AssignLeader2();
	string AssignLeader3();   string AssignLeader4();
	string AssignLeader5();
	string Assignleader1();   string Assignleader2();
	string Assignleader3();   string Assignleader4();
	string Assignleader5();
};
