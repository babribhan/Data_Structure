bool binarySearch(int arr[],int start , int end, int key){
  if ( end >= start ) {
    int mid = start +((end-start)>>1);
    if (!(arr[mid]^key))
      return true;
    else if ( arr[mid] > key )
      return binarySearch(arr,start,mid-1,key);
    else
      return binarySearch(arr,mid+1,end,key);
  }
  return false;
}
