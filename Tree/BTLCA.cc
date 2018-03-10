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

