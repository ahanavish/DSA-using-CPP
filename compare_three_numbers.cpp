#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cout<<"enter the three numbers";
	cin>>a>>b>>c;
	/*if(a>b)
	{
		if(a>c)
		cout<<"first no is biggest";
		else
		cout<<"third no is greatest";
	}
	else
	{
		if(b>c)
		cout<<"second no is greatest";
		else
		cout<<"third no is greatest";
	}
	*/
	if(a>b && a>c)
	cout<<"first no is biggest";
	if(b>a && b>c)
	cout<<"second no is greatest";
	else 
	cout<<"third no is greatest";
	return 0;
}
