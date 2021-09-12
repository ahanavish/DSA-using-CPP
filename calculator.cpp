#include <iostream>
using namespace std;
void add()
{
	int a,b;
	cout<<"enter two numbers";
	cin>>a>>b;
	cout<<"\n sum ="<<a+b;	
}
void sub()
{
	int a,b;
	cout<<"enter two numbers";
	cin>>a>>b;
	if(a>b)
	cout<<"\n difference ="<<a-b;
	else
	cout<<"\n difference ="<<b-a;
	
	
}
void mul()
{
	int a,b;
	cout<<"enter two numbers";
	cin>>a>>b;
	cout<<"\n product ="<<a*b;	
}
void div()
{
	int a,b;
	cout<<"enter two numbers";
	cin>>a>>b;
	cout<<"\n quotient ="<<a/b;	
}
int main()
{
	char c;
	cout<<"enter a mathematical operation(+,-,/,*)";
	cin>>c;
	switch(c)
	{
		case '+': add(); break;
		case '-': sub(); break;
		case '*': mul(); break;
		case '/': div(); break;
		default: cout<<"error";
	}
		
}
