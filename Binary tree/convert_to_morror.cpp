#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *left,*right;
};

void printIN_ORDER(node* node) 
{ 
    if (node == NULL) 
        return; 
    printIN_ORDER(node->left); 
    cout << node->data << " ";
    printIN_ORDER(node->right);  
} 

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

node* toMirror(node *root)
{
	node *tmp;
	if(root)
	{
		toMirror(root->left);
		toMirror(root->right);
		
		tmp=root->left;
		root->left=root->right;
		root->right=tmp;
	}
	return root;
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
	printIN_ORDER(root);
	cout<<endl;
	node *mirror=toMirror(root);
	printIN_ORDER(mirror);
    return 0; 
}

