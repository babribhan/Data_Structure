#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;
class Graph{
	short noOfVertex;
	list<int> *adj;
	public:
	Graph(int v);
	void addEdge(int,int);
	void bfs(int);
	void dfs(int);
	bool isCycle();
	bool cycleUtil(int,bool*,bool*);
	void dfsUtil(int,vector<bool> &);
};
bool Graph::cycleUtil(int v , bool *visited, bool *recStack){
	if ( !visited[v]){
		visited[v] = recStack[v] = true;
		list<int>::iterator i;
		for ( i = adj[v].begin();i != adj[v].end();i++){
			if ( !visited[*i] && cycleUtil(*i,visited,recStack))
				return true;
			else if (recStack[*i]) //for undirected graph we use parent vertec instead of recStack and check "else if ( *i != parent ) 
				return true;
		}
	}
	recStack[v] = false;
	return false;
}
bool Graph::isCycle(){
	bool *visited  = new bool[noOfVertex];
	bool *recStack = new bool[noOfVertex];
	for ( int i = 0 ; i < noOfVertex;++i)
		visited[i] = recStack[i] = false;
	for ( int i = 0 ; i < noOfVertex;++i) {
		if (cycleUtil(i,visited,recStack))
			return true;
	}
	return false;
}
Graph::Graph(int v):noOfVertex(v){
	adj = new list<int>[v];
}
void Graph::addEdge(int u , int v){
	adj[u].push_back(v);
}
void Graph::bfs(int s){
	queue<int> q;
	vector<bool> visited(noOfVertex,false);
	visited[s] = true;
	q.push(s);
	list<int>::iterator it;
	while (!q.empty()){
		s = q.front();q.pop();
		cout<<s<<' ';
		//Traverse all the adjacent vertex of current vertex.
		for (it = adj[s].begin(); it != adj[s].end();it++){
			if ( !visited[*it] ){
				visited[*it] = true;
				q.push(*it);
			}
		}
	}
}
void Graph::dfsUtil(int s,vector<bool> &visited){
	visited[s] = true;
	cout<<s<<' ';
	list<int>::iterator it;
	for ( it = adj[s].begin(); it != adj[s].end();it++){
		if ( !visited[*it])
			dfsUtil(*it,visited);
	}

}
void Graph::dfs(int s){
	vector<bool> visited(noOfVertex,false);
	dfsUtil(s,visited);
}
int main(){
	Graph g(4);
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);
	cout<<"BFS of Graph starting from vertex 2 \n";
	g.bfs(2);
	cout<<"\n";
	cout<<"DFS of Graph starting from vertex 2 \n";
	g.dfs(2);
	cout<<"\n";
	if(g.isCycle())
		cout << "Graph contains cycle\n";
	else
		cout << "Graph doesn't contain cycle\n";
}
