#include<stdio.h>
int visited[10];
int graph[10][10];
void dijkstras(int graph[10][10] ,int ,int);
void dijkstras(int graph[10][10],int src,int n)
{
	int i,cnt,u,v;
	int distance[10];
	for(i=1;i<=n;i++){
		visited[i]=0;
		distance[i]=999;		
	}
	distance[src]=0;
	int isUnvisited,hasEdge,isReachable,isShortPath;
	for(cnt=1;cnt<=n-1;cnt++)
	{
		u=findMinDistance(distance,visited,n);
		visited[u]=1;
		for(v=1;v<=n;v++)
		{
			isUnvisited= !visited[v];
			hasEdge =(graph[u][v])!=0;
			isReachable =distance[u]!=999;
			isShortPath =(distance[u]+graph[u][v]) < distance[v];
			if(isUnvisited && hasEdge && isReachable && isShortPath)
			{
				distance[v]=distance[u]+graph[u][v];				
			}
		}
	}
	visited[cnt]=1;
	printf("vertex\t distance from src\n");
    for(i=1;i<=n;i++)
	{
		printf("%d\t%d\n",i,distance[i]);
	}
	printf("Visited elements : ");
	for(i=1;i<=n;i++)
	{
		printf("%d->%d\n ",i,visited[i]);
	}
}
int findMinDistance(int distance[],int visited[],int n)
{           int i;
			int min=999,minIndex=-1;
			for(i=1;i<=n;i++){
				if(!visited[i] && distance[i]<min){
					min=distance[i];
					minIndex=i;
				}
			}
			return minIndex;
}
void main(){
		int n,graph[10][10];
		int v,src,i,j;
		printf("Enter number of vertices: ");
		scanf("%d",&n);
		printf("Enter source vertex: ");
		scanf("%d",&src);
		printf("enter adjacent matrices: ");
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				scanf("%d",&graph[i][j]);
			}
		}
	dijkstras(graph,src,n);
	
}
	
	

