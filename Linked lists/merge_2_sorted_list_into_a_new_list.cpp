/*
Given two sorted Linked Lists, how to merge them into the third list in sorted order?
*/
#include<iostream>
using namespace std;

class node
{
	public:
	int data,flag=0;
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


node* merge(node *head1, node *head2)
{
	node *result=NULL;
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;
	if(head1->data <= head2->data)
	{
		result=head1;
		result->next = merge(head1->next, head2);
	}
	else
	{
		result=head2;
		result->next = merge(head1, head2->next);
	}
	return result;
}


int main()
{
	node *head1=NULL, *head2=NULL,*tmp;
	node *result=NULL;
	int n;
	cout<<"enter numbers to insert into list 1, -1 to stop : ";
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		insert_at_end(&head1,n);
	}
	printList(head1);

	cout<<"enter numbers to insert into list 2, -1 to stop : ";
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		insert_at_end(&head2,n);
	}
	printList(head2);
	tmp->next=head2->next->next;
	result=merge(head1, head2);
	printList(result);
	return 0;
}
