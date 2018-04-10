include<iostream>
#include<vector>
#include<string>
using namespace std;
class Graph{
   vector<vector<bool> > graph{10,vector<bool>(10)};
   bool isDirected;
   short noOfEdge;
   public:
   Graph(bool graphType){
      isDirected = graphType;
      noOfEdge = 0;
   }
   ~Graph(){}
   void addEdge(int x , int y ) {
      graph[x][y] = true;
      if(!isDirected) graph[y][x] = true;
   }
   bool isEdge(int x,int y){
      return graph[x][y];
   }
   void removeEdge(int x , int y ) {
      if ( graph[x][y]) {
         graph[x][y] = false;
         graph[y][x] = false;
      }
      else
         cout<<"No Edge exist between the given vertices"<<endl;
   }
   bool getGraphType(){
      return isDirected;
   }
};
string checkEdge(bool val){
   if (val)
      return "YES";
   else
      return "NO";
}
int main(){
   Graph g(false);
   g.addEdge(1,2);
   g.addEdge(1,4);
   g.addEdge(2,5);
   g.addEdge(4,3);
   cout<<"Is Edge exist between 1 and 4 "<<checkEdge(g.isEdge(1,4))<<endl;
   g.removeEdge(1,4);
   cout<<"Is Edge exist between 1 and 4 "<<checkEdge(g.isEdge(1,4))<<endl;
   g.removeEdge(1,4);
   cout<<"Type of graph is "<<g.getGraphType()<<endl;
   return 0;
}
