/*
Give an algorithm for merging two binary max-heaps. Let us assume that the size
of the first heap is m + n and the size of the second heap is n.

Solution  1 : One simple way of solving this problem is:
•
Assume that the elements of the first array (with size m + n) are at the beginning.
That means, first m cells are filled and remaining n cells are empty.
Without changing the first heap, just append the second heap and heapify the array.
Since the total number of elements in the new array is m + n, each heapify operation
takes O(log(m + n)).
The complexity of this algorithm is : O((m + n)log(m + n)).

Solution  2 : One simple way of solving this problem is:
•
Instead of heapifying all the elements of the m + n array, we can use the technique of
“building heap with an array of elements (heapifying array)”. We can start with non-leaf nodes
and heapify them. The algorithm can be given as:
•
Assume that the elements of the first array (with size m + n) are at the beginning.
That means, the first m cells are filled and the remaining n cells are empty.
Without changing the first heap, just append the second heap.
Now, find the first non-leaf node and start heapifying from that element.
In the theory section, we have already seen that building a heap with n elements takes O(n)
complexity. The complexity of merging with this technique is: O(m + n).

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
	h->arr=(int*)malloc(sizeof(int)* h->capacity);
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

heap* merge(heap *h1, heap *h2)
{
	int i=h1->count, j=0, n;
	heap *merge =	(heap*)malloc(sizeof(heap));
	if(merge == NULL)
	{
		cout<<"memory error"<<endl;
		return NULL;
	}
	merge->heap_type = 1;
	merge->count = 0;
	merge->capacity = h1->count + h2->count;
	merge->arr=(int*)malloc(sizeof(int)* merge->capacity);
	cout<<"2"<<endl;
	for(i=0; i < h1->count; i++)
		merge->arr[i]=h1->arr[i];
	for(; i< (h1->count + h2->count);i++)
	{
		merge->arr[i]=h2->arr[j];
		j++;
	}
	merge->count = h1->count + h2->count;

	n=(merge->count - 1)/2;
	for(i = n; i >= 0; i--)
		percolateDown(merge,i);
	return merge;
}

int main()
{
	int size, type,i,n,num;
	cout<<"enter heap size, type : ";	// 0 = min Heap,  1 = max Heap
	cin>>size>>type;
	int a[1000];
	heap *heap, *heap2, *m;
	heap = createHeap(size,type);
	cout<<"enter no. of elements to insert in heap 1 : ";
	cin>>n;
	cout<<"enter numbers : ";
	for(i=0;i<n;i++)
		cin>>a[i];
	buildHeap(heap,a,n);
	for(i=0;i<n;i++)
		cout<<(heap->arr[i])<<" ";
	cout<<endl;

	heap2 = createHeap(size,type);
	cout<<"enter no. of elements to insert in heap 2 : ";
	cin>>n;
	cout<<"enter numbers : ";
	for(i=0;i<n;i++)
		cin>>a[i];
	buildHeap(heap2,a,n);
	for(i=0;i<n;i++)
		cout<<(heap2->arr[i])<<" ";
	cout<<endl;
	m=merge(heap, heap2);
	for(i=0;i<heap->count + heap2->count;i++)
		cout<<(m->arr[i])<<" ";
	return 0;
}
