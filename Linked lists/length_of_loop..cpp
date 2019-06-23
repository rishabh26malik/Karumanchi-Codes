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


void insert_at_front(node **head, int value)
{
	node *tmp=new node();
	tmp->data=value;
	tmp->next=*head;
	*head=tmp;
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


void detect_loop(node *head)
{
	int loopExists=0,count=0;
	node *slow=head,*fast=head;
	while(slow && fast && fast != NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(slow==fast)
		{
			loopExists=1;
			break;
		}
	}
	if(loopExists)
	{
		fast=fast->next;
		while(slow!=fast)
		{
			fast=fast->next;
			count++;
		}
		cout<<"loop length = "<<count+1<<endl;
	}
	else
		cout<<"no loop"<<endl;
}

int main()
{
	node *head=NULL,*tmp;
	int n;
	cout<<"enter numbers to insert into list, -1 to stop : ";
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		insert_at_front(&head,n);
	}
	tmp=head;
	while(tmp->next != NULL)
		tmp=tmp->next;
	tmp->next=head->next->next;
	detect_loop(head);
	//printList(head);
	return 0;
}
