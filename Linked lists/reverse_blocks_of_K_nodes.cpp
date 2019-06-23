/*
For a given K value (K > 0) reverse blocks of K nodes in a list.
Example: Input: 1 2 3 4 5 6 7 8 9 10. Output for different K values:
For K = 2: 2 1 4 3 6 5 8 7 10 9
For K = 3: 3 2 1 6 5 4 9 8 7 10
For K = 4: 4 3 2 1 8 7 6 5 9 10
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
/*
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
*/
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

node* getK_plus_1th_Node(node *head, int k)
{
	int i=0;
	node *kth=head;
	if(head==NULL)
		return head;
	while(i<k && kth!=NULL)
	{
		i++;
		kth=kth->next;
	}
	if(kth!=NULL && i==k)
		return kth;
	return head->next;
}

int hasKnodes(node *head, int k)
{
	int i=0;
	while(i<k && head!=NULL)
	{
		i++;
		head=head->next;
	}
	if(i==k)
		return 1;
	return 0;
}


node* reverse_k_blocks(node *head, int k)
{
	int i;
	node *current=head, *right, *prev,*newList=NULL;
	if(k==0 || k==1)
		return head;
	if(hasKnodes(current,k-1))
		newList=getK_plus_1th_Node(current,k-1);
	else
		newList=head;
	
	while(current && hasKnodes(current,k))
	{
		prev=getK_plus_1th_Node(current,k);
		i=0;
		while(i<k)
		{
			right=current->next;
			current->next=prev;
			prev=current;
			current=right;
			i++;	
		}
	}
	return newList;
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
	rev=reverse_k_blocks(head,3);
	printList(rev);
	return 0;
}
