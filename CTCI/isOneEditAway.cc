#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
bool isOneEdit(string text1,string text2){
int count = 0 ;
int len1 = text1.size();
int len2 = text2.size();
if ( abs(len1-len2) > 1) // Length differ by more than one characters.
return false;   
int i = 0, j = 0;
while ( i < len1 && j < len2){ // while both strings are not empty.
    if ( text1[i] != text2[j]){ // Not same characters
       if ( count == 1 )
       return false;
       if ( len1 > len2 )
            i++;
       else if ( len2 > len1 )
            j++;
       else {
           i++;j++;
       }
       count++;  // increment edits.
    }
    else {
        i++;
        j++;
        
    }
}
if (i < len1 || j < len2)
count++;

return count ==1;
     
}
int main() {
	string text,pattern;
	getline(cin,text);
	getline(cin,pattern);
    cout<<isOneEdit(text,pattern)<<endl;
	return 0;
}
