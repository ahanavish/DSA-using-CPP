#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char str[100];
    cout<<"enter string: ";
    gets(str);

    int i=0, j=strlen(str);
    int mid=j/2, t=0;
    while(i<mid)
    {
        if(str[i] == str[j-1])
            i++, j--;
        else 
        {
            t = 1;
            break;
        }
    }
    
    if(t == 1)
        cout<<"not a palindrome";
    else 
        cout<<"palindrome";
}