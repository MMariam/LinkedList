#include <QtCore/QCoreApplication>
#include "node.h"
#include<iostream>
//define preconditions

void InsertHead(node* &head, int thing);//insert a head node
void InsertAfter(node* &head, int num);//insert node with number after "head"
node* Search(node*head, int thing);//search and return the node with the thing
node* Remove(node* &head, node* here);//disconnect the node from the linked list
node* Previous(node* head, node* here);//return the node before the "here" node
void Delete(node* &head, node* here);//delete the memory allocated for "here"
void Print(node* head);//print the damn thing



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}



void InsertHead(node* &head, int thing)//insert a head node
{
node* temp = new node;//create a new node

temp->item=thing;
temp->next=head;
head=temp;
}

void InsertAfter(node* &head, int num)//insert node with number after "head"
{
node* thing=new node;
thing->item=num;
thing->next=head->next;
head->next=thing;
}

node* Search(node*head, int thing)//search and return the node with the thing
{
bool found=false;
node*it;
for(it=head; !found && it!=NULL; it=it->next)
if (it->item==thing)
found=true;
return it;
}

node* Remove(node* &head, node* here)//disconnect the node from the linked list
{
 node* p;
if(here!=NULL)
p=Previous(head, here);
p->next=here->next;
return p;
}

node* Previous(node* head, node* here)//return the node before the "here" node
{
node* it=head;
if(here==head)
return NULL;
while(it->next!=here)
it=it->next;
return it;
}

void Delete(node* &head, node* here)//delete the memory allocated for "here"
{
node* temp=Remove(head, here);
delete temp;
}


void Print(node* head)//print the damn thing
{
while(head!=NULL)
{
cout<<head->item<<" ";
head=head->next;
}
}
