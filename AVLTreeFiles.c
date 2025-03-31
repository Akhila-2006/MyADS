#include<stdio.h>
#include<stdlib.h>
struct avlnode{
	int data;
	struct avlnode *left;
	struct avlnode *right;
	int height;
};
typedef struct avlnode* NODE;

NODE root=NULL;
NODE createnode(int key)
{
	NODE newnode=(NODE)malloc(sizeof(struct avlnode));
	newnode->data=key;
	newnode->left=NULL;
	newnode->right=NULL;
	newnode->height=1;
	return newnode;
}
int getHeight(NODE n)
{
	if(n==NULL)
	return 0;
	
	return n->height;
}
int max(int a,int b)
{
	if(a>b)
	return a;
	else 
	return b;
}
void updateHeight(NODE node)
{
	if(node!=NULL)
	node->height=max(getHeight(node->left),getHeight(node->right))+1;
}
NODE rightRotation(NODE y)
{
	NODE x=y->left;
	NODE t2=x->right;
	x->right=y;
	y->left=t2;
	y->height=max(getHeight(y->left),getHeight(y->right))+1;
	x->height=max(getHeight(x->left),getHeight(x->right))+1;
	return x;
}
NODE leftRotation(NODE x)
{
	NODE y=x->right;
	NODE t2=y->left;
	y->left=x;
	x->right=t2;
	x->height=max(getHeight(x->left),getHeight(x->right));
	y->height=max(getHeight(y->left),getHeight(y->right));
	return y;
}
void inorderTraversal(NODE root,FILE *f1)
{
	if(root!=NULL)
	{
		inorderTraversal(root->left,f1);
		fprintf(f1,"%d ",root->data);
		printf("%d ",root->data);
		inorderTraversal(root->right,f1);
	}

}
int getBalfactor(NODE n)
{
	if(n==NULL)
	return 0;
	return (getHeight(n->left)-getHeight(n->right));
}
NODE balanceTree(NODE node,int key)
{
	int balance;
	balance=getBalfactor(node);
	if(balance>1&&key<node->left->data)
	return rightRotation(node);
	if(balance<-1&&key>node->right->data)
	return leftRotation(node);
	if(balance>1&&key>node->left->data)
	{
		node->left=leftRotation(node->left);
		return rightRotation(node);
	}
	if(balance<-1&&key<node->right->data)
	{
		node->right=rightRotation(node->right);
		return leftRotation(node);
	}
	return node;
}
NODE insert(NODE node,int key)
{
	if(node==NULL)
     	return createnode(key);
	else if(key<node->data)
	node->left=insert(node->left,key);
	else if(key>node->data)
	node->right=insert(node->right,key);
	else
	return node;
	updateHeight(node);
	return balanceTree(node,key);
	
}
NODE minValNode(NODE temp)
{
	NODE cur=temp;
	while(cur->left!=NULL)
	{
		cur=cur->left;
	}
	return cur;
}
NODE deleteNode(NODE root,int key)
{
	NODE temp;
	if(root==NULL)
	return root;
	if(key<root->data)
	root->left=deleteNode(root->left,key);
	else if(key>root->data)
	root->right=deleteNode(root->right,key);
	else
	{
		if(root->left==NULL)
		{
			temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			temp=root->left;
			free(root);
			return temp;
		}
		else{
			temp=minValNode(root->right);
			root->data=temp->data;
			root->right=deleteNode(root->right,temp->data);
		}
		updateHeight(root);
		return balanceTree(root,key);
	}
}
int main()
{
	//NODE root=NULL;
	FILE *f,*f1;
	int n;
	int choice,key;
	while(1){
		printf("AVLTREE operations\n 1.Insert a node\n 2.Delete a node\n 3.Inorder traversal \n 4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:

					f=fopen("filename.txt","w");
					printf("Enter numbers up to 0:");
						scanf("%d",&n);
					while(n!=0){
					fprintf(f,"%d ",n);
					root=insert(root,n);
						scanf("%d",&n);
						}
					fclose(f);
				break;
				case 2:
					printf("Enter the value to delete: ");
					//f=fopen("filename.txt","w");
					scanf("%d",&key);
					root=deleteNode(root,key);
					fclose(f);
					break;
					case 3:
						printf("Inorder traversal: ");
						f1=fopen("filename2.txt","w");
						inorderTraversal(root,f1);
						printf("\n");
						fclose(f);
						break;
						case 4:
							exit(0);
							break;
							default:
								printf("Invalid choice");
								
		}
	}
	return 0;
}
