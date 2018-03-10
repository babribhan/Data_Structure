void diaPrint(Node* root , int d , std::map<int,std::vector<int> >& dia){
  if(!root)
    return;
  // Store all nodes of same diagonal together.
  dia[d].push_back(root->data);
  //     // if left child exists then increase the vertical distance.
  diaPrint(root->left,d+1,dia);
  // if right child exists then the vertical distance remains same.
  diaPrint(root->right,d,dia);
}
void printDiagonal(Node* root){
  std::map<int,std::vector<int> > diagonal;
  diaPrint(root,0,diagonal);
  std::cout<<"Diagonal Traversal of the Tree is : "<<std::endl;
  for ( auto it = diagonal.begin(); it != diagonal.end();++it){
    for ( auto itr = it->second.begin(); itr != it->second.end();++itr){
      std::cout<<*itr<<' ';
    }
    std::cout<<std::endl;
  }
}
