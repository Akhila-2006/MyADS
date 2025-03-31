#include<stdio.h>
int main()
{
	int n,i;
	printf("Enter n value : ");
	scanf("%d",&n);
	printf("Multiples of 2 is : ");
	for(i=1;i<=n;i++)
	{
		if(i%2==0)
		printf("%d  ",i);
	}
	printf("\n");
	printf("Multiples of 3 is : ");
	for(i=1;i<=n;i++)
	{
		if(i%3==0)
		printf("%d ",i);
	}
	printf("\n");
	printf("Multiples of 11 is : ");
	for(i=1;i<=n;i++)
	{
		if(i%11==0)
		printf("%d ",i);
	}
	printf("\n");
}
