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
void bottomView(Node* root){
  std::map<int,std::vector<int> > m;
  verPrint(root,0,m);
  for ( auto it = m.begin(); it != m.end();++it)
    std::cout<<it->second.back()<<' ';
  std::cout<<std::endl;
}
  
