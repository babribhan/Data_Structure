/**********************************************************
 * File        : singleList_1.c
 * Description : Show Insertion at the END of the List
 * Author      : Babribhan Jangra
 * Date        : May 04, 2018
 **********************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #define EXIT_SUCCESS 0
 #define Trace(varName) printf("Startng %s\n ",varName);
 struct node 
{
 int info ;
 struct node *link;
};

typedef struct node NODE ;
NODE *head = NULL;
NODE * createNode ()
{
 NODE *newNode = (NODE *)malloc(sizeof(NODE ));
 newNode->link = NULL;
return newNode ;
}
int getCount()
{
        Trace("getCount");
	if (head == NULL)
	{
		return 0;

	}
	else 
	{
		return (1 + getCount());
	}


}


void InsertAtEnd(const int data )
{
        Trace("InsertAtEnd");
	NODE *newNode =createNode ();
	newNode->info = data;
	if (head == NULL)
	{
		head = newNode;
	}
	else 
	{
		NODE *iterator = head;
		while(iterator->link != NULL) 
                iterator = iterator->link;
		iterator->link=newNode;
	}

}
void InsertAtPos(const int data ,const int position)
{
        int index;
	NODE *newNode =createNode ();
	newNode->info = data;
        Trace("InsertAtPos");
        if ( position > getCount())
         {
         printf("Invalid Position.\n");
         exit(1);
         }
 	else if (head == NULL) // if List if empty.
	{
		head = newNode;
	}
	else 
	{
              
		NODE *iterator = head;
                for(index = 1;index <= (position -1 );index++)
                iterator = iterator->link;

                newNode->link = iterator->link;   
                iterator->link = newNode;
	}

}
void PrintList()
{
Trace("PrintList");
NODE *iterator = head;
printf("List is : ");
 while (iterator != NULL)
{
printf("%d ",iterator->info);
iterator = iterator->link;

}

printf("\n");
}
int main(int argc ,char *argv[])
{
int noOfElement;
int nodeValue;
int i;
Trace("main");
printf("How many numbers.\n");
scanf("%d",&noOfElement);
for ( i=1;i<=noOfElement;i++)
{
printf("Data :\n");
scanf("%d",&nodeValue);
InsertAtEnd(nodeValue);
}
PrintList();
//InsertAtPos(4,4);
printf("Number of elements in the list is : <%d>\n",getCount());
return EXIT_SUCCESS;
}
