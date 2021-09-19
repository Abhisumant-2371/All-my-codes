#include <bits/stdc++.h>
using namespace std;
vector<bool> visi;
vector<int> color;
bool bipart;
class Graph
{
    list<int> *l;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }
    void edge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    bool isbipartite(int src,vector<int> &dist)
    {
        queue<pair<int,int> >q;
        q.push({src,0});
        while(!q.empty())
        {
            pair<int,int>p=q.front();
            q.pop();
            if(dist[p.first]!=INT_MAX)
            {
                if(dist[p.first]!=p.second)return false;
            }
            else{
                dist[p.first]=p.second;
            }
            for(auto nbr:l[p.first])
            {
                if(dist[nbr]==INT_MAX)
                {
                    q.push({nbr,p.second+1});
                }
            }
        }
        return true;
    }
    void bipartite()
    {
        // vector<int> visi(v, false);
        vector<int> dist(v, INT_MAX);
        bool result = true;
        for (int i = 0; i < v; i++)
        {
            if (dist[i] ==INT_MAX);
            {
                if (!isbipartite(i, dist))
                    result = false;
            }
        }
        if (result)
            cout << "The graph is biparitite\n";
        else
            cout << "the graph is not bipartite\n";
        
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
    g.bipartite();

}