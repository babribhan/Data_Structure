#include<stdio.h>
#include<stdlib.h>

int* countingSort(int *arr,int size)
{
  int countArray[7] ={0};
  int *aux = (int*)calloc(size,sizeof(int));
  int i;
  for (i =0 ; i < size;++i)
  {
    countArray[arr[i]] = countArray[arr[i]] +1; // Find the number of times each element occurs in the array.
  }
  for (i =1 ; i <= 6;++i)
  {
    countArray[i] = countArray[i] + countArray[i - 1]; // Number of elements <= to i.
  }
  for (i = size-1 ; i >= 0;--i)
  {
    aux[countArray[arr[i]]] = arr[i];
    countArray[arr[i]] = countArray[arr[i]] -1;
  }
  return aux;
}
int main(void)
{
  int arr[]={6,0,2,0,1,3,4,6,1,3,2};
  int i ;
  printf("Original Array : ");

  for ( i = 0 ; i <11; i++)
  printf("%d ",arr[i]);

  printf("\n");
  int *sArr = countingSort(arr,11);
  printf("Sorted Array : ");

  for ( i = 1 ; i <=11; i++)
  printf("%d ",sArr[i]);
  printf("\n");
  return 0;
}


