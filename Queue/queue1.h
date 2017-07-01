/***************************************************************
 * File   : queue1.h
 * Author : Babribhan Jangra <babribhan@gmail.com>
 * Date   : July 01 ,2017 TIME :12:11:09
 ***************************************************************/
#ifndef _STACK_H
#define _STACK_H
class my_queue1{
  typedef struct node{
    int data;
    struct node *next;
  }Node;
  Node *head,*tail;
  int sz;
  public:
  my_queue1():sz(0) {
    head = tail = NULL;
  }
  int size(){
    return sz;
  }
  bool empty() {
    return head == NULL;
  }
  void enqueue(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    if ( empty()) {
    head = tail = temp;
    }
    else {
    tail->next = temp;
    tail = temp;
    }
    sz++;
  }
  int dequeue() {
    if (empty())  {
      std::cout<<"ERROR : Queue is empty."<<endl;
      exit(1);
    }
    sz--;
    Node *temp = head;
    head = head->next;
    if (!head) 
      tail = NULL;
    int val = temp->data;
    delete temp;
    return val;
  }
  int front() {
    if (empty())  {
      std::cout<<"ERROR : Queue is empty."<<endl;
      exit(1);
    }
    return head->data;
  }
  int back() {
    if (empty())  {
      std::cout<<"ERROR : Queue is empty."<<endl;
      exit(1);
    }
    return tail->data;
  }
  void print(){
    if(empty()){
      std::cout<<"ERROR : Queue is empty."<<endl;
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
