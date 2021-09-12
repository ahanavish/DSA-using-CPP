#include <iostream>
#include <string.h>
using namespace std;
/*
// permutation using recursion and backtracking
void perm(char [], int);
int main()
{
    char str[10];
    cout<<"enter a string: ";
    cin>>str;

    perm(str, 0);
}

void perm(char str[], int k)
{
    static int A[10];
    static char res[10];
    int i=0;

    if(str[k] == '\0')
    {
        res[k] = '\0';
        cout<<res<<endl;
    }
    else
    {
        for(int i=0; str[i] != '\0'; i++)
        {
            if(A[i] == 0)
            {
                res[k] = str[i];
                A[i] = 1;
                perm(str, k+1);
                A[i] = 0;
            }
        }
    }
}
*/
///permutation using recursion and swapping
void perm(char [], int, int);
void swap(char* , char*);
int main()
{
    char str[10];
    cout<<"enter a string: ";
    cin>>str;

    perm(str, 0, strlen(str) - 1);
}

void perm(char str[], int l, int h)
{
    int i;
    if(l == h)
        cout<<str<<endl;
    else
        for(int i=l; i<=h; i++)
        {
            swap(&str[l], &str[i]);
            perm(str, l+1, h);
            swap(&str[l], &str[i]);
        }
}

void swap(char *s1, char *s2)
{
    char temp = *s1;
    *s1= *s2;
    *s2= temp;
}