//Binary tree
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	char c_date[10];
	char m_date[10];
	char name[20];
	char owner[20];
	struct node *left;
	struct node *right;
}node;


node* createNode(){
	node *newNode = (node*)malloc(sizeof(node));
	printf("\nFile name: ");
	scanf("%s", newNode->name);
	printf("%s Created: ", newNode->name);
	scanf("%s", newNode->c_date);
	printf("%s Modified: ", newNode->name);
	scanf("%s", newNode->m_date);
	printf("Owner: ");
	scanf("%s", newNode->owner);
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

node *createDirectory(node *dNode){
	dNode = (node *)malloc(sizeof(node));
	printf("\nDirectory Name: ");
	scanf("%s", dNode->name);
	return dNode;
}

node *createTree(node *dNode){
	dNode = createDirectory(dNode);
	dNode->left = createNode();
	dNode->right = createNode();
	return dNode;
}

void preorder(node *root){
	if(root == NULL){
		return;
	}
	printf("%s ", root->name);
	preorder(root->left);
	preorder(root->right);
}

int main(){
	node *root;
	root = createDirectory(root);
	root->left = createTree(root->left);
	root->right = createTree(root->right);
	
	preorder(root);
	
	printf("\n\nRemoving File3..\n");
	free(root->right->left);
	root->right->left = NULL;
	printf("File3 Removed.\n");
	preorder(root);
	
	printf("\n\nMoving File1 under Dir2..\n");
	root->right->left = root->left->left;
	root->left->left = NULL;
	printf("File1 Moved.\n");
	preorder(root);
	
	printf("\n\nCreating File5 under Dir1..\n");
	root->left->left = createNode();
	printf("File5 Created.\n");
	preorder(root);
}
