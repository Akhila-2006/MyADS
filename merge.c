#include<stdio.h>
#include<stdlib.h>
void merge(int [],int,int,int);
void merge_sort(int [],int,int);
int main()
{
int i,n;
printf("Enter size of the array:\n");
scanf("%d",&n);
int arr[n];
printf("Enter array elements:\n");
for(i=0;i<n;i++)
 {
scanf("%d",&arr[i]);
 }
printf("Before sorting:\n");
for(i=0;i<n;i++)
 {
 printf("%d ",arr[i]);
 }
 merge_sort(arr,0,n-1);
 printf("\nAfter Sorting:\n");
 for(i=0;i<n;i++)
  {
printf("%d ",arr[i]);
  }
}
void merge_sort(int arr[],int l,int r)
{
int m;
  if(l<r)
  {
  m = l + (r-l) / 2;
  merge_sort(arr,l,m);
  merge_sort(arr,m+1,r);
  merge(arr,l,m,r);
  }
}
void merge(int arr[],int l,int m,int r)
{
int i,j,k;
int n1,n2;
n1=m-l+1;
n2=r-m;
int L[n1+1],R[n2+1];
for(i=0;i<n1;i++)
 {
 L[i]=arr[l+i];
 }
for(j=0;j<n2;j++)
 {
 R[j]=arr[m+1+j];
 }
 i=0;
 j=0;
 k=l;
while(i<n1 && j<n2)
 {
 if(L[i]<=R[j])
   {
   arr[k]=L[i];
   i++;
   }
else
  {
  arr[k]=R[j];
  j++;
  }
  k++;
 }
 while(i<n1)
 {
 arr[k]=L[i];
 i++;
 k++;
 }
 while(j<n2)
 {
 arr[k]=R[j];
 j++;
 k++;
 }
}
