#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[100];
    cout<<"enter the string: ";
    gets(str);

    int count=0, i=0;
    while(str[i] != '\0')
    {
        if(str[i+1] == ' '  && str[i] != ' ')                     //to avoid big spaces
            count++;
        i++;
    }
    cout<<"no of words: "<<count+1;
    return 0;
}