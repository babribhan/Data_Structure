/***************************************************************
 * File   : DListQ.cpp
 * Author : Babribhan Jangra <babribhan@gmail.com>
 * Date   : July 01 ,2017 TIME :12:10:09
 ***************************************************************/
#include<iostream>
using namespace std;
#include "dqueue1.h"
int main(void){
d_queue1 dq;
dq.push_front(1);
dq.print();
dq.push_back(3);
dq.push_back(9);
dq.push_back(8);
dq.push_back(7);
dq.print();
cout<<"Front of queue is "<<dq.front()<<endl;
cout<<"back of the queue is "<<dq.back()<<endl;
cout<<"size of the queue is "<<dq.size()<<endl;
dq.pop_front();
dq.print();
dq.pop_back();
dq.print();
cout<<"Front of queue is "<<dq.front()<<endl;
cout<<"back of the queue is "<<dq.back()<<endl;
cout<<"size of the queue is "<<dq.size()<<endl;
return 0;
}
