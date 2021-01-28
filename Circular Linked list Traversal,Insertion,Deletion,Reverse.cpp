//In circular Linked List the last node will point towards the first node(heaad node)
#include <iostream>
using namespace std;
class node{	//will be used as node of a linked list
	public:
	int data;
	node *next;
};
//insert data @ start of link list.
void push(node** head){			//insert data @ start of link list.
	node *newnode=new node();	//create a node name newnode
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
		}	//temp will reach to last node
		temp->next=newnode;	//last node will point to newnode
		newnode->next=*head;	//newnode point to head node
		*head=newnode;		//head node will point to newnode
	}
	cout<<"\n"<<newnode->data<<" added to link list\n";
}
void insertAt(node** head){	//insert node @ specific position
	int pos,c=1;		//c-count the no. of node passed to reach the required position in linked list
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
		}//temp will reach to ith position(@ which we need to add newnode) and prev will point to previous node
		newnode->next=temp;
		prev->next=newnode;
	}
	cout<<"\n"<<newnode->data<<" added to link list\n";
}
void append(node** head){	//insert node @ end
	node *newnode=new node();
	cout<<"\nEnter data \t";cin>>newnode->data;
	newnode->next=0;
	node *temp=*head;
	while(temp->next!=*head){
		temp=temp->next;
	}	//temp will point to end node
	temp->next=newnode;	//last node will point to newnode
	newnode->next=*head;	//newnode will point to head node i.e newnode will be inserted at end
	cout<<"\n"<<newnode->data<<" added to link list\n";
}
void deleteNode(node** head){	//take key data from user & search if it is present in LL,if found then delete the corresponding node.
	node *temp=*head,*pre=*head;
	int key;
	cout<<"\nEnter Data to delete \t";cin>>key;
	while(temp->next!=*head && temp->data!=key)	//using temp ,key data will be searched in whole LL(Linked List).
	{
		pre=temp;
		temp=temp->next;
	}	//pre will point to previous node of temp
	if(temp->next==*head && temp->data!=key)	//node not found
		cout<<"\n !!! ~~~ Data not found ~~~ !!!";
	else if(temp->next==*head && temp->data==key)	//node found @ end
	{
		pre->next=*head;
		delete temp;
		cout<<"\n!!! ~~~ Data deleted ~~~ !!!";
	}
	else if(temp==*head && temp->data==key)		//node found @ start i.e head
	{
		while(temp->next!=*head){
			temp=temp->next;
		}//temp will be pointing last node & pre will be pointing head
		temp->next=pre->next;	
		*head=pre->next;
		delete pre;
		cout<<"\n!!! ~~~ Data deleted ~~~ !!!";
	}
	else if(temp!=*head)				//node found at temp position
	{
		pre->next=temp->next;
		delete temp;
		cout<<"\n!!! ~~~ Data deleted ~~~ !!!";
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
	do
	{
		cout<<"\n\n\n1.Insert\t2.Delete\t3.Display\t4.Exit\nEnter your Choice \t";
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
			case 3:display(&head);break;
			case 4:cout<<"\n~~~~ THANK YOU ~~~~";break;
		}
	}while(choice!=4);
}
