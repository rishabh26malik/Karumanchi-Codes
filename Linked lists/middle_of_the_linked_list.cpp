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

void printMiddle(node *head)
{
	node *p1 = head, *p2 = head;
	int i=0;
	while(p1->next != NULL)
	{
		if(i==0)
		{
			i=1;
			p1=p1->next;
		}
		else
		{
			i=0;
			p1=p1->next;
			p2=p2->next;
		}
	}	
	cout<<(p2->data)<<endl;
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
	printMiddle(head);
	return 0;
}
