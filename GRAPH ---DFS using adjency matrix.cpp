#include <iostream>
using namespace std;
int adj[20][20],n,m,top=-1,k,j,i;
int *stack=new int(n);			 
int *visited=new int(n+1);
int dfs(int t)
{
	cout<<"->"<<t;
	visited[t]=1;
	stack[++top]=t;
	for(int l;l<=n;l++)
	{
		if(adj[t][l]==1 && visited[l]!=1)
			dfs(l);
	}
	top--;
	
	return 0;
}

int main()
{
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