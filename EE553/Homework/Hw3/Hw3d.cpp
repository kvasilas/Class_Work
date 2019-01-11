/*
  * Hw3b - Game of Life
  * Kirk Vasilas
  * Collaborators - Christopher Keenan, Kevin Largacha
  *I pledge my honor that i have abided by the stevens honor code
 */
#include <iostream>
#include <fstream>
using namespace std;

class Life{
  private:
    int L[12][12];
    double generation, numberPeople;

  public:
    Life(int i[12][12], double gen, double n){
      L[12][12] = i[12][12];
      generation = gen;
      numberPeople = n;
    }
    int checkNeighbors(int i, int j){
      return(L[i][j-1] + L[i][j+1] +L[i-1][j] +L[i+1][j] + L[i-1][j-1] + L[i-1][j+1] + L[i+1][j-1]+L[i+1][j+1]);
    }
    void print(){
      for (int i = 0; i <= 10; i++) {
        cout << L;
      }
    }
    void load(){
      fopen(const char * hw3b.dat, const char * p)
    }
};

int main(){

  int store[12][12];

  int b[12][12] =
    {"*",".","*","*",".",".","*",".",".","."};
    {".","*",".",".",".","*",".",".",".","."};
    {".",".",".","*",".",".",".",".",".","."};
    {".",".",".",".",".",".",".",".",".","."};
    {".",".",".",".",".",".",".",".",".","."};
    {".",".",".",".",".",".",".",".",".","."};
    {".",".",".",".",".",".",".",".",".","."};
    {".",".",".",".",".",".",".",".",".","."};
    {".",".",".",".",".",".",".",".",".","."};
    {".",".",".",".",".",".",".",".",".","."};

  for(int i = 1; i < 11; i++){
    for(int j = 1; j <11; j++){
      int sum = checkNeighbors[i,j];
      if((b[i][j] == '*') && sum < 2){
        store[i][j] = '.';
      }
      else if((b[i][j] == '*') && (sum == 2 || sum == 3)){
        store[i][j] = '*';
      }
      else if((b[i][j] == '*') && sum >3){
        store[i][j] = '.';
      }
      else if((b[i][j] == '.') && sum == 3){
        store[i][j] = '*';
      }
    }
  }
  return 0;
}
