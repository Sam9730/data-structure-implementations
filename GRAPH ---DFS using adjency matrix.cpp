#include <iostream>
using namespace std;
int adj[20][20],n,m,top=-1,k,j,i;	//adj-adjency matrix,n-no. of vertex,m-no. of columns,top-points top element of stack
int *stack=new int(n);			 //stack to store vertex 
int *visited=new int(n+1);		//visited to mark visited vertex
int dfs(int t){		//takevertex in t parameter
	cout<<"->"<<t;	
	visited[t]=1;	//t index is marked 1 in visited array
	stack[++top]=t;	//t added in stack
	for(int l;l<=n;l++)	//checks for edges from t to other elements
	{
		if(adj[t][l]==1 && visited[l]!=1)	//if edge is founf in t,l and l isnt visited yet,then recursivelly call dfs passing l as vertex.
			dfs(l);
	}
	top--;	//top element of stack deleted
	return 0;
}
int main(){
	int v;
	cout<<"\nEnter no. of Vertex ";cin>>n;
	cout<<"\nEnter no. of Edges ";cin>>m;
	cout<<"\nEnter Edges : ";
	for(k=1;k<=m;k++)
	{
		cin>>i>>j;
		adj[i][j]=1;
	}
	cout<<"\nEnter Starting Vertex : ";cin>>v;
	cout<<"\nDepth First Search : ";
	dfs(v);
	return 0;
}
