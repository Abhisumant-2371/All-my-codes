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
    }
    bool iscycle(int src,vector<bool>&visi,vector<bool>&stak)
    {
        if(stak[src]==true)return true;
        visi[src]=true;
        stak[src]=true;
        for(auto nbr:l[src])
        {
            if(visi[nbr]==false && iscycle(nbr,visi,stak))
            return true;
            else if(visi[nbr]==true)
            {
                if(stak[nbr]==true)return true;
            }
        }
        stak[src]=false;
        return false;
    }
    void dfs_cycle()
    {
        vector<bool>visi(v,false);
        vector<bool>stak(v,false);
        bool result=false;
        for(int i=0;i<v;i++)
        {
            if(visi[i]!=true)
            {
                if(iscycle(i,visi,stak))result=true;
            }
        }
        if(result)cout<<"the graph has cycle";
        else cout<<"cycle not present";
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
    g.dfs_cycle();


}