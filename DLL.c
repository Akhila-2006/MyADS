#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};
typedef struct node *NODE;
NODE head,temp;
NODE create(int x,NODE head)
{
	NODE new=(NODE)malloc(sizeof(NODE));
	new->data=x;
	new->next=NULL;
	new->prev=NULL;
	if(head==NULL)
	{
		head=new;
		temp=new;
	}
	else
	{
		temp->next=new;
		new->prev=temp;
		temp=new;
	}
	//return head;	
}
NODE display(NODE head)
{
	NODE temp=head;
	while(temp!=NULL)
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("1.create 2.dispaly 3.exit\n");
		printf("enter your choice :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("vaalue:");
				scanf("%d",&x);
				create(head,x);
				break;
				case 2:
				display(head);
				break;
				case 3:
				exit(0);
				break;
		}
	}
}
