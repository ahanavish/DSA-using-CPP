#include <iostream>
#include <ctime>
#include <iomanip>
#include <string.h>
using namespace std;

int cmp(char*, char*);
int main()
{
    time_t begin, end;
    time(&begin);

    char s1[10], s2[10];
    cout<<"Enter string1: ";
    gets(s1);
    cout<<"Enter string2: ";
    gets(s2);

    cout<<endl<<"-> Comparing the strings using built-in function, we get: "<<strcmp(s1, s2);
    cout<<endl<<"-> Comparing the strings without using built-in function, we get: "<<cmp(s1, s2);

    time(&end);
    double time = double(end-begin);

    cout<<endl<<"-> Time taken: "<<fixed<<time<<setprecision(5)<<"sec"<<endl;
    return 0;
}

int cmp(char* s1, char* s2)
{
    for(;*s1!='\0' && s2!='\0'; s1++, s2++)
    {
        if(*s1>*s2) return 1;
        if(*s1<*s2) return -1;
    }

    if(*s1 != '\0') return 1;
    if(*s2 != '\0') return -1;
    return 0;
}