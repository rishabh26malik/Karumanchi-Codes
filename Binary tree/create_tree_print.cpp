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
    printPOST_ORDER(root);
    cout<<endl;
    printPRE_ORDER(root);
    cout<<endl;
    printIN_ORDER(root);
    return 0; 
}

