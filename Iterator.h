/*
 *  Iterator.h
 *  Linked_list
 *
 *  Created by Mary H Abgarian on 3/27/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

#ifndef ITERATOR_H
#define ITERATOR_H

#include <iostream>

#include "Node.h"



using namespace std;

template <typename T>
class Iterator{
	
public:
		//constructors
	Iterator();//default constructor
	Iterator(Node<T>* marker);//constructor with a node pointer as a parameter
	Iterator(const Iterator<T>& it);//copy constructor
	
		//(no need for destructors because the pointer in this class is pointing to the same location as the pointer in the List class)
	
		//grants permission to List to access Iterator's private member variable
	template <typename ListType>
		friend class List;
	
		//Is the Iterator null? True for yes, False for no
	bool IsNull();
	
		//dereference, postfix and prefix increment operators
	T operator *();//dereferenes an iterator by returning it's int value
	Iterator<T> operator++(int);//postfix increment operator
	Iterator<T>& operator++();//prefix increment operator

		//accessor function
	Iterator<T> Next();//returns the next iterator
	
		//assignment operator, and boolean equal and not equal to
	Iterator<T>& operator=(const Iterator<T>& source);//overloaded assignment operator
	template <typename U>
	friend bool operator==(Iterator<U> A, Iterator<U> B);//returns true if A has the same data as B and false if doesn't not
		template <typename U>
	friend bool operator!=(const Iterator<U>& A, const Iterator<U>& B);//returns the opposite of the assignment operator
	friend bool operator>(const Iterator<U>& A, const Iterator<U>& B);
	friend bool operator<(const Iterator<U>& A, const Iterator<U>& B);
	
private:
	
	Node<T>* ptr;//the "walker" pointer
};

template <typename T>

Iterator<T>::Iterator()//default constructor
{
	ptr=NULL;
}
template <typename T>
Iterator<T>::Iterator(Node<T>* marker)//constructor with a node pointer as a parameter
{
	ptr=marker;
}
template <typename T>
Iterator<T>::Iterator(const Iterator<T>& it)//copy constructor
{
	ptr=it.ptr;
}
template <typename T>
bool Iterator<T>::IsNull()//returns true if ptr is null
{
	if(ptr!=NULL)
		return false;
	else
		return true;
}
template <typename T>
T Iterator<T>::operator *()//dereferenes an Iterator<T> by returning it's int value
{
	return ptr->data;
	
}
template <typename T>
Iterator<T> Iterator<T>::operator++(int)//postfix increment operator
{
	Iterator<T> it(ptr);
	
	ptr=ptr->next;
	
	return it;
}
template <typename T>
Iterator<T>& Iterator<T>::operator++() //prefix increment operator
{
	ptr=ptr->next;
	
	return *this;
}
template <typename T>
Iterator<T> Iterator<T>::Next()//returns the next Iterator<T>
{
	return Iterator<T>(ptr->next);
}
template <typename T>
Iterator<T>& Iterator<T>::operator=(const Iterator<T>& source)//overloaded assignment operator
{
	this->ptr=source.ptr;
	return *this;
}
template <typename U>
bool operator==(Iterator<U> A, Iterator<U> B)//returns true if A has the same data as B and false if doesn't not
{
	return A.ptr==B.ptr;
}
template <typename U>
bool operator!=(const Iterator<U>& A, const Iterator<U>& B)//returns the opposite of the assignment operator
{
	return !(A==B);
}


	// no match for 'operator<' in 'w. Iterator<T>::operator* [with T = PolyTerm]() < i'



#endif// ITERATOR_H

