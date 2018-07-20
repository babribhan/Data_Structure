#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<unistd.h>
using namespace std;
int x=11,y=11,z=11;
int val1 = 4;
int val2 = 4;
int val3 = 4;

vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
void printSolution(){
        cout<<"X : "<<x<<" Y : "<<y<<" Z : "<<z<<endl;
        cout.fill('0');
        cout<<"XY  : "<<setw(2)<<val1<<endl;
        cout<<"XY  : "<<setw(2)<<val2<<endl;
        cout<<"ZX  : "<<setw(2)<<val3<<endl;
}
bool isFoundSolution(){
        return (val3 == val1 + val2);
}
void assigneValue(char ch,int val){
        switch(ch){
                case 'x' :
                        x =val;
                        break;
                case 'y' :
                        y =val;
                        break;
                case 'z' :
                        z =val;
                        break;
        }
}
int returnValue(char ch){
        switch(ch){
                case 'x' : return x;
                case 'y' : return y;
                case 'z' : return z;
        }
}
void calculate(){
 val1 = 10*x+y;
 val2 = 10*x+y;
 val3 = 10*z+x;
}
bool solveCrypArithmetic(vector<char> &list){
        // Base case.
        if (!list.size() && isFoundSolution()){
                printSolution();
                return true;
        }
        for ( auto letter : list ) {
                for ( auto dig : digits ) {
                        cout<<"using Value "<<dig<<" for letter : "<<letter<<endl;
                        int backup = returnValue(letter);
                        assigneValue(letter,dig);
                        calculate();
                        digits.erase(find(digits.begin(),digits.end(),dig));
                        list.erase(find(list.begin(),list.end(),letter));
                        printSolution();
//                        sleep(8);
                        if (solveCrypArithmetic(list))
                                return true;
                        list.push_back(letter); // BACKTRACK
                        digits.push_back(dig); // BACKTRACK
                        printSolution();
                        assigneValue(letter,backup);
                        }
                }
        return false;
}
void solve(vector<char> &list ){

        if (!solveCrypArithmetic(list)){
                cout<<"No solution found."<<endl;
                return;
        }
}
int main(){
vector<char> list = {'x','y','z'};//,'d', 'm','o','r','y'};
solve(list);
return 0;
}
