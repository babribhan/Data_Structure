/*
   File        : hashTable.cpp
   Description : Implementation of Hash Table using simple Division hash function.
   Author      : Babribhan Jangra <babribhan@gmail.com>
 */
#include<iostream>
#include<vector>
using namespace std;
class Hash{
	vector<int> table;
	int max;
	int hash_val(int k){
        return k % max;
	}
	public:
	Hash(int size){
		table.assign(size,-1);
		max = size;
	}	
	int search(int key){
		return table[hash_val(key)];
	}
	void insert(int val , int key){
		table[hash_val(key)] = val;
	}
	void delete_key(int key ) {
		table[hash_val(key)] = -1;
	}
	void print_table(){
		for (int i = 0 ; i < table.size();++i)
			cout<<"Key = "<<i<<" ,Value= "<<table[i]<<endl;
	}
};
int main(){
	Hash h(10);
	h.insert(28,5);
	h.insert(8,15);
	h.insert(9,25);
	h.insert(6,65);
	h.insert(4,35);
	h.insert(7,55);
	h.print_table();
	h.delete_key(4);
	h.delete_key(44);
	h.print_table();
	cout<<"Is key 9 present in table ?";
	if ( h.search(29) == -1 ) 
		cout<<"No"<<endl;
	else 
		cout<<"Yes"<<endl;
	cout<<"key 44 contains value "<<h.search(44)<<endl;
	return 0;
}
