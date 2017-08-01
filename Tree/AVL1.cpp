#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <queue>
using namespace std;
int max(int a, int b) { return a > b ? a : b; }

typedef struct node
{
	int val;
	struct node *left;
	struct node *right;
	struct node *parent;
	int height;
} node_t;
typedef node_t* pnode_t;
pnode_t find(pnode_t root, int val) {
	if (root == NULL) return NULL;
	if (val < root->val)
		return find(root->left, val);
	else if (val > root->val)
		return find(root->right, val);
	else
		return root;
}

pnode_t min(pnode_t root)
{

while(root->left)
{
root = root->left;
}
return root;
}

int height(pnode_t root) {
	return root ? root->height : 0;
}
int get_balance(pnode_t n){
	return (height(n->left) - height(n->right));
} 
void up_height(pnode_t root)
{
	root->height = 1 + max(height(root->left), height(root->right));
}

/* We can assume node->left is non-null due to how this is called */
pnode_t rotate_right(pnode_t root)
{
	/* Fix pointers */
	pnode_t new_root = root->left;
	if (root->parent)
	{
		if (root->parent->left == root) root->parent->left = new_root;
		else root->parent->right = new_root;
	}
	new_root->parent = root->parent;
	root->parent = new_root;
	root->left = new_root->right;
	if (root->left) root->left->parent = root;
	new_root->right = root;

	/* Fix heights; root and new_root may be wrong. Do bottom-up */
	up_height(root);
	up_height(new_root);
	return new_root;
}

/* We can assume node->right is non-null due to how this is called */
pnode_t rotate_left(pnode_t root)
{
	/* Fix pointers */
	pnode_t new_root = root->right;
	if (root->parent)
	{
		if (root->parent->right == root) root->parent->right = new_root;
		else root->parent->left = new_root;
	}
	new_root->parent = root->parent;
	root->parent = new_root;
	root->right = new_root->left;
	if (root->right) root->right->parent = root;
	new_root->left = root;

	/* Fix heights; root and new_root may be wrong */
	up_height(root);
	up_height(new_root);
	return new_root;
}

pnode_t make_node(int val, pnode_t parent)
{
	pnode_t n = (pnode_t)malloc(sizeof(node_t));
	n->val = val;
	n->parent = parent;
	n->height = 1;
	n->left = NULL;
	n->right = NULL;
	return n;
}

bool case_ll(pnode_t n){
return height(n->left->left) > height(n->left->right);
}
bool case_rr(pnode_t n){
return height(n->right->right) > height(n->right->left);
}
bool left_subtree_insert(pnode_t n){
return get_balance(n) > 1;
}
bool right_subtree_insert(pnode_t n){
return get_balance(n) < -1;
}
pnode_t balance(pnode_t root) {
	if (left_subtree_insert(root)) {// Insertion in left subtree of root.
		if (case_ll(root)){ // CASE : LL
			root = rotate_right(root);
		}
		else { // CASE : LR
			rotate_left(root->left);
			root = rotate_right(root);
		}
	}
	else if (right_subtree_insert(root)){ // insertion in right subtree of root.
		if (case_rr(root)) { // CASE : RR
			root = rotate_left(root);
		}
		else { // CASE : RL
			rotate_right(root->right);
			root = rotate_left(root);
		}
	}
	return root;
}
pnode_t tree_balance(pnode_t n){
	do {
		n  = n->parent;
		up_height(n);
		n = balance(n);
	} while (n->parent);
	return n;
}
pnode_t insert(pnode_t root, int val) {
	// STEP 1 . INSERT NEW NODE.
	pnode_t current = root;
	pnode_t prnt = NULL;
	while(current ) {
		prnt = current;
		if ( val < current->val) current = current->left;
		else current = current->right;
	}
	current = make_node(val,NULL);
	if (!root) return current;
	if ( prnt->val < val ) prnt->right = current;
	else prnt->left = current;
	current->parent = prnt;
	// STEP 2 . UPDATE HEIGHT OF ALL ANCESTORS AND IF UNBALANCE THEN BALANCE THE TREE. 
	return tree_balance(current);	
}
pnode_t tree_balance_del(pnode_t root){
	if ( get_balance(root) == 2 ) {
		if ( get_balance(root->left) ==-1 ) {
			return rotate_right(root);
		}
		else if ( get_balance(root->left) == 1 ) {
			rotate_left(root->left);
			root = rotate_right(root);
		}
	}
	if ( get_balance(root) == -2 ) {
		if ( get_balance(root->right) ==-1 ) {
			return rotate_left(root);
		}
		else if ( get_balance(root->right) == 1 ) {
			rotate_right(root->right);
			root = rotate_left(root);
		}
	}
	return root;
}
pnode_t del_node(pnode_t root, int val){
	pnode_t temp;
	if ( !root ) return root;
	if ( root->val < val ) {
		root->right = del_node(root->right , val);
	}
	else if ( root->val > val ) {
		root->left = del_node(root->left,val);
	}
	else {
		if ( !root->left && root->right) {
			temp = root->right;
			*root = *temp;
			delete temp;
		}
		else if(!root->right && root->left ) {
			temp = root->left;
			*root = *temp;
			delete temp;
		}
		else if ( !root->left && !root->right ) {
			temp = root->left;
			temp = root;
			root = NULL;
		}
		else {
			temp = min(root->right);
			root->val = temp->val;
			root->right = del_node(root->right,temp->val); 
		}
	}
	if ( !root) return root;
	return tree_balance_del(root);
}
void level_order(pnode_t root) {
	if (root){
		queue<pnode_t> q;
		q.push(root);
		while (1){
			int count = q.size();
			if ( !count) break;
			while(count > 0 ) {
				pnode_t temp = q.front();
				q.pop();
				cout<<temp->val<<" ";
				if ( temp->left) q.push(temp->left);
				if ( temp->right) q.push(temp->right);
				count--;
			}
			cout<<endl;
		}
	}
	cout<<"-----------------"<<endl;
}
void inorder(pnode_t r){
if(r){
inorder(r->left);
cout<<r->val<<" ";
inorder(r->right);
}
}
int main(int argc, char *argv[])
{
	pnode_t root = make_node(10, NULL);
	level_order(root);
	root = insert(root, 20);
	level_order(root);
	root = insert(root, 30);
	level_order(root);
	root = insert(root, 40);
	level_order(root);
	root = insert(root, 50);
	level_order(root);
	root = insert(root, 45);
	level_order(root);
	root = insert(root, 55);
	level_order(root);
	root = insert(root, 75);
	level_order(root);
	root = insert(root, 65);
	level_order(root);
        root = del_node(root,65);
	level_order(root);
        inorder(root);
	//    print_tree(root);
	return 0;
}
