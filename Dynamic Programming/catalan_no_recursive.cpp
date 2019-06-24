/*
	pg - 753
	problem - 13
*/
#include<bits/stdc++.h>
using namespace std;

int catalan(int n)
{
	if(n==0)
		return 1;
	int i, count = 0;
	for(i=1;i<=n;i++)
		count += catalan(i-1) * catalan(n-i);
	return count;
}

int main()
{
	int n;
	cout<<"enter n :";
	cin>>n;
	cout<<catalan(n)<<endl;
	return 0;
}
