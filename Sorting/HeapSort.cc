#include<iostream>
#include<vector>
using namespace std;
void swap(int &a , int &b ){
        if ( a^b){
                a = a+b;
                b = a-b;
                a = a-b;
        }
}
int getParent(int child){
        return child>>1;
}
int lChild(int parent){
        return (parent<<1)+1;
}
int rChild(int parent){
        return (parent<<1)+2;
}
void maxHeapify(vector<int> &list , int parent ) {
        int lchild = lChild(parent);
        int rchild = rChild(parent);
        int largest = parent;
        if ( lchild < list.size() && list[lchild] > list[parent] )
                largest = lchild;
        if ( rchild < list.size() && list[rchild] > list[largest])
                largest = rchild;
        if ( largest^parent){
                swap(list[largest],list[parent]);
                maxHeapify(list,largest);
        }
}
void buildMaxHeap(vector<int> &list){
        for ( int i = (list.size()-1)>>1 ; i >= 0 ; i-- )
                maxHeapify(list,i);
}
void heapSort(vector<int> &list){
        vector<int> result;
        buildMaxHeap(list);
        for ( int i = list.size()-1 ; i >= 0 ; i-- ){
                swap(list[0],list[i]); // Take the largest element at last index.
                result.insert(result.begin(),list[i]);
                list.pop_back(); // remove the last element from the heap.
                maxHeapify(list,0);
        }
        list = result;
}
void printHeap(vector<int> list ) {
        for ( auto e : list )
                cout<<e <<' ';
        cout<<endl;
}
int main(){
        vector<int> arr = {4,1,3,2,16,9,10,14,8,7};
        printHeap(arr);
        //buildMaxHeap(arr);
        heapSort(arr);
        cout<<"after heap sort : "<<endl;
        printHeap(arr);
        return 0;
}
