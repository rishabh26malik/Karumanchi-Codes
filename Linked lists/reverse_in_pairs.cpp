/*
Reverse the linked list in pairs. If you have a linked list that holds 1 → 2 → 3
→ 4 → X, then after the function has been called the linked list would hold 2 → 1 → 4 →
3 → X.
*/
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

node* reversePairs(node *head)
{
	node *tmp;
	if(head==NULL || head->next==NULL)
		return head;
	else
	{
		tmp=head->next;
		head->next=tmp->next;
		tmp->next=head;
		head=tmp;
		head->next->next=reversePairs(head->next->next);
		return head;
	}
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

int main()
{
	node *head=NULL,*rev;
	int n;
	cout<<"enter numbers to insert into list, -1 to stop : ";
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		insert_at_end(&head,n);
	}
	rev=reversePairs(head);
	printList(rev);
	return 0;
}
