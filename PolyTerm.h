/*
 *  PolyTerm.h
 *  Linked_list
 *
 *  Created by Mary H Abgarian on 4/16/14.
 *  Copyright 2014 Pasadena City College. All rights reserved.
 *
 */

class PolyTerm//defining the behavior of T
{	public:
	double power, coeff;
	PolyTerm();
	PolyTerm(double n_coeff, double n_power);
	PolyTerm operator-(const PolyTerm& A);
	friend bool operator == (const PolyTerm& A, const PolyTerm& B);
	friend bool operator<(const PolyTerm& A, const PolyTerm& B);
	friend bool operator>(const PolyTerm& A, const PolyTerm& B);
	friend ostream& operator <<(ostream& out, const PolyTerm& B);
	friend PolyTerm operator*(const PolyTerm& A, int c) ;
	friend PolyTerm operator*(const PolyTerm& A, const PolyTerm& B);
	friend PolyTerm derive(const PolyTerm& A);
};

PolyTerm::PolyTerm()
{
	power=0, coeff=0;
}

PolyTerm::PolyTerm(double n_coeff, double n_power)
{
	power=n_power, coeff=n_coeff;
}

PolyTerm PolyTerm::operator-(const PolyTerm& A) 
{
	PolyTerm B;
	B.coeff=-A.coeff;
	B.power=A.power;
	return B;
}
PolyTerm operator*(const PolyTerm& A, const PolyTerm& B)
{	PolyTerm C;
	C.coeff=A.coeff*B.coeff;
	C.power=A.power+B.power;
	return C;
}

PolyTerm operator*(const PolyTerm& A, int c) 
{
	PolyTerm B;
	B.coeff=c*A.coeff;
	B.power=A.power;
	return B;
}

PolyTerm derive(const PolyTerm& A)
{
	PolyTerm B;
	B.coeff=A.coeff*A.power;
	B.power=A.power-1;
	return B;
}

bool operator<(const PolyTerm& A, const PolyTerm& B)//returns the opposite of the assignment operator
{
	return (A.power<B.power);
}

bool operator>(const PolyTerm& A, const PolyTerm& B)//returns the opposite of the assignment operator
{
	return (A.power>B.power);
}

bool operator==(const PolyTerm& A, const PolyTerm& B)//returns the opposite of the assignment operator
{
	return (A.power==B.power);
}

ostream& operator <<(ostream& out, const PolyTerm& B)
{
	if(!B.power && B.coeff)
		out<<B.coeff;
	
	if(B.power && B.coeff)
	 {
		if(B.power==1 && B.coeff!=1)
			out<<B.coeff<<"x";
		
		if(B.power==1 && B.coeff==1)
			out<<"x";
		
		if(B.power!=1 && B.coeff==1)
			out<<"x^"<<B.power;
		
		if((B.power>1 || B.power<-1) && (B.coeff>1 || B.coeff<-1))
	
			out<<B.coeff<<"x^"<<B.power;
	 }
	
    return out;
	
}
