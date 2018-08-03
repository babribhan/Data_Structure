#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printList(vector<string> list ) {
        for ( auto e : list )
                cout<<e<<" ";
        cout<<endl;
}
int countSort(vector<string> &list,int idx){
        vector<int> count(256,0);
        vector<string> result(list.size()+1,"");
        // count how many element are there which are = to i
        for ( int i = 0 ; i < list.size();i++)
              count[list[i][idx]]++;
        // count how many element are there which are <= to i
        for ( int i = 1 ; i <= 200 ; i++ )
             count[i] += count[i-1];
        // Placing the element i to its correct position in output array.
        for ( int i = list.size()-1;i >= 0; i--)
              result[count[list[i][idx]]--] = list[i];
        list = result;
        list.erase(list.begin());
}
int getMax(vector<string> list){
        int max = list[0].size();
        for (auto e : list ) {
                if ( e.size() > max ){
                        max = e.size();
                }
        }
        return max;
}
void radixSort(vector<string> &list ){
 int maxStringLength = getMax(list);
 for ( int i = maxStringLength-1; i >= 0; i--){
       countSort(list,i);
}
}
int main(){
        vector<string> arr = {"COW", "DOG", "SEA", "RUG", "ROW", "MOB", "BOX", "TAB","BAR", "EAR", "TAR", "DIG", "BIG", "TEA", "NOW", "FOX"};
        printList(arr);
        cout<<"After counting sort : "<<endl;
        radixSort(arr);
        printList(arr);
        return 0;
}
