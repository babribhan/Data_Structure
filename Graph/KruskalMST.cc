#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Graph{
	int V,E;
	vector<pair<int,pair<int,int> > > edges;
	vector<pair<int,pair<int,int> > > MST;
	public:
	Graph(int V,int E);
	void addEdge(int u , int v,int w );
	int kruskalMST();
	void printMST();
};
Graph::Graph(int V,int E){
	this->V = V;
	this->E = E;
}
void Graph::addEdge(int u, int v,int w){
	edges.push_back({w,{u,v}});
}
void Graph::printMST(){
	vector<pair<int,pair<int,int> > >::iterator it;
	for ( it = MST.begin(); it != MST.end();++it){
		cout<<"("<<it->second.first<<","<<it->second.second<<") :"<<it->first<<endl;
	}
}
struct DisjointSet{
	int *parent , *rank;
	int n;
	DisjointSet(int n) {
		this->n = n;
		parent = new int[n+1];
		rank = new int[n+1];
		for ( int i=0;i<=n;i++){
			rank[i] = 0;
			parent[i] = i;
		}
	}
	int find(int u){
		if ( u == parent[u] ) 
			return parent[u];
		else 
			return find(parent[u]);
	}
	void Union(int x, int y){
		x = find(x);
		y = find(y);
		if(x^y){
			if ( rank[x] < rank[y] ) {
				rank[y]+=rank[x];
				parent[x] = y;
			}
			else {
				rank[x]+=rank[y];
				parent[y] = x;
			}
		}
	}
};
int Graph::kruskalMST(){
	int MSTWeight = 0; // Weight of MST.
	sort(edges.begin(),edges.end());
	DisjointSet ds(this->V);
	vector<pair<int,pair<int,int> > >::iterator it;
	// for all edges in Graph.
	for ( it = edges.begin();it != edges.end();it++){
		int u = it->second.first;
		int v = it->second.second;

		int setU = ds.find(u);
		int setV = ds.find(v);

		if ( setU^setV){
			int w = it->first;
			MST.push_back({w,{u,v}});
			MSTWeight += it->first;
			ds.Union(setU,setV);
		}
	}
	return MSTWeight;
}
int main(){
	int V,E;
	cout<<"How many vertex ?"<<endl;
	cin>>V;
	cout<<"How many edges ?"<<endl;
	cin>>E;

	Graph g(V,E);
	int u,v,w;
	for ( int i =0 ; i < E;i++){
		cin>>u>>v>>w;
		g.addEdge(u,v,w);
	}
	int weight = g.kruskalMST();
	cout<<"MST: "<<endl;
	g.printMST();
	cout<<"Weight of MST is : "<<weight<<endl;
}
