#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#define NULL 0

class oll

{

public:

  class node

{

   public:

    int info;
    node *next;

} *first,*last,*temp,*temp1;



oll()

{

first=last=NULL;

}

~oll()

{

temp=first;

while(first!=NULL)

{

temp=temp->next;

delete first;

first=temp;

}

}

void insert(int);

void display();

void deletNode(int);

void merge(oll);

};







void oll::insert(int ele)

{

temp=new node;

temp->info=ele;

temp->next=NULL;

if(first==NULL)

{

first=last=temp;

}

else if(temp->info <= first->info)

{

temp->next=first;

first=temp;

}

else if(temp->info >= last->info)

{

last->next=temp;

last=temp;

}

else

{

temp1=first;

while(temp1!=last)

{

if((temp->info > temp1->info) && (temp->info <= temp1->next->info))

{

temp->next=temp1->next;

temp1->next=temp;

}

temp1=temp1->next;

}

}

}







void oll::deletNode(int n)

{

temp=first;

if(n==1)

{

temp=first;

first=first->next;

delete temp;

}

else

{

for(int i=1;i<n-1;i++)

{

temp=temp->next;

}

temp1=temp->next;

temp->next=temp1->next;

delete temp1;

cout<<"\n Node is Deleted Successfully\n";

}

}







void oll::display()

{

temp=first;

cout<<"\n LINKED LIST is : ";

while(temp!=NULL)

{

cout<<" "<<temp->info;

temp=temp->next;

}

}







void oll::merge(oll ob)

{

ob.temp=ob.first;

while(ob.temp!=NULL)

{

insert(ob.temp->info);

ob.temp=ob.temp->next;

}

}







int main()

{

int ch,ele,n,i=1;

oll ob1,ob2;

do

{

cout<<"\n MAIN MENU";

cout<<"\n 1. insert";

cout<<"\n 2. delete";

cout<<"\n 3. merge";

cout<<"\n 4. display";

cout<<"\n Enter you choice: ";

cin>>ch;

switch(ch)

{

case 1: cout<<"\n Enter  element you want to insert : ";

	    cin>>ele;

	    ob1.insert(ele);

	    break;

case 2: cout<<"\n Enter the position from which the node is to be deleted : ";

 cin>>n;

 ob1.deletNode(n);

 break;

case 3: cout<<"\n Enter the no. of nodes in the second list : ";

 cin>>n;

while(n>0)

{

cout<<"\n Enter the element nunber "<<i<<" : ";

cin>>ele;

ob2.insert(ele);

i++;

n--;

}

ob1.merge(ob2);

 break;

case 4: ob1.display();

 break;

default: break;

}

}while(ch!=0);

return 0;

}