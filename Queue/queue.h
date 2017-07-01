/***************************************************************
 * File   : queue.h
 * Author : Babribhan Jangra <babribhan@gmail.com>
 * Date   : July 01 ,2017 TIME :12:11:09
 ***************************************************************/
#ifndef _QUEUE_H
#define _QUEUE_H
class my_queue{
  int frnt,rear;
  int mx_size;
  int sz;
  int *arr;
  public:
  my_queue(int max):mx_size(max),sz(0),frnt(-1),rear(-1){
    arr = new int[max];
  }
  int max_size(){
  return mx_size;
  }
  int size(){
  return sz;
  }
  bool empty() {
    return (frnt == -1 && rear == -1);
  }
  bool full() {
    return rear == mx_size-1;
  }
  void enqueue(int data) {
    if (full())  {
      std::cout<<"ERROR : Queue is Full."<<endl;
      exit(1);
    }
    else {
      if ( empty()) {
      frnt = 0;
      }
      arr[++rear] = data;
      sz++; 
    } 
  }
  int dequeue() {
    if (empty())  {
      std::cout<<"ERROR : Queue is Empty."<<endl;
      exit(1);
    }
    sz--;
    return arr[frnt++];
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
      while ( temp <= rear) {
        std::cout<<arr[temp++]<<" ";
      }
      std::cout<<endl;
    }
  }
};
#endif
