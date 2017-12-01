// Example program
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
	srand((int)time(0));
	int i = 0;
	while(i++ < 30) {
		randi = (rand() % 4) + 1;
		cout << randi << " ";
	}
	return 0;
}
