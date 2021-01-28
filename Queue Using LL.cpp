#include <iostream>
using namespace std;
int size=5;	//Size will be compared in every function so defining it globally
struct node{	//will be used as node of a linked list 
	int data;
	node *next;
};
void push(node** head){
	int c=0;	//c will count no. of element in stack
	node *temp=*head,*pre;
	while(temp!=0)
	{
		pre=temp;
		temp=temp->next;
		c++;
	}		//c will have count of number of element,and pre will point to last element node
	if(c==size)	//if nodes==size i.e queue is full
		cout<<"\n\t!!! Queue OVERFLOW !!!";
	else		//adding nodes from end
	{
		node *newnode=new node();
		cout<<"\nEnter data  ";cin>>newnode->data;
		newnode->next=0;
		if(*head==0)	//if its first element to be added then it will be pointed by head
			*head=newnode;
		else		
			pre->next=newnode;	//last element will point to newnode and newnode will be end element
		cout<<"\n"<<newnode->data <<" is added to Queue";
	}
}
void pop(node** head){
	int c=0;
	node *temp=*head;
	if(*head==0)	//if queue is empty
 	       cout<<"\n\t!!! Queue UNDERFLOW  !!!";
    	else	//deleting element from head side
    	{
        	cout<<"\n"<<(*head)->data<<" DELETED ";
        	*head=(*head)->next;
		delete temp;
    	}  	
}
void peek(node** head){		//prints element @ the end i.e element which was added first
	int c=1;
	node *temp=*head;
	while(temp->next!=0)
	{
		temp=temp->next;
		c++;
	}
	if(c==1)
		cout<<"\n\t!!! Queue UNDERFLOW !!!";
	else
		cout<<"\nTop Element : "<<(*head)->data;
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
		cout<<"\n\t!!! Queue UNDERFLOW !!!";
	else
	{
		node *t=*head;
		cout<<"\nQUEUE IS : ";
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
