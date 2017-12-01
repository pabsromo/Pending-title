// endscreen.cpp
// NEEDS diff = difficulty level, totalMoves named total_moves, correct_tiles and user initials named userInitials
#include "Graph.h"
#include "GUI.h"
#include "Point.h"

#include "std_lib_facilities_5.h"
#include "Window.h"
#include "FL/Fl_JPEG_Image.H"

using namespace Graph_lib;

struct Endscreen_window: Graph_lib:: Window{  // window opens if no remaining moves

	//DONT KEEP THIS RIGHT HERE JUST FOR TESTING PURPOSE
	int total_moves = 40; int correct_tiles = 4; String userInitials = "MLS"; int diff = 1;
	//DELETE THIS DELETE THIS





	Endscreen_window(Point xy, int w, int h, const string& title);
	bool wait_for_button();
	int gogogo = 0;
	int finalScore = calculateScore(total_moves,correct_tiles);
	string score_one = AssignLeader1();
	string score_two = AssignLeader2();
	string score_three = AssignLeader3();
	string score_four = AssignLeader4();
	string score_five = AssignLeader5();
	string score_six = AssignLeader6();
	string Current_score = userInitials + " - " + to_string(finalScore);
	
private: // initialize buttons and in box
	
	Button replay_button;
	Button exit_button;
	Text first;
	Text second;
	Text third;
	Text fourth;
	Text fifth;
	Text current;
	bool button_pushed = false;
	void replay();
	void exit();


	int calculateScore(int totalMoves, int totalTiles);
	String returnScoresTxt(int diffLevel);
	String returnInitTxt(int diffLevel);
	vector<int> sortScoreVector();
	vector<String> sortInitialVector();
	void writetoFiles(int diff);
	String AssignLeader1();   String AssignLeader2();
	String AssignLeader3();   String AssignLeader4();
	String AssignLeader5();   String AssignLeader6();
	
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
	current{Point{ 100,425 }, score_six}
	
	{
	writetoFiles(diff);
	// attach each widget
	attach(replay_button);
	attach(exit_button);
	attach(first);
	attach(second);
	attach(third);
	attach(fourth);
	attach(fifth);
	attach(current);
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

String Endscreen_window::returnScoresTxt(int diffLevel) {
	String ScoresTxt;
	if (diffLevel == 1) { ScoresTxt = "ScoresDiff1.txt"; }
	else if (diffLevel == 2) { ScoresTxt = "ScoresDiff2.txt"; }
	else if (diffLevel == 3) { ScoresTxt = "ScoresDiff3.txt"; }
	else if (diffLevel == 4) { ScoresTxt = "ScoresDiff4.txt"; }

	return ScoresTxt;
}
String Endscreen_window::returnInitTxt(int diffLevel) {
	String initialTxt;
	if (diffLevel == 1) { initialTxt = "InitialsDiff1.txt"; }
	else if (diffLevel == 2) { initialTxt = "InitialsDiff2.txt"; }
	else if (diffLevel == 3) { initialTxt = "InitialsDiff3.txt"; }
	else if (diffLevel == 4) { initialTxt = "InitialsDiff4.txt"; }

	return initialTxt;
}

void Endscreen_window::writetoFiles(int diff) {
	String initialTxt = returnInitTxt(diff);
	String ScoresTxt = returnScoresTxt(diff);
	
	ofstream writeHighscore{ ScoresTxt };
	if (!writeHighscore) error("can't write to file", ScoresTxt);
	writeHighscore << finalScore;

	ofstream writeInitials{ initialTxt };
	if (!writeInitials) error("can't write to file", initialTxt);
	writeInitials << userInitials;
}
vector<int> Endscreen_window::sortScoreVector() {
	String ScoresTxt = returnScoresTxt(diff);
	ifstream Highscores{ ScoresTxt }; if (!Highscores) error("can't open input file ", ScoresTxt);
	int iterationSwitches; int tempScore; vector<int> Scoresv; int Score;
	while (Highscores >> Score) { Scoresv.push_back(Score); } Scoresv.push_back(finalScore);
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
vector<String> Endscreen_window::sortInitialVector() {
	String ScoresTxt = returnScoresTxt(diff); String InitialTxt = returnInitTxt(diff);
	ifstream Highscores{ ScoresTxt }; if (!Highscores) error("can't open input file ", ScoresTxt);
	ifstream initialScores{ InitialTxt }; if (!initialScores) error("can't open input file ", InitialTxt);

	int iterationSwitches; int tempScore; String tempString; vector<String> Initialsv; String Initial; vector<int> Scoresv; int Score;
	while (Highscores >> Score) { Scoresv.push_back(Score); } Scoresv.push_back(finalScore);
	while (initialScores >> Initial) { Initialsv.push_back(Initial); } Initialsv.push_back(userInitials);
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

int Endscreen_window::calculateScore(int totalMoves, int totalTiles) {
	int totalScore = totalMoves * totalTiles;
	return totalScore;
}

String Endscreen_window::AssignLeader1() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[0];
	String Init = Initialsv[0];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}
String Endscreen_window::AssignLeader2() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[1];
	String Init = Initialsv[1];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}
String Endscreen_window::AssignLeader3() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[2];
	String Init = Initialsv[2];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}
String Endscreen_window::AssignLeader4() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[3];
	String Init = Initialsv[3];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}
String Endscreen_window::AssignLeader5() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[4];
	String Init = Initialsv[4];
	String leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

String Endscreen_window::AssignLeader6() {
	vector<String> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	if (score_one == Current_score || score_two == Current_score || score_three == Current_score || score_four == Current_score || score_five == Current_score) {
		int Score = Scoresv[5];
		String Init = Initialsv[5];
		String leaderInitScore = Init + " - " + to_string(Score);
		return leaderInitScore;
	}
	else {
		return Current_score;
	}
	
	
}
// If scores 1,2,3,4,5 are not equal to current score,
// score6 = userScore