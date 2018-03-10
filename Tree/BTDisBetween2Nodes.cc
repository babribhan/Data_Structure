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
