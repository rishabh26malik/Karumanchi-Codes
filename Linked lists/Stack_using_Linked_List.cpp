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


void insert_at_front(node **head, int value)
{
	node *tmp=new node();
	tmp->data=value;
	tmp->next=*head;
	*head=tmp;
}

int pop(node **head)
{
	node *tmp=*head;
	int val=tmp->data;
	*head=(*head)->next;
	delete(tmp);
	return val;
}	

int main()
{
	node *head=NULL;
	int n,ch;
	cout<<"push - 1"<<endl;
	cout<<"pop - 2"<<endl;
	cout<<"display - 3"<<endl;
	cout<<"exit - 4"<<endl;
	
	do
	{
		cout<<"enter choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1: cout<<"enter no. :";
					cin>>n;
					insert_at_front(&head,n);
					break;
			case 2: n=pop(&head);
					cout<<"no. popped is : "<<n<<endl;
					break;
			case 3: printList(head);
					break;
			
		}
		
	}while(ch!=4);
	printList(head);
	return 0;
}
