#include<iostream>
#include<cstdio>
using namespace std;
struct node {
  int key;
  struct node *left,*right;
};
node* removeOutRange(node* root , int min , int max ) {
  if ( !root ) return root;
  root->left = removeOutRange(root->left,min,max);
  root->right = removeOutRange(root->right,min,max);

  if ( root->key > max ) {
    node *lChild = root->left;
    delete root;
    return lChild;
  }
  if ( root->key < min ) {
    node *rChild = root->right;
    delete root;
    return rChild;
  }
  return root;
}
node* newNode(int v ) {
  node* t = new node;
  t->key = v;
  t->left = t->right = NULL;
  return t;
}
node* insert(node* root,int v ) {
  if ( !root ) 
    return newNode(v);
  if ( root->key > v ) 
    root->left = insert(root->left,v);
  else 
    root->right = insert(root->right,v);
  return root;
}
void inorder(node* root ) {
  if ( root){
    inorder(root->left);
    cout<<root->key<<' ';
    inorder(root->right);
  }
}
int main()
{
  node* root = NULL;
  root = insert(root, 6);
  root = insert(root, -13);
  root = insert(root, 14);
  root = insert(root, -8);
  root = insert(root, 15);
  root = insert(root, 13);
  root = insert(root, 7);
  cout << "Inorder traversal of the given tree is: ";
  inorder(root);
  root = removeOutRange(root, -10, 13);
  cout << "\nInorder traversal of the modified tree is: ";
  inorder(root);

  return 0;
}
