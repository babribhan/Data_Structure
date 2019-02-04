#include<iostream>
using namespace std;

class DisjointSet{
   int *parent;
   int *rank;
   DisjointSet(const int items){
      parent = new int[items+1];
      rank = new int[items+1];
      for ( int i = 1 ; i <= items; ++i){
         parent[i] = i;
      rank[i] = 0;
}
   }
   ~DisjointSet(){
      if ( parent)
         delete[] parent;
      if ( rank )
         delete[] rank;
   }
   int find(const int item){
      if ( parent[item] == item )
         return item;
      else
         return find(parent[item]);
   }
   void Union(const int item1, const int item2){
      if ( rank[item1] > rank[item2] )
         parent[item2] = item1;
      else if ( rank[item1] < rank[item2] )
         parent[item1] = item2;
      else {
         parent[item1] = item2;
         rank[item2]++;
      }
   }
};
