#include<stdio.h>
#include<stdlib.h>
struct Jobseq{
	int jobid;
	int deadline;
	int profits;
};
typedef struct Jobseq Job;
int findMaxDeadline(Job jobs[],int n)
{
	int max=jobs[0].deadline;
	int i;
	for(i=0;i<n;i++)
	{
		if(jobs[i].deadline>max)
		{
			max=jobs[i].deadline;
		}
	}
	printf("MaxDeadline : %d\n",max);
	return max;
	
}
void SortJobsProfits(Job jobs[],int n)
{
	int i,j;
	Job temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(jobs[j].profits<jobs[j+1].profits)
			{
				temp=jobs[j];
				jobs[j]=jobs[j+1];
				jobs[j+1]=temp;
			}
		}
	}
	printf("Sorting order based on profits : ");
	for(i=0;i<n;i++)
	{
		printf("%d ",jobs[i].profits);
	}
	printf("\n");
}
void JobseqdDeadlines(Job jobs[],int n)
{
	int maxdeadline,slot[10],i,maxprofit,j;
	SortJobsProfits(jobs,n);
	maxdeadline=findMaxDeadline(jobs,n);
	for(i=0;i<maxdeadline;i++)
	{
		slot[i]=-1;
	}
	maxprofit=0;
	for(i=0;i<n;i++)
	{
		for(j=jobs[i].deadline-1;j>=0;j--)
		{
			if(slot[j]==-1)
			{
				slot[j]=jobs[i].jobid;
				maxprofit=maxprofit+jobs[i].profits;
				break;
			}
		}
	}
	printf("Optimal solution: ");
	for(i=0;i<maxdeadline;i++)
	{
		printf("J%d ",slot[i]);
	}
	printf("\n");
	printf("MaxProfit : %d\n",maxprofit);
}
int main()
{
	Job j[20];
	int n,i;
	printf("Number of Jobs : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Job %d details: ",i+1);
		scanf("%d%d%d", &j[i].jobid, &j[i].deadline, &j[i].profits);
	}
	JobseqdDeadlines(j,n);
}
