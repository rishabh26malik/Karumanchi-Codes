#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *next;
};

void printList(node *head)
{
	while(head!=NULL)
	{
		cout<<(head->data)<<" ";
		head=head->next;
	}
	cout<<endl;
}


void insert_at_end(node **head, int value)
{
	node *tmp=new node();
	tmp->data=value;
	tmp->next=NULL;
	if(*head==NULL)
	{
		*head=tmp;
		return ;
	}	
	node *ptr=*head;
	while(ptr->next != NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=tmp;
	return ;
}

void Nthnode(node *head, int n)
{
	int count=1;
	node *tmp=head,*nth=NULL;
	while(count<n){
		tmp=tmp->next;
		count++;
	}
	while(tmp!=NULL)
	{
		if(nth==NULL)
			nth=head;
		else
			nth=nth->next;	
		tmp=tmp->next;
		
	}
	cout<<"nth node = "<<(nth->data)<<endl;
}

int main()
{
	node *head=NULL;
	int n;
	cout<<"enter numbers to insert into list, -1 to stop : ";
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		insert_at_end(&head,n);
	}
	printList(head);
	cout<<"enter nth val : ";
	cin>>n;
	Nthnode(head,n);
	return 0;
}
