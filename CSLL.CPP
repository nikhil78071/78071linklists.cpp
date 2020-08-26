#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#define null 0
class csll
{
    public:
       struct node
    {
    int info;
    struct node*ptr;

    }*temp,*head,*last,*tail,*next,*pre;

  csll()
{
   head->ptr=null;

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
     cout<<"			CIRCULAR SINGLE LINK LIST"<<endl;
     cout<<endl;
     cout<<" 1.  CREATE\n 2.  TRAVERSE\n 3.  INSERT IN BEGINING\n 4.  INSERT AT END\n 5.  INSERT AT BETWEEN\n 6.  DELETE IN BEGINING\n 7.  DELETE AT END\n 8.  DELETE AT BETWEEN\n 9.  SEARCH\n 10. REVERSE\n 11. COUNTER\n 12. EXIT\n";
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
 void csll::create()
 {
 char ch='y';
 int n;
 do
 {
 temp=new node;
 temp->ptr=null;
 cout<<"Enter info you want to store:";
 cin>>n;
 if(head==null)
 {
 head=temp;
 head->info=n;
 tail=head;
 }

 else
 {

 temp->info=n;
 tail->ptr=temp;
 tail=temp;
 tail->ptr=head;
 }

 cout<<"Do you want to enter new node(y/n):";
 cin>>ch;
 }
 while(ch=='y');

}

void csll::traverse()
{
    cout<<"\nLinked List is:";
    temp=head;
    while(temp->ptr!=head)
 {
     cout<<temp->info<<"->";
     temp=temp->ptr;

   }

   cout<<temp->info;
   cout<<endl;
   }
 void csll::insb()
{
  int n;
  temp=new node;
  cout<<"Enter info you want to store:";
  cin>>n;
  temp->info=n;
  if(tail==null)
  {
  tail=temp;
  tail->ptr=temp;
  }
  else
  {
  temp->ptr=tail->ptr;
  tail->ptr=temp;
  head=temp;
  }
  }
void csll::inse()
{
int n;
temp=new node;
cout<<"Enter info you want to store:";
cin>>n;
temp->info=n;
if(tail==null)
{
tail=temp;
tail->ptr=temp;
}
else
{
temp->ptr=tail->ptr;
tail->ptr=temp;
tail=temp;
}


}
void csll::inst()
{
int d,n,count=1;
temp=new node;
next=new node;
cout<<"Enter info you want to store:";
cin>>d;
cout<<" At Which position you want to insert a new node:";
cin>>n;
next->info=d;
temp=tail->ptr;
while(count<(n-1))
{
 temp=temp->ptr;
 count++;
 }
next->ptr=temp->ptr;
temp->ptr=next;
  }
 void csll::delb()
 {
 temp=new node;
 temp=tail->ptr;
 if(tail==null)
 {
 cout<<"Linklist is Empty."<<endl;
 }
 else if(temp->ptr==temp)
 {
 tail=0;
 free(temp);
 }
 else
 {
 tail->ptr=temp->ptr;
 head=temp->ptr;
 free(temp);
 }
 }

 void csll::dele()
 {
 next=new node;
 temp=new node;
 temp=tail->ptr;
 while(temp->ptr!=tail->ptr)
 {
 next=temp;
 temp=temp->ptr;
 }
 next->ptr=tail->ptr;
 tail=next;
 free(temp);
}
void csll::delt()
{
int n,count=1;
temp=new node;
next=new node;
cout<<"Which node you want to delete:";
cin>>n;
temp=tail->ptr;
while(count<(n-1))
{
temp=temp->ptr;
count++;
}
next=temp->ptr;
temp->ptr=next->ptr;
free(next);
}
void csll::search()
{
int n,flag=0;
cout<<"Enter element to be search:";
cin>>n;
temp=new node;
temp=tail->ptr;
while(temp!=tail)
{
if(temp->info==n)
{
cout<<"Element Found."<<endl;
flag++;
}
temp=temp->ptr;
}
if(temp->info==n)
{
  cout<<"Element Found."<<endl;
  flag++;
  }
if(flag==0)
{
cout<<"Element not found!"<<endl;
}
}
void csll::reverse()
{
temp=new node;
pre=new node;
next=new node;
temp=tail->ptr;
next=temp->ptr;
if(tail==null)
{
cout<<"Linklist is Empty."<<endl;
}
else if(temp->ptr==temp)
{
cout<<"Single Node."<<endl;
}
else
{
while(temp!=tail)
{
pre=temp;
temp=next;
next=temp->ptr;
temp->ptr=pre;
}
next->ptr=tail;
tail=next;
head=temp;
}
}
void csll::counter()
{
int count=1;
temp=new node;
temp=tail->ptr;
while(temp->ptr!=tail->ptr)
{
temp=temp->ptr;
count++;
}
cout<<"Total no. of nodes are:"<<count<<endl;
}
