#include <iostream>
using namespace std;

class term
{
    int coeff;
    int exp;
    friend class poly;
};

class poly
{
    int n;
    term *t;
    public:
    poly()
    {
        cout<<"enter the no of terms: ";
        cin>>n;

        t = new term [n];
        for(int i=0; i<n; i++)
        {
            cout<<"enter the coeff and power of x of "<<i+1<<" term: ";
            cin>>t[i].coeff>>t[i].exp;
        }
    }
    ~poly()
    {
        delete []t;
    }

    int value(int x)
    {
        int s=0;
        for(int i=0; i<n; i++)
        {
            int m = t[i].coeff;
            for(int j=0; j<t[i].exp; j++)
                m = m*x;
            s = s + m;
        }
        return s;
    }
};

int main()
{
    poly p;
    int x;
    cout<<"enter value of x: ";
    cin>>x;
    int val = p.value(x);
    cout<<"evaluated value of polynomial: "<<val;
}
