#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s1[100], s2[100];
    cout<<"enter two strings: ";         //there must'nt be duplicate alphabets in a string
    cin>>s1>>s2;

    int hash[26] = {0}, i=0, temp=0;
    while(s1[i] != '\0')
    {
        hash[s1[i] - 97]++;
        i++;
    }

    i=0;
    while(s2[i] != '\0')
    {
        hash[s2[i] - 97]--;
        i++;
    }

    for(i=0; i<26; i++)
    {
        if(hash[i] == 0)
            temp=1;
        else
        {
            temp=0;
            break;
        }
    }

    if(temp == 1)
        cout<<"anagrams";
    else
        cout<<"not anagrams";
}