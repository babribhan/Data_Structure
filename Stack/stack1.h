#ifndef _STACK_H
#define _STACK_H
class my_stack1{
  typedef struct node{
    int data;
    struct node *next;
  }Node;
  Node *head;
  int sz;
  public:
  my_stack1()
  {
    head = NULL;
  }
  int size(){
    return sz;
  }
  bool empty() {
    return head == NULL;
  }
  void push(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = head;
    head = temp;
    sz++;
  }
  int pop() {
    if (empty())  {
      std::cout<<"ERROR : Stack Unerflow."<<endl;
      exit(1);
    }
    sz--;
    Node *temp = head;
    head = head->next;
    int val = temp->data;
    delete temp;
    return val;
  }
  int top() {
    if (empty())  {
      std::cout<<"ERROR : Stack Unerflow."<<endl;
      exit(1);
    }
    return head->data;
  }
  void print(){
    if(empty()){
      std::cout<<"Stack is Empty."<<endl;
    }
    else {
      Node *temp = head;
      while (temp) {
        std::cout<<temp->data<<" ";
        temp = temp->next;
      }
      std::cout<<endl;
    }
  }
};
#endif
