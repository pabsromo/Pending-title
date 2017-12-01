
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

struct highscore_window : Graph_lib::Window {
	highscore_window(Point xy, int w, int h, const string& title );

    bool wait_for_button(); // simple event loop
	int diff;
private:
	    // the "next" button
	Graph_lib::Text leaderBoard;
	Graph_lib::Text leader1;
	Graph_lib::Text leader2;
	Graph_lib::Text leader3;
	Graph_lib::Text leader4;
	Graph_lib::Text leader5;
	Graph_lib::Text leaderCurrent;
	string s5;
		//Leaderboard Functions
		string returnScoresTxt(int diffLevel); string returnInitTxt(int diffLevel);
	vector<int> sortScoreVector(); vector<string> sortInitialVector();

	string AssignLeader1();   string AssignLeader2();
	string AssignLeader3();   string AssignLeader4();
	string AssignLeader5();



	Button next_button;
	//Colors
	bool button_pushed;
    static void cb_next(Address, Address);
    void next();            // action to be done when next_button is pressed

};
