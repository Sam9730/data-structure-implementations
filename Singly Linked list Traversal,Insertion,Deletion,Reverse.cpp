#include <iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;
};
void push(node** head){
	node *newnode=new node();
	cout<<"\nEnter Data\t";cin>>newnode->data;
	newnode->next=*head;
	*head=newnode;
	cout<<"\nLink added at start \n";
}
void insertAfter(node** head){
	int i,count=1;
	node *temp=*head;;
	cout<<"\nEnter position after which you wantto insert data";cin>>i;
	if(i<0)
		cout<<"\nIncorrect Position plz re-enter position";cin>>i;
	node *newnode=new node();
	cout<<"\nEnter Data \t";cin>>newnode->data;
	while(count!=i)
	{
		temp=temp->next;
		count++ ;
	}
	newnode->next=temp->next;
	temp->next=newnode;
	cout<<"\nNode added \n";
}
void append(node** head){
	node *temp=*head;
	node *newnode=new node();
	cout<<"\nEnter Data\t";cin>>newnode->data;
	while(temp->next!=0)
		temp=temp->next;
	newnode->next=0;
	temp->next=newnode;
	cout<<"\nNode added \n";
}
void deleteNode(node** head){
	int key;
	cout<<"\nEnter data key to delete \t";
	cin>>key;
	node *temp=*head;
	node *pre;
	while(temp!=0 && temp->data!=key)
	{
		pre=temp;
		temp=temp->next;
	}
	if(temp==0)
		return ;
	pre->next=temp->next;
	delete temp;
	cout<<"\nNode DELETED";
}
void reverse(node** head){
	node *crnt=*head,*post=*head,*pre=0;
	while(post!=0)
	{
		post=post->next;
		crnt->next=pre;
		pre=crnt;
		crnt=post;
	}
	*head=pre;
}
void display(node** head){
	node *temp=*head;
	cout<<"\n\nList is : ";
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main(){
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
					case 2:insertAfter(&head);break;
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
