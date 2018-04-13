// LINEAR SEARCH WITH O(n2) comparisons.
bool LinearSearch(int arr[],int n, int key){
for ( int i = 0 ; i < n ; ++i){
if(!(key^arr[i])){
return true;
}
}
return false;
}
// SENTINAL SEARCH OR COMPARISON OPTIMISED LINEAR SEARCH. O(n) comparisons

bool LinearSearch(int arr[],int n, int key){
  if (!n){ 
    cout<<"ERROR : Empty Array."<<endl;
    exit(1);
  }
  // SENTINAL CODE STARTS
  int temp = arr[n-1];
  if (!(temp^key))
    return true;
  else
    arr[n-1] = key;
  // SENTINAL CODE ENDS  
  int i = 0;
  while(1){
    if(!(arr[i]^key)){
      break;
    }
    i++;
  }
  arr[n-1] = temp;
  return (i != (n-1));
}
