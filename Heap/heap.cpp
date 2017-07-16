#include<iostream>
#include<vector>
using namespace std;

template<class T>
class heap{
	vector<T> list;
	void shift_up();
	void shift_down();
	void swap(int child , int parent);
	int get_lchild(int parent);
	int get_rchild(int parent);
	int get_parent(int child);
	public:
	heap();
	void insert(T);
	T remove();
	int get_size();
};
template<class T>
heap<T>::heap(){

}
template<class T>
int heap<T>::get_size(){
	return list.size();
}
template<class T>
void heap<T>::swap(int child , int parent){
	T temp = 	list[child];
	list[child] = list[parent];
	list[parent] = temp;
}

template<class T>
int heap<T>::get_parent(int child){
	if ( child % 2  == 0 ) 
		return (child/2) -1;
	else 
		return child/2;

}

template<class T>
int heap<T>::get_lchild(int parent){
	return 2*parent+1;
}
template<class T>
int heap<T>::get_rchild(int parent){
	return 2*parent+2;
}
template<class T>
void heap<T>::insert(T value ) {
	list.push_back(value);
	shift_up();
}

template<class T>
void heap<T>::shift_up(){
	int child = list.size() - 1;
	int parent = get_parent(child);
	while ( list[child] > list[parent] && child >=0 && parent >= 0 ){
		swap(child,parent);
		child = parent;
		parent = get_parent(child);
	} 
}
template<class T>
T heap<T>::remove(){
	int child = list.size()-1 ;
	swap(child,0);
	T value = list.back();
	list.pop_back();
	shift_down();
	return value;
}

template<class T>
void heap<T>::shift_down(){
	int parent = 0 ;
	while ( 1 ) {
		int length = list.size();
		int left = get_lchild(parent);
		int right = get_rchild(parent);
		int largest = parent;
		if ( left < length && list[left] > list[largest] ) 
			largest = left;
		if (  right < length && list[right] > list[largest])
			largest = right;

		if (largest^parent ){
			swap ( largest,parent);
			parent = largest;
		}
		else 
			break;
	}
}
int main(){
int a[] = {4,5,2,3,6,7};
heap<int> h;
int len = sizeof(a)/sizeof(a[0]);
for ( int i = 0  ; i < len ; i++ ) 
h.insert(a[i]);

while(h.get_size() > 0 ) {
cout<<"Heap max : "<<h.remove()<<endl;
}
return 0;
}
