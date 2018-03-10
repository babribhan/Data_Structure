void revLevelOrder(){
  if (root){
    Node* temp = root;
    std::queue<Node*> q;
    std::stack<Node*> s;
    q.push(root);
    while(!q.empty()){
      temp = q.front();q.pop();
      s.push(temp);
      if( temp->left) q.push(temp->left);
      if( temp->right) q.push(temp->right);
    }
    while (!s.empty()){
      std::cout<<s.top()->data<<' ';
      s.pop();
    }
  }
}
