/***************************************************************
 * File   : ListQ.cpp
 * Author : Babribhan Jangra <babribhan@gmail.com>
 * Date   : July 01 ,2017 TIME :12:10:09
 ***************************************************************/
#include <iostream>
using namespace std;
#include "queue1.h"
int main(void)
{
my_queue1 q;
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
