#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left,*right;
};
typedef struct node*NODE;
NODE create(int value)
{
	NODE new1=(NODE)malloc(sizeof(NODE));
	new1->data=value;
	new1->left=NULL;
	new1->right=NULL;
	return new1;
}
void inorder(NODE root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}

}
NODE minValue(NODE node)
{
	NODE temp=node;
	while(temp && temp->left!=NULL)
	{
		temp=temp->left;
	}
	return temp;
}
NODE insert(NODE node , int val)
{
	if(node==NULL)
	{
		return create(val);
	}
	if(val<node->data)
	{
		node->left=insert(node->left,val);
	}
	else
	{
		node->right=insert(node->right,val);
	}
	return node;
}
struct node * search(struct node* root, int key){
    if(root==NULL){
        return NULL;
    }
    if(key==root->data){
        return root;
    }
    else if(key<root->data){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
    return root;
}
int main()
{
	NODE root=NULL;
	int i,n,x;
	int key;
	printf("Enter no of nodes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter value: ");
		scanf("%d",&x);
		root=insert(root,x);
	}
	printf("Inorder traversal: ");
	inorder(root);
	printf("Enter key value : ");
	scanf("%d",&key);
	root=search(root,key);
	if(key==root->data)
	printf("Element found\n");
	else
	printf("Element not found\n");

}
