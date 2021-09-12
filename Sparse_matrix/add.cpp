#include <iostream>
using namespace std;

class element
{
    public: 
    int i;
    int j;
    int no;
    friend class sparse;
};

class sparse
{
    int m;
    int n;
    int num;
    element *e;
    
    public: 
    sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new element[num];
    }
    ~sparse()
    {
        delete []e;
    }

    friend istream& operator>> (istream &in, sparse &s);        //extraction
    friend ostream& operator<< (ostream &out, sparse &s);       //insertion
    friend sparse operator+ (sparse s1, sparse s2);
};

istream& operator>> (istream &in, sparse &s)
{
    cout<<"enter the row no, column no and element itself: ";
    for(int k=0; k<s.num; k++)
        in>>s.e[k].i>>s.e[k].j>>s.e[k].no;
    return in;
}

ostream& operator<< (ostream &out, sparse &s)
{
    int k=0;
    for(int p=1; p<=s.m; p++)
    {
        for(int q=1; q<=s.n; q++)
            if(p == s.e[k].i && q == s.e[k].j)
                out<<s.e[k++].no<<ends;
            else
                out<<"0"<<ends;
        out<<endl;
    }
    return out;
}

sparse operator+ (sparse s1, sparse s2)
{
    int p=0, q=0, k=0;
    if(s2.m == s1.m && s2.n == s1.n)
    {
        sparse *sum = new sparse(s1.m, s1.n, s1.num + s2.num);
        sum->e = new element[sum->num];
        while(p<s1.num && q<s2.num)
        {
            if(s1.e[p].i < s2.e[q].i)
                sum->e[k++] = s1.e[p++];
            else if(s1.e[p].i > s2.e[q].i)
                sum->e[k++] = s2.e[q++];
            else
            {
                if(s1.e[p].j < s2.e[q].j)
                    sum->e[k++] = s1.e[p++];
                else if(s1.e[p].j > s2.e[q].j)
                    sum->e[k++] = s2.e[q++];
                else
                {
                    sum->e[k] = s1.e[p];
                    sum->e[k++].no = s1.e[p++].no + s2.e[q++].no;
                }
            }
        }

        for(; p<s1.num; p++)   {sum->e[k++] = s1.e[p];}
        for(; q<s2.num; q++)   {sum->e[k++] = s2.e[q];}
        sum->num = k;
        return *sum;
    }
}

int main()
{
    sparse s1(5, 6, 5), s2(5, 6, 6);
    cout<<"sparse matrix 1: "<<endl;
    cin>>s1;
    cout<<endl<<"sparse matrix 2: "<<endl;
    cin>>s2;

    cout<<"addition of both sparse matrix: "<<endl;
    sparse sum = s1+s2;
    cout<<sum;
}