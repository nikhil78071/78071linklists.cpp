#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#define null 0
class sll
{
public:
       struct node
    {
int info;
struct node *ptr;
    }*temp,*head,*last,*next,*prev;

  sll()
{
   head=null;
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
 void counter();
 void reverse();
 }p;

 void main()
 {
 int i;
 char j;

 clrscr();
      do
  {  cout<<"		        	SINGLE LINK LISTS"<<endl;
     cout<<endl;
     cout<<" 1. CREATE\n 2. TRAVERSE\n 3. INSERT AT BEGIN\n 4. INSERT AT END\n 5. INSERT BETWEEN\n 6. DELETE AT BEGIN\n 7. DELETE AT END\n 8. DELETE BETWEEN\n 9. SEARCH\n 10. COUNTER\n 11. REVERSE\n 12. EXIT\n";
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
  case 10: p.counter();
  break;
  case 11: p.reverse();
  break;
  case 12: exit(0);
  }
  cout<<endl;
  cout<<"Do you want something more (y/n):";
  cin>>j;
  }while(j=='y');

 getch();
 }
 void sll::create()
 {
 char ch='y';
 int n;
 do
 {
 next=new node;
 next->ptr=null;
 cout<<"Enter info you want to Store:";
 cin>>n;
 if(head==null)
 {
 head=temp=next;
 head->info=n;
 last=head;
 }

 else
 {
 temp=new node;
 temp->info=n;
 temp->ptr=null;
 last->ptr=temp;
 last=temp;
 }

 cout<<"Do you want to enter new node (y/n):";
 cin>>ch;
 }
 while(ch=='y');

}

void sll::traverse()
{
    cout<<"\nLinked List is ";
    temp=head;
    while(temp!=null)
 {
     cout<<temp->info<<"->";
     temp=temp->ptr;

   }

   cout<<"null";
   cout<<endl;
   }
void sll::insb()
{
  int n;
  temp=new node;
  cout<<"Enter info you want to Store:";
  cin>>n;
  temp->info=n;
  temp->ptr=head;
  head=temp;
  }
void sll::inse()
{
int n;
temp=new node;
cout<<"Enter info you want to Store:";
cin>>n;
temp->info=n;
last->ptr=temp;
last=temp;
last->ptr=null;
}
void sll::inst()
{
int d,n,count=1;
next=new node;
cout<<"Enter info you want to Store:";
cin>>d;
cout<<"At which position you want to insert:";
cin>>n;
next->info=d;
temp=new node;
temp=head;
while(count<(n-1))
{
temp=temp->ptr;
count++;
}
next->ptr=temp->ptr;
temp->ptr=next;
  }
 void sll::delb()
 {
 temp=new node;
 temp=head;
 head=head->ptr;
 free(temp);
 }

 void sll::dele()
 {
 temp=new node;
 next=new node;
 if(head->ptr==null)
 {
   temp=head;
   head=null;
   free(temp);
   }
else
{
temp=head;
while(temp->ptr!=null)
{
next=temp;
temp=temp->ptr;
}

next->ptr=null;
free(temp);
}
}
void sll::delt()
{
int n,count=1;
temp=new node;
next=new node;
temp=head;
cout<<"Which node you want to delete:";
cin>>n;
while(count<n-1)
{
temp=temp->ptr;
count++;
}
next=temp->ptr;
temp->ptr=next->ptr;
free(next);
}
void sll::search()
{
int n,flag=0;
cout<<"Enter element to be search:";
cin>>n;
temp=new node;
temp=head;
while(temp->ptr!=null)
{
if(temp->info==n)
{
cout<<"Element Found";
flag++;
}
temp=temp->ptr;
}
if(flag!=1)
{
cout<<"Element not found!";
}
}
void sll::counter()
{
 int count=1;
temp=new node;
temp=head;
while(temp->ptr!=null)
{
  temp=temp->ptr;
  count++;
}
cout<<"Total number of node are:"<<count;
}
void sll::reverse()
{
temp=new node;
next=new node;
prev=new node;
prev=null;
temp=head;
while(temp!=null)
{
next=temp->ptr;
temp->ptr=prev;
prev=temp;
temp=next;
}
head=prev;
}


