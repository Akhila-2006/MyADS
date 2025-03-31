#include<stdio.h>
#include<stdlib.h>
int a[30],b[30];
void merge(int a[],int l,int m,int h){
	int i,j,k,x;
	i=l;
	j=m+1;
	k=l;
	while((i<=m)&&(j<=h))
	{
		if(a[i]>a[j]){
			b[k++]=a[j++];
		}
		else{
			b[k++]=a[i++];
		}
	}
	if(i<=m)
	{
		for(x=i;x<=m;x++)
		{
			b[k++]=a[x];
		}
	}
	else
	{
		for(x=j;x<=h;x++){
			b[k++]=a[x];
		}
	}
	for(x=l;x<=h;x++)
	a[x]=b[x];
}
void mergesort(int a[],int l,int h){
	int m;
	if(l<h){
		m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}
void quicksort(int a[],int f,int l)
{
	int j;
	if(f<l)
	{
		j=parition(a,f,l);
		quicksort(a,f,j-1);
		quicksort(a,j+1,l);
	}
}
int parition(int a[],int f,int l)
{
	int i,j,pvt;
	int temp;
	pvt=a[f];
	i=f;
	j=l;
	while(i<j)
	{
		while(a[i]<=pvt&&i<j)
		i++;
		while(a[j]>pvt)
		j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	//a[f]=a[j];
    //a[j]=pvt;
	temp=a[j];
	a[j]=a[f];
	a[f]=temp;
	return j;
}
int main()
{
	int n,i;
	int ch,k;
	while(1)
	{
	
	printf("1.Quick Sort\n 2.MergeSort\n3.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
				case 1:
					printf("Enter no.of elements: ");
	                 scanf("%d",&n);
	                 int l=1,h=n;
					printf("Enter array elements : ");
	                  for(i=1;i<=n;i++)
	                 {
		              scanf("%d",&b[i]);
	                 }
				printf("Before Sorting : ");
				for(i=1;i<=n;i++)
				{
					printf("%d ",b[i]);
				}
				printf("\n");
				quicksort(b,l,h);
				printf("After QuickSorting : ");
				for(i=1;i<=n;i++)
				{
					printf("%d ",b[i]);
				}
				printf("\n");
				break;
				case 2:
					printf("Enter no.of elements: ");
	                 scanf("%d",&k);
	                int lo=1,hi=k;
					printf("Enter array elements : ");
	                  for(i=1;i<=k;i++)
	                   {
		              scanf("%d",&a[i]);
	                   }
					printf("Before sorting:");
                     for(i=1;i<=k;i++)
                       {
                       printf("%d ",a[i]);
                       }
                        printf("\n");
                      mergesort(a,lo,hi);
                      printf("After MergeSorting:");
                      for(i=1;i<=k;i++)
                        {
                      printf("%d ",a[i]);
                        }
                       printf("\n");
                       break;
				case 3:
					exit(0);
				break;
					
				
		}
	}
	
}
