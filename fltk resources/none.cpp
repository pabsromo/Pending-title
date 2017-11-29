// Example program
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  /*
  // Create (row,col)
    vector< vector<int> > vec(16, vector<int>(2));
    vector< vector<int> > vec2(16, vector<int>(2));
    // Write
    vec[2][1] = 5;
    vec[2][2] = 10;
    vec2[13][1] = 5;
    vec2[13][2] = 11;
    // Read
*/
    int k = 0;
    vector< vector<int> > Ovec(16, vector<int>(2));
    vector< vector<int> > vec(16, vector<int>(2));
    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
      {
        Ovec[k][1] = 50+100*i;
        Ovec[k][0] = 50+100*j;
        vec[k][1] = 50+100*i;
        vec[k][0] = 50+100*j;
        k++;
      }
    }

    return 0;
}
