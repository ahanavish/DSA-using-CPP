#include <iostream>
#include <ctime>
#include <iomanip>
#include <string.h>
using namespace std;

int main()
{
    time_t begin, end;
    time(&begin);

    char a[10];
    cout<<"Enter the string: ";
    gets(a);

    int length = 0;
    while(a[length]!='\0')  length++;

    cout<<endl<<"-> Length of given string using built-in function(strlen): "<<strlen(a)<<endl;
    cout<<"-> Length of given string without using built-in function(strlen): "<<length<<endl; 

    time(&end);
    double time = double(end-begin);

    cout<<"-> Time taken: "<<fixed<<time<<setprecision(5)<<"sec";
    return 0;
}