#include<bits/stdc++.h>
using namespace std;
struct Car
{
    int x;
    int y;
    int id;
    int dist()
    {
        return pow((x*x+y*y),0.5);
    }
    Car(int x,int y,int id)
    {
        this->x=x;
        this->y=y;
        this->id=id;
    }
};
//costomize function class for the priority queue
class functor
{
  public:
    bool operator()(Car c1,Car c2)
    {
        return c1.dist()<c2.dist();
    }  
};
int main()
{
    priority_queue<Car,vector<Car>,functor> q;
    int a[]={2,4,3,6,5};
    int b[]={1,4,3,5,6};
    for(int i=0;i<5;i++)
    {
        Car c(a[i],b[i],i);
        q.push(c);
    }   
    while(!q.empty())
    {  
        cout<<"Car with id-> "<<q.top().id<< " x-coordinate "<<q.top().x;
        cout<<"and y coordinate " <<q.top().y<<endl;
        q.pop();
    }
    return 0;
}
