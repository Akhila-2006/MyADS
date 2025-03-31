#include<stdio.h>
#include<stdlib.h>
struct Items{
	int profit;
	int weight;
};
typedef struct Items item;
void Gknapsack(item items[],int n,int capacity){
	int curweight,i,remcapacity;
	double totalprofit;
	curweight=0;
	totalprofit=0.0;
	int op[n];
	for(i=1;i<=n;i++)
	op[i]=0;
	for(i=1;i<=n;i++){
		if((curweight+items[i].weight)<=capacity)
		{
			curweight=curweight+items[i].weight;
			totalprofit=totalprofit+items[i].profit;
			op[i]=1;
			
		}
		
	}
		printf("Maximum Profit : %lf\n",totalprofit);
		printf("Optimal Solution : ");
		for(i=1;i<=n;i++)
		printf("%d ",op[i]);
		
		printf("\n");
	
}
int main(){
	int n,m,i;
	item it[20];
	printf("Enter the bag capacity : ");
	scanf("%d",&m);
	printf("Enter the number of items : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter item%d profits and weights : ",i);
		scanf("%d%d",&it[i].profit,&it[i].weight);
		
	}
	Gknapsack(it,n,m);
}
