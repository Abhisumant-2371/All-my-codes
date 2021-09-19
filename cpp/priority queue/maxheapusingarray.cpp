#include <bits/stdc++.h>
using namespace std;
class Maxheap
{
    int size;
    int *arr;
    int ele_sofar;
public:
    Maxheap(int size)
    {
        this->size=size+1;
        arr=new int [size+1];
        ele_sofar=0;
    }
    void swap(int *a,int *b)
    {
        int temp;
        temp=*a;
        *a=*b;
        *b=temp;
    }
    void insert(int key)
    {
        if(ele_sofar==size)return;
        ++ele_sofar;
        arr[ele_sofar]=key;
        int i=ele_sofar;
        while(!(i<=1 || arr[i]<arr[i/2]))
        {
            swap(&arr[i],&arr[i/2]);
            i=i/2;
        }
    }
    void deleteit()
    {
        if(!ele_sofar)
            {
                cout<<"already empty\n";
                return ;
            }
        swap(&arr[1],&arr[ele_sofar]);
        int i=1;
        ele_sofar--;
        while(ele_sofar>=2*i)
        {
            if(ele_sofar>=2*i+1)
            {
                int child=(arr[2*i]>arr[2*i+1])?0:1;
                if(child)
                {
                    if(arr[i]>arr[2*i+1])break;
                    swap(&arr[i],&arr[2*i+1]);
                    i=2*i+1;
                }
                else
                {
                    if(arr[i]>arr[2*i])break;
                    swap(&arr[i],&arr[2*i]);
                    i=2*i;
                }
            }
            else
            {
                if(arr[i]>arr[2*i])break;
                    swap(&arr[i],&arr[2*i]);
                    i=2*i+1;
            }
        }
        
    }
    void display()
    {
        for(int i=1;i<7;i++)
        cout<<arr[i]<<" ";
    }
};
int main()
{
    int n,a;
    cout<<"Enter the no. of element to be inserted\n";
    cin>>a;
    Maxheap m(10);
    while(a--)
    {
        cin>>n;
        m.insert(n);
    }
    cout<<"Now deleting the element to get heap  sort\n";
    for(int i=1;i<7;i++)
        m.deleteit();
    m.display();

}