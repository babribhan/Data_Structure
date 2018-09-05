#include<iostream>
#include<cstdio>
using namespace std;
struct node{
  int exp;
  int coef;
  struct node* next;
};
node* newNode(int exp,int coef){
  node* t = new node;
  t->exp = exp;
  t->coef = coef;
  t->next = nullptr;
  return t;
}
void insert(int x, int y, struct node **temp)
{
  struct node *r, *z;
  z = *temp;
  if(z == NULL)
  {
    r = newNode(x,y);
    *temp = r;
    r->next = new node;
    r = r->next;
    r->next = NULL;
  }
  else
  {
    r->coef = y;
    r->exp = x;
    r->next = new node;
    r = r->next;
    r->next = NULL;
  }
}
void addPolynomial(node* p1, node* p2, node* p ) {
  while ( p1->next && p2->next ) {
    if ( p1->exp > p2->exp ) {
      p->exp = p1->exp;
      p->coef = p1->coef;
      p1 = p1->next;
    }
    else if ( p1->exp < p2->exp ) {
      p->exp = p2->exp;
      p->coef = p2->coef;
      p2 = p2->next;
    }
    else {
      p->exp = p2->exp;
      p->coef = p2->coef+p1->coef;
      p2 = p2->next;
      p1 = p1->next;
    }
    p->next = new node;
    p = p->next;
    p->next = nullptr;
  }
  while ( p1->next || p2->next ) {
    if ( p1->next ) {
      p->coef = p1->coef;
      p->exp = p1->exp;
      p1 = p1->next;
    }
    if ( p2->next ) {
      p->coef = p2->coef;
      p->exp = p2->exp;
      p2 = p2->next;
    }
    p->next = new node;
    p = p->next;
    p->next = nullptr;
  }
}
void print(node* h ) {
  node* curr = h;
  while(curr->next ) {
    cout<<curr->coef<<"x^"<<curr->exp;
    curr = curr->next;
    if ( curr->next ) cout<<"+";
  }
  cout<<endl;
}
int main(){
  node *poly1=nullptr;
  insert(3,5,&poly1);
  insert(1,4,&poly1);
  insert(0,2,&poly1);
  print(poly1);
  node *poly2=nullptr;
  insert(1,5,&poly2);
  insert(0,5,&poly2);
  print(poly2);

  node *p = new node;
  addPolynomial(poly1,poly2,p);
  print(p);
}
