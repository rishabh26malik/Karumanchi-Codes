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
  
int height(node *root)
{
	if(root==NULL)
		return 0;
	return max(height(root->left),height(root->right))+1;
}   
  
void paths(node *root, char *arr, int start, int h)
{
	if(root->left == NULL && root->right==NULL)
	{
		arr[start]=(root->data) + '0';
		arr[start+1]='\0';
		cout<<arr<<endl;
		return;
	}
	if(root->left)
	{
		arr[start]=(root->data) + '0';
		paths(root->left,arr,start+1,h);
	}
	if(root->right)
	{
		arr[start]=char(root->data) + '0';
		paths(root->right,arr,start+1,h);
	}
}


int main() 
{ 
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
    int h=height(root);
    char arr[h+1];
    arr[h]='\0';
    paths(root,arr,0,h);
    return 0; 
}

