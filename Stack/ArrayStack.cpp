//  A C++ program to implement stack using array.
#include <iostream>
using namespace std;
#include "stack.h"
int main(void){
  my_stack s(100);
  cout<<"Stack size is "<<s.size()<<endl;
  cout<<"Stack max_size is "<<s.max_size()<<endl;
  s.push(2);
  s.push(4);
  s.push(3);
  s.push(9);
  s.push(7);
  s.print();
  cout<<"stack top is "<<s.top()<<endl;
  s.pop();
  s.print();
  cout<<"stack top is "<<s.top()<<endl;
  cout<<"Stack size is "<<s.size()<<endl;
  cout<<"Stack max_size is "<<s.max_size()<<endl;
  return 0;
}

