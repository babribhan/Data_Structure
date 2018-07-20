#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<unistd.h>
using namespace std;
int o=11,d=11,e=11,v=11,n=11;
int val1 = 4;
int val2 = 4;
int val3 = 4;

vector<int> digits = {0,1,2,3,4,5,6,7,8,9};
void printSolution(){
        cout<<"O : "<<o<<" D : "<<d<<" E : "<<e<<endl;
        cout<<"V : "<<v<<" N : "<<n<<endl;
        cout.fill('0');
        cout<<" ODD  : "<<setw(3)<<val1<<endl;
        cout<<" ODD  : "<<setw(3)<<val2<<endl;
        cout<<"EVEN  : "<<setw(4)<<val3<<endl;
}
bool isFoundSolution(){
        return (val3 == val1 + val2);
}
void assigneValue(char ch,int val){
        switch(ch){
                case 'o' :
                        o =val;
                        break;
                case 'd' :
                        d =val;
                        break;
                case 'e' :
                        e =val;
                        break;
                case 'v' :
                        v =val;
                        break;
                case 'n' :
                        n =val;
                        break;
        }
}
int returnValue(char ch){
        switch(ch){
                case 'o' : return o;
                case 'd' : return d;
                case 'e' : return e;
                case 'v' : return v;
                case 'n' : return n;
        }
}
void calculate(){
 val1 = 100*o+10*d+d;
 val2 = 100*o+10*d+d;
 val3 = 1000*e+100*v+10*e+n;
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
vector<char> list = {'o','d','e','v','n'};//,'d', 'm','o','r','y'};
solve(list);
return 0;
