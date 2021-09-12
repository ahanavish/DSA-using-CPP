#include <iostream>
using namespace std;

class term
{
    public:
    int coeff;
    int exp;
    friend class poly;
};

class poly
{
    int n;
    term *t;

    public:
    void get()
    {
        cout<<"enter the no of terms in poly: ";
        cin>>n;

        t = new term[n];
        for(int i=0; i<n; i++)
        {
            cout<<"enter the coeff and power of x in term "<<i+1<<": ";
            cin>>t[i].coeff>>t[i].exp;
        }
    }

    friend poly operator+(poly, poly);
    void display();
};

poly operator+(poly p1, poly p2)
{
    poly *p3 = new poly;
    p3->n = p1.n + p2.n;
    int i=0, j=0, k=0;
    while(i<p1.n && j<p2.n)
    {
        if(p1.t[i].exp < p2.t[j].exp)
            p3->t[k++] = p2.t[j++];
        else if(p1.t[i].exp > p2.t[j].exp)
            p3->t[k++] = p1.t[i++];
        else
        {
            p3->t[k].exp = p1.t[i].exp;
            p3->t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }
    }
    p3->n = k;
    return *p3;
}

void poly::display()
{
    for(int i=0; i<n; i++)
        cout<<t[i].coeff<<" "<<t[i].exp<<endl;
}
int main()
{
    poly p1, p2, p3;
    cout<<"poly 1: ";
    p1.get();
    cout<<"poly 2: ";
    p2.get();
    p3 = p1+p2;
    cout<<"added poly: "<<endl;
    p3.display();
}