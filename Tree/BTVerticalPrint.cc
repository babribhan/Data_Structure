void verPrint(Node* root , int d , std::map<int,std::vector<int> >& m){
  if(!root)
    return;
  // Store all nodes of same diagonal together.
  m[d].push_back(root->data);
  // if left child exists then decrease the Horizontal distance.
  verPrint(root->left,d-1,m);
  // if right child exists then increase teh Horizontal distance.
  verPrint(root->right,d+1,m);
}
void printVertical(Node* root){
  std::map<int,std::vector<int> > m;
  verPrint(root,0,m);
  std::cout<<"Vertical Traversal of the Tree is : "<<std::endl;
  for ( auto it = m.begin(); it != m.end();++it){
    for ( int i = 0 ; i < it->second.size();++i)
      std::cout<<it->second[i]<<' ';
    std::cout<<std::endl;
  }
}
