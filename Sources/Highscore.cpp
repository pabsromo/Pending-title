#include "Highscore.h"
#include "std_lib_facilities.h"


Highscore::Highscore(String i, int s)
	:initials{ i }, Score{ s }
{ }

Highscore::Highscore()
	: initials("AAA"),
	Score(1)
{ }

bool operator< (const Highscore score1, const Highscore score2) {
	bool isLess;
	if (score1.Score - score2.Score < 0)
		isLess = true;
	else
		isLess = false;
	return isLess;
}
ostream& operator<<(ostream& os, const Highscore& s)
{
	return os << s.initials << " " << s.Score;
}
istream& operator>>(istream& is, Highscore& s)
{
	//String spaceDashspace = " - ";
	is >> s.initials >> " " >> s.Score;
	if (!is) return is;

	s = Highscore(s.initials, s.Score);     // update dd
	return is;
}