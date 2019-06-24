#include<bits/stdc++.h>
using namespace std;

int fun(int n)
{
	int i,sum[n],j;
	sum[0]=sum[1]=2;
	for(i=2;i<=n;i++)
	{
		sum[i]=0;
		for(j=1;j<i;j++)	
			sum[i] += 2 * sum[j] * sum[j-1];
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
