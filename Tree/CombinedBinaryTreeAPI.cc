#include<iostream>
#include<queue>
#include<stack>
#include<map>
#include<vector>
typedef struct node {
  int data;
  struct node *left,*right;
}Node;
class Tree{
  Node* root;
  int sz;
  public:
  Tree():sz(0),root(nullptr){}
  Node* getNewNode(int);
  void buildTree();
  Node* getRoot();
  void levelOrder();
  void revLevelOrder();
  void inOrder1();
  void levelOrder1();
  void levelOrder2();
  void leftView();
  void rightView();
  void diagonalOrder();
};
int getHeight(Node* root){
  if ( !root) return 0;
  int leftHeight = getHeight(root->left);
  int rightHeight = getHeight(root->right);
  return  ( leftHeight > rightHeight ? leftHeight+1 : rightHeight+1 );
}
int max ( int a , int b){
  return a>b ? a : b;
}
int height(Node* root ) {
  if ( !root ) return 0;
  std::queue<Node*> q;
  q.push(root);
  int h = 0 ;
  while ( !q.empty()){
    int size  = q.size();
    while ( size--){
      Node* temp = q.front();q.pop();
      if (temp->left) q.push(temp->left);
      if (temp->right) q.push(temp->right);
    }
    ++h;
  }
  return h;
}
int diameter(Node* root , int& h){
  int leftH = 0,rightH = 0;
  int lDia = 0 , rDia = 0 ; 
  if ( !root ) {
    h = 0;
    return 0;
  }
  lDia = diameter(root->left,leftH);
  rDia = diameter(root->right,rightH);
  h = leftH > rightH ? leftH+1 : rightH+1;
  return max(rightH + leftH + 1, max(lDia,rDia));
}
void diaPrint(Node* root , int d , std::map<int,std::vector<int> >& dia){
  if(!root) 
    return; 
  // Store all nodes of same diagonal together.
  dia[d].push_back(root->data);
  // if left child exists then increase the vertical distance.
  diaPrint(root->left,d+1,dia);
  // if right child exists then the vertical distance remains same.
  diaPrint(root->right,d,dia);
}
void printDiagonal(Node* root){
  std::map<int,std::vector<int> > diagonal;
  diaPrint(root,0,diagonal);
  std::cout<<"Diagonal Traversal of the Tree is : "<<std::endl;
  for ( auto it = diagonal.begin(); it != diagonal.end();++it){
    for ( auto itr = it->second.begin(); itr != it->second.end();++itr){
      std::cout<<*itr<<' ';
    } 
    std::cout<<std::endl;
  }
}
void verPrint(Node* root , int d , std::map<int,std::vector<int> >& m){
  if(!root) 
    return; 
  // Store all nodes of same diagonal together.
  m[d].push_back(root->data);
  // if left child exists then decrease the Horizontal distance.
  verPrint(root->left,d-1,m);
  // if right child exists then increase teh Horizontal distance.
  verPrint(root->right,d+1,m);
}
void printVertical(Node* root){
  std::map<int,std::vector<int> > m;
  verPrint(root,0,m);
  std::cout<<"Vertical Traversal of the Tree is : "<<std::endl;
  for ( auto it = m.begin(); it != m.end();++it){
    for ( int i = 0 ; i < it->second.size();++i)
      std::cout<<it->second[i]<<' ';
    std::cout<<std::endl;
  }
}
void bottomView(Node* root){
  std::map<int,std::vector<int> > m;
  verPrint(root,0,m);
  for ( auto it = m.begin(); it != m.end();++it)
    std::cout<<it->second.back()<<' ';
  std::cout<<std::endl;
}
void topView(Node* root){
  std::map<int,std::vector<int> > m;
  verPrint(root,0,m);
  for ( auto it = m.begin(); it != m.end();++it)
    std::cout<<it->second.front()<<' ';
  std::cout<<std::endl;
}
void Tree::diagonalOrder(){
  if (!root) return ;
  std::queue<Node*> q;
  q.push(root);
  q.push(nullptr); // Push delimiter.
  while (!q.empty()){
    Node* temp = q.front();q.pop();
    if (!temp) { // if current is null then insert null for another diagonal and print new Line.
      if ( q.empty())
        return;
      std::cout<<std::endl;
      q.push(nullptr); // for next diagonal.
    }
    else {
      while ( temp ) {
        std::cout<<temp->data<<' ';
        if ( temp->left) 
          q.push(temp->left);
        temp = temp->right;
      }
    }
  }
}
void Tree::inOrder1(){
  std::stack<Node*> s;
  Node* temp = root;
  do{
    while (temp){
      s.push(temp);
      temp = temp->left;
    }
    if (!s.empty()){
      temp = s.top();s.pop();
      std::cout<<temp->data<<' '; 
      temp = temp->right;
    }
  }while(!s.empty() || temp );
}
void Tree::levelOrder2(){
  if (root){
    std::queue<Node*> q1,q2;
    q1.push(root);
    while (!q1.empty() || !q2.empty()){
      while(!q1.empty()){
        Node *temp = q1.front();q1.pop();
        std::cout<<temp->data<<' ';
        if( temp->left) q2.push(temp->left);
        if( temp->right) q2.push(temp->right);
      }
      std::cout<<std::endl;
      while(!q2.empty()){
        Node *temp = q2.front();q2.pop();
        std::cout<<temp->data<<' ';
        if( temp->left) q1.push(temp->left);
        if( temp->right) q1.push(temp->right);
      }
      std::cout<<std::endl;
    }
  }
}
void Tree::levelOrder1(){
  if (root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      Node* temp = q.front();q.pop();
      std::cout<<temp->data<<' ';
      if( temp->left) q.push(temp->left);
      if( temp->right) q.push(temp->right);
    }
  }
}
void Tree::revLevelOrder(){
  if (root){
    Node* temp = root;
    std::queue<Node*> q;
    std::stack<Node*> s;
    q.push(root);
    while(!q.empty()){
      temp = q.front();q.pop();
      s.push(temp);
      if( temp->left) q.push(temp->left);
      if( temp->right) q.push(temp->right);
    }
    while (!s.empty()){
      std::cout<<s.top()->data<<' ';
      s.pop();
    }
  }
}
void Tree::levelOrder(){
  if (root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      int n = q.size();
      for ( int i = 0 ; i < 1 ; ++i){  // Only Print the current level nodes.
        Node* temp = q.front();q.pop();
        std::cout<<temp->data<<' ';
        if( temp->left) q.push(temp->left);
        if( temp->right) q.push(temp->right);
      }
      std::cout<<std::endl;
    }
  }
}
void Tree::rightView(){
  if (root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      int n = q.size();
        std::cout<<q.back()->data<<' ';
      for ( int i = 0 ; i < n ; ++i){  // Only Print the current level nodes.
        Node* temp = q.front();q.pop();
        if( temp->left) q.push(temp->left);
        if( temp->right) q.push(temp->right);
      }
    }
  }
}
void Tree::leftView(){
  if (root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      int n = q.size();
        std::cout<<q.front()->data<<' ';
      for ( int i = 0 ; i < n ; ++i){  // Only Print the current level nodes.
        Node* temp = q.front();q.pop();
        if( temp->left) q.push(temp->left);
        if( temp->right) q.push(temp->right);
      }
    }
  }
}
Node* Tree::getNewNode(int data){
  Node *temp = new Node();
  temp->data = data;
  temp->left = temp->right = nullptr;
  return temp;
}
Node* Tree::getRoot(){
  return root;
}
void inOrder(Node *root){
  if ( root ) {
    inOrder(root->left);
    std::cout<<root->data<<' ';
    inOrder(root->right);
  }
}
void postOrder(Node *root){
  if ( root ) {
    postOrder(root->left);
    postOrder(root->right);
    std::cout<<root->data<<' ';
  }
}
void preOrder(Node *root){
  if ( root ) {
    std::cout<<root->data<<' ';
    preOrder(root->left);
    preOrder(root->right);
  }
}
void Tree::buildTree(){
  root = getNewNode(1);
  root->left = getNewNode(2);
  root->right = getNewNode(3);
  root->left->left = getNewNode(4);
  root->left->right = getNewNode(5);
  root->right->left = getNewNode(6);
  root->right->right = getNewNode(7);
  root->left->left->left = getNewNode(8);
  root->left->left->right = getNewNode(9);
  /* 4 becomes left child of 2
     1
     /\
     2  3
     /\  /\
     4  5 6 7
     /\
     8  9
     */
}
int leavesCount(Node* root){
  if (!root ) 
    return 0;
  if ( !root->left && !root->right ) return 1;
  return ( leavesCount(root->left) + leavesCount(root->right));
}
void printLeaves(Node* root){
  if (root){
    printLeaves(root->left);
    if ( !root->left && !root->right ) 
      std::cout<<root->data<<' ';
    printLeaves(root->right);
  }
}
void printBoundaryRight(Node* root){
  if (root){
    if ( root->right) {
      printBoundaryRight(root->right);
      std::cout<<root->data<<' ';
    }
    else if ( root->left) {
      printBoundaryRight(root->left);
      std::cout<<root->data<<' ';
    }
  } 
}
void printBoundaryLeft(Node* root){
  if (root){
    if ( root->left) {
      std::cout<<root->data<<' ';
      printBoundaryLeft(root->left);
    }
    else if ( root->right) {
      std::cout<<root->data<<' ';
      printBoundaryLeft(root->right);
    }
  } 
}
void printBoundary(Node* root){
  if ( root){
    std::cout<<root->data<<' ';
    // Print the left boundary in top-down manner.
    printBoundaryLeft(root->left);
    // Print all leaves from left to right.
    printLeaves(root->left);
    printLeaves(root->right);
    // Print the right boundary in bottom-up manner.
    printBoundaryRight(root->right);
  }
}
bool findPath(Node* root , std::vector<int> &path , int k){
if ( !root ) 
  return false;
path.push_back(root->data);
if ( root->data == k )
  return true;
// check if k is found in left or right subtree.
if ( (root->left && findPath(root->left,path,k)) || ( root->right && findPath(root->right,path,k)))
  return true;

path.pop_back();
return false;
}
int findLCA(Node* root,int p , int q){
  std::vector<int> path1,path2;
  // if either p or q is not present.
  if ( !findPath(root,path1,p) || !findPath(root,path2,q))
    return -1;
  int i;
  for ( i = 0 ; i < path1.size() && i < path2.size();++i){
    if ( path1[i] != path2[i] ) 
      break;
  }
  return path1[i-1];
}
Node* findLCA1(Node* root,int p , int q){
  if ( !root ) return nullptr;

  if ( root->data == p || root->data == q ) return root;

  Node* leftLCA = findLCA1(root->left,p,q);
  Node* rightLCA = findLCA1(root->right,p,q);

  if ( leftLCA && rightLCA ) 
    return root;
  if ( !leftLCA && !rightLCA ) 
    return nullptr;
  return leftLCA ? leftLCA : rightLCA ; 
}
int findLevel(Node* root , int k , int level ) {
  if ( !root ) return -1;
  if ( root->data == k ) return level;
  int left = findLevel(root->left,k,level+1);
  if ( left == -1 ) 
    return findLevel(root->right,k,level+1);
  return left;
}
int findDistance(Node* root, int a , int b ) {
  if ( !root ) return -1;
  Node* lca = findLCA1(root,a,b);
  int d1 = findLevel(root,a,0);
  int d2 = findLevel(root,b,0);
  if ( d1 == -1 || d2 == -1  ) 
    return -1;

  return d1 + d2;
}
void printPath(std::vector<int> &path){
  for ( auto i = path.begin();i != path.end();++i)
    std::cout<<*i<<' ';
  std::cout<<std::endl;
}
void printPaths(Node* root , std::vector<int> &path,int sum){
  if ( !root ) 
    return;
  // Add root to path.
  path.push_back(root->data);
  int subSum = sum - root->data;
  // if leaf and sum = 0 then print path
  if ( !root->left && !root->right && !subSum ){ 
    printPath(path);
  }
  else {
    // if not leaf then try for both subtrees.
    printPaths(root->left,path,subSum);
    printPaths(root->right,path,subSum);
  }
    path.pop_back();
}
void printAllleafPaths(Node* root , int sum ) {
  std::vector<int> path;
  printPaths(root,path,sum);
}
int main(){
  Tree t;
  t.buildTree();
  /* std::cout<<"InOrder   : ";
  inOrder(t.getRoot());
  std::cout<<std::endl;
  std::cout<<"InOrder1  : ";
  t.inOrder1();
  std::cout<<std::endl;
  std::cout<<"PreOrder  : ";
  preOrder(t.getRoot());
  std::cout<<std::endl;
  std::cout<<"PostOrder : ";
  postOrder(t.getRoot());
  std::cout<<std::endl;
  std::cout<<"levelOrder: ";
  t.levelOrder1();
  std::cout<<std::endl;
  std::cout<<"revlevelOrder: ";
  t.revLevelOrder();
  std::cout<<std::endl;
  std::cout<<std::endl;
  std::cout<<"DiagonalOrder: ";
  std::cout<<std::endl;
  t.diagonalOrder();
  std::cout<<std::endl;
  printDiagonal(t.getRoot());
  std::cout<<std::endl;
  printVertical(t.getRoot());
  std::cout<<"Height of the given tree is : "<<getHeight(t.getRoot())<<std::endl;
  int h = 0 ; 
  std::cout<<"Diameter of the given tree is : "<<diameter(t.getRoot(),h)<<std::endl;*/
  std::cout<<"levelOrder: ";
  std::cout<<std::endl;
  t.levelOrder2();
  std::cout<<std::endl;
  std::cout<<"leftView : "<<std::endl;;
  t.leftView();
  std::cout<<std::endl;
  std::cout<<"---------------------: ";
  std::cout<<std::endl;
  std::cout<<"rightView : "<<std::endl;;
  t.rightView();
  std::cout<<std::endl;
  std::cout<<"---------------------: ";
  std::cout<<std::endl;
  std::cout<<"topView : "<<std::endl;;
  topView(t.getRoot());
  std::cout<<"---------------------: ";
  std::cout<<std::endl;
  std::cout<<"bottomView : "<<std::endl;;
  bottomView(t.getRoot());
  std::cout<<"---------------------: ";
  std::cout<<std::endl;
  std::cout<<"Boundary anti-clockwise : "<<std::endl;;
  printBoundary(t.getRoot());
  std::cout<<std::endl;
  std::cout<<"---------------------: ";
  std::cout<<std::endl;
  std::cout<<"Total leaves nodes : "<<leavesCount(t.getRoot())<<std::endl;
  std::cout<<"---------------------: ";
  std::cout<<"LCA of 5 and 9 is : "<<findLCA(t.getRoot(),5,9)<<std::endl;
  std::cout<<"LCA of 5 and 9 is : "<<findLCA1(t.getRoot(),5,91)->data<<std::endl;
  std::cout<<"Distacne between 9 and 7 is : "<<findDistance(t.getRoot(),9,7)<<std::endl;
  printAllleafPaths(t.getRoot(),10);
  std::cout<<"Height of the tree is : "<<height(t.getRoot()->left)<<std::endl;
  std::cout<<"Height of the tree is : "<<getHeight(t.getRoot()->left)<<std::endl;
}
