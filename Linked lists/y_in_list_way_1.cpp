/*
Suppose there are two singly linked lists both of which intersect at some point
and become a single linked list. The head or start pointers of both the lists are known, but
the intersecting node is not known. Also, the number of nodes in each of the lists before
they intersect is unknown and may be different in each list. List1 may have n nodes before
it reaches the intersection point, and List2 might have m nodes before it reaches the
intersection point where m and n may be m = n,m < n or m > n. Give an algorithm for
finding the merging point.
*/
#include<bits/stdc++.h>
#include<iostream>
#include<stack>
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


void detect_y(node *head1, node *head2)
{
	stack <node*>s1;
	stack <node*>s2;
	node *tmp=head1,*prev;
	while(tmp!=NULL)
	{
		s1.push(tmp);
		tmp=tmp->next;
	}
	tmp=head2;
	while(tmp!=NULL)
	{
		s2.push(tmp);
		tmp=tmp->next;
	}
	if(s1.top()==s2.top())
	{
		prev=s1.top();
		s1.pop();
		s2.pop();
		while(!s1.empty() && !s2.empty() )
		{
			if(s1.top()==s2.top())
			{
				prev=s1.top();
				s1.pop();
				s2.pop();
			}	
			else
				break;
		}
		cout<<"y detected at node "<<(prev->data)<<endl;
		return ;
	}	
	cout<<"y not found"<<endl;
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
	printList(head1);
	printList(head2);
	detect_y(head1, head2);
	return 0;
}
