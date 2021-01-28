#include <iostream>
using namespace std;
class node{	//will be used as node of a linked list
	public:
	int data;
	node *next;
};
//insert data @ start of link list.
void push(node** head){	//recieve address of head pointer using double pointer reference name head.
	node *newnode=new node();	//create a node name newnode
	cout<<"\nEnter Data\t";cin>>newnode->data;
	newnode->next=*head;
	*head=newnode;	`		//head pointer will point to newnode i.e newnode will be added @ start
	cout<<"\nLink added at start \n";
}
void insertAfter(node** head){	//insert node after a specific position
	int i,count=1; //count-count the no. of node present in linked list
	node *temp=*head;;
	cout<<"\nEnter position after which you wantto insert data";cin>>i;
	if(i<0){
		cout<<"\nIncorrect Position plz re-enter position";cin>>i;
	}
	else{
		node *newnode=new node();
		cout<<"\nEnter Data \t";cin>>newnode->data;
		while(count!=i)
		{
			temp=temp->next;
			count++ ;
		}//temp will reach to ith position(after which we need to add newnode)
		newnode->next=temp->next;
		temp->next=newnode;
		cout<<"\nNode added \n";
	}
}
void append(node** head){	//insert node @ end
	node *temp=*head;
	node *newnode=new node();
	cout<<"\nEnter Data\t";cin>>newnode->data;
	while(temp->next!=0){
		temp=temp->next;
	}			//temp will reach to end node
	newnode->next=0;
	temp->next=newnode;	//last node's next pointer will point newnode i.e newnode will become last node
	cout<<"\nNode added \n";
}
void deleteNode(node** head){//take key data from user & search if it is present in LL,if found then delete the corresponding node.
	int key;
	cout<<"\nEnter data key to delete \t";
	cin>>key;
	node *temp=*head;
	node *pre;
	while(temp!=0 && temp->data!=key)//using temp ,key data will be searched in whole LL(Linked List).
	{
		pre=temp;
		temp=temp->next;
	}
	if(temp==0)	//if temp reaches end and key data isn't found
		return ;
	pre->next=temp->next;
	delete temp;	//the the node that temp pointer is pointing
	cout<<"\nNode DELETED";
}
void reverse(node** head){
	node *crnt=*head,*post=*head,*pre=0; //pre-point to previous node,crnt-point to current node,post-will poin t to next node
	while(post!=0)
	{
		post=post->next;
		crnt->next=pre;	
		pre=crnt;		
		crnt=post;
	}
	*head=pre;	//head will point to last node & LL will start from last i.e Reversed 
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
