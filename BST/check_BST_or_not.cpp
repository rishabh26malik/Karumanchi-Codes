#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *left,*right;
};

node *newNode(int item) 
{ 
    node *temp =  (node *)malloc(sizeof(node)); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
   
void inorder(node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d \n", root->data); 
        inorder(root->right); 
    } 
} 
   
node* insert(node* node, int key) 
{ 
    if (node == NULL) 
    	return newNode(key); 
    if (key < node->data) 
        node->left  = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key);    
    return node; 
} 
 
int find_min(node *root)
{	
	if(root->left ==NULL)
		return root->data;
	else
		return find_min(root->left);
}

int find_max(node *root)
{
	
	if(root->right ==NULL)
		return root->data;
	else
		return find_max(root->right);
}

int isBST(node *root)
{
	if(root==NULL)
		return 1;
	if(root->left != NULL && find_max(root->left) > root->data )
		return 0;
	if(root->right!= NULL && find_min(root->right) < root->data)
		return 0;
	if(!isBST(root->left) || !isBST(root->right))
		return 0;
	return 1;
}
  
int main() 
{ 
	node *root = newNode(4);   
    root->left        = newNode(2); 
    root->right       = newNode(6); 
    root->left->left  = newNode(1); 
  /*  
           4 
       /       \ 
      2          6 
    /   \       /  \ 
   1    3      5    7 
 
*/
	root->left->right=newNode(3);
	root->right->left=newNode(5);
	root->right->right=newNode(7);
	/*
	INSERTION CODE
    node *root = NULL; 
    int n;
    cout<<"enter no. to insert in BST, -1 to stop : ";
    cin>>n;
    root = insert(root, n); 
  	while(1)
  	{
  		cin>>n;
  		if(n==-1)
  			break;
  		insert(root,n);
  	}*/
    //inorder(root); 
    cout<<isBST(root)<<endl;
    return 0; 
} 


