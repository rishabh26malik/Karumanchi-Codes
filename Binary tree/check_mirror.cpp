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

int checkMirror(node *root1, node *root2)
{
	if(root1 == NULL && root2==NULL)
		return 1;
	if(root1==NULL || root2==NULL)
		return 0;
	if(root1->data != root2->data)
		return 0;
	else
		return checkMirror(root1->left, root2->left) && checkMirror(root1->right, root2->right);
}

int main() 
{ 
	int h,mirror;
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
	
	  /*  
           1 
       /     \ 
      3        2 
    /   \     /  \ 
   7    6    5    4 
  /               \  
  9                8
*/
	
	node *root2 = newNode(1);   
    root2->left        = newNode(3); 
    root2->right       = newNode(2); 
    root2->left->left  = newNode(7); 
	root2->left->right=newNode(6);
	root2->right->left=newNode(5);
	root2->right->right=newNode(4);
	root2->left->left->left=newNode(9);
	root2->right->right->right=newNode(8);
	
	printIN_ORDER(root);
	cout<<endl;
	printIN_ORDER(root2);
	mirror=checkMirror(root,root2);
	if(mirror)
		cout<<"mirror"<<endl;
	else
		cout<<"not mirror"<<endl;	
	
    return 0; 
}

