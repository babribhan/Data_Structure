void Tree::levelOrder2(){
  if (root){
    std::queue<Node*> q1,q2;
    q1.push(root);
    while (!q1.empty() || !q2.empty()){
      while(!q1.empty()){
        Node *temp = q1.front();q1.pop();
        std::cout<<temp->data<<' ';
        if( temp->left) q2.push(temp->left);
        if( temp->right) q2.push(temp->right);
      }
      std::cout<<std::endl;
      while(!q2.empty()){
        Node *temp = q2.front();q2.pop();
        std::cout<<temp->data<<' ';
        if( temp->left) q1.push(temp->left);
        if( temp->right) q1.push(temp->right);
      }
      std::cout<<std::endl;
    }
  }
}
void Tree::levelOrder1(){
  if (root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      Node* temp = q.front();q.pop();
      std::cout<<temp->data<<' ';
      if( temp->left) q.push(temp->left);
      if( temp->right) q.push(temp->right);
    }
  }
}
void Tree::levelOrder(){
  if (root){
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      int n = q.size();
      for ( int i = 0 ; i < 1 ; ++i){  // Only Print the current level nodes.
        Node* temp = q.front();q.pop();
        std::cout<<temp->data<<' ';
        if( temp->left) q.push(temp->left);
        if( temp->right) q.push(temp->right);
      }
      std::cout<<std::endl;
    }
  }
}
