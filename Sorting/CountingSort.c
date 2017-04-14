/* Counting Sort Implementation .
*/
#include<stdio.h>
#include<stdlib.h>

void printArray(int *arr, int size,char *msg)
{
    int i;
      printf("Array  %s : ",msg);
        for ( i = 0 ; i <size; i++)
              printf("%d ",arr[i]);
                printf("\n");
}
int* countingSort(int *arr,int size)
{
  int countArray[7] ={0};
  int *aux = (int*)calloc(size,sizeof(int));
  int i;
  for (i =0 ; i < size;++i)
  {
    ++countArray[arr[i]]; // Find the number of times each element occurs in the array.
  }
  for (i =1 ; i <= 7;++i)
  {
    countArray[i] += countArray[i - 1]; // Number of elements <= to i.
  }
  for (i = size-1 ; i >= 0;--i)
  {
    aux[countArray[arr[i]]] = arr[i];
    --countArray[arr[i]];
  }
  return ++aux;
}
int main(void)
{
  int list[]={6,0,2,0,1,3,4,6,1,3,2};
  int length = (int)sizeof(list)/sizeof(list[0]) ;
  printArray(list,length,"Original");
  int *sorted_list = countingSort(list,length);
  printArray(sorted_list,length,"Sorted  ");

  return 0;
}
