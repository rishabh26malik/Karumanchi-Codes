#include<bits/stdc++.h>
using namespace std;

int fun(int n)
{
	int i,sum=0;
	if(n==0 || n==1)
		return 2;
	for(i=1; i < n; i++)
		sum += 2 * fun(i) * fun(i-1);
	return sum;
}

int main()
{
	int n;
	cout<<"enter n :";
	cin>>n;
	cout<<fun(n)<<endl;
	return 0;
}
