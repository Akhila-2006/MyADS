#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
}*head,*temp;
typedef struct node *NODE;
NODE createnode()
{
	NODE new=(NODE)malloc(sizeof(NODE));
	new->next=NULL;
	return new;
}
NODE insertatbegin(NODE head,int x)
{
NODE new=createnode();
new->data=x;
new->next=NULL;
if(head==NULL)
{
	head=new;
	head->next=new;
	}
	else
	{
		temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=new;
	new->next=head;
	head=new;
	//temp->next=new;
	}	
	return head;
}
void display(NODE head)
{
	NODE temp=head;
	printf("Elements are : ");
	do
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}
NODE delend(NODE head)
{
	NODE temp=head;
	if(head->next==head)
	{
		printf("Deleted element : %d\n",head->data);
		free(head);
	}
	else
	{
		while(temp->next->next!=head)
		{
			temp=temp->next;
		}
		NODE del=temp->next;
		temp->next=head;
		del->next=NULL;
		printf("Deleted element:%d\n",del->data);
		free(del);
	}
	return head;
	
}
int main()
{
	int n,x;
	NODE head=NULL;
	while(1)
	{
		printf("1.insertbegin 2.display 3.deleteend 4.exit\n");
		printf("Choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("enter value : ");
				scanf("%d",&x);
				head=insertatbegin(head,x);
				break;
				case 2:
					display(head);
					break;
					case 3:
					head=delend(head);
					break;
				case 4:
					exit(0);
					break;
		}
	}
	return 0;
}
