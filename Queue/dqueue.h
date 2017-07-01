/***************************************************************
 * File   : dqueue.h
 * Author : Babribhan Jangra <babribhan@gmail.com>
 * Date   : July 01 ,2017 TIME :12:11:09
 ***************************************************************/
#ifndef _DQUEUE_H
#define _DQUEUE_H
class d_queue{
  int frnt,rear;
  int mx_size;
  int sz;
  int *arr;
  public:
  d_queue(int max):mx_size(max),sz(0),frnt(-1),rear(-1){
    arr = new int[max];
  }
  int max_size(){
  return mx_size;
  }
  int size(){
  return sz;
  }
  bool empty() {
    return sz == 0;
  }
  bool full() {
    return sz == mx_size-1;
  }
  void push_front(int data) {
    if ( frnt == 0 ) {
    cout<<"Insertion can't be done at front. Try at Rear end."<<endl;
    exit(1);
    }
    else if ( frnt == -1 ) 
    {
    arr[++frnt]  = data;
    rear++;
    sz++;
    }
    else 
    {
    arr[--frnt] = data;
    sz++;
    }
  }
  void pop_front() {
    int temp;
    if ( frnt == -1 ) {
    cout<<"Queue is empty."<<endl;
    exit(1);
    }
    else if ( rear == 0 && frnt == 0) 
    {
    temp = arr[frnt];
    frnt = rear = -1;
    sz--;
    }
    else 
    {
    temp = arr[frnt++];
    sz--;
    }
  }
  void pop_back() {
    int temp;
    if ( rear == -1 ) {
    cout<<"Queue is empty."<<endl;
    exit(1);
    }
    else if ( rear == 0 && frnt == 0) 
    {
    temp = arr[rear];
    frnt = rear = -1;
    sz--;
    }
    else 
    {
    temp = arr[rear--];
    sz--;
    }
  }
  void push_back(int data) {
    if ( rear  == mx_size ) {
    cout<<"Insertion can't be done at rear. Try at Front end."<<endl;
    exit(1);
    }
    else if ( rear == -1 ) 
    {
    arr[++rear]  = data;
    frnt++;
    sz++;
    }
    else 
    {
    arr[++rear] = data;
    sz++;
    }
  }
  int back() {
    if (empty())  {
      std::cout<<"ERROR : Queue is Empty."<<endl;
      exit(1);
    }
    return arr[rear];
  }
  int front() {
    if (empty())  {
      std::cout<<"ERROR : Queue is Empty."<<endl;
      exit(1);
    }
    return arr[frnt];
  }
  void print(){
    if(empty()){
      std::cout<<"ERROR : Queue is Empty."<<endl;
    }
    else {
      int temp = frnt;
      while ( temp != rear) {
        std::cout<<arr[temp++]<<" ";
      }
      std::cout<<arr[rear];
      std::cout<<endl;
    }
  }
};
#endif
