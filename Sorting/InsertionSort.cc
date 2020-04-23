// Insertion Sort Algorithm
// Best Case Complexity = Avg Case Complexity = Worst Case Complexity = O(N2)
// 
void insertion_sort (int *Ar, int size)
{
  if ( size == 0 || size == 1 || !Ar ) return;
  
  int element_chosen, sorted_high_index;
  for ( int unsorted_low_index = 1; unsorted_low_index < size; unsorted_low_index++ )  //traverse the unsorted list from left.
  {
    element_chosen = Ar[unsorted_low_index];
    sorted_high_index = unsorted_low_index;
    while ( sorted_high_index > 0 && element_chosen < Ar[sorted_high_index-1] ) //traverse the sorted list from right.
    {
        Ar[sorted_high_index] = Ar[sorted_high_index-1];
        sorted_high_index--;
    }
     Ar[sorted_high_index] = element_chosen;
      
  }
  
}
