/*

Median in an infinite series of integers
Solution: Median is the middle number in a sorted list of numbers (if we have odd number of
elements). If we have even number of elements, median is the average of two middle numbers in a
sorted list of numbers.We can solve this problem efficiently by using 2 heaps: One MaxHeap and one MinHeap.

1. MaxHeap contains the smallest half of the received integers
2. MinHeap contains the largest half of the received integers

The integers in MaxHeap are always less than or equal to the integers in MinHeap. Also, the
number of elements in MaxHeap is either equal to or 1 more than the number of elements in the
MinHeap.
In the stream if we get 2n elements (at any point of time), MaxHeap and MinHeap will both
contain equal number of elements (in this case, n elements in each heap). Otherwise, if we have
received 2n + 1 elements, MaxHeap will contain n + 1 and MinHeap n.
Let us find the Median: If we have 2n + 1 elements (odd), the Median of received elements will
be the largest element in the MaxHeap (nothing but the root of MaxHeap). Otherwise, the Median
of received elements will be the average of largest element in the MaxHeap (nothing but the root
of MaxHeap) and smallest element in the MinHeap (nothing but the root of MinHeap). This can be
calculated in O(1).
Inserting an element into heap can be done in O(logn). Note that, any heap containing n + 1
elements might need one delete operation (and insertion to other heap) as well.

*/

#include<bits/stdc++.h>
using namespace std;

struct Heap
{
	int *arr;
	int count;
	int capacity, heap_type;
};
typedef Heap heap;

heap* createHeap(int size, int type)
{
	heap *h=(heap*)malloc(sizeof(heap));
	if(h==NULL)
	{
		cout<<"memory error"<<endl;
		return NULL;
	}	
	h->heap_type=type;
	h->count=0;
	h->capacity=size;
	h->arr=(int*)malloc(sizeof(int) * h->capacity );
	if(h->arr == NULL)
	{
		cout<<"memory error"<<endl;
		return NULL;
	}
	return h;
}

int parent(heap *h, int i)
{
	if(i<=0 || i>=h->count)
		return -1;
	return (i-1)/2;
}

int leftChild(heap *h, int i)
{
	int left=2*i+1;
	if(left>=h->count)
		return -1;
	return left;
}

int rightChild(heap *h, int i)
{
	int right=2*i+2;
	if(right>=h->count)
		return -1;
	return right;
}

void resizeHeap(heap *h)
{
	cout<<"222"<<endl;
	int i, *arr_old = h->arr;
	h->arr = (int*)malloc(sizeof(int) * (h->capacity*2));
	if(h->arr == NULL)
	{
		cout<<"memory error"<<endl;
		return ;
	}
	for(i=0;i<(h->capacity);i++)
	{
		h->arr[i]=arr_old[i];
	}
	h->capacity = h->capacity * 2;
	delete(arr_old);
}


void percolateDown(heap *h, int i)
{
	int left,right,tmp,max1;
	left=leftChild( h, i);
	right=rightChild( h, i);
	if(left != -1 && h->arr[left] > h->arr[i])
		max1=left;
	else
		max1=i;
	if(right!=-1 && h->arr[right] > h->arr[max1])
		max1=right;
	if(max1 != i)
	{
		tmp=h->arr[i];
		h->arr[i]=h->arr[max1];
		h->arr[max1]=tmp;	
		
		percolateDown(h,max1);
	}
	
}

void percolateDown_min(heap *h, int i)
{
	int left,right,tmp,max1;
	left=leftChild( h, i);
	right=rightChild( h, i);
	if(left != -1 && h->arr[left] < h->arr[i])
		max1=left;
	else
		max1=i;
	if(right!=-1 && h->arr[right] < h->arr[max1])
		max1=right;
	if(max1 != i)
	{
		tmp=h->arr[i];
		h->arr[i]=h->arr[max1];
		h->arr[max1]=tmp;	
		
		percolateDown_min(h,max1);
	}
	
}


void insert(heap *h, int data)
{
	int i;
	if(h->count == h->capacity)
		resizeHeap(h);
	h->count++;
	i=h->count-1;
	h->arr[i]=data;
	int n=h->count;
	if(h->heap_type == 1)
		for(i = (n-1)/2; i >= 0; i--)
			percolateDown(h, i);
	else
		for(i = (n-1)/2; i >= 0; i--)
			percolateDown_min(h, i);
}



void buildHeap(heap *h, int a[], int n)
{
	int i;
	if(h==NULL)
		return;
	while(n > h->capacity)	
		resizeHeap(h);
	for(i=0;i<n;i++)
		h->arr[i] = a[i];
	h->count = n;
	for(i = (n-1)/2; i >= 0; i--)
		percolateDown(h, i);
}

int deleteMax(heap *h)		// used to delete the maximum element
{
	int data;
	if(h->count == 0)
		return -1;
	data=h->arr[0];
	h->arr[0]=h->arr[(h->count)-1];
	h->count--;
	percolateDown(h,0);
	return data;
}


int main()
{
	int size, type,i=0,n,del;
	heap *maxHeap,*minHeap;
	maxHeap = createHeap(100,1);
	minHeap = createHeap(100,0);
	cout<<"start entering elements, -1 to stop : ";
	while(1)
	{
		cin>>n;
		if(n==-1)
			break;
		if(i==0)
		{
			insert(maxHeap,n);
		}
		else
		{
			if(maxHeap->arr[0] > n )//&& maxHeap->count == minHeap->count )
			{
				if( maxHeap->count == minHeap->count )
				{
					insert(maxHeap,n);
				}
				else
				{
					del=maxHeap->arr[0];
					deleteMax(maxHeap);
					insert(minHeap,del);
					insert(maxHeap,n);
				}
			}		
			else if( minHeap->arr[0] < n )//&& maxHeap->count = minHeap->count + 1 )
			{
				if( maxHeap->count == minHeap->count + 1 )
				{
					insert(minHeap,n);
				}
				else
				{
					del=minHeap->arr[0];
					deleteMax(minHeap);
					insert(maxHeap,del);
					insert(minHeap,n);
				}
			}
			
		}
		i++;
		cout<<"min ";
		for(i=0;i<(minHeap->count);i++)
			cout<<(minHeap->arr[i])<<" ";
		cout<<endl;
		cout<<"max ";
		for(i=0;i<(maxHeap->count);i++)
			cout<<(maxHeap->arr[i])<<" ";
		cout<<endl;
		if(maxHeap->count == minHeap->count)
			cout<<"median = "<<(maxHeap->arr[0] + maxHeap->arr[0])/2<<endl;
		else
			cout<<"median = "<<maxHeap->arr[0]<<endl;
	}

	
	return 0;
}
