//Austin Offill
//CSCE 121-518
//

#include "highscore.h"


using namespace Graph_lib;

//------------------------------------------------------------------------------

highscore_window::highscore_window(Point xy, int w, int h, const string& title) :
	Window(xy, w, h, title),
	next_button(Point((x_max() / 2) - 50, (y_max() / 2) + 20), 100, 30, "Start", cb_next),
	button_pushed(false),
	s5(AssignLeader5()),
	//leader1(Point(350,520), AssignLeader1()),
	//leader2 (Point(350,540), AssignLeader2()),
	//leader3 (Point(350,560), AssignLeader3()),
	//leader4 (Point(350,580), AssignLeader4()),
	//leader5(Point( 350,600 ), s5),
	leaderBoard(Point(350, 500), "Leaderboard")

{
	
	attach(leaderBoard);
	attach(leader1);
	attach(leader2);
	attach(leader3);
	attach(leader4);
	attach(leader5);
	
	
	attach(next_button);

}

//------------------------------------------------------------------------------

bool highscore_window::wait_for_button()
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

void highscore_window::cb_next(Address, Address pw)
{  
    reference_to<highscore_window>(pw).next();
}

//------------------------------------------------------------------------------

void highscore_window::next()
{
    button_pushed = true;
    hide();
}

//------------------------------------------------------------------------------
string highscore_window::returnScoresTxt(int diffLevel) {
	string ScoresTxt;
	if (diffLevel == 1) { ScoresTxt = "ScoresDiff1.txt"; }
	else if (diffLevel == 2) { ScoresTxt = "ScoresDiff2.txt"; }
	else if (diffLevel == 3) { ScoresTxt = "ScoresDiff3.txt"; }
	else if (diffLevel == 4) { ScoresTxt = "ScoresDiff4.txt"; }

	return ScoresTxt;
}

string highscore_window::returnInitTxt(int diffLevel) {
	string initialTxt;
	if (diffLevel == 1) { initialTxt = "InitialsDiff1.txt"; }
	else if (diffLevel == 2) { initialTxt = "InitialsDiff2.txt"; }
	else if (diffLevel == 3) { initialTxt = "InitialsDiff3.txt"; }
	else if (diffLevel == 4) { initialTxt = "InitialsDiff4.txt"; }

	return initialTxt;
}

vector<int> highscore_window::sortScoreVector() {
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

vector<string> highscore_window::sortInitialVector() {
	string ScoresTxt = highscore_window::returnScoresTxt(diff); string InitialTxt = highscore_window::returnInitTxt(diff);
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

string highscore_window::AssignLeader1() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[0];
	string Init = Initialsv[0];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

string highscore_window::AssignLeader2() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[1];
	string Init = Initialsv[1];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

string highscore_window::AssignLeader3() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[2];
	string Init = Initialsv[2];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

string highscore_window::AssignLeader4() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[3];
	string Init = Initialsv[3];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}

string highscore_window::AssignLeader5() {
	vector<string> Initialsv = sortInitialVector();
	vector<int> Scoresv = sortScoreVector();
	int Score = Scoresv[4];
	string Init = Initialsv[4];
	string leaderInitScore = Init + " - " + to_string(Score);

	return leaderInitScore;
}