#include<stdio.h>
#include<stdlib.h>
struct node{
	int key;
	struct node *left;
	struct node *right;
};
int getRightMin();
struct node *insert();
struct node *getNewNode();
void inorder();
int searchNode();
struct node *removeNode();
int main()
{
	struct node *root=NULL;
	root=insert(root,100);
	root=insert(root,50);
	root=insert(root,200);
	root=insert(root,150);
	root=insert(root,300);
	
	inorder(root);
	int key;
    scanf("%d",&key);

    printf("%d",searchNode(root,key));
	
	int val;
    scanf("%d",&val);

    root = removeNode(root,val);
    inorder(root);
    return 0;
}
struct node *insert(struct node *root,int val)
{
	if(root==NULL)
		return getNewNode(val);
	if(root->key<val)
	{
		root->right=insert(root->right,val);
	}
	else if(root->key>val)
	{
		root->left=insert(root->left,val);
	}
	return root;
}
struct node *getNewNode(int val)
{
	struct node *root= (struct node*)malloc(sizeof(struct node));
	root->key=val;
	root->left=NULL;
	root->right=NULL;
	
	return root;
}
void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ",root->key);
	inorder(root->right);
}
int searchNode(struct node *root,int val)
{
	if(root==NULL)
		return 0;
	else if(root->key==val)
		return 1;
	else if(root->key<val)
		return searchNode(root->right,val);
	else
		return searchNode(root->left,val);
}
struct node *removeNode(struct node *root,int val)
{
	if(root==NULL)
		return NULL;
	else if(root->key<val)
		root->right=removeNode(root->right,val);
	else if(root->key>val)
		root->left=removeNode(root->left,val);
	else
	{
		if(root->left==NULL&&root->right==NULL)
		{
			return NULL;
		}
		else if(root->left==NULL)
		{
			struct node *temp=root;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node *temp=root;
			free(root);
			return temp;
		}
		else
		{
			int rightMin=getRightMin(root->right);
			root->key=rightMin;
			root->right=removeNode(root->right,rightMin);
		}
	}
}
int getRightMin(struct node *root)
{
	struct node *temp;
	while(temp->left!=NULL)
	{
		temp=temp->left;
	}
	
	return temp->key;
}
