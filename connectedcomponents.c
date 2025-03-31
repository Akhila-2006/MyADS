#include<stdio.h>
#define MAX  20 
int adjMatrix[MAX][MAX];  
int visited[MAX],n;
void dfs(int v)
{
	int i;
	visited[v]=1;
	for(i=1;i<=n;i++)
	{
		if(adjMatrix[v][i]==1&&visited[i]==0)
		{
			dfs(i);
		}
	}
}
void findconnectedcomponents()
{
	int coc,i,v;
	for(i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	coc=0;
	for(v=1;v<=n;v++)
	{
		if(visited[v]==0)
		{
			dfs(v);
			coc++;
		}
	}
	printf("Total no.of connected components : %d\n",coc);
}
int main(){
    int  i, j, sv;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix:\n");
    for (i = 1; i<=n; i++) {
        for (j = 1; j<=n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
   	findconnectedcomponents();
        			
}
