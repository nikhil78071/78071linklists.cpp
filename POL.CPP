#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<math.h>
class pol
{
public:
class node
{
public:
int coeff;
int pow;
node *next;
}*first,*last,*temp,*temp1;

void insert(int,int);
void display();
void sum(pol);
pol()
{
first=last=NULL;
}
};

void pol::display()
{
temp=first;
while(temp!=NULL)
{

if(temp->coeff>0)
{
if(temp->coeff==0)
{
temp=temp->next;
}

if(temp->pow==0)
{
cout<<'+'<<temp->coeff;
}
else if(temp->pow==1)
{
cout<<'+'<<temp->coeff<<"x";
}
else
{
cout<<'+'<<temp->coeff<<"x^"<<temp->pow;
}

}
else
{
if(temp->coeff==0)
{
temp=temp->next;
}
if(temp->pow==0)
{
cout<<temp->coeff;
}
else if(temp->pow==1)
{
cout<<temp->coeff<<"x";
}
else
{
cout<<temp->coeff<<"x^"<<temp->pow;
}
}
temp=temp->next;
}
}

void pol::sum(pol t)
{
int flag;
t.temp1=t.first;
while(t.temp1)
{
temp1=first;
while(temp1)
{
if(temp1->pow == t.temp1->pow)
{
temp1->coeff = temp1->coeff+t.temp1->coeff;
flag=1;
break;
}
else
{
flag=0;
}
temp1=temp1->next;
}
if(flag==0)
{
insert(t.temp1->pow,t.temp1->coeff);
}
t.temp1=t.temp1->next;
}
cout<<"\n\n SUM : ";
display();
}

void pol::insert(int p,int c)
{
temp=new node;
temp->next=NULL;
temp->pow=p;
temp->coeff=c;
if(first==NULL)
first=last=temp;
else
{
last->next=temp;
last=temp;
}
}

int main()
{
clrscr();
pol s1,s2;
int a,b;
char ch;
cout<<"\n First Polynomial  ";
do
{
cout<<"\n Enter the power : ";
cin>>a;
cout<<"\n Enter the coefficient : ";
cin>>b;
s1.insert(a,b);
cout<<"\n Want to add more(y/n) : ";
cin>>ch;
}
while(ch=='y' || ch=='Y');
s1.display();
cout<<"\n\n";
cout<<"\n   Second Polynomial ";
do
{
cout<<"\n Enter the power : ";
cin>>a;
cout<<"\n Enter the coefficient : ";
cin>>b;
s2.insert(a,b);
cout<<"\n Want to add more (y/n) : ";
cin>>ch;
}
while(ch=='y' || ch=='Y');
s2.display();
cout<<"\n\n";
s1.sum(s2);
return 0;
}