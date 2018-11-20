//linked list
#include<iostream>
using namespace std;
class node
{
	public:
	int data;
	node* next;
	node* last;
		node(int x=0)
		{
			data=x;
			next=NULL;
			last=NULL;
		}
};
class SLL
{
	node *head;
	node *tail;
	public :
		SLL()
		{
			head=NULL;
			tail=NULL;
		}
		void addtotail(int);
		void addtohead(int);
		void addtopos(int,int);
		void removefrom(int);
		int middle();
		void sort();
		int count();
		void print();
		void printback();
		void reverse();
};
void SLL::sort()
{
	node *temp;
	temp=head;
	int temp2,k=count();
	for(int i=0;i<k;i++)
	{
			while(temp->next)
			{
				if(temp->data>temp->next->data)
				{
					temp2=temp->data;
					temp->data=temp->next->data;
					temp->next->data=temp2;
				}
				temp=temp->next;
			}
			temp=head;
	}
}
int SLL::middle()
{
	node *temp,*temp2;
	temp=head;
	temp2=tail;
	int tem;
	while(temp!=temp2||temp->next==temp2)
	{
		temp=temp->next;
		temp2=temp2->last;
	}
	return temp->data;
}
void SLL::reverse()
{
	node *temp,*temp2;
	temp=head;
	temp2=tail;
	int tem;
	while(temp!=temp2)//||temp->next==temp2)
	{
		tem=temp->data;
		temp->data=temp2->data;
		temp2->data=tem;
		temp=temp->next;
		temp2=temp2->last;
	}
	cout<<"\nLIST REVERSED";
}
void SLL::removefrom(int pos)
{
	node *temp,*t;
	int c=1;
	temp=head;
	if(head==NULL)
	{
		cout<<"\nNOTHING TO DELETE"	;
	}
	else if(head==tail)
	{
		t=temp->next;
		head=NULL;
		tail=NULL;
	}
	else
	{
		if(pos==1)
		{
			t=head;
			head=temp->next;
		}
		else
			while(c!=pos-1)
			{
				c++;
				temp=temp->next;
			}
			t=temp->next;
			if(t->next==NULL)
			{
				tail=temp;
				temp->next=NULL;
			}
			else
				temp->next=t->next;
				t->next->last=temp;
		delete t;
	}
}
void SLL::addtotail(int x)
{
	node *p=new node(x);
	if(head==NULL)
	{
		head=p;
		tail=p;
	}
	else
	{
		tail->next=p;
		p->last=tail;
		tail=p;
	}
}
int SLL::count()
{
	node *temp;
	int c=0;
	temp=head;
	while(temp!=NULL)
	{
		c++;
		temp=temp->next;
	}
	return c;
}
void SLL::addtohead(int x)
{
	node *p=new node(x);
	node *temp;
	temp=head;
	if(head==NULL)
	{
		head=p;
		tail=p;
	}
	else
	{
		p->next=head;
		head=p;
	}
}
void SLL::addtopos(int x,int pos)
{
	node *p=new node(x);
	node *temp;
	int c=1;
	temp=head;
	if(head==NULL)
	{
		head=p;
	}
	while(c!=pos-1)
	{
		c++;
		temp=temp->next;
	}
	p->last=temp;
	p->next=temp->next;
	temp->next->last=p;
	temp->next=p;
}
void SLL::print()
{
	node *temp;
	temp=head;
	if(head==NULL)
	{
		cout<<"\nNO ELEMENTS ENTERED TILL NOW\n";
	}
	else
		cout<<"\nEntered elements are: ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
void SLL::printback()
{
	node *temp;
	temp=tail;
	if(head==NULL)
	{
		cout<<"\nNO ELEMENTS ENTERED TILL NOW\n";
	}
	else
		cout<<"\nEntered elements are: ";
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->last;
	}
}
int main()
{
	SLL lil;
	int n;
	do{
		cout<<"\n\n1.ADD TO TAIL\n2.ADD TO HEAD\n3.ADD TO POSITION\n4.Remove from position\n5.COUNT\n6.PRINT\n7.Sort\n8.Reverse\n9.Middle element\n0.EXIT\nEnter a choice:";
		cin>>n;
		switch(n)
		{
			case 1:
			{
				int s;
				cout<<"\nEnter element:";
				cin>>s;
				lil.addtotail(s);
				break;
			}
			case 4:
			{
				int temp;
				cout<<"Enter the position:";
				cin>>temp;
				lil.removefrom(temp);
				break;
			}
			case 5:
			{
				cout<<"\nSize is "<<lil.count()<<endl;
				break;
			}
			case 2:
			{
				int s;
				cout<<"\nEnter element:";
				cin>>s;
				lil.addtohead(s);
				break;
			}
			case 3:
			{
				int s,p;
				cout<<"\nEnter element:";
				cin>>s;
				cout<<"\nEnter position:";
				cin>>p;
				lil.addtopos(s,p);
				break;
			}
			case 6:
			{
				lil.print();
				break;
			}
			case 7:
			{
				lil.sort();
				break;
			}
			case 8:
			{
				lil.reverse();
				break;
			}
			case 9:
			{
				cout<<"\nMiddle element :"<<lil.middle();
				break;
			}
			case 0:
			{
				//cout<<"\n\tEXITING....";
				break;
			}
			default :
			{
				cout<<"Enter a valid input";
			}
		}
	}while(n!=0);
}
