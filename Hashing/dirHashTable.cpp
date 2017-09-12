/*
   File        : dirHashTable.cpp
   Description : Implementation of  Direct Hash Table.
   Author      : Babribhan Jangra <babribhan@gmail.com>
 */
#include<iostream>
#include<vector>
using namespace std;
class Hash{
	vector<int> table;
	int max;
	void valid_key(int k){
		if ( k < 0 || k >= max ){
			cout<<"Invalid key "<<k<<". Key must lies in range {0,"<<max<<"}"<<endl;
			exit(1); 
		}
	}
	public:
	Hash(int size){
		table.assign(size,-1);
		max = size;
	}	
	int search(int key){
		valid_key(key);
		return table[key];
	}
	void insert(int val , int key){
		valid_key(key);
		table[key] = val;
	}
	void delete_key(int key ) {
		valid_key(key);
		table[key] = -1;
	}
	void print_table(){
		for (int i = 0 ; i < table.size();++i)
			cout<<"Key = "<<i<<" ,Value= "<<table[i]<<endl;
	}
};
int main(){
	Hash h(25);
	//h.insert(5,28);
	h.insert(1,8);
	h.insert(0,9);
	h.insert(6,6);
	h.insert(3,4);
	h.insert(5,7);
	h.print_table();
	h.delete_key(4);
	//h.delete_key(44);
	h.print_table();
	cout<<"Is key 9 is present in table ?";
	if ( h.search(29) == -1 ) 
		cout<<"No"<<endl;
	else 
		cout<<"Yes"<<endl;
	//h.search(44);
	return 0;
}
