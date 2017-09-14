/*
   File        : doubleHash.cpp
   Description : Implementation of Hash Table using simple Division hash function with open addressing.
               : Collision is resolved by Double Hashing.
   Author      : Babribhan Jangra <babribhan@gmail.com>
 */
#include<iostream>
#include<vector>
using namespace std;
class Hash{
	enum entry_type{avaliable,deleted,occupied};
	struct node{
		int val;
		enum entry_type info;
		int key;        
	};
	vector<node*> table;
	int max;
	int hash_val1(int k){
		return k % max;
	}
	int hash_val2(int k){
		return (k*max - 1) % max;
	}
	public:
	Hash(int size){
                table.assign(size,NULL);
		for ( int i = 0 ; i < size;i++){
                        table[i] = new node();
			table[i]->val = table[i]->key = -1;
			table[i]->info = avaliable;
		}
		max = size;
	}	
	int search(int key){
		int h = hash_val1(key);                
		while ( h < max && (table[h]->info == deleted 
					||( table[h]->info == occupied && table[h]->key != key )))
		{
			h = (h + hash_val2(key))%max;
		}
		if ( table[h]->key  != key ) {
			cout<<"Key "<<key<<" is not int the hash"<<endl;
			return -1;              
		}		
		return table[h]->val;
	}
	void insert(int key , int val){
		int h = hash_val1(key);                
		while ( h < max &&  table[h]->info == occupied )
		{
			h = (h + hash_val2(key))%max;
		}
		table[h]->val = val;
		table[h]->key = key;
		table[h]->info = occupied;
	}
	void delete_key(int key ) {
		int h = hash_val1(key);                
		while ( h < max &&  ( table[h]->info == deleted || (table[h]->info == occupied && table[h]->key != key ) ))
		{
			h = (h + hash_val2(key))%max;
		}
                if ( table[h]->key  != key ) cout<<"Key "<<key<<" is not int the hash"<<endl;
		table[h]->info = deleted;
	}
	void print_table(){
		for (int i = 0 ; i < table.size();++i)
			cout<<"Key = "<<table[i]->key<<" ,Value = "<<table[i]->val<<" ,status = "<<table[i]->info<<endl;
	}
};
int main(){
	Hash h(11);
	h.insert(28,5);
	h.insert(7,65);
	h.insert(6,55);
	h.insert(8,15);
	h.insert(9,25);
	h.insert(4,35);
	h.print_table();
	h.delete_key(4);
	h.delete_key(44);
	h.print_table();
	cout<<"Is key 6 present in table ?";
	if ( h.search(6) == -1 ) 
		cout<<"No"<<endl;
	else 
		cout<<"Yes and value is "<<h.search(6)<<endl;
	return 0;
}
