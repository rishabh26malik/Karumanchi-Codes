#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *next;
};

void printFromEnd(node *head)
{
	if(head==NULL)
		return;
	printFromEnd(head->next);
	cout<<(head->data)<<endl;
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
	printFromEnd(head);
	return 0;
}
