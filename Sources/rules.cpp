

#include "rules.h"
#include "difficulty.cpp"

using namespace Graph_lib;

//------------------------------------------------------------------------------

Rule_window::Rule_window(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	next_button(Point((x_max() / 2) - 50, (y_max() / 2) + 20), 100, 30, "Start", cb_next),
	quit_button(Point(x_max() - 70, 0), 70, 20, "QUIT", cb_quit),
	button_pushed(false),
	rules(Point(0, 50), "The object of the puzzle is to place the tiles in order by making sliding moves that use the empty space."),
	leaders(Point(5, 65), "Leaderboard"),
	s1(Point(5, 80), Assignleader1()),//assigns leaderbord positions
	s2(Point(5, 95), Assignleader2()),
	s3(Point(5, 110), Assignleader3()),
	s4(Point(5, 125), Assignleader4()),
	s5(Point(5, 140), Assignleader5()),
	diff(2)

{
	//attach text and buttons
	attach(rules);
	attach(s1);
	attach(s2);
	attach(s3);
	attach(s4);
	attach(s5);

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
	Difficulty_window win3{ Point{ 100,100 },500,700,"Select a Difficulty" };
	win3.wait_for_button();
}

//------------------------------------------------------------------------------

void Rule_window::quit()
{
	button_pushed = true;
	hide();
}

//------------------------------------------------------------------------------
//selects text files for scores
string Rule_window::returnScoresTxt(int diffLevel) {
	string ScoresTxt;
	if (diffLevel == 1) { ScoresTxt = "ScoresDiff1.txt"; }
	else if (diffLevel == 2) { ScoresTxt = "ScoresDiff2.txt"; }
	else if (diffLevel == 3) { ScoresTxt = "ScoresDiff3.txt"; }
	else if (diffLevel == 4) { ScoresTxt = "ScoresDiff4.txt"; }

	return ScoresTxt;
}
//selects text files for scores
string Rule_window::returnInitTxt(int diffLevel) {
	string initialTxt;
	if (diffLevel == 1) { initialTxt = "InitialsDiff1.txt"; }
	else if (diffLevel == 2) { initialTxt = "InitialsDiff2.txt"; }
	else if (diffLevel == 3) { initialTxt = "InitialsDiff3.txt"; }
	else if (diffLevel == 4) { initialTxt = "InitialsDiff4.txt"; }

	return initialTxt;
}
//stores text fiels
vector<int> Rule_window::sortScoreVector() {
	string ScoresTxt = returnScoresTxt(diff);
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
//sorts vectors from txt
vector<string> Rule_window::sortInitialVector() {
	string ScoresTxt = Rule_window::returnScoresTxt(diff); string InitialTxt = Rule_window::returnInitTxt(diff);
	ifstream Highscores{ ScoresTxt }; if (!Highscores) error("can't open input file ", ScoresTxt);
	ifstream initialScores{ InitialTxt }; if (!initialScores) error("can't open input file ", InitialTxt);

	int iterationSwitches; int tempScore; string tempString; vector<string> Initialsv; string Initial; vector<int> Scoresv;
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
//the rest assighn value for score
string Rule_window::AssignLeader1() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[0];
	string Init = Initialsv[0];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

string Rule_window::AssignLeader2() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[1];
	string Init = Initialsv[1];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

string Rule_window::AssignLeader3() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[2];
	string Init = Initialsv[2];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

string Rule_window::AssignLeader4() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[3];
	string Init = Initialsv[3];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

string Rule_window::AssignLeader5() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[4];
	string Init = Initialsv[4];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

string Rule_window::Assignleader1() {
	return "QJB - 960";
}
string Rule_window::Assignleader2() {
	return "PBG - 720";
}
string Rule_window::Assignleader3() {
	return "TLG - 480";
}
string Rule_window::Assignleader4() {
	return "AJO - 240";
}
string Rule_window::Assignleader5() {
	return "PXR - 140";
}