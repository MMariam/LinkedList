/*
 *  SortedList.h
 *  Linked_list
 *
 *  Created by Mary H Abgarian on 4/8/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

#ifndef SORTEDLIST_H
#define SORTEDLIST_H
#include "List.h"

	//A list that stays sorted as you insert items into it. You will have WhereThisGoes, Insert, Merge functions, and += operator
template <typename T>
class SortedList : public List<T> {
	
public:
	SortedList();
	SortedList(const List<T>& copyThis);
	List<T>& operator+=(T num);
	SortedList<T> Sort();//sorts the list
	Iterator<T> WTG(T i);
	void InsertSorted(T num);
	List<T>& Merge(const List<T>& rhs);
	
private:

	
};

template <typename T>
SortedList<T>::SortedList():List<T>()
{
	
}


template <typename T>
SortedList<T>::SortedList(const List<T>& copyThis):List<T>(copyThis)
{
	
}


template<typename T>
List<T>& SortedList<T>::operator+=(T num)//inserts num into a sorted list
{
	InsertSorted(num);
	return *this;
}

template<typename T>
List<T>& SortedList<T>::Merge(const List<T>& rhs)//merges two sorted lists
{
	for(Iterator<T> it=rhs.Begin(); !it.IsNull(); it++)
	 	InsertSorted(*it);
	
	return *this; // return the result by reference
}


template<typename T>
void SortedList<T>:: InsertSorted(T num)//inserts a node into a sorted list
{
	Iterator<T> where=WTG(num);
	
	if(where.IsNull()) 
	 {
		if(this->Empty())
			
			InsertHead(num);
		
		else
			InsertAfter(this->End(), num);
	 }
	
	else
		InsertBefore(where, num);	
}



template<typename T>
SortedList<T> SortedList<T>::Sort()//sorts a list
{
		//local sorted object
	
		//as long as list is not empty()...
	
		//remove(head) and insert sorted into the sorted object
	
		//point my head at the sorted object's head;
	
	
	SortedList<T> Sorted;
	int r;
	Iterator<T> it(this->Begin());
	Iterator<T> w=it;
	while(!it.IsNull())
	 {
	    it++;
		r=Delete(w);
		Sorted+=r;
		w=it;
		
	 }
	return Sorted;
}

template<typename T>
Iterator<T> SortedList<T>::WTG(T i)//decides where a number goes
{
	Iterator<T> w=this->Begin();
		while(!w.IsNull() && *w<i )
			w++;
		
		return w;//for insert before
}


#endif //SORTEDLIST_H
