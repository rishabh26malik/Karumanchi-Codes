#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node *next;
};

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

node* getMiddle(node *head)
{
	node *p1 = head, *p2 = head;
	if(head != NULL)
	{
		while(p2!=NULL && p2->next != NULL)
		{
			p1=p1->next;
			p2=p2->next->next;
		}
	}
	//cout<<(p1->data)<<endl;
	return p1;
}

void reverse(node **head)
{
	node *current=*head, *right=(*head)->next, *prev=NULL;
	while(current != NULL)
	{
		//cout<<"1"<<endl;
		right=current->next;
		current->next=prev;
		prev=current;
		current=right;
	}
	*head=prev;
}

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

int find_Kth_node(node *head, int k)
{
	int i=0;
	while(i<k)
	{
		head=head->next;
		i++;
	}
	return head->data;
}

void isPalindrome_METHOD_1(node *head)
{
	int begin=0,end=total_nodes(head)-1;
	
	while(begin < end)
	{
		if(find_Kth_node(head,begin) != find_Kth_node(head,end) )
		{
			cout<<"Not palindrome"<<endl;
			return ;
		}
		begin++;
		end--;
	}
	cout<<"palindrome"<<endl;
}

void printList(node *head)
{
	while(head!=NULL)
	{
		cout<<(head->data)<<" ";
		head=head->next;
	}
}

void isPalindrome_METHOD_2(node *head)
{
	int tot_nodes=total_nodes(head);
	node *mid=getMiddle(head), *tmp=head;
	reverse(&mid);
	cout<<"---"<<(mid->data)<<endl;
	printList(mid);
	//if(tot_nodes % 2 ==1)
		//mid=mid->next;
	while(mid != NULL)
	{
		if(mid->data != tmp->data)
		{
			cout<<"not palindrome"<<endl;
			return ;
		}	
		mid=mid->next;
		tmp=tmp->next;
	}
	cout<<"palindrome"<<endl;
	/*while(mid != NULL )
	{
		insert_at_end(&head,mid->data);
		mid=mid->next;
	}
	printList(head);*/
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
	//cout<<total_nodes(head)<<endl;
	isPalindrome_METHOD_2(head);
	
	return 0;
}
