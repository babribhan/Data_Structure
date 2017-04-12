/*
File : DirTableHash.c
Description : Implementation of  Direct Hash Table.
Author: Babribhan Jangra <babribhan@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct dirHash
{
	unsigned capacity;
	unsigned size;
	int *arr;
}dirHash_t;

int isEmpty(dirHash_t* dirHash )
{
	return dirHash->size == 0;
}
int isFull(dirHash_t* dirHash )
{
	return dirHash->size == dirHash->capacity;
}

dirHash_t* initDirHash(unsigned max_size)
{
	dirHash_t* temp = (dirHash_t*)malloc(sizeof(dirHash_t));
	temp->capacity = max_size;
	temp->size = 0;
	temp->arr = (int*)malloc(sizeof(int)*max_size);
	return temp;
}
void Insert( dirHash_t* dirHash ,unsigned key, int value)
{
	if ( isFull(dirHash))
	{
		printf("Hash Table is Full.Can't Insert anymore item.\n");
		exit(1);
	}
	dirHash->arr[key] = value;
dirHash->size++;
}
int  Search(dirHash_t* dirHash ,unsigned key)
{
	if ( isEmpty(dirHash))
	{
		printf("Hash Table is Empty.\n");
		exit(1);
	}
	return dirHash->arr[key];
}
void Delete(dirHash_t* dirHash ,unsigned key)
{
	if ( isEmpty(dirHash))
	{
		printf("Hash Table is Empty.\n");
		exit(1);
	}
	dirHash->arr[key] = -1;
dirHash->size--;
}
	int 
main(void)
{
	dirHash_t* dirHash = initDirHash(11);
	Insert(dirHash,1,33);
	Insert(dirHash,2,8);
	Insert(dirHash,4,65);
	if( -1 != Search(dirHash,2))
	{
		printf("Value at key 2 is <%d>\n",Search(dirHash,2));
	}
	else
	{
		printf("Key 2 doesn't have a value.\n");
	}
	Delete(dirHash,1);
	if( -1 != Search(dirHash,1))
	{
		printf("Value at key 2 is <%d>\n",Search(dirHash,2));
	}
	else
	{
		printf("Key 2 doesn't have a value.\n");
	}
	return 0;
}
