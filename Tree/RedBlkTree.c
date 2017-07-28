/* Author: Babribhan */
#include <stdio.h>
#include <stdlib.h>
#define RED	1
#define BLACK	2

struct rb_node {
	int key;
	struct rb_node *left, *right, *p;
	int color;
};

typedef struct rb_node *PNODE;
struct rb_node NIL;
PNODE PNIL = &NIL;

int height(PNODE x){
	if (x == PNIL) return -1;
	int left_h  = height(x->left);
	int right_h = height(x->right);
	return(left_h > right_h ? left_h+1 : right_h + 1 ) ; 
}
void inorder(PNODE x) {
	if (x != PNIL) {
		inorder(x->left);
		printf("%d ", x->key);
		inorder(x->right);
	}
}

PNODE search(PNODE root, int k) {
	if (root == PNIL || root->key == k)
		return root;
	if (k < root->key)
		return search(root->left, k);
	else
		return search(root->right, k);
}

PNODE minimum(PNODE root) {
	while (root->left != PNIL)
		root = root->left;
	return root;
}

PNODE maximum(PNODE root) {
	while (root->right != PNIL)
		root = root->right;
	return root;
}

PNODE successor(PNODE root, int x) {
	PNODE temp = search(root, x);
	if (temp == PNIL) {
		printf("%d not in tree\n", x);
		return temp;
	}
	if (temp->right != PNIL)
		return minimum(temp->right);
	PNODE y = temp->p;
	while (y != PNIL && temp == y->right) {
		temp = y;
		y = y->p;
	}
	return y;
}

PNODE predecessor(PNODE root, int x) {
	PNODE temp = search(root, x);
	if (temp == PNIL) {
		printf("%d not in tree\n", x);
		return temp;
	}
	if (temp->left != PNIL)
		return maximum(temp->left);
	PNODE y = temp->p;
	while (y != PNIL && temp == y->left) {
		temp = y;
		y = y->p;
	}
	return y;
}
void left_rotate(PNODE *root, PNODE x) {
	PNODE y = x->right;
	x->right = y->left;
	if (y->left != PNIL)
		y->left->p = x;
	y->p = x->p;
	if (x->p == PNIL)
		*root = y;
	else if (x->p->left == x)
		x->p->left = y;
	else
		x->p->right = y;
	y->left = x;
	x->p = y;
}

void right_rotate(PNODE *root, PNODE y) {
	PNODE x = y->left;
	y->left = x->right;
	if (x->right != PNIL)
		x->right->p = y;
	x->p = y->p;
	if (y->p == PNIL)
		*root = x;
	else if (y->p->left == y)
		y->p->left = x;
	else
		y->p->right = x;
	x->right = y;
	y->p = x;
}

void rbinsert_fixup(PNODE *root, PNODE z) {
	while (z->p->color == RED) {
		if (z->p == z->p->p->left) {  // If z's parent is left child of grand parent of z.
			PNODE y = z->p->p->right; // Uncle is right child.
			if (y->color == RED) {  //If Uncle is Red.
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {  // Uncle is not red.
				if (z == z->p->right) {  // And z is right child.
					z = z->p;
					left_rotate(root,z);  // Perform left rotation.
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				right_rotate(root,z->p->p); 
			}
		}
		else {
			PNODE y = z->p->p->left;
			if (y->color == RED) {
				z->p->color = BLACK;
				y->color = BLACK;
				z->p->p->color = RED;
				z = z->p->p;
			}
			else {
				if (z == z->p->left) {
					z = z->p;
					right_rotate(root,z);
				}
				z->p->color = BLACK;
				z->p->p->color = RED;
				left_rotate(root,z->p->p);
			}
		}
	}
	(*root)->color = BLACK;
}

void rbinsert(PNODE *root, int z) {
	PNODE Z = (PNODE) malloc(sizeof(struct rb_node));
	Z->key = z;
	PNODE y = PNIL;
	PNODE x = *root;
	while (x != PNIL) {
		y = x;
		if (Z->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	Z->p = y;
	if (y == PNIL)
		*root = Z;
	else if (Z->key < y->key)
		y->left = Z;
	else
		y->right = Z;
	Z->left = PNIL;
	Z->right = PNIL;
	Z->color = RED;
	rbinsert_fixup(root,Z);
}

void rbtransplant(PNODE *root, PNODE u, PNODE v) {
	if (u->p == PNIL)
		*root = v;
	else if (u == u->p->left)
		u->p->left = v;
	else
		u->p->right = v;
	v->p = u->p;
}

void rbdelete_fixup(PNODE *root, PNODE x) {
	while (x != *root && x->color == BLACK) {
		if (x == x->p->left) {
			PNODE w = x->p->right;
			if (w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				left_rotate(root,x->p);
				w = x->p->right;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
				if (w->right->color == BLACK) {
					w->left->color = BLACK;
					w->color = RED;
					right_rotate(root,w);
					w = x->p->right;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->right->color = BLACK;
				left_rotate(root,x->p);
				x = *root;
			}
		}
		else {
			PNODE w = x->p->left;
			if (w->color == RED) {
				w->color = BLACK;
				x->p->color = RED;
				right_rotate(root,x->p);
				w = x->p->left;
			}
			if (w->left->color == BLACK && w->right->color == BLACK) {
				w->color = RED;
				x = x->p;
			}
			else {
				if (w->left->color == BLACK) {
					w->right->color = BLACK;
					w->color = RED;
					left_rotate(root,w);
					w = x->p->left;
				}
				w->color = x->p->color;
				x->p->color = BLACK;
				w->left->color = BLACK;
				right_rotate(root,x->p);
				x = *root;
			}
		}
	}
	x->color = BLACK;
}

void rbdelete(PNODE *root, int z) {
        // Step 1 . Search For the Node.
	PNODE Z = search(*root, z);
	if (Z == PNIL) {
		printf("Node to be deleted not found\n");
		return;
	}
	PNODE y = Z;
	int yoc = y->color; // Store its original color.
	PNODE x;
	if (Z->left == PNIL) {
		x = Z->right;
		rbtransplant(root,Z,Z->right);
	}
	else if (Z->right == PNIL) {
		x = Z->left;
		rbtransplant(root,Z,Z->left);
	}
	else {
		y = minimum(Z->right);
		yoc = y->color;
		x = y->right;
		if (y->p == Z)
			x->p = y;
		else {
			rbtransplant(root,y,y->right);
			y->right = Z->right;
			y->right->p = y;
		}
		rbtransplant(root,Z,y);
		y->left = Z->left;
		y->left->p = y;
		y->color = Z->color;
	}
	if (yoc == BLACK)
		rbdelete_fixup(root,x);
}

int main()
{
	NIL.left = NIL.right = NIL.p = PNIL;
	NIL.color = BLACK;
	PNODE tree = PNIL;
	int n;
	while (1) {
		printf("1.Insert\n2.Search\n3.Inorder Walk\n4.Minimum\n5.Maximum\n6.Successor\n7.Predecessor\n8.Delete\n9.Height\n10.Exit\n");
		scanf("%d", &n);
		switch(n){
			case 1 :  {
					  printf("Enter any number:\n");
					  int num;
					  scanf("%d", &num);
					  rbinsert(&tree, num);
				  }
				  continue;
			case 2 : {
					 printf("Enter the number to be search\n");
					 int num;
					 scanf("%d", &num);
					 if (search(tree, num) == PNIL)
						 printf("%d not found\n", num);
					 else
						 printf("%d found\n", num);
				 }
				 continue;
			case 3 : {
					 inorder(tree);
					 printf("\n");
				 }
				 continue;
			case 4 : 
				 printf("%d\n", minimum(tree)->key);
				 continue;
			case 5 : 
				 printf("%d\n", maximum(tree)->key);
				 continue;
			case 6 : { 
					 printf("Enter the number whose successor needs to be found\n");
					 int num;
					 scanf("%d", &num);
					 PNODE t = successor(tree, num);
					 if (t != NULL)
						 printf("%d\n", t->key);
				 }
				 continue;
			case 7 : {
					 printf("Enter the number whose predecessor needs to be found\n");
					 int num;
					 scanf("%d", &num);
					 PNODE t = predecessor(tree, num);
					 if (t != NULL)
						 printf("%d\n", t->key);
				 }
				 continue;
			case 8 : {
					 printf("Enter the number to be deleted\n");
					 int num;
					 scanf("%d", &num);
					 rbdelete(&tree, num);
				 }
				 continue;
			case 9 : 
				 printf("%d\n",height(tree));
				 continue;
			default: 
				 exit(0);
		}
	}
	return 0;
}
