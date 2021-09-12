#include <iostream>
using namespace std;
main()
{
	int a[3][3];
	int b[3][3]={1,2,3,4,5,6,7,8,9};
	int c[3][3]={1,2,3,4,5,6,7,8,9};
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			a[i][j]=b[i][j]+c[i][j];
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<"\t\t"<<a[i][j];
	    }
		cout<<"\n";
	}
	cout<<"\n";
	int *p;
	p=&a[0][0];
	for(i=0;i<3;i++,p++)
	{
		for(j=0;j<3;j++,p++)
		{
			cout<<"\t"<<p;
		} 
		cout<<"\n";
	}
}
