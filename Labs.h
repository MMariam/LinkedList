/*
 *  Labs.h
 *  Linked_list
 *
 *  Created by Mariam Mkhitaryan on 4/24/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

#include "LinkedList.h"


class station {
public:
	station();
	station(string new_ID);
	
	friend bool operator==(station A, station B);
	friend bool operator!=(station A, station B);
	friend ostream& operator <<(ostream& out, station A);
	string userID;
};

station::station()
{
	
}

station::station(string new_ID)
{
	userID=new_ID;
}

bool operator==(station A, station B)//returns true if A has the same data as B and false if doesn't not
{
	return A.userID==B.userID;
}

bool operator!=(station A, station B)//returns true if A has the same data as B and false if doesn't not
{
	return !(A.userID==B.userID);
}

ostream& operator <<(ostream& out, station A)
{
	out<<A.userID;
	return out;
}

class Labs {
	
public:
	
	Labs();
	
	void SignIn(station ID, int row);
	
	void SignOut(station ID, int row);
	
	Iterator<station> Search(station ID);
	
	int Search(station ID, int row);
	
	void Print();
private:
	List<List<station> > lab;
};


Labs::Labs()
{
	
}

void Labs::SignIn(station ID, int row)
{

	lab[row].InsertHead(ID);

}

Iterator<station> Labs::Search(station ID)
{
	Iterator<station> found, save;
	for(int i=0;!lab[i].Empty(); i++)
	 {	
		 found=lab[i].List<station>::Search(ID);
	   if(!found.IsNull())
		save=found;
	}
	found=save;
	return found;
}

int Labs::Search(station ID, int row)
{
	lab[row].List<station>::Search(ID);
	return row;
}

void Labs::SignOut(station ID, int row)
{
	Iterator<station> Out=Search(ID);
	lab[row].Delete(Out);
}


void Labs::Print()
{
	for(int i=0; !lab[i].Empty(); i++)
		lab[i].List<station>::Print();
}
