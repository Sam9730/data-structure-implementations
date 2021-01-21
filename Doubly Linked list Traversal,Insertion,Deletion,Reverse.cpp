#include <iostream>
using namespace std;
class node
{
	public:
	int data;
	node *pre;
	node *next;
};

void push(node** head)
{
	node *newnode=new node();
	cout<<"\nEnter data \t";cin>>newnode->data;
	newnode->pre=0;
	newnode->next=*head;
	*head=newnode;
	cout<<"\n"<<newnode->data<<" added to link list\n";
}

void insertAt(node** head)
{
	int pos,c=1;
	node *newnode=new node();
	cout<<"\nEnter data \t";cin>>newnode->data;
	newnode->pre=0;
	newnode->next=0;
	cout<<"\nEnter position at which you want to insert data\t";cin>>pos;
	if(*head==0)
		*head=newnode;
	else
	{
		node *temp=*head,*prev;
		while(c<pos)
		{
				prev=temp;
				temp=temp->next;
				c++;
		}
		newnode->pre=prev;
		newnode->next=temp;
		prev->next=newnode;
		temp->pre=newnode;
	}
	cout<<"\n"<<newnode->data<<" added to link list\n";
}

void append(node** head)
{
	node *newnode=new node();
	cout<<"\nEnter data \t";cin>>newnode->data;
	newnode->pre=0;
	newnode->next=0;
	if(*head==0)
		*head=newnode;
	else
	{
		node *temp=*head;
		while(temp->next!=0)
			temp=temp->next;
		newnode->pre=temp;
		temp->next=newnode;
	}
	cout<<"\n"<<newnode->data<<" added to link list\n";
}

void deleteNode(node** head)
{
	node *temp=*head;
	int key;
	cout<<"\nEnter Data to delete \t";cin>>key;
	while(temp!=0 && temp->data!=key)
	{
		temp=temp->next;
	}
	if(temp==0)
		cout<<"\n !!! ~~~ Data not found ~~~ !!!";
	else
	{
		node *frwd=temp->next,*bkwd=temp->pre;
		frwd->pre=bkwd;
		bkwd->next=frwd;
		delete temp;
		cout<<"\n Node Deleted ";
	}
}

void reverse(node** head)
{
	node*temp=*head,*t;
	while(temp!=0)
	{
		t=temp->pre;
		temp->pre=temp->next;
		temp->next=t;
		temp=temp->pre;
	}
	*head=t->pre;
}

void display(node** head)
{
	node *temp=*head;
	cout<<"\n\tList is : ";
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}

int main() 
{
	int choice,i;
	node *head=0;
	while(choice!=5)
	{
		cout<<"\n\n\n1.Insert\t2.Delete\t3.Reverse\t4.Display\t5.Exit\nEnter your Choice \t";
		cin>>choice;
		switch(choice)
		{
			case 1:cout<<"\n1.Insert at start\t2.Insrt at position\t3.Insert at end\nEnter Choice \t";cin>>i;
				switch(i)
				{
					case 1:push(&head);break;
					case 2:insertAt(&head);break;
					case 3:append(&head);break;
					default:break;
				};break;
			case 2:deleteNode(&head);break;
			case 3:reverse(&head);break;
			case 4:display(&head);break;
			case 5:cout<<"\n~~~~ THANK YOU ~~~~";break;
		}
	}
}