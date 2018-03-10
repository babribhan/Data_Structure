int leavesCount(Node* root){
    if (!root )
          return 0;
      if ( !root->left && !root->right ) return 1;
        return ( leavesCount(root->left) + leavesCount(root->right));
}
