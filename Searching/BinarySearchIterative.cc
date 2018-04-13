bool binarySearch1(int arr[],int start , int end, int key){
  while( end >= start ) {
    int mid = start +((end-start)>>1);
    if (!(arr[mid]^key))
      return true;
    else if ( arr[mid] > key )
      end = mid-1;
    else
      start = mid+1;
  }
  return false;
}
