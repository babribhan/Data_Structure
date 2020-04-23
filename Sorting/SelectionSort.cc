/*  The Selection sort algorithm is based on the idea of finding the minimum or maximum element 
    in an unsorted array and then putting it in its correct position in a sorted array.
    
    Time Complexity:
    To find the minimum element from the array of N elements,N-1 comparisons are required. 
    After putting the minimum element in its proper position, the size of an unsorted array reduces
    to N-1 and then N-2 comparisons are required to find the minimum in the unsorted array.
    Therefore (N-1) + (N-2) +....+ 1 = (N.(N-1))/2 comparisons and N swaps result in the overall complexity of .O(N2)
*/

void selectionSort (int arr[], int n )
{
  int minimum; // hold the position of minimum element in array.
  for ( int i = 0; i < n;++i)
  {
    minimum = i;  // Assume first element of unsorted array to be min.
    for ( int j = i+1; j <n;++j)
    {
      if ( arr[j] < arr[minimum])
        minimum = j;
    }
    // Put the minimum element to it's proper position.
    std::swap(arr[i],arr[minimum]);
  }
}

