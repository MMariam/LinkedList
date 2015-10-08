/*
 *  Node.h
 *  Linked_list
 *
 *  Created by Mary H Abgarian on 4/1/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

template<typename T>

struct Node//node that contains an integer data
{	
	T data;
	Node *next;
};

#endif //NODE_H
