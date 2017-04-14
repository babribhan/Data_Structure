/* Radix Sort Implementation which use counting sort as intermediate sorting algorithm
   Date   : April 14 , 2017
   Babribhan Jangra<babribhan@gmail.com>
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_DIGITS 10
void printArray(int *arr, int size,char *msg)
{
  int i;
  printf("Array  %s : ",msg);
  for ( i = 0 ; i <size; i++)
    printf("%d ",arr[i]);
  printf("\n");
}
int getMax(int *arr,int size)
{
  int max = arr[0];
  int i ;
  for( i =1 ; i < size;++i)
  {
    if ( max < arr[i] )
    {
      max = arr[i];
    }
  }
  return max;
}
int* countingSort(int *arr,int size,int exp)
{
  int countArray[MAX_DIGITS] ={0};
  int *auxilary_list = (int*)calloc(size+1,sizeof(int));
  int i;
  for (i =0 ; i < size;++i)
  {
    ++countArray[(arr[i]/exp)%10]; // Find the number of times each element occurs in the array.
  }
  for (i =1 ; i <=MAX_DIGITS;++i)
  {
    countArray[i] += countArray[i - 1]; // Number of elements <= to i.
  }
  for (i = size-1; i >=0;--i)
  {
    auxilary_list[countArray[(arr[i]/exp)%10]] = arr[i];
    --countArray[(arr[i]/exp)%10];
  }
  arr = ++auxilary_list;
  free(auxilary_list);
  return arr;
}
int*  RadixSort(int *orginial_list,int size)
{
  if ( size == 1 ) return orginial_list;
  int max_element = getMax(orginial_list,size);
  int *temp_list = orginial_list;
  int exp,i;
  for (exp = 1; max_element/exp > 0 ; exp*=10)
  {
    temp_list = countingSort(temp_list,size,exp);

  }
  return temp_list;
}
int main(void)
{
  int list[]={329,457,657,839,436,720,355};
  int length = (int)sizeof(list)/sizeof(list[0]) ;
  printArray(list,length,"Original");
  int *sorted_list = RadixSort(list,length);
  printArray(sorted_list,length,"Sorted");
  return 0;
}
