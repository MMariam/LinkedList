/*
 *  List.h
 *  Linked_list
 *
 *  Created by Mariam Mkhitaryan on 3/20/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>

#include "Iterator.h"
#include "Node.h"

using namespace std;

template<typename T>

class List{

public:
		//constructors
	List();//default constructor
	//List(T A[]);//constructor with integer array as a parameter
	
		//THE BIG THREE
	List(const List<T>& A);//copy constructor
	~List();//destructor
	List& operator=(const List<T>& source);//overloaded assignment operator	
	
		//prints the contents of this linked list
	void Print();//prints it like an array	

		//is the list empty?
	bool Empty();//returns true if yes, false if no
	
		//overloaded operators 
		//List& operator+=(T num);//inserts num into a sorted list
	T& operator[](int index);//indexes an the list

		//accessor functions
	Iterator<T> End() const;//returns Iterator<T> to the last node
	Iterator<T> Begin() const;	//returns an Iterator<T> to the first node
	
		//lower level functions for sort merge and reverse
	Iterator<T> WTG(T i);//decides where a number goes
	Iterator<T> InsertHead(T the_number);//inserts a head node that contains i
	Iterator<T> Remove(Iterator<T> RemoveThis);//disconnect the node from the linked list and return it's address
	Iterator<T> Search(T i);//searches for the node that contains i
	Iterator<T> Previous(Iterator<T> where) const;//returns address of previous node
	T Delete(Iterator<T> marker);//deletes the marker and returns it's int value
	
	//void InsertSorted(Iterator<T> This, Iterator<T> &Sorted);//inserts a node into a sorted list
	void InsertAfter(Iterator<T> marker, T i);//inserts a node that contains an i after the marker node
	void InsertBefore(Iterator<T> marker, T i);//inserts a node that contains i before a marker node
	//void InsertSorted(T num);//inserts a number in a sorted list
	void DeleteList();//deletes an entire list
	
		//sort list, merge 2 lists, and reverse a list
	List<T> Reverse(const List<T>& source);//reverses a list
	
	
private: 
	Node<T> *head;//private member variable of List
	
};

template<typename T>

List <T> ::List()//default constructor
{
	head=NULL;
}
//template<typename T>
//List<T>::List(T A[])//constructor with integer array as a parameter
//{
//	int size;
//	for(size=0; A[size]>-1; size++);
//	for(int i=size-1; i>=0; i--)
//		InsertHead(A[i]);		
//}
template<typename T>
List<T>::List(const List<T>& A)//copy constructor
{
		//DeleteList();
	Iterator<T> it;
	for(it=A.End(); it!=A.Begin(); it=A.Previous(it))
		InsertHead(*it);
			 cout<<"\ncopy constructor firing!!!\n";
}
template<typename T>
List<T>::~List()//destructor
{
	DeleteList();
}
template<typename T>
List<T>& List<T>::operator=(const List<T>& source)//overloaded assignment operator	
{
	DeleteList();
	for(Iterator<T> it(source.End()); it!=source.Begin(); it=source.Previous(it))
	 {InsertHead(*it);
		 cout<<"\ncopy constructor firing!!!\n";
	 }
	return *this;
}
template<typename T>
void List<T>::Print()//prints the contents of this nested list
{
	for (Iterator<T> it(head); !it.IsNull(); it++)
		cout<<"["<<*it<<"]->";
	cout<<"|||"<<endl;
}
template<typename T>
bool List<T>:: Empty()//returns true if yes, false if no
{
	if(head==NULL)
		return true;
	else
		return false;
}
template<typename T>  
T& List<T>::operator[](int index)//indexes an the list
{
	Node<T>* w=head;
	for(int i=0; i<index; i++)//make sure not falling off the edge
		w=w->next;
	
	return w->data;//pointer to the ith array
}
template<typename T>
Iterator<T> List<T>:: End() const//returns Iterator<T> to the last node
{	Iterator<T> null;
	Node<T>* w=head;
	
	if(w)
	 {
		while(w->next)
			w=w->next;
		return Iterator<T>(w);
	 }
	else
		return null;
}

template<typename T>
Iterator<T> List<T>::Begin() const//returns an Iterator<T> to the first node
{
	return Iterator<T>(head);
}

template<typename T>
Iterator<T> List<T>::InsertHead(T the_number)//inserts a head node that contains i
{
		//pointer to a node which is not a node itself, we now point to a dynamic memory reserved for a single node
	Node<T>* temp_head=new Node<T>;//points to a new node
	
	
		//dereferencing the pointer to the node and assigning the value of the_number
	temp_head->data=the_number;
	
		//nexting this node to the previous head by dereferencing it and assigning the address of head to it's pointer variable
	
	temp_head->next=head;//points to where head was pointing to 
	
		//we don't get rid of head, but we make it have the same address as the temp_head so that now it points to the same thing that temp_head is pointing to
	head=temp_head;
	
	return Iterator<T>(head);	
}
template<typename T>
Iterator<T> List<T>::Remove(Iterator<T> RemoveThis)//disconnect the node from the list and return it's Iterator<T>
{
	Iterator<T> P=Previous(RemoveThis);
	
	
	if(!P.IsNull())
		P.ptr->next=RemoveThis.ptr->next;
	else
		head=RemoveThis.ptr->next;
	
	RemoveThis.ptr->next=NULL;
	
	return RemoveThis;
	
}
template<typename T>
Iterator<T> List<T>::Search(T i)//returns the Iterator<T> that contains i 
{	Iterator<T> null;
	Node<T>* w=head;
		//what happens when i is not found?
	if(w==NULL)//empty list case
		return null;
	else{
		while(w->data!=i && w->next!=NULL)
			w=w->next;
		
		if(w->data==i)
			return Iterator<T>(w);
		else
			return null;
	}
}
template<typename T>
	//change to Iterator<T>s
Iterator<T> List<T>::Previous(Iterator<T> where) const//returns Iterator<T> of previous node
{
	Iterator<T> null;
	Node<T>* w=head;
		//
	if(where.ptr==head)
		return null;
	while(w->next!=where.ptr)
		w=w->next;
	return Iterator<T>(w);
}

template<typename T>
T List<T>::Delete(Iterator<T> marker)//deletes the marker and returns it's int value
{
	T temp;
	Iterator<T> R=Remove(marker.ptr);
	
	if(!R.IsNull())
	 {
		temp=*marker;
		delete R.ptr;
	 }
	
	return temp;
}

template<typename T>
void List<T>::DeleteList()//deletes an entire list
{
    Iterator<T> it;
	while(!Empty())
	 {	 
		 if(!it.IsNull())
			 Delete(it);
		 it=Begin();
	 }
}


	//Iterator<T> w(head);
	//
	//for(Iterator<T> it(head);!it.IsNull(); ++it)
	//{
	//	r=Delete(w);
	//	Sorted.InsertSorted(r);
	//	
	//	w=it;
	//	Print();
	//}



template<typename T>
List<T> List<T>::Reverse(const List<T>& source)//reverses a list
{
	List<T> R;
	for(Iterator<T> it(source.Begin()); !it.IsNull(); it++)
		R.InsertHead(*it);
	DeleteList();
	return R;
}

template<typename T>
void List<T>::InsertAfter(Iterator<T> marker, T i)//inserts a node that contains i after the marker node
{
	Node<T>* temp_head=new Node<T>;//create a location for a new node
	
	temp_head->data=i;
	
	temp_head->next=marker.ptr->next;//points to the node that comes after the marker
	
	marker.ptr->next=temp_head;
}

template<typename T>
void List<T>::InsertBefore(Iterator<T> marker, T i)//inserts a node that contains i before the marker node
{
	Iterator<T> P=Previous(marker);
	
	if(!P.IsNull())
		InsertAfter(P,i);
	else
		InsertHead(i);
}



#endif //LIST_H


