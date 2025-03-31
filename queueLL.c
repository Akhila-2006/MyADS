#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
NODE rear=NULL;
NODE front=NULL;
NODE enqueue(int x)
{
	NODE new=(NODE)malloc(sizeof(NODE));
	new->data=x;
	new->next=NULL;
	if(front==NULL&&rear==NULL)
	{
		front=new;
		rear=new;
	}
	else
	{
		rear->next=new;
		rear=new;
	}
}
NODE dequeue()
{
	NODE del=front;
	front=front->next;
	del->next=NULL;
	printf("Deleted element: %d\n",del->data);
	free(del);
}
void display()
{
	NODE temp;
	if(front==NULL)
	printf("Queue is empty\n");
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d<-->",temp->data);
			temp=temp->next;
		}
	}
	printf("NULL\n");
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("1.Enqueue 2.Dequeue 3.Display 4.exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
		printf("Enter value:");
		scanf("%d",&x);
		enqueue(x);
		break;
		case 2:
		dequeue();
		break;
		case 3:
		display();
		break;
		case 4:
		exit(0);
		break;
	}
		
	}
}
