/*
   File        : hashTabOpenAdd.cpp
   Description : Implementation of Hash Table using simple Division hash function with open addressing.
               : Collision is resolved by linear probing.
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
		int h = hash_val(key);
		int i = 0;                
		while ( h < max  &&  ( table[h] != -1 && table[h] == 9999 ))
		{
			h = hash_val(key)+i++;
		}
		return table[h];
	}
	void insert(int key , int val){
		int h = hash_val(key);
		int i = 0;                
		while ( h < max && ( table[h] != -1 && table[h] != 9999) )
		{
			h = hash_val(key)+i++;
		}
		table[h] = val;
	}
	void delete_key(int key ) {
		table[hash_val(key)] = 9999;
	}
	void print_table(){
		for (int i = 0 ; i < table.size();++i)
			cout<<"Key = "<<i<<" ,Value= "<<table[i]<<endl;
	}
};
int main(){
	Hash h(11);
	h.insert(28,5);
	h.insert(6,65);
	h.insert(7,55);
	h.insert(8,15);
	h.insert(9,25);
	h.insert(4,35);
	h.print_table();
	h.delete_key(4);
	h.delete_key(44);
	h.print_table();
	cout<<"Is key 7 present in table ?";
	if ( h.search(6) == -1 ) 
		cout<<"No"<<endl;
	else 
		cout<<"Yes and value is "<<h.search(6)<<endl;
	cout<<"key 44 contains value "<<h.search(44)<<endl;
	return 0;
}
