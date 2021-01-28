#include <iostream>
using namespace std;
int size=5;	//Size will be compared in every function so defining it globally
struct node{	//will be used as node of a linked list 
	int data;
	node *next;
};
void push(node** head){
	int c=0;	//c will count no. of nodes in linked link
	node *temp=*head;
	while(temp!=0)
	{
		temp=temp->next;
		c++;
	}//c will have count of number of nodes 
	if(c==size)	//if nodes==size i.e linked list is full
		cout<<"\n\t!!! STACK OVERFLOW !!!";
	else		//adding nodes @ start from head
	{
		node *newnode=new node();
		cout<<"\nEnter data  ";cin>>newnode->data;
		newnode->next=*head;
		*head=newnode;
		cout<<"\n"<<newnode->data <<" is added to stack ";
	}
}
void pop(node** head){
	int c=0;	//c will count no. of nodes in linked link
	node *temp=*head;
	while(temp!=0)
	{
		temp=temp->next;
		c++;
	}		//c will have count of number of nodes 
	if(c==0)	//if linked list is empty
		cout<<"\n\t!!! STACK UNDERFLOW !!!";
	else	//node will be deleted from start i.e head 
	{
		node *t=*head;
		cout<<"\n"<<t->data<<" is deleted";
		*head=t->next;
		delete t;
	}
}
void peek(node** head){	//prints top element i.e Element at Head
	int c=1;
	node *temp=*head;
	while(temp->next!=0)
	{
		temp=temp->next;
		c++;
	}
	if(c==1)
		cout<<"\n\t!!! STACK UNDERFLOW !!!";
	else
	{
		node *t=*head;
		cout<<"\nTop Element : "<<t->data;
	}         
}
void display(node** head){
	int c=1;
	node *temp=*head;
	while(temp->next!=0)
	{
		temp=temp->next;
		c++;
	}
	if(c==1)
		cout<<"\n\t!!! STACK UNDERFLOW !!!";
	else
	{
		node *t=*head;
		cout<<"\nSTACK IS : ";
		while(t!=0)
		{
			cout<<"\n"<<t->data;
			t=t->next;
		}
	}
}
int main(){
	node *head=0;
	int choice;
	do{
		cout<<"\n~~~ MENU ~~~\n1.PUSH\t2.POP\t3.Peek\t4.Display\t5.Exit\n ";
		cin>>choice;
		switch(choice)
		{
			case 1:push(&head);break;
			case 2:pop(&head);break;
			case 3:peek(&head);break;
			case 4:display(&head);break;
			case 5:cout<<"\n~~~ THANK YOU ~~~";break;
			default:cout<<"\nInvalid choic try again ";
		}
	}while(choice!=5);
}
