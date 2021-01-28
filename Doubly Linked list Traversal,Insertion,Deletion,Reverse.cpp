#include <iostream>
using namespace std;
class node{	//will be used as node of a linked list
	public:
	int data;
	node *pre;
	node *next;
};
//insert data @ start of link list.
void push(node** head){		//recieve address of head pointer using double pointer reference name head.
	node *newnode=new node();	//create a node name newnode
	cout<<"\nEnter data \t";cin>>newnode->data;
	newnode->pre=0;
	newnode->next=*head;
	*head=newnode;
	cout<<"\n"<<newnode->data<<" added to link list\n";
}
//insert node @ specific position
void insertAt(node** head){
	int pos,c=1;	//c-count the no. of node passed to reach the required position in linked list
	node *newnode=new node();
	cout<<"\nEnter data \t";cin>>newnode->data;
	newnode->pre=0;
	newnode->next=0;
	cout<<"\nEnter position at which you want to insert data\t";cin>>pos;
	if(*head==0)	//if LL is empty
		*head=newnode;
	else
	{
		node *temp=*head,*prev;
		while(c<pos)
		{
			prev=temp;
			temp=temp->next;
			c++;
		}	//temp will reach to desired position(pos) and prev will point to its previous node
		newnode->pre=prev;	//newnode's pre will point to previous node
		newnode->next=temp;	//newnode's next will point to node presentg at the desired position(pos)
		prev->next=newnode;	//previous node's next will point to newnode i.e newnode will be inserted @ desired position
		temp->pre=newnode;	
	}
	cout<<"\n"<<newnode->data<<" added to link list\n";
}
void append(node** head){	//insert node @ end
	node *newnode=new node();
	cout<<"\nEnter data \t";cin>>newnode->data;
	newnode->pre=0;
	newnode->next=0;
	if(*head==0)
		*head=newnode;
	else
	{
		node *temp=*head;
		while(temp->next!=0){
			temp=temp->next;
		}	//temp will point to end node
		newnode->pre=temp;
		temp->next=newnode;	//last node's next pointer will point newnode i.e newnode will become last node
	}
	cout<<"\n"<<newnode->data<<" added to link list\n";
}
void deleteNode(node** head){	//take key data from user & search if it is present in LL,if found then delete the corresponding node.
	node *temp=*head;
	int key;
	cout<<"\nEnter Data to delete \t";cin>>key;
	while(temp!=0 && temp->data!=key){	//using temp ,key data will be searched in whole LL(Linked List).
		temp=temp->next;
	}
	if(temp==0)	//if temp reaches end and key data isn't found
		cout<<"\n !!! ~~~ Data not found ~~~ !!!";
	else	//i.e temp is pointing key data node
	{
		node *frwd=temp->next,*bkwd=temp->pre;//frwd-point to next node temp,bkwrd-point to previous node of temp
		frwd->pre=bkwd;		//next node will be pointing to pre node.
		bkwd->next=frwd;	//previous node's will be pointing to next node
		delete temp;	//the node having key data & that temp pointer is pointing will be deleted
		cout<<"\n Node Deleted ";
	}
}
void reverse(node** head){
	node*temp=*head,*t;
	while(temp!=0)
	{
		//Every node's pre & next pointer will swap each others value
		t=temp->pre;
		temp->pre=temp->next;
		temp->next=t;
		temp=temp->pre;
	}
	*head=t->pre;	//head will point to last node & LL will start from last i.e Reversed
}
void display(node** head){
	node *temp=*head;
	cout<<"\n\tList is : ";
	while(temp!=0)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
int main() {
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
