/*
	pg - 747
	problem - 6
*/

#include<bits/stdc++.h>
using namespace std;

int max_sum(int *a,int n)
{
	int maxSum=INT_MIN,M[n],i;
	if(a[0]>0)
		M[0]=a[0];
	else 
		M[0]=0;
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
