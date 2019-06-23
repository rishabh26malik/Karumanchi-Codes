#include<iostream>
using namespace std;

class node
{
	public:
	int data,flag=0;
	node *next;
};

int total_nodes(node *head)
{
	int i=0;
	while(head != NULL)
	{
		head=head->next;
		i++;
	}
	return i;
}

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


void detect_y(node *head1, node *head2)
{
	int count1,count2,i;
	count1=total_nodes(head1);
	count2=total_nodes(head2);
	if(count1 > count2)
	{
		i=count1-count2;
		while(i)
		{
			head1=head1->next;
			i--;
		}
	}
	else
	{
		i=count2-count1;
		while(i)
		{
			head2=head2->next;
			i--;
		}
		
	}
	while(head1 != NULL)
	{
		if(head1->next == head2->next)
		{
			cout<<"y detected"<<endl;
			return ;
		}
		head1=head1->next;
		head2=head2->next;
	}
	cout<<"y not found"<<endl;
	return;
}


int main()
{
	node *head1=NULL, *head2=NULL,*tmp;
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
	tmp=head1;
	while(tmp->next != NULL)
	{
		tmp=tmp->next;
	}
	tmp->next=head2->next->next;
	detect_y(head1, head2);
	return 0;
}
