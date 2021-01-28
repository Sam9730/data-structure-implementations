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
	if(root==0)
		return ;
	cout<<" "<<root->data;
	preorder(root->left);
	preorder(root->right);
}
void inorder(node* root){	//prints in (Left, Root, Right)
	if(root==0)
		return ;
	inorder(root->left);
	cout<<" "<<root->data;
	inorder(root->right);
}
void postorder(node* root){	//prints in (Left, Right, Root)
	if(root==0)
		return ;
	postorder(root->left);
	postorder(root->right);
	cout<<" "<<root->data;
}
node* search(node* root,node** parent ,int data){ //search for a node in a tree and return its position if found
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
	node *temp=search(root,&parent,data);//search function will return data's location which will be stored in temp pointer.
	if(temp==0 || root==0){		//if search return 0 i.e data is not found or root==0 i.e no data is present.
		cout<<"\n"<<data<<" not found in tree.";
	}
	else if(temp->left==0 && temp->right==0)//if data node has no childs
	{
		if(temp!=root)	//if its not root element
		{
			if(parent->left==temp)	//if it is left child of parent then that node will be made 0.
				parent->left=0;
			else			//if it is right child of parent then that node will be made 0.
				parent->right=0;
		}
		else		//if its root element then make root 0
			root=0;
		delete temp;
	}
	
	else if(temp->right!=0 && temp->left!=0) //if data node has 2 childs then data will be replaced by its INORDER SUCCESSOR.
	{
		node *pret,*t=temp->right;
		while(t->left!=0)
		{
			pret=t;
			t=t->left;
		}//t will point to leftest element and pre will point its parent node
		temp->data=t->data;	//element will be replaced by inorder succesor
		pret->left=0;	//that leftest node will be deleted
		delete t;
	}
	else if(temp->right!=0 || temp->left!=0)	//if data node has 1 child
	{
		if(temp->right!=0)	//if it has right child
		{
			if(parent->left==temp)	//if the data node is on left subtree of its parents then it will be replaced by its right child
				parent->left=temp->right;
			else			//if the data node is on right subtree of its parents then it will be replaced by its right child
				parent->right=temp->right;
		}
		else	//if it has left child
		{
			if(parent->left==temp)	//if the data node is on left subtree of its parents then it will be replaced by its left child
				parent->left=temp->left;
			else			//if the data node is on righ subtree of its parents then it will be replaced by its left child
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
