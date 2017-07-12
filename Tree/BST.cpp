#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct node {
	int data;
	struct node *left;
	struct node *right;
	struct node *parent;
};
struct node* newNode(int data) {
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return(node);
}
/* POST ORDER RECURSIVE TREE TRAVERSAL API */
void post_order(node* root) {
	if (root){
		post_order(root->left);
		post_order(root->right);
		cout<<root->data<<" ";
	}
}
/* IN ORDER RECURSIVE TREE TRAVERSAL API */
void in_order(node* root) {
	if (root){
		in_order(root->left);
		cout<<root->data<<" ";
		in_order(root->right);
	}
}
/* PRE ORDER RECURSIVE TREE TRAVERSAL API */
void pre_order(node* root) {
	if (root){
		cout<<root->data<<" ";
		pre_order(root->left);
		pre_order(root->right);
	}
}
/* POST ORDER ITERATIVE TREE TRAVERSAL API */
void post_order_i(node* root) {
	stack<node*> s;
	node *prev = NULL;
	do {
		while ( root){
			s.push(root);
			root = root->left;
		}
		while ( !root && !s.empty()){
			root = s.top();
			if ( !root->right || root->right == prev ){
				cout<<root->data<<" ";
				s.pop();
				prev = root;
				root = NULL;
			}
			else {
				root = root->right;
			} 
		}
	}while(!s.empty());
}
/* IN ORDER ITERATIVE TREE TRAVERSAL API */
void in_order_i(node* root){
	stack<node*> s;
	do {
		while(root){
			s.push(root);
			root = root->left;
		}
		if (!s.empty()){
			root = s.top();
			s.pop();
			cout<<root->data<<" ";
			root= root->right;
		}
	}while(!s.empty() || root );
}
/* PRE ORDER ITERATIVE TREE TRAVERSAL API */
void pre_order_i(node* root) {
	if (root){
		stack<node*> s; // Make a stack.
		node* temp = root;
		while(temp){
			std::cout<<temp->data<<" "; // Process Current Node.
			if ( temp->right) s.push(temp->right);  // If right child then put to stack.
			if ( temp->left ) { // If left child is then make current to left child.
				temp = temp->left;
			}
			else {
				if ( !s.empty()){  // If stack is not empty then take out top of stack and make it current.
					temp = s.top();
					s.pop();
				}
				else { // Else make current to NULL.
					temp = NULL;
				}
			}
		}        
	}
}
/* LEVEL ORDER TREE TRAVERSAL API */
void level_order(node* root)
{
	if ( root){
		queue<node*> q;
		q.push(root);
		while ( !q.empty()){
			node* temp = q.front();
			q.pop();
			cout<<temp->data<<" ";
			if ( temp->left) q.push(temp->left);
			if ( temp->right) q.push(temp->right);
		}
	}
}
int max_2(node *root){
    if ( !root->right ) return root->data;
    else
    return max_2(root->right);
}
int min_2(node *root){
	if ( !root->left) return root->data;
        else 
        return min_2(root->left); 
}
int max(node *root){
	while(root->right){
		root = root->right;
	}
	return root->data;
}
int min(node *root){
	while(root->left){
		root = root->left;
	}
	return root->data;
}
node* max_1(node *root){
	while(root->right){
		root = root->right;
	}
	return root;
}
node* min_1(node *root){
	while(root->left){
		root = root->left;
	}
	return root;
}
node* successor(node *x){
	if ( x->right) return min_1(x->right);
	node *temp_parent = x->parent;
	while(temp_parent && x == temp_parent->right){
		x = temp_parent;
		temp_parent = temp_parent->parent;
	}
	return temp_parent;
}
node* predecessor(node *x){

	if ( x->left) return max_1(x->left);
		node *temp = x->parent;
	while(temp && x == temp->left ) {
		x = temp;
		temp = temp->parent;
	}
	return temp;
}
node* search(node *root,int key){
	while(root &&  root->data != key){
         if ( key < root->data ) root = root->left;
         else root = root->right;
	}
	return root;
}
node*  insert_i(node *root , int data){
	node *curr = root,*prnt = root;
	while (curr){
		prnt = curr;
		if ( data < curr->data ) curr = curr->left;
		else 
			curr  = curr->right;
	}
	node *temp = newNode(data);
	if ( !root ) return temp;

	if ( prnt->data < data ){ 
		prnt->right = temp;
	}
	else {
		prnt->left = temp;
	}
	temp->parent = prnt;
	return root;
}
node*  insert(node *root , int data){
	if ( !root) return newNode(data);
	if ( root->data < data ){ 
		node *rchild  = insert(root->right,data);
		root->right = rchild;
                rchild->parent = root;
	}
	else {
		node *lchild  = insert(root->left,data);
		root->left = lchild;
                lchild->parent = root;
	}
	return root;
}
node* Delete(node *r , int key){
	if (!r) return NULL;
	if ( r->data > key) {
		r->left = Delete(r->left , key);
	}             
	else if ( r->data < key ) {
		r->right = Delete(r->right , key);
	}
	else {
		if (!r->right) return r->left;
		else if ( !r->left ) return r->right;
		node *minimum = min_1(r->right);
		r->data = minimum->data;
		r->right = Delete(r->right,r->data);
	}
	return r;
}
void testBST(node *root){
	cout<<"Pre Order  : "; pre_order(root); std::cout<<endl;
	cout<<"Pre Order2 : "; pre_order_i(root); std::cout<<endl; std::cout<<endl;
	cout<<"In Order   : "; in_order(root); std::cout<<endl;
	cout<<"In Order1  : "; in_order_i(root); std::cout<<endl; std::cout<<endl;
	cout<<"Post Order : "; post_order(root); std::cout<<endl;
	cout<<"Post Order1: "; post_order_i(root); std::cout<<endl; std::cout<<endl;
	cout<<"Level Order: "; level_order(root); std::cout<<endl;
        cout<<"Minimum Element in the tree is : "<<min(root)<<endl;
        cout<<"Maximum Element in the tree is : "<<max(root)<<endl;
        cout<<"Minimum Element in the tree is : "<<min_2(root)<<endl;
        cout<<"Maximum Element in the tree is : "<<max_2(root)<<endl;
        cout<<"Search For key 4  : "<<search(root,4)<<endl;
        cout<<"Search For key 14 : "<<search(root,14)<<endl;
        cout<<"Successor of node 9 : "<<successor(root->right->right)<<endl;
        cout<<"Predeccessor of node 4 : "<<predecessor(root->left)<<endl;
}

int main() {
  	struct node *root = newNode(6);  
        /* following is the tree after above statement 
	   6
	  / \
	 #   # 
	 */
	root->left        = newNode(4);
	root->right       = newNode(8);
        root->left->parent = root->right->parent = root;
	/* 2 and 3 become left and right children of 1
	   6
	  / \
	 4   8

	 */


	root->left->left    = newNode(2);
	root->left->right   = newNode(5);
        root->left->left->parent = root->left->right->parent = root->left;
	root->right->left   = newNode(7);
	root->right->right  = newNode(9);
        root->right->left->parent = root->right->right->parent = root->right;
    
        
	root->left->left->left    = newNode(1);
	root->left->left->right   = newNode(3);

        root->left->left->left->parent = root->left->left->right->parent = root->left->left;
	/* 4 becomes left child of 2
           6
	  /\
	 4  8
	/\  /\
       2  5 7 9
      /\       \
     1  3       14
               /  \
              11  16
                   \  
                   19
	 */
        testBST(root);
        root  = insert(root,14);
        root  = insert(root,11);
        testBST(root); 
        root  = insert_i(root,16);
        root  = insert_i(root,19);
        testBST(root); 
        cout<<"Search For key 14 : "<<search(root,14)<<endl;
        cout<<"Successor of node 14 : "<<successor(search(root,14))<<endl;
        cout<<"Predeccessor of node 14 : "<<predecessor(search(root,14))<<endl;
        cout<<"Successor of node 19 : "<<successor(search(root,19))<<endl;
        cout<<"Predeccessor of node 19 : "<<predecessor(search(root,19))<<endl;
	root = Delete(root,3); // Delete Node with no left or right child.
	root = Delete(root,9); // Delete Node with only right child.
	root = Delete(root,4); // Delete Node having both left & right child.
	root = Delete(root,1); 
	testBST(root); 
	return 0;
}
