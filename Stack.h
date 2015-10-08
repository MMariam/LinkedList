/*
 *  Stack.h
 *  Linked_list
 *
 *  Created by Mariam Mkhitaryan on 4/8/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

#ifndef STACK_H
#define STACK_H
#include "List.h";

template <typename T>
	// Push, Pop, Top, IsEmpty 
class Stack : public List<T> {
	
public:
	Stack();
	void Push(T num);
	T Pop();
	Iterator<T> Top();//returns top;
	bool IsEmpty();
	
private:
	Iterator<T> top;
	
};

template <typename T>
Stack<T>::Stack(): List<T>(), top(this->Begin())
{
	
}
template <typename T>
void Stack<T>::Push(T num)
{
	InsertHead(num);
}
template <typename T>
	//do i need to account for when the Stack<T> is empty????
T Stack<T>::Pop()
{
	T temp=*top;
	Delete(top);
	return temp;
}
template <typename T>
Iterator<T> Stack<T>::Top()//returns top;
{
	return top;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
	return top.IsNull();
}









#endif //STACK_H