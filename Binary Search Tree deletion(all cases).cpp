#include <iostream>
using namespace std;
class node{
	public:
	int data;
	node *left,*right;
};
node* insert(node *root,int data){
	if(root==0)
	{
		node *newnode=new node();
		newnode->data=data;
		newnode->left=0;
		newnode->right=0;
		return newnode;
	}
	else if(root->data<data)
		root->right=insert(root->right,data);
	else
		root->left=insert(root->left,data);
	return root;
}
void preorder(node* root){
	if(root==0)
		return ;
	cout<<" "<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void inorder(node* root){
	if(root==0)
		return ;
	inorder(root->left);
	cout<<" "<<root->data;
	inorder(root->right);
}
void postorder(node* root){
	if(root==0)
		return ;
	postorder(root->left);
	postorder(root->right);
	cout<<" "<<root->data;
}
node* search(node* root,node** parent ,int data){
	while(root->data!=data && root!=0)
	{
		*parent=root;
		if(root->data>data)
			root=root->left;
		else
			root=root->right;
	}
	if(root->data==data)
		return root;
	else
		return 0;
}
void deleteNode(node *root,int data){
	node *parent=0;
	node *temp=search(root,&parent,data);
	if(temp==0 || root==0)
		cout<<"\n"<<data<<" not found in tree.";
	else if(temp->left==0 && temp->right==0)
	{
		if(temp!=root)
		{
			if(parent->left==temp)
				parent->left=0;
			else
				parent->right=0;
		}
		else
			root=0;
		
		delete temp;
	}
	//Inorder Succesor
	else if(temp->right!=0 && temp->left!=0)
	{
		node *pret,*t=temp->right;
		while(t->left!=0)
		{
			pret=t;
			t=t->left;
		}
		temp->data=t->data;
		pret->left=0;
		
		delete t;
	}
	else if(temp->right!=0 || temp->left!=0)
	{
		if(temp->right!=0)
		{
			if(parent->left==temp)
				parent->left=temp->right;
			else
				parent->right=temp->right;
		}
		else
		{
			if(parent->left==temp)
				parent->left=temp->left;
			else
				parent->right=temp->left;
		}
		delete temp;
	}
}
int main() {
	node *root=0;
	root=insert(root,15);
	root=insert(root,10);
	root=insert(root,20);
	root=insert(root,8);
	root=insert(root,12);
	root=insert(root,16);
	cout<<"\nInorder Traversal Before Delete: ";
	inorder(root);
	deleteNode(root,16);
	cout<<"\nInorder Traversal After Delete: ";
	inorder(root);	
	return 0;
}
