#include <bits/stdc++.h>
using namespace std;
class Graph
{
    list<int>*l;
    int v;
    public:
    Graph(int v)
    {
        this->v=v;
        l=new list<int>[v];
    }
    void edge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    int cyclelengthfromsrc(int src,vector<int>dist)
    {
        int min=INT_MAX;
        queue<pair<int,int>>q;
        q.push({src,0});
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            if(dist[p.first]!=INT_MAX)
            {
                if(dist[p.first]!=p.second)
                {
                    int a=2*dist[p.first]+1;
                    return a;
                }
                else 
                {
                    int a=2*dist[p.first];
                    return a;
                }
            }
            else
            {

                dist[p.first]=p.second;
            }
            for(auto nbr :l[p.first])
                {
                    if(dist[nbr]==INT_MAX)
                    {
                        q.push({nbr,p.second+1});
                    }
                }
        }
        return min;

    }
};
int main()
{
    int v,e;
    cin>>v>>e;
    Graph g(v);
    for(int i=0;i<e;i++)
    {
        int x,y;
        cin>>x>>y;
        g.edge(x,y);
    }
    int min=INT_MAX;
    vector<int>dist(v,INT_MAX);
    for(int i=0 ;i<v;i++)
    {
            int a=g.cyclelengthfromsrc(i,dist);
            min=min<a?min:a;

    }
    cout<<min;
    // cout<<g.cyclelengthfromsrc(0,dist);
}
