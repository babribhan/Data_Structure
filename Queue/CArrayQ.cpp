/***************************************************************
 * File   : CArrayQ.cpp
 * Author : Babribhan Jangra <babribhan@gmail.com>
 * Date   : July 01 ,2017 TIME :12:10:09
 ***************************************************************/
#include<iostream>
using namespace std;
#include "cqueue.h"
int main(void){
c_queue q(100);
q.enqueue(9);
q.enqueue(3);
q.enqueue(1);
q.enqueue(7);
q.enqueue(4);
q.print();
cout<<"Front of queue is "<<q.front()<<endl;
cout<<"back of the queue is "<<q.back()<<endl;
cout<<"size of the queue is "<<q.size()<<endl;
q.dequeue();
q.dequeue();
q.dequeue();
q.print();
cout<<"Front of queue is "<<q.front()<<endl;
cout<<"back of the queue is "<<q.back()<<endl;
cout<<"size of the queue is "<<q.size()<<endl;
return 0;
}
