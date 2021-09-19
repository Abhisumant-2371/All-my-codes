#include <bits/stdc++.h>
using namespace std;
class Graph
{
    list<pair<int,int>>*l;
    int vertex;
    public:
    Graph(int v)
    {
        vertex=v;
        l=new list<pair<int,int>>[v];
        
        
    }
    void addedge(int x,int y,int wt)
    {
        l[x].push_back({y,wt});

    }
    void shortest_path(int src,vector<int>&dist,vector<string>&path)
    {
        queue<int>p;
        p.push(src);
        while(!p.empty())
        {
            int a=p.front();
            p.pop();
            for(auto x:l[a])
            {
                if(dist[x.first]==INT_MAX || dist[x.first]>(dist[a]+x.second))
                {
                    dist[x.first]=dist[a]+x.second;
                    path[x.first]=path[a]+to_string(x.first);
                    p.push(x.first);
                }
                
               
            }
        }
    }
    void print()
    {
        for(int i=0;i<vertex;i++)
        {
            for(auto a:l[i])
            {
                cout<<a.first<<" "<<a.second;
            }
        }
    }
};
int main()
{
    int v,e;
    cin>>v>>e;
    int x,y,w;
    Graph d(v);

    for(int i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        d.addedge(x,y,w);
    }
    vector<int>dist(v,INT_MAX);
    dist[0]=0;
    vector<string>path(v,"");
    path[0]=to_string(0);
    d.shortest_path(0,dist,path);
    for(int i=0;i<v;i++)
    {
        cout<<"dist of "<<i<<"is "<<dist[i]<<"=>"<<path[i]<<" \n" ;
    }
}