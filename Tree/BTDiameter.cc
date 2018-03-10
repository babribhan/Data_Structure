int max ( int a , int b){ 
  return a>b ? a : b;
}
int diameter(Node* root , int& h){
  int leftH = 0,rightH = 0;
  int lDia = 0 , rDia = 0 ;
  if ( !root ) {
    h = 0;
    return 0;
  }
  lDia = diameter(root->left,leftH);
  rDia = diameter(root->right,rightH);
  h = leftH > rightH ? leftH+1 : rightH+1;
  return max(rightH + leftH + 1, max(lDia,rDia));
}
