#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int data;
	struct node *next;
};
typedef struct node *NODE;
NODE head,temp;
NODE insertend(NODE head,int x)
{
	NODE new=(NODE)malloc(sizeof(NODE));
	new->data=x;
	new->next=new;
	if(head==NULL)
	{
		head=new;
		temp=new;
	}
	else 
	{
		NODE temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		//new->next=temp;
		new->next=temp->next;
		temp->next=new;
	}
	temp=head;
return head;
}
NODE delbegin(NODE head)
{
	NODE del;
	if(head==NULL)
	{
	printf("empty\n");
}
	else if(head->next==head)
	{
		printf("deleted element:%d\n",head->data);
		free(head);
	}
	else
	{
		NODE temp=head;
		del=head;
		//del->next=NULL;
		//head=head->next;
		//del->next=NULL;
		while(temp->next!=head){
	
		temp=temp->next;
	}
		head=head->next;
		del->next=NULL;
		temp->next=head;
		printf("deleted element:%d\n",del->data);
		free(del);
	}
	return head;
}
void display(NODE head)
{
	NODE temp=head;
	printf("Elemnts :");
	do
	{
		printf("%d-->",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("NULL\n");
}
int main()
{
	int ch,x;
	while(1)
	{
		printf("1.insertend 2.deletebegin 3.display 4.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter value :");
				scanf("%d",&x);
				head=insertend(head,x);
				break;
				case 2:
					head=delbegin(head);
					break;
					case 3:
						display(head);
						break;
						case 4:
							exit(0);
		}
	}
}
