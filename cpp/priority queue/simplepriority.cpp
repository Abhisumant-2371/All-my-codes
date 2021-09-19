#include <bits/stdc++.h>
using namespace std;
class Remainder
{
    public:
        int x;
        Remainder(int x)
        {
            this->x=x;
        }
         int remind() const
        {
            return (x%6);
        }

};
struct com
{
    bool operator()(Remainder x,Remainder y)
    {
        return y.remind()>x.remind();
    }
};
int main()
{
    int a[]={2,4,5,3,7,5};
    //if third argument isn't passed in the below line the by default it is 
    // max heap
    priority_queue<Remainder,vector<Remainder>,com> p;
    for(int i=0;i<6;i++)
    {
        Remainder r(a[i]);
        p.push(r);
    }
    while(!p.empty())
    {
        cout<<p.top().x<< "whose reminder is "<<p.top().remind()<<" \n";
        p.pop();
    }
    return 0;
    
}
//Here in this question the priority of the code is remainder by 6