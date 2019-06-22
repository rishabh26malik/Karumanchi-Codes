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
  
int findInTree(node *root , int key)  
{
	int tmp;
	if(root==NULL)
		return 0;
	else
	{
		if(root->data == key)
			return 1;
		else
		{
			tmp=findInTree(root->left, key);
			if(tmp!=0)
				return tmp;
			else
				return findInTree(root->right, key);
		}
	}	
}

int main() 
{ 
	int h,k,found;
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
 
*/
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
	cout<<"enter value to search : ";
	cin>>k;
    found = findInTree(root,k);
    if(found)
    	cout<<"found"<<endl;
    else
    	cout<<"not found"<<endl;	
    return 0; 
}

