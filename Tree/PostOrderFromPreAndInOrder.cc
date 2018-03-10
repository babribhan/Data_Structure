#include<iostream>
int search_key(int* arr , int key , int n ) {
for ( int i = 0 ; i < n ; ++i){
if (!(arr[i]^key)) 
  return i;
}
return -1;
}
void postOrder(int in[] , int pre[] , int n ) {
  int root = search_key(in,pre[0],n);
  // If left sub tree is not empty then print it.
  if (root != 0 ) 
    postOrder(in,pre+1,root);
  // If right sub tree is not empty then print it.
  if ( root != n-1 ) 
    postOrder(in+root+1,pre+root+1,n-root-1);
  std::cout<<pre[0]<<' ';
}
int main(){
  int in[] ={4, 2, 5, 1, 3, 6};
  int pre[] = {1, 2, 4, 5, 3, 6};
  int n = sizeof(in)/sizeof(in[0]);
  std::cout<<"Post Order traversal : ";
  postOrder(in,pre,n);
  std::cout<<std::endl;
}

