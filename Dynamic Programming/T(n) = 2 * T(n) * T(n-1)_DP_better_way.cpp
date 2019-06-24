#include<bits/stdc++.h>
using namespace std;

int fun(int n)
{
	int i,sum[n+1],j;
	sum[0]=sum[1]=2;
	sum[2] = 2 * sum[0] * sum[1];
	for(i=3;i<=n;i++)
	{
		sum[i] = sum[i-1] + 2 * sum[i-1] * sum[i-2];
	}
	return sum[n];
}

int main()
{
	int n;
	cout<<"enter n :";
	cin>>n;
	cout<<fun(n)<<endl;
	return 0;
}
