#include <iostream>
using namespace std;
 
template <class T>
void Print(T& vec, int n)
{
    for (int i=0; i<n; i++)
        cout << vec[i] <<" ";
}
 
int Max(int A[], int n)
{
    int max = -32768;
    for (int i=0; i<n; i++)
        if (A[i] > max)
            max = A[i];
    return max;
}
 
class Node
{
    public:
    int value;
    Node* next;
};
 
void Insert(Node** ptrBins, int idx)
{
    Node* temp = new Node;
    temp->value = idx;
    temp->next = nullptr;
 
    if (ptrBins[idx] == nullptr)    // ptrBins[idx] is head ptr
        ptrBins[idx] = temp;
    else 
    {
        Node* p = ptrBins[idx];
        while (p->next != nullptr)
            p = p->next;
        p->next = temp;
    }
}
 
int Delete(Node** ptrBins, int idx)
{
    Node* p = ptrBins[idx];  // ptrBins[idx] is head ptr
    ptrBins[idx] = ptrBins[idx]->next;
    int x = p->value;
    delete p;
    return x;
}
 
void BinSort(int A[], int n)
{
    int max = Max(A, n);
    Node** bins = new Node* [max + 1];
 
    for (int i=0; i<max+1; i++)
        bins[i] = nullptr;
 
    for (int i=0; i<n; i++)
        Insert(bins, A[i]);
 
    int i=0, j=0;
    while(i < max+1)
    {
        while (bins[i] != nullptr)
            A[j++] = Delete(bins, i);
        i++;
    }
    delete [] bins;
}
 
int main() 
{
    int A[] = {2, 5, 8, 12, 3, 5, 7, 10};
    int n = sizeof(A)/sizeof(A[0]);
 
    BinSort(A, n);
    Print(A, n);
    return 0;
}