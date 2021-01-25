#include <iostream>
using namespace std;
int main(){
	int adj[10][10],n,m,v;
	cout<<"\nEnter no. of Vertex ";cin>>n;
	cout<<"\nEnter no. of Edges ";cin>>m;
	int *q=new int(n);
	int front=0,rear=-1;	//Queue Variables 
	int *visited=new int(n);
	int k,j,i;				//Loop variables
	cout<<"\nEnter Edges : ";
	for(k=1;k<=m;k++)
	{
		cin>>i>>j;
		adj[i][j]=1;
	}
	cout<<"\nEnter Starting Vertex : ";cin>>v;
	q[++rear]=v;
	visited[v]=1;
	cout<<"\nBreadth First Traversal : ";
	k=1;
	while(k<=n)
	{
		for(i=0;i<=n;i++)
		{
			if(adj[v][i]==1 && visited[i]==0)
			{
				q[++rear]=i;
				visited[i]=1;
			}
		}
		cout<<v<<" ";
		v=q[++front];
		k++;
	}
	return 0;
}
