/*
	pg - 754
	problem -14
*/
#include<bits/stdc++.h>
using namespace std;



int catalan(int n)
{
	int cat[n+1],i,j;
	cat[0]=cat[1]=1;
	for(i=2;i<=n;i++)
	{
		cat[i]=0;
		for(j=0;j<i;j++)
			cat[i] += cat[j] * cat[i-j-1];
	}
	return cat[n];
}

int main()
{
	int n;
	cout<<"enter n :";
	cin>>n;
	cout<<catalan(n)<<endl;
	return 0;
}
