#include <iostream>
using namespace std;
class node{
	public:
	int data;
	node *left,*right;
};
/*func. will compare inserting value with root value and as per result it will recursively call its self for left subtree(if data is small) or for right subtree(if data is greater)
,func. will be called untill root reaches 0 i.e no element left to traverse and then it will create nodes and return its adress corrresponding root of that value.
  func will return node pointers of each subroot */
node* insert(node *root,int data){
	if(root==0)//if root=0 i.e no next element remain in tree then it will insert newnode at that root pointer.
	{
		node *newnode=new node();
		newnode->data=data;
		newnode->left=0;
		newnode->right=0;
		return newnode;
	}
	else if(root->data<data)	//if inserting data is greater than root data then it will be added in right child of root	 
		root->right=insert(root->right,data);//recursively call insert untill no child is left of right side i.e root=0
	else				//if inserting data is less than root data then it will be added in left child of root
		root->left=insert(root->left,data);//recursively call insert untill no child is left of left side i.e root=0
	return root;
}
void preorder(node* root){	//prints in (Root, Left, Righ)
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
