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
   
int main() 
{ 
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
  	}
    inorder(root); 
    
    return 0; 
} 


