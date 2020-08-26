#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#define null 0
class dll
{
public:
       struct node
    {
     int info;
     struct node *prev;
     struct node *next;
    }*temp,*head,*last,*tail,*pre;

  dll()
{
   head->next=null;
   head->prev=null;
   }
 void create();
 void traverse();
 void insb();
 void inse();
 void inst();
 void delb();
 void dele();
 void delt();
 void search();
 void reverse();
 void counter();
 }p;

 void main()
 {
 int i;
 char j;

 clrscr();
      do
  {
     cout<<"			DOUBLE  LINK  LIST"<<endl;
     cout<<endl;
     cout<<" 1.  CREATE\n 2.  TRAVERSE\n 3.  INSERT IN BEGINING\n 4.  INSERT AT END\n 5.  INSERT AT BETWEEN\n 6.  DELETE IN BEGINING\n 7.  DELETE AT END\n 8.  DELETE IN BETWEEN\n 9.  SEARCH\n 10. REVERSE\n 11. COUNTER\n 12. EXIT\n";
     cout<<endl;
     cout<<"Enter your choice:";
     cin>>i;
 switch(i)
 {
  case 1: p.create();
  break;
  case 2: p.traverse();
  break;
  case 3: p.insb();
  break;
  case 4: p.inse();
  break;
  case 5: p.inst();
  break;
  case 6: p.delb();
  break;
  case 7: p.dele();
  break;
  case 8: p.delt();
  break;
  case 9: p.search();
  break;
  case 10: p.reverse();
  break;
  case 11: p.counter();
  break;
  case 12: exit(0);
  }
  cout<<endl;
  cout<<"Do you want something more(y/n):";
  cin>>j;
  }while(j=='y');

 getch();
 }
 void dll::create()
 {
 char ch='y';
 int n;
 do
 {
 temp=new node;
 temp->next=null;
 cout<<endl;
 cout<<"Enter info you want to store:";
 cin>>n;
 if(head==null)
 {
 head=temp;
 head->info=n;
 last=head;
 }

 else
 {
 temp=new node;
 temp->info=n;
 temp->next=null;
 last->next=temp;
 temp->prev=last;
 last=temp;
 }

 cout<<"Do you want new node(y/n):";
 cin>>ch;
 }
 while(ch=='y');

}

void dll::traverse()
{
    cout<<"\nLinked List is:";
    temp=head;
    while(temp!=null)
 {
     cout<<temp->info<<"->";
     temp=temp->next;

   }

   cout<<"null";
   cout<<endl;
   }
 void dll::insb()
{
  int n;
  temp=new node;
  cout<<"Enter info you want to store:";
  cin>>n;
  temp->info=n;
  temp->prev=null;
  temp->next=head;
  head->prev=temp;
  head=temp;
  }
void dll::inse()
{
int n;
temp=new node;
cout<<"Enter info you want to store:";
cin>>n;
temp->info=n;
temp->next=null;
temp->prev=last;
last->next=temp;
last=temp;
}
void dll::inst()
{
int d,n,count=1;
temp=new node;
pre=new node;
cout<<"Enter info you want to store:";
cin>>d;
cout<<"At which position you want to insert a new node:";
cin>>n;
pre->info=d;
temp=head;
while(count<(n-1))
{
temp=temp->next;
count++;
}
pre->next=temp->next;
temp->next->prev=pre;
temp->next=pre;
pre->prev=temp;
}
 void dll::delb()
 {
 temp=new node;
 temp=head;
 head=head->next;
 temp->next=null;
 head->prev=null;
 free(temp);
 }

 void dll::dele()
 {
 temp=new node;
 if(head->next==null)
 {
   temp=head;
   head=null;
   free(temp);
   }
else
{
temp=last;
last=last->prev;
temp->prev=null;
last->next=null;
free(temp);
}
}
void dll::delt()
{
int n,count=1;
temp=new node;
pre=new node;
temp=head;
cout<<"Which node you want to delete:";
cin>>n;
while(count<(n-1))
{
temp=temp->next;
count++;
}
pre=temp->next;
temp->next=temp->next->next;
temp->next->prev=temp;
free(pre);
}
void dll::search()
{
int n,flag=0;
cout<<"Enter element to be search:";
cin>>n;
temp=new node;
temp=head;
while(temp!=null)
{
if(temp->info==n)
{
cout<<endl;
cout<<"Element Found."<<endl;
flag++;
}
temp=temp->next;
}
if(flag==0)
{
cout<<endl;
cout<<"Element not found!"<<endl;
}
}
void dll::reverse()
{
temp=new node;
pre=new node;
pre=head;
if(pre==null)
{
cout<<"Linklist is empty."<<endl;
}
else if(pre->next==null)
{
cout<<"Single node."<<endl;
}
else
{
while(pre!=null)
{
temp=pre->prev;
pre->prev=pre->next;
pre->next=temp;
pre=pre->prev;
}
if(temp!=null)
{
temp=temp->prev;
}
}
head=temp;
}
void dll::counter()
{
int count=1;
temp=new node;
temp=head;
while(temp->next!=null)
{
temp=temp->next;
count++;
}
cout<<endl;
cout<<"Total no. of nodes are:"<<count<<endl;
}


