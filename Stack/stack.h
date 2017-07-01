#ifndef _STACK_H
#define _STACK_H
class my_stack{
  int tp;
  int mx_size;
  int sz;
  int *arr;
  public:
  my_stack(int max):mx_size(max),sz(0),tp(-1) {
    arr = new int[max];
  }
  int max_size(){
  return mx_size;
  }
  int size(){
  return sz;
  }
  bool empty() {
    return tp == -1;
  }
  bool full() {
    return tp == mx_size-1;
  }
  void push(int data) {
    if (full())  {
      std::cout<<"ERROR : Stack Overflow."<<endl;
      exit(1);
    }
    else {
      arr[++tp] = data;
      sz++; 
    } 
  }
  int pop() {
    if (empty())  {
      std::cout<<"ERROR : Stack Unerflow."<<endl;
      exit(1);
    }
    sz--;
    return arr[tp--];
  }
  int top() {
    if (empty())  {
      std::cout<<"ERROR : Stack Unerflow."<<endl;
      exit(1);
    }
    return arr[tp];
  }
  void print(){
    if(empty()){
      std::cout<<"Stack is Empty."<<endl;
    }
    else {
      int temp = sz;
      while ( --temp >= 0) {
        std::cout<<arr[temp]<<" ";
      }
      std::cout<<endl;
    }
  }
};
#endif
