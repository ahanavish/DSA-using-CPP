#include <iostream>
using namespace std;
int* add(int*,int*, int*z);       //passing address and returning address 
int main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={10,20,30,40,50};
	int c[5]={0};
	int *p;                       //storing returned address in pointer p(doesnt have any use ,done just to call function)
	p=add(a,b,c);
	for(int i=0;i<5;i++)
		cout<<"\n"<<c[i];                //printing c[0],c[1] etc
	return 0;
}
int* add(int*x,int*y,int*z)              //since *z=c,thus z=&c[0],*z=c[0]
{
	for(int j=0;j<5;j++,x++,y++,z++)
	    *z=*x+*y;                           //c[0]=a[0]+b[0]
    return z;                                //returning c[0] at p which is useless but what did the work is since z and c are related so ultimately we got c[0]
}
