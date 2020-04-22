/* Bubble sort is based on the idea of repeatedly comparing pairs of adjacent elements 
   and then swapping their positions if they exist in the wrong order.
   
   Complexity:  The complexity of bubble sort is O(n2) in both worst and average cases,
   because the entire array needs to be iterated for every element.
   
   Optimizaton: Bubble Sort can be usefull of Already or partially Sorted array in which 
   case it will take O(n) time.
*/

void swap (int &a, int &b)
{
  if (a^b)
  {
    a= a^b;
    b= a^b;
    a= a^b;
  }
}
void bubbleSortOpt (int arr[], int n ) 
{
  bool swapped = false;
  for ( int i = 0; i < n;++i)
  {
    for ( int j = 0; j <n-i;++j)
    {
      if ( arr[j] > arr[j+1])
      {
        swap (arr[j],arr[j+1]);
        swapped = true;
      }
    }
    if(!swapped) // if swapped is false then the array is Already Sorted.
      return ;
  }
}
