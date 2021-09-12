#include <iostream>
using namespace std;
int sum(int b[]);
int main()
{
	int i,j,k=0,a[200];            
	for(i=2;i<1000;i++)
	{
		int c=0,s=0;
		for(j=2;j<i;j++)
		{
			if(i%j==0)   //non prime
			c++;
		}
		if(c==0)
	    {
	    	a[k]=i;
	    	k++;
	    }
	}
	for(int l=0;l<168;l++)
	cout<<"\n"<<a[l];              //printing prime no
	cout<<"\n sum="<<sum(a);            //passing array into a function to calc sum
}
int sum(int b[200])
{
	int i,s=0;
	for(i=0;i<168;i++)
	{
	s=s+b[i];
	}
	return s;             //returning sum to the main function
}
