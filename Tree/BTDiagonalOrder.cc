void diagonalOrder(){
  if (!root) return ;
  std::queue<Node*> q;
  q.push(root);
  q.push(nullptr); // Push delimiter.
  while (!q.empty()){
    Node* temp = q.front();q.pop();
    if (!temp) { // if current is null then insert null for another diagonal and print new Line.
      if ( q.empty())
        return;
      std::cout<<std::endl;
      q.push(nullptr); // for next diagonal.
    }
    else {
      while ( temp ) {
        std::cout<<temp->data<<' ';
        if ( temp->left)
          q.push(temp->left);
        temp = temp->right;
      }
    }
  }
}
