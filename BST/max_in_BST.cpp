#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *left,*right;
};

void printPOST_ORDER(node* node) 
{ 
    if (node == NULL) 
        return; 
    printPOST_ORDER(node->left); 
    printPOST_ORDER(node->right); 
      cout << node->data << " "; 
} 

void printPRE_ORDER(node* node) 
{ 
    if (node == NULL) 
        return; 
    cout << node->data << " "; 
    printPRE_ORDER(node->left); 
    printPRE_ORDER(node->right); 
} 

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
  
node* find_max_BST(node *root)
{
	if(root==NULL)
		return NULL;	
	else if(root->right ==NULL)
		return root;
	else
		return find_max_BST(root->right);
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
	node *tmp=find_max_BST(root);
	if(tmp)
		cout<<"min = "<<(tmp->data)<<endl;
	else
		cout<<"no tree available"<<endl;
    return 0; 
}

