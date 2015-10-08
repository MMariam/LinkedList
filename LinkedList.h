/*
 *  LinkedList.h
 *  Linked_list
 *
 *  Created by Mary H Abgarian on 4/10/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

#include <iostream>

using namespace std;

//666-------------------NODE--------------------------------
template<typename T>
struct Node//node that contains an integer data
{	
	T data;
	Node *next;
};


//666-------------------ITERATOR--------------------------------
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



//666-------------------LIST--------------------------------
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
	Iterator<T> InsertHead(const T& the_number);//inserts a head node that contains i
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
	friend ostream& operator <<(ostream& out, List<T> A);
	
	
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
	DeleteList();
	Iterator<T> it;
	for(it=A.End(); it!=A.Begin(); it=A.Previous(it))
		InsertHead(*it);
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
		InsertHead(*it);
	return *this;
}
template<typename T>
void List<T>::Print()//prints the contents of this nested list
{
	for (Iterator<T> it(head); !it.IsNull(); it++)
		cout<<"["<<*it<<"]->";//a cout for T?
	cout<<"|||"<<endl;
}
template<typename T >
ostream& operator <<(ostream& out, List<T> A)
{
	for (Iterator<T> it(A.head); !it.IsNull(); it++)
	out<<"["<<*it<<"]->";
	out<<"|||"<<endl;
	return out;
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
Iterator<T> List<T>::InsertHead(const T& the_number)//inserts a head node that contains i
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

//666-------------------STACK--------------------------------
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

//666------------------QUEUE---------------------------------
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
//666-------------------CURSOREDLIST--------------------------------
template <typename T>
class CursoredList : public List<T> {
	
public:
	CursoredList();
	void GoNext();
	void GoPrev();
	Iterator<T> InsertHead(T num);
	
	
private:
	Iterator<T> cursor;
};

template <typename T>
CursoredList<T>::CursoredList():List<T>(), cursor(NULL)
{
	
}

template <typename T>
void CursoredList<T>::GoNext()
{
	cursor++;
}
template <typename T>
void CursoredList<T>::GoPrev()
{
	Iterator<T> P=Previous(cursor);
	
	if(!P.IsNull())
		cursor=P;
	
}
template <typename T>
Iterator<T> CursoredList<T>::InsertHead(T num)
{
	cursor=List<T>::InsertHead(num);
	
	return cursor;
}

//666------------------SORTEDLIST---------------------------------
template <typename T>
class SortedList : public List<T> {
	
public:
	SortedList();
	SortedList(char type);
	SortedList(const List<T>& copyThis);
	List<T>& operator+=(T num);
	SortedList<T> Sort();//sorts the list
	Iterator<T> WTG(T i);
	void InsertSorted(T num);
	List<T>& Merge(const List<T>& rhs);
	
private:
	bool ascending;

};

template <typename T>
SortedList<T>::SortedList():List<T>()
{
	
}

template <typename T>
SortedList<T>::SortedList(char type):List<T>()
{
	switch (type) {
		case 'a':
		case 'A':
			ascending=true;
			break;
		case 'D':
		case 'd':
			ascending=false;
			break;
		default:
			break;
	}
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
SortedList<T> SortedList<T>::Sort()//sorts a list
{
		//local sorted object
	
		//as long as list is not empty()...
	
		//remove(head) and insert sorted into the sorted object
	
		//point my head at the sorted object's head;
	
	
	SortedList<T> Sorted;
	T r;
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
void SortedList<T>:: InsertSorted(T num)//inserts a node into a sorted list
{
	Iterator<T> where(WTG(num));

	if(where.IsNull()) 
	 {
		if(this->Empty())//because where can be null but the list doesn't have to be empty
			
			InsertHead(num);//if it's empty insert a head
		
		else
			
			InsertAfter(this->End(), num);	
	 }
	else
		InsertBefore(where, num);	
		
}

template<typename T>
Iterator<T> SortedList<T>::WTG(T i)//decides where a number goes
{
		Iterator<T> u=this->Begin();

	if(this->ascending)
	 	for(;!u.IsNull() && (*u)<i; u++);
	 
	else
	 	for(;!u.IsNull() && (*u)>i; u++);

	return u;//for insert before
}



