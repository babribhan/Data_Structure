// Insertion Sort Algorithm
#include <stdio.h>
void swap(int *a , int *b)
{
  *a = *a^*b;
  *b = *a^*b;
  *a = *a^*b;
}

void InsertionSort(int *list , int n , int order)
{
  // order 1 means sort in decresing order.
  // order 0 means sort in increasing order.
  int i , j,key ;
  for ( i = 0 ; i < n ; i++)
  {
    key = list[i]; // current element is the key
    j =i-1;
    while(j >= 0 &&  (order ? list[j] < key :list[j] > key))  // find the proper location in sortedlist of [0- i-1]
    {
      list[j+1] = list[j];  // move element right
      --j;
    }
    list[j+1] =key;   // place the key to proper location in sorted list.
  }
}
/* Driver Program to test above functions */
int main()
{
  // 0 means unassigned cells
  int list[] = {3, 0, 6, 5, 1, 8, 4, 7, 2};
  int i ;

  printf("Array before : ");
  for ( i = 0 ; i < 9 ; i++)
    printf("%d ",list[i]);

  printf("\n");
  InsertionSort(list,9 ,1);
  printf("Array After Insertion Sort with order 1: ");
  for ( i = 0 ; i <9 ; i++)
    printf("%d ",list[i]);
  printf("\n");
  InsertionSort(list,9 ,0);
  printf("Array After Insertion Sort with order 0: ");
  for ( i = 0 ; i <9 ; i++)
    printf("%d ",list[i]);
  printf("\n");

return 0;
}
