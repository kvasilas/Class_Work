
#include <iostream>
#include <fstream>
using namespace std;

class Life{
private:
	int L[12][12];
  double gen, numP;
public: //null constructor
	Life(int i[12][12], double g, double n){
		L[12][12] = i[12][12];
    gen = g;
    numP = n;
	}

  int checkNeighbors(int i, int j) {
    int aliveNeighbors = L[i][j-1] + L[i][j+1] +L[i-1][j] +L[i+1][j] + L[i-1][j-1] + L[i-1][j+1] + L[i+1][j-1]+L[i+1][j+1];
    return aliveNeighbors;
  }

};


int main(){

  int temp[12][12];

  int b[12][12]; /*= {
    {"*",".","*","*",".",".","*",".",".","."},
    {".","*",".",".",".","*",".",".",".","."}
    {".",".",".","*",".",".",".",".",".","."}
    {".",".",".",".",".",".",".",".",".","."}
    {".",".",".",".",".",".",".",".",".","."}
    {".",".",".",".",".",".",".",".",".","."}
    {".",".",".",".",".",".",".",".",".","."}
    {".",".",".",".",".",".",".",".",".","."}
    {".",".",".",".",".",".",".",".",".","."}
    {".",".",".",".",".",".",".",".",".","."}
    };
*/
  for(int i = 1; i < 11; i++){
    for(int j = 1; j <11; j++){

      int sum =3; // checkNeighbors[i,j];

      if((b[i][j] == '*') && sum < 2){temp[i][j] = '.';}
      else if((b[i][j] == '*') && (sum == 2 || sum == 3)){temp[i][j] = '*';}
      else if((b[i][j] == '*') && sum >3){
        temp[i][j] = '.';
      }
      else if((b[i][j] == '.') && sum == 3){temp[i][j] = '*';}
    }
  }
  return 0;
}
