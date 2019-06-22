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
  
int find_level_sum(node *root, int level)
{
	if(root==NULL)
		return 0;
	if(level==1)
	{
		//cout<<(root->data)<<" ";
		return root->data;
	}
	return find_level_sum(root->left,level-1) + find_level_sum(root->right,level-1);
	
}  

int maxSumLevel(node *root)
{
	int tmp,level;
	if(root==NULL)
		return -1;
	int h=height(root),maxLevel=INT_MIN;
	int i;
	for(i=1;i<=h;i++)
	{
		tmp=find_level_sum(root,i);
		if(tmp > maxLevel){
			maxLevel=tmp;
			level=i;
		}
	}
	return level;
}

int main() 
{ 
	int h;
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
    cout<<maxSumLevel(root)<<endl;
    return 0; 
}

