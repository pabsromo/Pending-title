#include "std_lib_facilities.h"
#include "Highscore.h"



int main()
try {
	String ScoresTxt = "Scores.txt";
	ifstream Highscores{ ScoresTxt };           // open file for reading
	if (!Highscores) error("can't open input file ", ScoresTxt);

	vector<Highscore> scores;            // store the readings here
	String initials;
	int Score;
	






while (Highscores >> initials >> Score) // Put readings from file into vector
	scores.push_back(Highscore{ initials,Score });
	
	
// SORT FUNCTION
	//sort(scores.begin(), scores.end());

	//for (vector<Highscores>::reverse_iterator i = scores.rbegin(); scores != scores.rbegin() + 5; ++i) // PRINT top 5 scores
	//	cout << *i << ' ' << endl;

}

catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}

catch (...) {
	cerr << "Some exception\n";
	return 2;
}