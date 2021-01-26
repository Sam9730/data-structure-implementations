#include <iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;
};
void push(node** head){
	node *newnode=new node();
	node *temp=*head;
	cout<<"\nEnter data \t";cin>>newnode->data;
	if(*head==0)
	{
		*head=newnode;
		newnode->next=*head;
	}
	else
	{
		while(temp->next!=*head){
			temp=temp->next;
		}
		temp->next=newnode;
		newnode->next=*head;
		*head=newnode;
	}
	cout<<"\n"<<newnode->data<<" added to link list\n";
}
void insertAt(node** head){
	int pos,c=1;
	node *newnode=new node();
	cout<<"\nEnter data \t";cin>>newnode->data;
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
		newnode->next=temp;
		prev->next=newnode;
	}
	cout<<"\n"<<newnode->data<<" added to link list\n";
}
void append(node** head){
	node *newnode=new node();
	cout<<"\nEnter data \t";cin>>newnode->data;
	newnode->next=0;
	node *temp=*head;
	while(temp->next!=*head){
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=*head;	
	cout<<"\n"<<newnode->data<<" added to link list\n";
}
void deleteNode(node** head){
	node *temp=*head,*pre=*head;
	int key;
	cout<<"\nEnter Data to delete \t";cin>>key;
	while(temp->next!=*head && temp->data!=key)
	{
		pre=temp;
		temp=temp->next;
	}
	if(temp->next==*head && temp->data!=key)
		cout<<"\n !!! ~~~ Data not found ~~~ !!!";
	else if(temp->next==*head && temp->data==key)
	{
		pre->next=*head;
		delete temp;
		cout<<"\n 1 !!! ~~~ Data deleted ~~~ !!!";
	}
	else if(temp==*head && temp->data==key)
	{
		while(temp->next!=*head)
			temp=temp->next;
		temp->next=pre->next;
		*head=pre->next;
		delete pre;
		cout<<"\n 2 !!! ~~~ Data deleted ~~~ !!!";
	}
	else if(temp!=*head)
	{
		pre->next=temp->next;
		delete temp;
		cout<<"\n 3 !!! ~~~ Data deleted ~~~ !!!";
	}
}
void display(node** head){
	node *temp=*head;
	cout<<"\n\tList is : ";
	while(temp->next!=*head)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data<<" ";
}
int main() {
	int choice,i;
	node *head=0;
	while(choice!=5)
	{
		cout<<"\n\n\n1.Insert\t2.Delete\t4.Display\t5.Exit\nEnter your Choice \t";
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
			case 4:display(&head);break;
			case 5:cout<<"\n~~~~ THANK YOU ~~~~";break;
		}
	}
}
