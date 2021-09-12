#include <iostream>
#include <ctime>
#include <iomanip>
#include <string.h>
using namespace std;

int main()
{
    time_t begin, end;
    time(&begin);

    char s1[10];
    cout<<"Enter the string1: ";
    gets(s1);

    int i=0;
    while(s1[i]!='\0')
        i++;

    char *s2 = new char[i];
    for(int j=0; j<=i; j++)
        s2[j] = s1[j];

    cout<<endl<<"-> String2 (copy of String1) using built-in function(strcpy): "<<strcpy(s2, s1)<<endl;
    cout<<"-> String2 (copy of String1) without using built-in function(strcpy): "<<s2<<endl;


    time(&end);
    double time = double(end-begin);

    cout<<"-> Time taken: "<<fixed<<time<<setprecision(7);
    cout<<"sec"<<endl;

    return 0;
}