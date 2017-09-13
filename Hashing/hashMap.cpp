/*
File        : hashMap.cpp
Description : Implementation of Hash Map using simple Division hash function.
            : And collision is resolved using chaining.(singly linked list)
Author      : Babribhan Jangra <babribhan@gmail.com>
 */
#include<iostream>
#include<vector>
using namespace std;
class HashNode{
	public:
		int val;
		int key;
		HashNode *next;
		HashNode(int k, int v){
			this->key = k;
			this->val = v;
			this->next = nullptr;
		}
};
class HashMap{
	HashNode** table;
	int max;
	int hash_value(int key){
		return key % max;
	}      
	public:
	HashMap(int size){
		table = new HashNode*[size];
		for ( int i =0 ; i < size; i++)
			table[i] = nullptr;
		max = size;
	}
	~HashMap(){
		delete[] table;
	}
	void insert(int key , int value){
		HashNode *head = table[hash_value(key)];
		HashNode *temp= new HashNode(key,value);
		temp->next = head;
		head = temp;
		table[hash_value(key)] = head;
	}
	void remove(int key){
		HashNode *head = table[hash_value(key)];
		if ( head) {
			HashNode *temp = head;
			head = head->next;
			table[hash_value(key)] = head;
			cout<<temp->val<<" is successfully deleted"<<endl;
			delete temp;
		}
	}
	int search(int key){
		HashNode *curr = table[hash_value(key)];
		while(curr && curr->key != key) 
			curr = curr->next;

		if (!curr) {
			cout<<"Key "<<key<<" is not present in map."<<endl;
			exit(1);
		}
		else 
			return curr->val;
	}
	void print_table(){
		for ( int i = 0 ; i< max;i++){
			HashNode *curr = table[i];
			cout<<"key = "<<i<<" values ";
			while(curr)
			{
				cout<<curr->val<<" ";
				curr = curr->next;
			}
			cout<<endl;
		}
	}
};
int main(){
	HashMap h(11);
	h.insert(28,5);
	h.print_table();
	h.insert(9,25);
	h.insert(8,15);
	h.insert(6,65);
	h.insert(4,35);
	h.insert(7,55);
	h.insert(39,9);
	cout<<"After Insertion"<<endl;
	h.print_table();
	h.remove(6);
	h.print_table();
	cout<<"key 28 contains value "<<h.search(28)<<endl;
	cout<<"key 44 contains value "<<h.search(44)<<endl;
	return 0;
}
