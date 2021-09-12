#include <iostream> 
using namespace std;

void func(int, int);
int main() 
{
	int t, n, k;
	cin>>t;

	for(int i=0; i<t; i++)
	{
		cin>>n>>k;
		func(n, k);
	}
	return 0;
}

void func(int n, int k)
{
	int a[n]={0}, j, m=0, t=n;
	for(int i=1; i<=n; i++)
	{
		cin>>j;
		a[j-1]++;
	}

	for(int i=1; i<=n; i++)
	{
		if(a[i-1]>2)
		{
			m++;
			t = t-i;
		}
	}

	while(t>0)
	{
		t = t-k;
		m++;
	}

	cout<<m<<endl;
}