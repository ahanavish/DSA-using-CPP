#include <iostream>
#include <ctime>
#include <iomanip>
#include <string.h>
using namespace std;

int main()
{
    time_t begin, end;
    time(&begin);

    char s1[10], s2[10];
    cout<<"Enter string1: ";
    gets(s1);
    cout<<"Enter string2: ";
    gets(s2);

    int s1l = 0, s2l = 0;
    for(s1l=0; s1[s1l] != '\0'; s1l++);
    for(s2l=0; s2[s2l] != '\0'; s2l++);
    
    char s3[s1l + s2l];
    for(int i=0; i<s1l; i++)
        s3[i] = s1[i];
    for(int i=0; i<=s2l; i++, s1l++)
        s3[s1l] = s2[i];

    cout<<endl<<"-> String concatenated using built-in function(strcat): "<<strcat(s1, s2);
    cout<<endl<<"-> String concatenated wihtout using built-in function(strcat): "<<s3;

    time(&end);
    cout<<endl<<"-> Total length of the concatenated string: "<<s1l-1<<endl;
    double time = double(end-begin);

    cout<<"-> Time taken: "<<fixed<<time<<setprecision(5);
    cout<<"sec"<<endl;
    return 0;
}