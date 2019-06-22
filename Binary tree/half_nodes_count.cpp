#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *left,*right;
};



node* newNode(int data) 
{ 

    node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    return(node); 
} 

void countHalfNodes(node *root, int &c)
{
	if(root==NULL)	
		return ;
	if(root->left == NULL && root->right != NULL)
		c++;
	if(root->left != NULL && root->right == NULL)
		c++;
	countHalfNodes(root->left,c);
	countHalfNodes(root->right,c);
}

int main() 
{ 
	int c=0;
    node *root = newNode(1);   
    root->left        = newNode(2); 
    root->right       = newNode(3); 
    root->left->left  = newNode(4); 
  /*  
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    5      6    7 
  /                 \
  8                  9
*/
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	root->left->left->left=newNode(8);
	root->right->right->right=newNode(9);
	countHalfNodes(root,c);
	cout<<c<<endl;
    return 0; 
}

