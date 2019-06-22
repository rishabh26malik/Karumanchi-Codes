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
  
int maxInTree(node *root)
{
	int lmax,rmax,rootVal,max1=INT_MIN;
	
	if(root!=NULL)
	{
		lmax=maxInTree(root->left);
		rmax=maxInTree(root->right);
		rootVal=root->data;
		if(lmax > rmax)
			max1 = lmax;
		else
			max1=rmax;
		if(rootVal > max1)
			max1=rootVal;
	}
	return max1;
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
 
*/
	root->left->right=newNode(5);
	root->right->left=newNode(6);
	root->right->right=newNode(7);
    cout<<maxInTree(root)<<endl;
    return 0; 
}

