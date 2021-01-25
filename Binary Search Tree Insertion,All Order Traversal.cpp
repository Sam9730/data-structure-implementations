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
int main() {
	node *root=0;
	root=insert(root,100);
	root=insert(root,20);
	root=insert(root,200);
	root=insert(root,10);
	root=insert(root,30);
	root=insert(root,150);
	root=insert(root,300);
	cout<<"\nPreorder Traversal : ";
	preorder(root);
	cout<<"\nInorder Traversal : ";
	inorder(root);
	cout<<"\nPostorder Traversal : ";
	postorder(root);
	return 0;
}
