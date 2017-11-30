#include "std_lib_facilities.h"

class Highscore {
public:

	Highscore(String i, int s);
	Highscore();

	String initials;
	int Score;
};

bool operator< (const Highscore score1, const Highscore score2);

ostream& operator<<(ostream& os, const Highscore& s);
istream& operator>>(istream& is, Highscore& s);