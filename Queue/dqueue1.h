/***************************************************************
 * File   : dqueue1.h
 * Author : Babribhan Jangra <babribhan@gmail.com>
 * Date   : July 01 ,2017 TIME :12:11:09
 ***************************************************************/
#ifndef _DQUEUE_H
#define _DQUEUE_H
class d_queue1{
  typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
  }Node;
  Node *head,*tail;
  int sz;
  public:
  d_queue1():sz(0) {
    head = tail = NULL;
  }
  int size(){
    return sz;
  }
  bool empty() {
    return head == NULL && tail == NULL;
  }
  void push_back(int data) {
    Node *temp = new Node;
    temp->data = data;
    if ( empty()) {
    head = tail = temp;
    temp->next  = temp->prev = NULL;
    }
    else {
    tail->next = temp;
    temp->prev = tail;
    temp->next = NULL;
    tail = temp;
    }
    sz++;
  }
  void push_front(int data) {
    Node *temp = new Node;
    temp->data = data;
    if ( empty()) {
    head = tail = temp;
    temp->next  = temp->prev = NULL;
    }
    else {
    temp->next = head;
    head->prev = temp;
    temp->prev = NULL;
    head = temp;
    }
    sz++;
  }
  int pop_front() {
    if (empty())  {
      std::cout<<"ERROR : Queue is empty."<<endl;
      exit(1);
    }
    else {
     Node *temp = head;
     head = head->next;
     head->prev = NULL;
     int val = temp->data; 
     if ( !head) tail = NULL; 
     delete temp;
     sz--;
     return val;
    }
  }
  int pop_back() {
    if (empty())  {
      std::cout<<"ERROR : Queue is empty."<<endl;
      exit(1);
    }
    else {
     Node *temp = tail;
     tail = tail->prev;
     tail->next = NULL;
     int val = temp->data; 
     if ( !tail) head = NULL; 
     delete temp;
     sz--;
     return val;
    }
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
