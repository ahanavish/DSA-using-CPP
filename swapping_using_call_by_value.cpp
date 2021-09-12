#include <iostream>
using namespace std;
int swap(int, int);
main()
{
	int a=1,b=5;
	swap(a,b);
}
int swap(int a,int b)
{
	cout<<"before swapping:";
	cout<<"\na="<<a<<"and"<<"b="<<b;
	int c;
	c=a;
	a=b;
	b=c;
	cout<<"\nafter swapping:";
	cout<<"\na="<<a<<"and"<<"b="<<b;
}
