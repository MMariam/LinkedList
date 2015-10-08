/*
 *  Polynomial.h
 *  Linked_list
 *
 *  Created by Mary H Abgarian on 4/10/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */
#include "LinkedList.h"
#include "PolyTerm.h"

	//2d array class
	//read write search



class Polynomial : protected SortedList<PolyTerm> {

public:
	Polynomial();
	friend PolyTerm operator+(const PolyTerm& A, const PolyTerm& B);
	friend PolyTerm operator-(const PolyTerm& A, const PolyTerm& B);
	friend Polynomial& operator+=(Polynomial& A, const PolyTerm& B);
	friend Polynomial operator+(const Polynomial& A, const Polynomial& B);
	friend bool operator==(const PolyTerm& A, const PolyTerm& B);
	friend ostream& operator <<(ostream& out, const Polynomial& B);
	friend istream& operator >>(istream& in,  Polynomial& B);
	Polynomial& operator=(const Polynomial& B);
	friend Polynomial operator-(const Polynomial& A);
	friend Polynomial operator-(const Polynomial& A, const Polynomial& B);
	friend Polynomial operator*(const Polynomial& A, const Polynomial& B);
	friend Polynomial operator*(const PolyTerm& A, const Polynomial& B);
	friend Polynomial& operator+=(Polynomial& A, const Polynomial& B);//insert a polyterm
	friend Polynomial Derive(const Polynomial& F);
	private:

};
	
Polynomial::Polynomial(): SortedList<PolyTerm>('D')//'D')
	{
	   
	}
	

PolyTerm operator+(const PolyTerm& A, const PolyTerm& B)//only if two degrees are equal
	{
	   PolyTerm C;
	   C.coeff=A.coeff+B.coeff;
	   C.power=A.power;
	   return C;
	}
	
PolyTerm operator-(const PolyTerm& A, const PolyTerm& B)
	{
	   PolyTerm C;
	   C.coeff=B.coeff*-1;
	   C=A+C;
	   return C;
	}

Polynomial Derive(const Polynomial& F)
{
	Polynomial C;
	for(Iterator<PolyTerm> it=F.Begin(); !it.IsNull(); it++)
		C+=derive(*it);
	return C;
}

Polynomial operator*(const PolyTerm& A, const Polynomial& B)
{
	Polynomial C;
	for(Iterator<PolyTerm> it=B.Begin(); !it.IsNull(); it++)
		C+=*it*A;
	return C;
}

Polynomial operator*(const Polynomial& A, const Polynomial& B)
{
	Polynomial C;
	for(Iterator<PolyTerm> it=B.Begin(); !it.IsNull(); it++)
		C+=*it*A;
	return C;
	
}

Polynomial& operator+=(Polynomial& A, const Polynomial& B)//insert a polyterm
{
	A=A+B;
	return A;
}

Polynomial& operator+=(Polynomial& A, const PolyTerm& B)//insert a polyterm
	{
	   bool found=false;
	   for(Iterator<PolyTerm> it=A.Begin(); !it.IsNull(); it++)
		   if(*it==B)
			{
			   PolyTerm temp=*it+B;//polyterm plus polyterm
			   A.Delete(it);
			   A.InsertSorted(temp);
			   found=true;
			}
		   if(!found)
			A.InsertSorted(B);
		
	   
	   return A;
	}

Polynomial& Polynomial::operator=(const Polynomial& B)
{
	DeleteList();
	for(Iterator<PolyTerm> it=B.Begin(); !it.IsNull(); it++)
		(*this)+=*it;
	return *this;
}
	
Polynomial operator+(const Polynomial& A, const Polynomial& B) 
	{
	   Polynomial C;
	   C=A;
	   for(Iterator<PolyTerm> it=B.Begin(); !it.IsNull(); it++)
		   C+=*it;
	
	   return C;
	}

Polynomial operator-(const Polynomial& A)
{
	Polynomial B;
	for(Iterator<PolyTerm> it=A.Begin(); !it.IsNull(); it++)
		B+=*it*-1;
	return B;
}

Polynomial operator-(const Polynomial& A, const Polynomial& B) 
{
	Polynomial C;
	C=-B;
	Iterator<PolyTerm> it=A.Begin();
	for(; !it.IsNull(); it++)
		C+=*it;
	
	return C;
}

ostream& operator <<(ostream& out, const Polynomial& B)
{

	Iterator<PolyTerm> u=B.Begin();
		 for(Iterator<PolyTerm> it=B.Begin(); !it.IsNull(); it++)
		  { if (it!=B.Begin() && (*it).coeff>0) 
				out<<'+'<<*it;
			else 
				out<<*it;
		  }
	
  return out;	
}



istream& operator >>(istream& in,  Polynomial& B)
{
	char x, carrot, ch='+';
	PolyTerm A(1,1);
	while(in.get(ch) && ch!='\n')
	 {	
		 int s=1;
			//takes care of the first term

		 if(isdigit(ch))//is it a digit, put it back
		 in.putback(ch);
		 
		 if(ch=='-')//is it a ch, take it
			s=-1;
		 
		 in.get(ch);
		 
		 if(!isalpha(ch))//is it a character, take it and take one more, otherwise put it back
		  {
			 in.putback(ch);
			  in>>A.coeff;
		  }
		 else
			 in.get(ch);
			//>>x>>carrot>>A.power;
		 
		A.coeff*=s;

		in.get(x);//what happens after taking in the coefficient 

			if(!(x=='\n' || x=='+' || x=='-'))
				in>>carrot>>A.power;
		else
		 {
			A.power=0;
			in.putback(x);
		 }
		B+=A;

	 }
		
    return in;
}


