#include <iostream>
#include <ctime>
#include "Labs.h"


/*
 THIS PROGRAM WILL BE ABLE TO CONSTRUCT A LIST, SORT IT, MERGE IT, AND REVERSE IT.
 */

using namespace std;
void TestList();

int main (int argc, char * const argv[]) {

	/*Polynomial A, B, C;
	cout<<"\nEnter a polynomial: ";
	cin>>A;

	cout<<"\nEnter another polynomial: "; 
	cin>>B;
	C=A*B;
	cout<<endl<<endl<<C;
	C=Derive(C);
	cout<<endl<<endl<<C;
	*/
	
	Labs CLC;
	station J("Jacob");
	cout<<J;
	CLC.SignIn(J,1);
		//CLC.Print();
	
//	Labs<string > CLA;
//	CLA.SignIn("Nick");
//	CLA.SignIn("Michael");
//	CLA.SignIn("Mary");
//	CLA.Print();
//	
//	Labs<string > CLB;
//	CLB.SignIn("Ashley");
//	CLB.SignIn("Mary");
//	CLB.Print();
//	
//	
	//List<Labs<string> >A;
//	A.InsertHead(CLC);
//	A.Print();
	
	
	
	
	return 0;
}





//void TestList()
//{
//	SortedList<int> A,C,W,D,R;
//	
//	srand(time(0));
//	for(int i=0; i<20; i++)
//		C.InsertHead(rand()%100+9);
//	for(int i=0; i<20; i++)
//		W.InsertHead(rand()%200+109);
//	
//	cout<<"\n\a";
//	cout<<"\nUNSORTED list 1: ";C.Print();
//	A=C.Sort();
//	cout<<"SORTED list 1: ";A.Print();
//	
//	cout<<"\nUnsorted list 2: ";W.Print();
//	D =W.Sort();
//	cout<<"SORTED list 2: ";D.Print();	
//	
//	A.Merge(D);
//	cout<<"\n\nSorted list 1 MERGED with sorted list 2: ";A.Print();
//	
//	R=D.Reverse(A);
//	cout<<"\nThe merged list REVERSED: ";R.Print();
//	
//	Queue<char> B;
//	for(int i=0; i<20; i++)
//		B.EnQueue(rand()%100+9);
//	cout<<endl;
//	B.Print();
//	
//		//cout<<B.DeQueue()<<" ";
//}