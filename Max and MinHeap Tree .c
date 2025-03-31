#include<stdio.h>
#include<stdlib.h>
int n,k;
int a[30],b[30];
void maxheapify(int i){
	int lt,rt,lar,temp;
	lt=2*i;
	rt=2*i+1;
	if(lt>n)
	return;
	if(a[lt]>a[i]&&lt<=n)
	lar=lt;
	else
	lar=i;
	if(a[rt]>a[lar]&&rt<=n)
	lar=rt;
	if(lar!=i){
		temp=a[i];
		a[i]=a[lar];
		a[lar]=temp;
		maxheapify(lar);
	}
}
void buildmaxHeap(){
	int j;
	for(j=n/2;j>=1;j--){
		maxheapify(j);
	}
}
void insertmax()
{
	n++;
	int ele;
	printf("Enter element to insert : ");
	scanf("%d",&ele);
	a[n]=ele;
	buildmaxHeap();
	printf("Insertion success\n");
}
void deleteMax(){
	printf("Deleted element : %d\n",a[1]);
	a[1]=a[n];
	n--;
	buildmaxHeap();
}
void displaymax(){
	int i;
	printf("Maxheap elements: ");
	for(i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
}
void minheapify(int i){
	int lt,rt,lar,temp;
	lt=2*i;
	rt=2*i+1;
	if(lt>k)
	return;
	if(b[lt]<b[i]&&lt<=k)
	lar=lt;
	else
	lar=i;
	if(b[rt]<b[lar]&&rt<=k)
	lar=rt;
	if(lar!=i){
		temp=b[i];
		b[i]=b[lar];
		b[lar]=temp;
		minheapify(lar);
	}
}
void buildminHeap(){
	int j;
	for(j=k/2;j>=1;j--){
		minheapify(j);
	}
}
void insertmin()
{
	k++;
	int ele;
	printf("Enter element to insert : ");
	scanf("%d",&ele);
	b[k]=ele;
	buildminHeap();
	printf("Insertion success\n");
}
void deleteMin(){
	printf("Deleted element : %d\n",b[1]);
	b[1]=b[k];
	k--;
	buildminHeap();
}
void displaymin(){
	int i;
	printf("Minheap elements: ");
	for(i=1;i<=k;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
}
int main(){
	int ch2;
	int ch1,ch3;
	while(1){
		printf("1.MaxHeap 2.MinHeap 3.Exit\n");
		printf("Enter choice for outer switch : ");
		scanf("%d",&ch1);
		switch(ch1){
			case 1:
		printf("MaxHeap programm\n");
		printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		do{
		printf("Enter your choice for max switch:");
		scanf("%d",&ch2);
		switch(ch2){
			case 1:
				insertmax();
				break;
				case 2:
				deleteMax();
				break;
				case 3:
				displaymax();
				break;		
		}
	}while(ch2!=4);
		break;
		case 2:
			printf("MinHeap programm\n");
		printf("1.Insertion\n2.Deletion\n3.Display\n4.Exit\n");
		do{
		printf("Enter your choice for min :");
		scanf("%d",&ch3);
		switch(ch3){
			case 1:
				insertmin();
				break;
				case 2:
				deleteMin();
				break;
				case 3:
				displaymin();
				break;	
		}
	}while(ch3!=4);
		break;
		case 3:
			exit(0);
			break;
			default:
				printf("Invalid choice\n");
	}
}
}

