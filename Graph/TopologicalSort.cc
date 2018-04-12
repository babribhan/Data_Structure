// Program to Implement a Topological Sort of A DAG.
#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topological_util(int v ,bool visited[], stack<int> &Stack);
	public:
	Graph(int v);
	void add_edge(int x , int y);
	void topological_sort();
};
Graph::Graph(int v ) : V(v){
	adj = new list<int>[v];
}
void Graph::add_edge(int x , int y){
	adj[x].push_back(y);
}
void Graph::topological_util(int v , bool visited[],stack<int> &stk){
	visited[v] = true;
	list<int>::iterator it;
	for ( it = adj[v].begin();it != adj[v].end();++it){
		if(!visited[*it])
			topological_util(*it,visited,stk);
	}
	stk.push(v);
}
void Graph::topological_sort(){
	stack<int> st;
	bool *visited = new bool[V];
	for ( int i = 0; i < V;++i)
		visited[i] = false;

	for ( int i = 0 ; i<V;++i){
		if (!visited[i]) 
			topological_util(i,visited,st);
	}
	while ( !st.empty()){
		cout<<st.top()<<" ";
		st.pop();
	}
}
// Driver program to test above functions
int main()
{
	// Create a graph given in the above diagram
	Graph g(6);
	g.add_edge(5, 2);
	g.add_edge(5, 0);
	g.add_edge(4, 0);
	g.add_edge(4, 1);
	g.add_edge(2, 3);
	g.add_edge(3, 1);

	cout << "Following is a Topological Sort of the given graph \n";
	g.topological_sort();
	cout<<endl;
	return 0;
}
