#include <iostream>
using namespace std;
main ()
{
   int i = 0;
   char ch, s[1000];
   cout<<"enter a string \n";
   gets(s);
   while (s[i] != '\0') 
   {
      ch = s[i];
      if (ch >= 'A' && ch <= 'Z')
         s[i] = s[i] + 32;
      else if (ch >= 'a' && ch <= 'z')
         s[i] = s[i] - 32;  
      i++;  
   }
   cout<<"After changing the case:"<<s;
}
