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
  
int check_identical(node *root1 , node *root2)
{
	if(root1==NULL && root2==NULL)
		return 1;
	if(root1==NULL || root2==NULL)
		return 0;
	return ((root1->data == root2->data) && check_identical(root1->left , root2->left) && check_identical(root1->left , root2->left));
}  

int main() 
{ 
    node *root1 = newNode(1);   
    root1->left        = newNode(2); 
    root1->right       = newNode(3); 
    root1->left->left  = newNode(4); 
  /*  
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    5      6    7 
 
*/
	root1->left->right=newNode(5);
	root1->right->left=newNode(6);
	root1->right->right=newNode(7);
    ////////--------------------------///////////
	node *root2 = newNode(1);   
    root2->left        = newNode(2); 
    root2->right       = newNode(3); 
    root2->left->left  = newNode(4); 
  /*  
           1 
       /       \ 
      2          3 
    /   \       /  \ 
   4    5      6    7 
 
*/
	root2->left->right=newNode(5);
	root2->right->left=newNode(6);
	root2->right->right=newNode(7);
    cout<<check_identical(root1,root2)<<endl;
    return 0; 
}

