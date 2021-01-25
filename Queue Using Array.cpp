#include <iostream>
using namespace std;
int q[5];
int front=-1,rear=0;
void push(){
	if(rear==5)
		cout<<"\n\t!!! Queue is OVERFLOW !!!";
	else
	{
        	if(front==-1)
            		front=0;
		cout<<"\nEnter Data to Queue  ";cin>>q[rear];
		cout<<"\n"<<q[rear]<<" added to Queue ";
       		++rear;
	}
}
void pop(){
	if(front==-1 || front>=rear)
		cout<<"\n\t!!! Queue is UNDERFLOW !!!";
	else
	{
		int i;
		cout<<"\n "<<q[front]<<" is deleted.";
		front++;
	}
}
void peek(){
	if(front==-1 || front>=rear)
		cout<<"\n\t!!! Queue UNDERFLOW !!!";
	else
		cout<<"\nTop Element : "<<q[front];
}
void display(){
	if(front==-1 || front==rear) 
		cout<<"\n\t!!! Queue UNDERFLOW !!!";
	else
	{
		int i;
		cout<<"\nQueue : ";
		for(i=front;i<rear;i++)
		{
			cout<<"\n"<<q[i];
		}
	}
}
int main() {
	int choice;
	do{
		cout<<"\n~~~ MENU ~~~\n1.PUSH\t2.POP\t3.Peek\t4.Display\t5.Exit\n ";
		cin>>choice;
		switch(choice)
		{
			case 1:push();break;
			case 2:pop();break;
			case 3:peek();break;
			case 4:display();break;
			case 5:cout<<"\n~~~ THANK YOU ~~~";break;
			default:cout<<"\nInvalid choice plz try again ";
		}
	}while(choice!=5);
}
