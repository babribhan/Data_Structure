#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<unistd.h>
using namespace std;
int s=11,e=11,n=11,d=11,m=1,o=0,r=11,y=11;
int val1 = 4;
int val2 = 4;
int val3 = 4;

vector<int> digits = {2,3,4,5,6,7,8,9};
void printSolution(){
        cout<<"S : "<<s<<" E : "<<e<<" N : "<<n<<" D : "<<d<<endl;
        cout<<"M : "<<m<<" O : "<<o<<" R : "<<r<<" Y : "<<y<<endl;
        cout.fill('0');
        cout<<"SEND  :  "<<setw(4)<<val1<<endl;
        cout<<"MORE  :  "<<setw(4)<<val2<<endl;
        cout<<"MONEY : "<<setw(5)<<val3<<endl;
}
bool isFoundSolution(){
        return (val3 == val1 + val2);
}
void assigneValue(char ch,int val){
        switch(ch){
                case 's' :
                        s =val;
                        break;
                case 'e' :
                        e =val;
                        break;
                case 'n' :
                        n =val;
                        break;
                case 'd' :
                        d =val;
                        break;
                case 'm' :
                        m =val;
                        break;
                case 'o' :
                        o =val;
                        break;
                case 'r' :
                        r =val;
                        break;
                case 'y' :
                        y =val;
                        break;
        }
}
int returnValue(char ch){
        switch(ch){
                case 's' : return s;
                case 'e' : return e;
                case 'n' : return n;
                case 'd' : return d;
                case 'm' : return m;
                case 'o' : return o;
                case 'r' : return r;
                case 'y' : return y;
        }
}
void calculate(){
 val1 = 1000*s+100*e+10*n+d;
 val2 = 1000*m+100*o+10*r+e;
 val3 = 10000*m+1000*o+100*n+10*e+y;
}
bool solveCrypArithmetic(vector<char> &list){
        // Base case.
        if (!list.size() && isFoundSolution()){
                printSolution();
                return true;
        }
        for ( auto letter : list ) {
                for ( auto dig : digits ) {
                        if ( dig != 1 ) {
                                cout<<"using Value "<<dig<<" for letter : "<<letter<<endl;
                                int backup = returnValue(letter);
                                assigneValue(letter,dig);
                                calculate();
                                digits.erase(find(digits.begin(),digits.end(),dig));
                                list.erase(find(list.begin(),list.end(),letter));
                                printSolution();
                                if (solveCrypArithmetic(list))
                                        return true;
                                list.push_back(letter); // BACKTRACK
                                digits.push_back(dig); // BACKTRACK
                                printSolution();
                                assigneValue(letter,backup);
                        }
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
vector<char> list = {'s','e','n','d', 'r','y'};
solve(list);
return 0;
}
