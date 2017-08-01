#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
typedef struct node{
	struct node *left,*right,*parent;
	int height;
	int key;
}NODE;
typedef NODE* PNODE;
int max(int a, int b) {
	return (a > b)? a : b;
}
int height(PNODE N ) {
	if (N == NULL)
		return 0;
	return N->height;
}
PNODE newNode(int key) {
	PNODE node   = new NODE; 
	node->key    = key;
	node->left   = NULL;
	node->right  = NULL;
	node->parent = NULL;
	node->height = 1;  // new node is initially added at leaf
	return(node);
}
PNODE rightRotate(PNODE x){
	PNODE y = x->left;
	x->left = y->right;
	if ( x->left ) x->left->parent = x;
	y->parent = x->parent;
	if ( x->parent->left == x ) x->parent->left = y;
	else x->parent->right = y;
	// Perform rotation
	y->right = x;
	x->parent = y;
	// Update heights
	y->height = max(height(y->left),height(y->right))+1;
	x->height = max(height(x->left),height(x->right))+1;
	// Return new root
	return x;
	}
PNODE leftRotate(PNODE x ){ 
	PNODE y = x->right;
	x->right = y->left;
	if (x->right ) x->right->parent = x;
	y->parent = x->parent;
	if (  x == x->parent->left ) x->parent->left = y;
	else x->parent->right = y;
	// Perform rotation
	y->left = x;
	x->parent  = y;
	//  Update heights
	y->height = max(height(y->left),height(y->right))+1;
	x->height = max(height(x->left),height(x->right))+1;
	// Return new root
	return y;
	}
int getBalance(PNODE N) {
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}
PNODE insert(PNODE node, int key) {
	if (!node) return(newNode(key));
	if ( key < node->key ) {
		PNODE lchild = insert(node->left , key);
		node->left = lchild;
		lchild->parent = node;
	}
	else if ( key > node->key) {
		PNODE rchild =insert(node->right,key);
		node->right = rchild;
		rchild->parent = node;
	}
	else 
		return node;
	node->height = max(height(node->left),height(node->right))+1;
	int balance = getBalance(node);
	/*        cout<<"node.bal = "<<balance<<endl;
		  cout<<"Node height ="<<node->height<<endl;
		  cout<<"TL height = "<<height(node->left)<<endl;
		  cout<<"RL height = "<<height(node->right)<<endl;
	 */      
	// there are 4 cases

	// Left Left Case
	if (balance > 1 && key < node->left->key) return rightRotate(node);
	// Right Right Case
	if (balance < -1 && key > node->right->key) return leftRotate(node);
	// Left Right Case
	if (balance > 1 && key > node->left->key) {
		node->left =  leftRotate(node->left);
		return rightRotate(node);
	}
	// Right Left Case
	if (balance < -1 && key < node->right->key) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
void preOrder(PNODE root) {
	if(root != NULL) {
		preOrder(root->left);
		printf("%d(%d) ", root->key,root->height);
		preOrder(root->right);
	}
}

void level_order(PNODE root) {
	if (root){
		queue<PNODE> q;
		q.push(root);
		while (1){
			int count = q.size();
			if ( !count) break;
			while(count > 0 ) {
				PNODE temp = q.front();
				q.pop();
				cout<<temp->key;
				if ( temp->left) q.push(temp->left);
				if ( temp->right) q.push(temp->right);
				count--;
			}
			cout<<endl;
		}
	}
	cout<<"-----------------"<<endl;
} 
/* Drier program to test above function*/
int main() {
	PNODE root = NULL;
	/* Constructing tree given in the above figure */
	root = insert(root, 10);
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

	/* The constructed AVL Tree would be
	   30
	   /  \
	   20   40
	   /  \     \
	   10  25    50
	 */

	printf("Preorder traversal :");
	preOrder(root);
	printf("Height of root is %d \n",height(root)); 
	return 0;
}
