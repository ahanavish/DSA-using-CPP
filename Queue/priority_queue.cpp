#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

struct item 
{
    int value;
    int priority;
};
 
item pr[100];
int size = -1;
 
void enqueue(int value, int priority)
{
    size++;
    pr[size].value = value;
    pr[size].priority = priority;
}
 
int peek()
{
    int highestPriority = -1;
    int ind = -1;
 
    for (int i = 0; i <= size; i++) 
        if (highestPriority == pr[i].priority && ind>-1 && pr[ind].value<pr[i].value) 
        {
            highestPriority = pr[i].priority;
            ind = i;
        }
        else if (highestPriority<pr[i].priority) 
        {
            highestPriority = pr[i].priority;
            ind = i;
        }

    return ind;
}
 
int dequeue()
{
    int ind = peek();
 
    for (int i = ind; i < size; i++) 
        pr[i] = pr[i + 1];
 
    size--;
    return ind;
}
 
int main()
{
    time_t begin, end;
    time(&begin);

    int value[] = {10, 14, 16, 12}, priority[] = {2, 4, 4, 3};

    cout<<"elements with their priorities: "<<endl;
    for(int i=0; i<4; i++)
        cout<<value[i]<<" ";
    cout<<endl;
    for(int i=0; i<4; i++)
        cout<<priority[i]<<"  ";

    for(int i=0; i<4; i++)
        enqueue(value[i], priority[i]);
    
    repeat:
    int opt;
    cout<<endl<<endl<<"--> Choose the operation to be performed:"<<endl<<"1. peek"<<endl<<"2. dequeue"<<endl;
    cin>>opt;

    if(opt == 1)
    {
        int ind = peek();
        cout <<"The element with the highest priority: "<<pr[ind].value << endl;
    }
    else if(opt == 2)
    {
        int ind = dequeue();
        cout<<"The deleted element: "<<pr[ind].value<<endl;
    }

    int again;
    cout<<endl<<"--> Would you like to perform another operation(1/ 0): ";
    cin>>again;
    if(again==1)
        goto repeat;
    else
        cout<<endl<<"exit!";

    time(&end);
    double time = double(end-begin);
    cout<<endl<<"-> Time taken: "<<fixed<<time<<setprecision(5);
    cout<<"sec"<<endl;
    return 0;
}