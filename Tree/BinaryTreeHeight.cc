int getHeight(Node* root){
  if ( !root) return 0;
  int leftHeight = getHeight(root->left);
  int rightHeight = getHeight(root->right);
  return  ( leftHeight > rightHeight ? leftHeight+1 : rightHeight+1 );
}
int height(Node* root ) { 
  if ( !root ) return 0;
  std::queue<Node*> q;
  q.push(root);
  int h = 0 ; 
  while ( !q.empty()){
    int size  = q.size();
    while ( size--){
      Node* temp = q.front();q.pop();
      if (temp->left) q.push(temp->left);
      if (temp->right) q.push(temp->right);
    }   
    ++h;
  }
  return h;
}

