#include <iostream>
using namespace std;
int main(){
	int adj[10][10],n,m,v;	//adj-adjency matrix,n-no. of vertex,m-no. of edges.v-stores current vertex
	cout<<"\nEnter no. of Vertex ";cin>>n;
	cout<<"\nEnter no. of Edges ";cin>>m;
	int *q=new int(n);	//Queue of size n 
	int front=0,rear=-1;	//Queue Variables 
	int *visited=new int(n);//visited array to store visited indexes
	int k,j,i;				//Loop variables
	cout<<"\nEnter Edges : ";
	for(k=1;k<=m;k++)
	{
		cin>>i>>j;
		adj[i][j]=1;
	}
	cout<<"\nEnter Starting Vertex : ";cin>>v;
	q[++rear]=v;	//starting vertex will be added in queue
	visited[v]=1;	//v index of visited array will be marked 1
	cout<<"\nBreadth First Traversal : ";
	k=1;
	while(k<=n)
	{
		for(i=0;i<=n;i++)
		{
			if(adj[v][i]==1 && visited[i]==0) //if there is a edge from vertex v to i, and if i is not visited then i is added in q and marked visited.
			{
				q[++rear]=i;
				visited[i]=1;
			}
		}
		cout<<v<<" ";	//vertex is printed
		v=q[++front];	//printed vertex is removed from Queue and front points to next element,v is assign next elemnt of Queue
		k++;
	}
	return 0;
}
