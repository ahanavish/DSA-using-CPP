#include <iostream>
using namespace std;

class element
{
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
    sparse()
    {
        cout<<"enter the dimensions(row no and column no): ";
        cin>>m>>n;
        cout<<"enter no of non zero elements: ";
        cin>>num;
        e = new element[num];
    }
    ~sparse()   {delete []e;}

    void read()
    {
        
        cout<<"enter the row no, column no and row itself: ";
        for(int k=0; k<num; k++)
            cin>>e[k].i>>e[k].j>>e[k].no; 
    }

    void display()
    {
        int k =0;
        for(int p=1; p<=m; p++)
        {
            for(int q=1; q<=n; q++)
                    if(p == e[k].i && q == e[k].j)
                        cout<<e[k++].no<<" ";
                    else
                        cout<<"0 ";
            cout<<endl;
        }
    }
};

int main()
{
    sparse s;
    s.read();
    cout<<"sparse matrix: "<<endl;
    s.display();
}
