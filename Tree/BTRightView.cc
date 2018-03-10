void rightView(){
  if (root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      int n = q.size();
      std::cout<<q.back()->data<<' ';
      for ( int i = 0 ; i < n ; ++i){  // Only Print the current level nodes.
        Node* temp = q.front();q.pop();
        if( temp->left) q.push(temp->left);
        if( temp->right) q.push(temp->right);
      }
    }
  }
}
