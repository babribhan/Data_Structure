#include<iostream>
#include<cstring>
using namespace std;
class DArray{
        int *arr;
        int size;
        int max;
        void allocatSpace(){
                int *temp = new int[2*max];
                memcpy(temp,arr,size*sizeof(int));
                delete arr;
                arr = temp;
                max = max<<1;
        }
        bool isValid(const int idx){
                return ( idx >= 0 && idx < max );
        }
        bool isFull(){
                return max == size;
        }
        public:
        int getSize() const{
        return size;
}
        int getMax() const{
        return max;
}
        DArray(const int capacity){
                arr = new int[capacity];
                size = 0;
                max = capacity;
        }
        ~DArray(){
                delete []arr;
                size =0;
                        max = 0;
        }

        void insertEnd(const int value){
                // check if array is full
                if ( isFull())
                        allocatSpace();
                arr[size++] = value;
        }
        void insertFront(const int value){
                // check if array is full
                if ( isFull())
                        allocatSpace();
                for ( int i = size-1;i>= 0 ;i--)
                        arr[i+1] = arr[i];
                arr[0] = value;
                size++;
        }
        void insertAt(const int value,const int idx){
                if (!isValid(idx)){
                        cout<<"ERROR: Invalid index "<<endl;
                        return;
                }
                // check if array is full
                if ( isFull())
                        allocatSpace();
                for ( int i = size-1;i>= idx ;i--)
                        arr[i+1] = arr[i];
                arr[idx] = value;
                size++;
        }
        void printArray(){
                for ( int i = 0 ; i < size;i++ )
                        cout<<arr[i]<<' ';
                cout<<endl;
        }
        void deleteFront(){
        if ( !size) return;
        else
        for ( int i = 1 ; i < size;i++)
        arr[i-1] = arr[i];
        --size;
}
        void deleteEnd(){
        if (!size) return;
        else
        arr[size-1] = 0;
        --size;
}
        void deleteAt(int idx){
                if (!isValid(idx)){
                        cout<<"ERROR: Invalid index "<<endl;
                        return;
                }
        if (!size) return;
        else
        for ( int i = idx ; i < size;i++)
        arr[i] = arr[i+1];
        --size;
}
};
int main(){
        DArray da(10);
        da.insertEnd(2);
        da.insertEnd(3); // 2 3
        da.insertEnd(7); // 2 3 7
        da.insertFront(8); // 8 2 3 7
        da.insertFront(1); // 1 8 2 3 7
        da.insertAt(4,2); // 1 8 4 2 3 7
        cout<<"Size of the array is "<<da.getSize()<<endl;
        cout<<"Max of the array is "<<da.getMax()<<endl;
        da.printArray();
        for ( int i = 0 ; i < 5 ; i++ ){
        da.insertFront(i+4);
}
        da.printArray();
        da.deleteFront();
        da.printArray();
        da.deleteEnd();
        da.printArray();
        da.deleteAt(1);
        da.printArray();
        cout<<"Size of the array is "<<da.getSize()<<endl;
        cout<<"Max of the array is "<<da.getMax()<<endl;
        return 0;
}
