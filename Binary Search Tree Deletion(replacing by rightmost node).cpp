#include <iostream>
using namespace std;
class node{
	public:
	int data;
	node *left,*right;
};
/* insert() func. will create nodes for left child of root by recursively calling itself untill user enter -1,then it will create nodes for right
  child untill user again enters -1.
  func will return node pointers of each subroot */
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
void preorder(node* root){	//prints in (Root, Left, Right)
	if(root==0){
		return ;
	}
	cout<<" "<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void inorder(node* root){	//prints in (Left, Root, Right)
	if(root==0){
		return ;
	}
	inorder(root->left);
	cout<<" "<<root->data;
	inorder(root->right);
}
void postorder(node* root){	//prints in (Left, Right, Root)
	if(root==0){
		return ;
	}
	postorder(root->left);
	postorder(root->right);
	cout<<" "<<root->data;
}
node* search(node* root,int data){	//search for a node in a tree and return its position if found else return 0.
	while(root->data!=data && root!=0)
	{
		if(root->data>data)
			root=root->left;
		else
			root=root->right;
	}
	if(root->data==data)
		return root;
}
void deleteNode(node *root,int data){	//replace the node with its rightmost child of the tree.
	node *parent,*temp=search(root,data);//search function will return data's location which will be stored in temp pointer.
	while(root->right!=0)
	{
		parent=root;	//parent pointr will always point to parent node of root.
		root=root->right;
	}//root will be now pointing to rightmost child of tree.
	temp->data=root->data;	//element replaced by rightmost child
	parent->right=0;	//rightmost root deleted
	cout<<"\n"<<root->data<<" Deleted"; 
	delete root;
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
	cout<<"\nPreorder Traversal Before Delete: ";
	preorder(root);
	cout<<"\nInorder Traversal Before Delete: ";
	inorder(root);
	cout<<"\nPostorder Traversal Before Delete: ";
	postorder(root);
	deleteNode(root,20);
	cout<<"\nPreorder Traversal After Delete: ";
	preorder(root);
	cout<<"\nInorder Traversal After Delete: ";
	inorder(root);
	cout<<"\nPostorder Traversal After Delete: ";
	postorder(root);
	return 0;
}
