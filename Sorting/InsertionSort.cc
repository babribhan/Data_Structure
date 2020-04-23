// Insertion Sort Algorithm

void insertion_sort (int arr[], int n )
{
  for ( int i = 0; i < n;++i)
  {
    int temp = arr[i];
    int j = i;
    while (j > 0 && temp < arr[j-1])
    {
      arr[j] = arr[j-1];
      j--;
    }
    arr[j] = temp;
  }
}
