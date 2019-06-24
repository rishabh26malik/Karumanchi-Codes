/*
Find k max elements from max heap.

Solution: One simple solution to this problem is: build max-heap and perform deletion k times.
T(n) = DeleteMin from heap k times = Θ(klogn).
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
	h->arr=(int*)malloc(sizeof(int) * h->capacity);
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

int deleteMin(heap *h)
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
	int size, type,i,n,max1,k;
	cout<<"enter heap size, type : ";	// 0 = min Heap,  1 = max Heap
	cin>>size>>type;
	int a[size];
	heap *heap;
	heap = createHeap(size,type);
	cout<<"enter no. of elements to insert : ";
	cin>>n;
	cout<<"enter numbers : ";
	for(i=0;i<n;i++)
		cin>>a[i];
	buildHeap(heap,a,n);
	for(i=0;i<n;i++)
		cout<<(heap->arr[i])<<" ";
	cout<<"enter  k : ";
    cin>>k;
	while(k)
	{
		max1=deleteMin(heap);
		cout<<max1<<" ";
		k--;
	}
	return 0;
}
