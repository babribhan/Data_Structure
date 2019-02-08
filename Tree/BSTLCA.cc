Node* findLCA1(Node* root,int n1 , int n2){
while ( root ) {
if ( n1 < root->data && n2 < root->data ) // lca lies in left subtree.
  root = root->left;
else if ( n1 > root->data && n2 > root->data ) // lca lies in right subtree.
  root = root->right;
  else 
    break;
}
  return root;
}

