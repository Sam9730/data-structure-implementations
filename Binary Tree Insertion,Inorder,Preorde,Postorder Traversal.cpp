#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *left,*right;
};
void inorder(node *root){
	if(root==0)
		return ;
	inorder(root->left);
	cout<<" "<<root->data;
	inorder(root->right);
}
void preorder(node *root){
	if(root==0)
		return ;
	cout<<" "<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void postorder(node *root){
	if(root==0)
		return ;
	postorder(root->left);
	postorder(root->right);
	cout<<" "<<root->data;
}
node* creat(){
	int x;
	cout<<"\nEnter Data(-1 for no node)  ";cin>>x;
	if(x==-1)
		return 0;
	node* newnode=new node();
	newnode->data=x;
	newnode->left=newnode->right=0;
	cout<<"\nEnter left child of "<<x;
	newnode->left=creat();
	cout<<"\nEnter right child of "<<x;
	newnode->right=creat();
	return newnode;
}
int main(){
	node *root=0;
	root=creat();
	cout<<"\nInorder Traversal : ";
	inorder(root);
	cout<<"\nPreorder Traversal : ";
	preorder(root);
	cout<<"\nPostorder Traversal : ";
	postorder(root);
}
