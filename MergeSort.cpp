#include <iostream>
#include <vector>
using namespace std;
void merge(int a[],int p,int q,int r)
{
    vector<int> b={};
    int i=p;
    int j=q+1;
    while (i<q+1 && j<=r)
    {
        if(a[i]<=a[j])
        {
            b.push_back(a[i]);
            i++;
        }
        else
        {
            b.push_back(a[j]);
            j++;
        }
    }
    while (i<q+1)
    {
        b.push_back(a[i++]);
    }
    while (j<=r)
    {
        b.push_back(a[j++]);
    }
    for (int i=p;i<=r;i++)
    {
        a[i]=b[i-p];
    }
}
void mergesort(int a[],int p,int r)
{
    int q=(p+r)/2;
    if (p>=r)
    {
        return; 
    }
    mergesort(a,p,q);
    mergesort(a,q+1,r);
    merge(a,p,q,r);
}
int main()
{
    int a[5]={0,5,4,3,2};
    for (int i=0;i<5;i++)
    {
        cout<<a[i]<<"  ";
    }
    cout <<endl;
    mergesort(a,0, 5);
    cout <<"res:"<<endl;
    for (int i=0;i<5;i++)
    {
        cout <<a[i]<<"  ";
    }
}