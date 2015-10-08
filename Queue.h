/*
 *  Queue.h
 *  Linked_list
 *
 *  Created by Mary H Abgarian on 4/8/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

#ifndef QUEUE_H
#define QUEUE_H
#include "List.h"

//EnQueue, DeQueue, IsEmpty functions
template <typename T>
class Queue : public List<T> {
	
public:
	Queue();
	void EnQueue(T num);
	T DeQueue();
	bool IsEmpty();
	
private:
	Iterator<T> front, back;
	
};

template <typename T>
Queue<T>::Queue(): List<T>(), front(this->Begin()), back(this->End())
{
	
}
template <typename T>
void Queue<T>::EnQueue(T num)
{
	if(IsEmpty())
	 {
		front=back=InsertHead(num);
	 }
	else
	 {
		InsertAfter(back, num);
	 }
	
}
template <typename T>
T Queue<T>::DeQueue()
{
	T temp=*front;
	Delete(front);
	return temp;
}

template <typename T>
bool Queue<T>::IsEmpty()
{
	return front.IsNull();
}





#endif //QUEUE_H
