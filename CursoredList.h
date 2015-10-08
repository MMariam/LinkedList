/*
 *  CursoredList.h
 *  Linked_list
 *
 *  Created by Mariam Mkhitaryan on 4/8/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

#ifndef CURSOREDLIST_H
#define CURSOREDLIST_H
#include "List.h"

	//A List with a current (cursor) pointer. Will have GoNext, GoPrev functions
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
CursoredList<T>::CursoredList():List(), cursor(NULL)
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
	Iterator P=Previous(cursor);
	
	if(!P.IsNull())
		cursor=P;
	
}
template <typename T>
Iterator CursoredList<T>::InsertHead(T num)
{
	cursor=List::InsertHead(num);
	
	return cursor;
}




#endif //CURSORED_H