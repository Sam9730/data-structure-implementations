#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *left,*right;
};
node* creat(){
	int x;
	cout<<"\nEnter Data(-1 for no node)  ";cin>>x;
	if(x==-1)
		return 0;
	node* newnode=new node();
	newnode->data=x;
	cout<<"\nEnter left child of "<<x;
	newnode->left=creat();
	cout<<"\nEnter right child of "<<x;
	newnode->right=creat();
	return newnode;
}
int main(){
	node *root=0;
	root=creat();
}
