void printPath(std::vector<int> &path){
  for ( auto i = path.begin();i != path.end();++i)
    std::cout<<*i<<' ';
  std::cout<<std::endl;
}
void printPaths(Node* root , std::vector<int> &path,int sum){
  if ( !root )
    return;
  // Add root to path.
  path.push_back(root->data);
  int subSum = sum - root->data;
  // if leaf and sum = 0 then print path
  if ( !root->left && !root->right && !subSum ){
    printPath(path);
  }
  else {
    // if not leaf then try for both subtrees.
    printPaths(root->left,path,subSum);
    printPaths(root->right,path,subSum);
  }
  path.pop_back();
}
void printAllleafPaths(Node* root , int sum ) {
  std::vector<int> path;
  printPaths(root,path,sum);
}

