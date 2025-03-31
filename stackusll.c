#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
NODE top=NULL;
NODE push(int x)
{
	NODE head;
	NODE new=(NODE)malloc(sizeof(NODE));
	new->data=x;
	new->next=NULL;
	if(head==NULL)
	{
		head=new;
		top=new;
	}
	else
	{
		new->next=top;
		top=new;
	}
}
void display()
{
	NODE temp;
	if(top==NULL)
	printf("Stack is empty\n");
	else
	{
		temp=top;
		printf("Elements in the stack are: ");
		while(temp!=NULL)
		{
			printf("%d<-->",temp->data);
			temp=temp->next;
			}
		}
		printf("NULL\n");
	
}
NODE pop()
{
	if(top==NULL)
	printf("Deletion is not possible\n");
	else
	{
		NODE del=top;
		top=top->next;
		printf("Deleted element:%d\n",del->data);
		free(del);
	}
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("1.Push 2.display 3.Pop 4.exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("Enter value:");
			scanf("%d",&x);
			push(x);
			break;
			case 2:
			display();
			break;
			case 3:
			pop();
			break;
			case 4:
			exit(0);
			break;
		}
	}
}

