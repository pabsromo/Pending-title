#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include "Point.h"
#include "Window.h"
#include <vector>

using namespace Graph_lib;
using namespace std;

//------------------------------------------------------------------------------

struct Oasis : Graph_lib::Window
{
	Oasis(Point xy, int w, int h, const string& title);
	int diffLev = 1;
	void checklevel();
private:
	// Leaderboard
	Text leaderBoard;
	Text leader1;
	Text leader2;
	Text leader3;
	Text leader4;
	Text leader5;
	Text leaderCurrent;*/
	//Leaderboard Functions
	String returnScoresTxt(int diffLevel); String returnInitTxt(int diffLevel);
	vector<int> sortScoreVector(); vector<String> sortInitialVector();

	String AssignLeader1();   String AssignLeader2();
	String AssignLeader3();   String AssignLeader4();
	String AssignLeader5();




	//Colors
	Color grey;
};

//------------------------------------------------------------------------------

Oasis::Oasis(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title), //making the window
	leaderBoard{ Point{ 350,500 }, "LEADERBOARD" }, 
	leader1{ Point{ 350,520 }, AssignLeader1() }
	leader2{ Point{ 350,540 }, AssignLeader2() }
	leader3{ Point{ 350,560 }, AssignLeader3() }
	leader4{ Point{ 350,580 }, AssignLeader4() }
	leader5{ Point{ 350,600 }, AssignLeader5() }
	grey(fl_rgb_color(128, 128, 128)),

{
	//All attachments
	//attach(backgnd);
	attach(clocstr);
	attach(remain);
	attach(rb); rb.set_fill_color(grey); attach(hints);
	attach(b1); attach(b2); attach(b3); attach(b4); attach(b5); attach(b6);
	attach(b7); attach(b8); attach(b9); attach(b10); attach(b11); attach(b12);
	attach(b13); attach(b14); attach(b15); attach(bH);
	//Except r16. That is the invisible "empty" spot
	s1 = true; s2 = true; s3 = true; s4 = true; s5 = true; s6 = true; s7 = true; s8 = true;
	s9 = true; s10 = true; s11 = true; s12 = true; s13 = true; s14 = true; s15 = true;
}

String Oasis::returnScoresTxt(int diffLevel) {
	String ScoresTxt;
	if (diffLevel == 1) { ScoresTxt = "ScoresDiff1.txt"; }
	else if (diffLevel == 2) { ScoresTxt = "ScoresDiff2.txt"; }
	else if (diffLevel == 3) { ScoresTxt = "ScoresDiff3.txt"; }
	else if (diffLevel == 4) { ScoresTxt = "ScoresDiff4.txt"; }

	return ScoresTxt;
}
String Oasis::returnInitTxt(int diffLevel) {
	String initialTxt;
	if (diffLevel == 1) { initialTxt = "InitialsDiff1.txt"; }
	else if (diffLevel == 2) { initialTxt = "InitialsDiff2.txt"; }
	else if (diffLevel == 3) { initialTxt = "InitialsDiff3.txt"; }
	else if (diffLevel == 4) { initialTxt = "InitialsDiff4.txt"; }

	return initialTxt;
}

vector<int> Oasis::sortScoreVector() {
	String ScoresTxt = returnScoresTxt(diffLev);
	ifstream Highscores{ ScoresTxt }; if (!Highscores) error("can't open input file ", ScoresTxt);
	int iterationSwitches; int tempScore; vector<int> Scoresv; int Score;
	while (Highscores >> Score) { Scoresv.push_back(Score); }
	do {
		iterationSwitches = 0;
		for (int i = 0; i < Scoresv.size() - 1; i++) {
			if (Scoresv[i] < Scoresv[i + 1])
			{
				tempScore = Scoresv[i];
				Scoresv[i] = Scoresv[i + 1];
				Scoresv[i + 1] = tempScore;
				iterationSwitches++;
			}
		}
	} while (iterationSwitches != 0);
	return Scoresv;
}
vector<String> Oasis::sortInitialVector() {
	String ScoresTxt = returnScoresTxt(diffLev); String InitialTxt = returnInitTxt(diffLev);
	ifstream Highscores{ ScoresTxt }; if (!Highscores) error("can't open input file ", ScoresTxt);
	ifstream initialScores{ InitialTxt }; if (!initialScores) error("can't open input file ", InitialTxt);

	int iterationSwitches; int tempScore; String tempString; vector<String> Initialsv; String Initial; vector<int> Scoresv;
	while (initialScores >> Initial) { Initialsv.push_back(Initial); }
	do {
		iterationSwitches = 0;
		for (int i = 0; i < Initialsv.size() - 1; i++) {
			if (Scoresv[i] < Scoresv[i + 1])
			{
				tempScore = Scoresv[i];
				Scoresv[i] = Scoresv[i + 1];
				Scoresv[i + 1] = tempScore;
				tempString = Initialsv[i];
				Initialsv[i] = Initialsv[i + 1];
				Initialsv[i + 1] = tempString;
				iterationSwitches++;
			}
		}
	} while (iterationSwitches != 0);
	return Initialsv;
}

String Oasis::AssignLeader1() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[0];
	String Init = Initialsv[0];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}
String Oasis::AssignLeader2() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[1];
	String Init = Initialsv[1];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}
String Oasis::AssignLeader3() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[2];
	String Init = Initialsv[2];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}
String Oasis::AssignLeader4() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[3];
	String Init = Initialsv[3];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}
String Oasis::AssignLeader5() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[4];
	String Init = Initialsv[4];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}
