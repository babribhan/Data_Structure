#include<iostream>
#include<unistd.h>
#include<map>
#include<utility>
using namespace std;
struct coord {
    int x, y;
    bool const operator==(const coord &o) const {
        return x == o.x && y == o.y;
    }
    bool const operator<(const coord &o) const{
        return x < o.x || (x == o.x && y < o.y);
    }
};
coord myCell={-1,-1};
map<coord,bool> history;
static const int N=9;
int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
void printGrid(){
  for ( int row = 0 ; row < N ; row++){
  //cout<<"+---+---+---+---+---+---+---+---+---+"<<endl;
  cout<<"|---|---|---|---|---|---|---|---|---|"<<endl;
    cout<<"|";
    for ( int col = 0 ; col < N ; col++){
      cout<<"   |";
    }
    cout<<endl;
  }
  cout<<"|___|___|___|___|___|___|___|___|___|"<<endl;
  //cout<<"|---|---|---|---|---|---|---|---|---|"<<endl;
  //cout<<"+---+---+---+---+---+---+---+---+---+"<<endl;
}  
void printSolution(){
  for ( int row = 0 ; row < N ; row++){
  //cout<<"+---+---+---+---+---+---+---+---+---+"<<endl;
  cout<<"|---|---|---|---|---|---|---|---|---|"<<endl;
    cout<<"|";
    for ( int col = 0 ; col < N ; col++){
      myCell.x = row;
      myCell.y = col;
      if (history.find(myCell)->second)
        // \033[0;33;42m   "\033[0m
      cout<<"\x1B[30;102m "<<grid[row][col]<<" |"<<"\x1B[0m";
      else  
      cout<<"\x1B[31;104m "<<grid[row][col]<<" |"<<"\x1B[0m";
    }
    cout<<endl;
  }
  cout<<"|---|---|---|---|---|---|---|---|---|"<<endl;
  //cout<<"+---+---+---+---+---+---+---+---+---+"<<endl;
}  
bool findUnassignedCell(int &r , int &c){
  for ( r = 0 ; r < N ; r++){
    for ( c = 0 ; c < N ; c++){
      if (!grid[r][c] )
      {
        return true;
      } 
    }
  }
  return false; 
}
bool isUsedInCol(int c , int num){
  for (int r = 0 ; r < N ; r++){
    if (grid[r][c] == num )
    {
      return true;
    } 
  }
  return false; 
}
bool isUsedInRow(int r , int num){
    for ( int c = 0 ; c < N ; c++){
      if (grid[r][c] == num )
      {
        return true;
      } 
    }
  return false; 
}
bool isUsedInBox(int r_start ,int c_start ,int num){
  for ( int r = 0 ; r < 3 ; r++){
    for ( int c = 0 ; c < 3 ; c++){
      if (grid[r_start+r][c+c_start] == num )
        return true;
    }
  }
  return false; 
}
bool isSafe(int row , int col,int num) {
   return !isUsedInRow(row,num) && !isUsedInCol(col,num) && !isUsedInBox(row-row%3,col-col%3,num);
}

bool solve(){
  int r,c;
  if ( !findUnassignedCell(r,c)){
    return true;
  }
  for ( int digit = 1; digit < 10 ; digit++){
    myCell.x  = r;
    myCell.y  = c;
    history.insert(make_pair(myCell,true));
    if (isSafe(r,c,digit)){
      // choose
      grid[r][c] = digit;
//      printSolution();
      // Explore 
     // sleep(2);  // For Animation Effect
      if ( solve())
        return true; 
      // Un-choose
      grid[r][c] = 0;
    }
  }
  return false;
}
int main(){
  printSolution();
  if (solve()){
  printSolution();
  cout<<"Solved !!!!!"<<endl;
  }
  else 
   cout<<"No solution found."<<endl;
//  printGrid();
  return 0;
}

