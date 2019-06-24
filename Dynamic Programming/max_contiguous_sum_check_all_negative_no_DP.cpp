/*
	pg - 748
	problem - 7 dynamic programming solution
The algorithm doesn’t work if the input contains all negative numbers. It returns 0 if all
numbers are negative. To overcome this, we can add an extra check before the actual
implementation. The phase will look if all numbers are negative, and if they are it will return
maximum of them (or smallest in terms of absolute value).
*/

#include<bits/stdc++.h>
using namespace std;

int max_sum(int *a,int n)
{
	int maxSum=INT_MIN,M[n],i,max1=INT_MIN;
	if(a[0]>0)
		M[0]=a[0];
	else 
		M[0]=0;
	
	for(i=0;i<n;i++)
	{
		if(a[i] <= 0 && max1 < a[i])
			max1 = a[i];
		if(a[i] > 0)
			break;
	}
	
	if(i==n)
		return max1;
	
	for(i=1;i<n;i++)
	{
		if(M[i-1] + a[i] > 0)
			M[i] = M[i-1] + a[i];
		else
			M[i]=0;
	}
	for(i=0;i<n;i++)
		if(M[i] > maxSum)
			maxSum=M[i];
	return maxSum;
}

int main()
{
	int n,i;
	cout<<"enter n :";
	cin>>n;
	int a[n];
	cout<<"enter aray elements : ";
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<max_sum(a,n)<<endl;
	return 0;
}
