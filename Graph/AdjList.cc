#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;
#define Trace(name) printf("Starting %s\n",name)
typedef struct node{
	int y;
	int weight;
	struct node *next;
} edgenode;
class Graph{
	const static int max_vertex = 100;
	edgenode *edges[max_vertex+1];
	int degree[max_vertex+1], nvertices, nedges;
	bool directed;
	int parent[max_vertex+1];
	public: 
	Graph(bool dir) {
		nvertices = nedges = 0;
		directed = dir;
		for (int i=1; i<=max_vertex; i++) {
			degree[i] = 0;
			edges[i] = nullptr;
			parent[i] = -1;
		}
	}
	~Graph(){
	}
	void remove_edge(int x, int y, bool  directed) {
		Trace("remove_edge");
		edgenode *p= edges[x];
		edgenode *pre_node= nullptr;
		while ( p && p->y != y ) 
		{
			pre_node = p;
			p= p->next;
		}                 
		if (p) {
			edgenode *temp = p;
			pre_node->next = p->next;
			delete p;
			if (!directed){
				remove_edge(y,x,directed);
			}
		}
		else {
			cout<<"Edge between "<<x<<" and "<<y<<" doesn't exists.\n";
		}
	}
	void insert_edge(int x, int y, bool  directed) {
		Trace("insert_edge");
		edgenode *p;                 
		p = new edgenode;
		p->weight = -1;
		p->y = y;
		p->next = edges[x];
		edges[x] = p;
		degree[x]++;
		if (!directed)
			insert_edge(y,x,true);
		else 
			nedges++;
	}
	void read_graph(bool  directed) {
		Trace("read_graph");
		int max_edges;
		int x, y;
		scanf("%d %d",&(nvertices),&max_edges);
		for (int i=1; i<=max_edges; i++) {
			scanf("%d %d",&x,&y);
			insert_edge(x,y,directed);
		} 
	}
void print_graph() {
	Trace("print_graph");
	int i;
	edgenode *p;
	for (i=1; i<=nvertices; i++) {
		printf("%d: ",i);
		p = edges[i];
		while (p) {
			printf(" %d",p->y);
			p = p->next;
		}
		printf("\n");
	}
}
void bfs(int s){
	std::queue<int> q;
	int curr,successor;
	bool processed[nvertices+1],discovered[nvertices+1];
	for ( int i = 1 ; i <= nvertices;i++)
		processed[i] = discovered[i] = false;
	edgenode *temp;
	q.push(s);
	discovered[s] = true;
	while(!q.empty()){
		curr = q.front();q.pop();
		process_vertex(curr);
		temp = edges[curr];
		while(temp){
			successor = temp->y ; 
			if(!processed[successor] || directed)
				process_edge(curr,successor);
			if (!discovered[successor]){
				q.push(successor);
				discovered[successor] = true;
				parent[successor] = curr;
			}
			temp = temp->next;   
		}
		processed[curr] = true;
	}                  
}
	void dfs(int s){
		edgenode *temp;
		vector<bool> visited(nvertices,false);
		stack<int> st;
		st.push(s);
		while(!st.empty()){
			s = st.top();st.pop();
			if ( !visited[s]){
				process_vertex(s);
				visited[s] = true;
			}
			temp = edges[s];
			while(temp){
				if (!visited[temp->y]){
					st.push(temp->y);
					process_edge(s,temp->y);
				}
				temp = temp->next;   
			}
		}
	}                  
	void DFS_util(int v , bool vis[]){
		vis[v] = true;
		process_vertex(v);
		edgenode *temp = edges[v];
		while(temp){
			if (!vis[temp->y]){
				process_edge(v,temp->y);
				DFS_util(temp->y,vis);
			}
			temp = temp->next;
		}
	}
void DFS(int s){
	bool *visited = new bool[nvertices];
	for(int i  = 0 ; i < nvertices ; i++)
		visited[i] = false;
   DFS_util(s,visited);
}

	void conn_comp(){
		bool *visited = new bool[nvertices];
		for(int i = 0 ; i < nvertices;i++)   visited[i] = false;
		for(int v = 0 ; v < nvertices;v++){
			if (!visited[v]){
				DFS_util(v,visited);
				cout<<endl;
			}
		}

	}
	void process_edge(int u,int v){
		std::cout<<"processed edge ("<<u<<","<<v<<")"<<std::endl;
	}
	void process_vertex(int v){
		std::cout<<"processed vertex "<<v<<std::endl;
	}
	void find_path(int start, int end){
		if ( start == end || end == -1 ) 
			cout<<start;
		else {
			find_path(start,parent[end]);
			cout<<" "<<end;
		}
	}
	bool is_two_col_util(int v , int col[]){
		col[v] = 1;
		queue<int> q; 
		q.push(v);
		while(!q.empty()){
			int curr = q.front();q.pop();		
			edgenode *temp = edges[curr];
			while(temp){
				if ( col[temp->y] == - 1 ) {
					col[temp->y] = 1 - col[curr];
					q.push(temp->y);
				}
				if ( col[temp->y] == col[curr] ) return false;

				temp = temp->next;
			}
		}
		return true;
	}
	bool two_color(){
		int *color = new int[nvertices];

		for(int i = 0; i < nvertices;i++){
			color[i] = -1;
		}
		for(int j = 0; j <nvertices;j++){
			if(color[j] == -1 ) {
				if (!is_two_col_util(j,color)) return false;
			}
		}
		return true;
	}
};
int main(){
	Trace("main");
	Graph g(false);
	g.read_graph(false);
	g.print_graph();
// g.remove_edge(1,5,false);
//	g.print_graph();
	std::cout<<"BFS of the graph is "<<std::endl;
	g.bfs(1);
	std::cout<<"DFS of the graph is "<<std::endl;
   g.dfs(1);
	std::cout<<"DFS of the graph is "<<std::endl;
	g.DFS(1);
/*	cout<<"Path between 1 and 4 is :";
	g.find_path(1,4);
	cout<<endl<<"Connected components of the graph is : "<<endl;
	g.conn_comp();
	cout<<"Is the graph is Biparite ? "<<g.two_color()<<endl;
*/	return 0;
}
