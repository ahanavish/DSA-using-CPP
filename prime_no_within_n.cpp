#include <iostream>
using namespace std;
int main()
{
	int i,j,n; //c cant be declared here
	cout<<"enter a no";
	cin>>n;             
	for(i=2;i<n;i++)
	{
		int c=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)   //non prime
			c++;
		}
		if(c==0)
	    cout<<"\n"<<i;
	}
	return 0;
}
