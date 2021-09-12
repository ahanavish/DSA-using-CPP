#include <iostream>
using namespace std;
int swap(int*, int*);
main()
{
	int a=1,b=5;
	swap(&a,&b);
}
int swap(int *i,int *j)
{
	cout<<"before swapping:";
	cout<<"\na="<<*i<<"and"<<"b="<<*j;
	int c;
	c=*i;
	*i=*j;
	*j=c;
	cout<<"\nafter swapping:";
	cout<<"\na="<<*i<<"and"<<"b="<<*j;
}
