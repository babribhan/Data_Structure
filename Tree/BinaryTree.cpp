#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct node {
        int data;
        struct node *left;
        struct node *right;
};
struct node* newNode(int data) {
        struct node* node = (struct node*)malloc(sizeof(struct node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
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
int main() {
        struct node *root = newNode(1);
        /* following is the tree after above statement
           1
          / \
         #   #
         */
        root->left        = newNode(2);
        root->right       = newNode(3);
        /* 2 and 3 become left and right children of 1
           1
          / \
         2   3

         */


        root->left->left    = newNode(4);
        root->left->right   = newNode(5);
        root->right->left   = newNode(6);
        root->right->right  = newNode(7);


        root->left->left->left    = newNode(8);
        root->left->left->right   = newNode(9);

                /* 4 becomes left child of 2
           1
          /\
         2  3
        /\  /\
       4  5 6 7
      /\
     8  9
         */
        cout<<"Pre Order  : ";
        pre_order(root);
        std::cout<<endl;
        cout<<"Pre Order2 : ";
        pre_order_i(root);
        std::cout<<endl;
        std::cout<<endl;
        cout<<"In Order   : ";
        in_order(root);
        std::cout<<endl;
        cout<<"In Order1  : ";
        in_order_i(root);
        std::cout<<endl;
        std::cout<<endl;
        cout<<"Post Order : ";
        post_order(root);
        std::cout<<endl;
        cout<<"Post Order1: ";
        post_order_i(root);
        std::cout<<endl;
        std::cout<<endl;
        cout<<"Level Order: ";
        level_order(root);
        std::cout<<endl;
        return 0;
}
