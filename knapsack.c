#include<stdio.h>
int max(int a, int b) 
{
    return (a > b) ? a : b;
}
void knapsack(int n,int m,int profit[],int weight[]){
	int T[n+1][m+1];
	int i,j,tm,maxvalue;
	for(i=0;i<=n;i++)
	{
		for(j=0;j<=m;j++)
		{
			if(i==0||j==0)
			T[i][j]=0;
			else if(j-weight[i-1]>=0)
			T[i][j]=max(T[i-1][j],profit[i-1]+T[i-1][j-weight[i-1]]);
			else
			T[i][j]=T[i-1][j];
		}
	}
	printf("Matrix : \n");
	for(i=0;i<=n;i++)
	{
		
		for(j=0;j<=m;j++)
		{
			printf("%d ",T[i][j]);
		}
		printf("\n");
	}
	maxvalue=T[n][m];
	printf("Maxprofit earned : %d\n",maxvalue);
	tm=m;
	printf("Optimal solution : \n");
	for(i=n;i>0 && maxvalue>0;i--)
	{
		if(maxvalue!=T[i-1][tm])
		{
			printf("item-%d, profit of item =%d, weight of item =%d\n",i,profit[i-1],weight[i-1]);
			maxvalue-=profit[i-1];
			tm=tm-weight[i-1];
		}
	}
}
int main(){
	int n,m,i;
	printf("Enter no.of rows (n-value) : ");
	scanf("%d",&n);
	printf("Enter no.of columns (m-value) : ");
	scanf("%d",&m);
	int profit[n],weight[n];
	for(i=0;i<n;i++)
	{
		printf("Enter item%d profits and weights : ",i+1);
		scanf("%d %d",&profit[i],&weight[i]);
	}
	knapsack(n,m,profit,weight);
}
