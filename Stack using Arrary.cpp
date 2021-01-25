#include <iostream>
using namespace std;
int *stack,n;
int top=-1;
void push(){
	if(top==n-1)
		cout<<"\n\t!!! STACK OVERFLOW !!!";
	else
	{
		top++;
		cout<<"\nEnter Data to Stack  ";cin>>stack[top];
		cout<<"\n"<<stack[top]<<" added to STACK ";
	}
}
void pop(){
	if(top==-1)
		cout<<"\n\t!!! STACK UNDERFLOW !!!";
	else
	{
		cout<<"\n"<<stack[top]<<" removed from STACK. ";
		top--;
	}
}
void peek(){
	if(top==-1)
		cout<<"\n\t!!! STACK UNDERFLOW !!!";
	else
		cout<<"\nTop Element : "<<stack[top];
}
void display(){
	if(top==-1)
		cout<<"\n\t!!! STACK UNDERFLOW !!!";
	else
	{
		int i;
		cout<<"\nSTACK : ";
		for(i=top;i>=0;i--)
		{
			cout<<"\n"<<stack[i];
		}
	}
}
int main(){
	cout<<"\nEnter Size of Stack : ";cin>>n;
	stack=new int(n);
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
