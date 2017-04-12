/* A Simple Implementaion of Hash table where collision is resolved with chaining 
   Hash Function used is Division .
   Babribhan Jangra<babribhan@gmail.com>
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 30
typedef struct node
{
  int id;
  int key;
  char *name;
  float salary;
  float exp;
  char *skills;
  struct node *next;
}node_t;

typedef struct hash
{
  int count;
  node_t **head;
}hash_t;

node_t* getNewNode(int key ,int id, char *name,float sal,float ex , char* skill)
{
  node_t *temp = (node_t*)malloc(sizeof(node_t));
  temp->id  = id ;
  temp->key = key;
  temp->name = name;
  temp->salary = sal;
  temp->exp = ex;
  temp->skills = skill;
  temp->next = NULL;
  return temp;
}
void insert(hash_t *table,int key , int id, char *name,float sal,float ex , char* skill)
{
  int hashValue = key % MAX;
  node_t *newNode = getNewNode(key ,id,name,sal,ex,skill);

  if(!*(table[hashValue].head)) 
  {
    (table[hashValue].head)= (node_t**)malloc(sizeof(node_t));
    *(table[hashValue].head)= newNode;
  } 
  else
  {
    newNode->next = *(table[hashValue].head);
    *(table[hashValue].head)  = newNode;
  }
  table[hashValue].count++;
}
void printTable(hash_t *table)
{
  int i ;
  node_t *curr;
  for (i =0;i < MAX ;++i)
  {
    if ( *(table[i].head))
    {
      curr = *(table[i].head);
      printf("[%d]  List Count is %d \n",i,table[i].count);
      while(curr)
      {
        printf("----------------------------------------------------------------------------------------------\n");
        printf("KEY : %d ",curr->key);
        printf("NAME : %s ",curr->name);
        printf("ID : %d ",curr->id);
        printf("SALARY : $%.2f ",curr->salary);
        printf("EXPERIENCE : %.1f Yrs. ",curr->exp);
        printf("SKILLS : %s\n",curr->skills);
        printf("----------------------------------------------------------------------------------------------\n");
        curr = curr->next; 
      }
    }
  } 
}
void delete(hash_t *table,int key )
{
  int hashValue = key % MAX;
  node_t *curr,*temp=NULL,*prev=NULL;
  if (!*(table[hashValue].head))
  {
    printf("Key %d is not present in the table\n",key);  
  }
  else
  {
    curr = *(table[hashValue].head);
    while(curr)
    {
      if(curr->key == key )
      {
        temp = curr;
        if (!prev)
        {
          curr = curr->next;
          *(table[hashValue].head) = curr;
        }
        else
        {
          prev->next = curr->next;
        }
      free(temp); 
      }
      prev = curr;
      curr = curr->next;
    }
    table[hashValue].count--;
  }
}
void search(hash_t *table,int key )
{
  int hashValue = key % MAX;
  node_t *curr;
  if (!*(table[hashValue].head))
  {
    printf("Key %d is not present in the table\n",key);  
  }
  else
  {
    curr = *(table[hashValue].head);
    while(curr)
    {
      if(curr->key == key )
      {
        printf("Search results\n");
        printf("----------------------------------------------------------------------------------------------\n");
        printf("KEY : %d ",curr->key);
        printf("NAME : %s ",curr->name);
        printf("ID : %d ",curr->id);
        printf("SALARY : $%.2f ",curr->salary);
        printf("EXPERIENCE : %.1f Yrs.",curr->exp);
        printf("SKILLS : %s \n",curr->skills);
        printf("----------------------------------------------------------------------------------------------\n");
        return ;
      }
      curr = curr->next;
    }
    printf("Key %d is not present in the table\n",key);
  }
}
int main(void)
{
  hash_t *hashTable = (hash_t*)malloc(MAX*sizeof(hash_t));;
  int i ;
  for ( i = 0 ; i < MAX ; ++i)
  hashTable[i].head = NULL;
  insert(hashTable,1,104845,"BABRIBHAN",300,2.4,"C++");
  insert(hashTable,31,104840,"BABRI",250,3,"JAVA");
  insert(hashTable,41,104841,"JANGRA",250,3.5,"SQL");
  printTable(hashTable);
  search(hashTable,3);
  search(hashTable,1);
  printTable(hashTable);
  return 0;
}
