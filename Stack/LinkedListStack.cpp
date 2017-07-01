//  A C++ program to implement stack using linked list.
#include <iostream>
using namespace std;
#include "stack1.h"
int main(void){
  my_stack1 s;
  cout<<"Stack size is "<<s.size()<<endl;
  s.print();
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
  cout<<"Is stack is empty"<<s.empty()<<endl;
  return 0;
}

