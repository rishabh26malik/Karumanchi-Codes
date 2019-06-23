#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *next;
};

void checkEven(node *head)
{
	while(head!=NULL && head->next!=NULL )
		head=head->next->next;
	if(head==NULL)
		cout<<"even"<<endl;
	else
		cout<<"odd"<<endl;
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
	checkEven(head);
	return 0;
}
