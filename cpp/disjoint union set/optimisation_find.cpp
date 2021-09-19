#include <bits/stdc++.h>
using namespace std;

//Cycle detection in an undirected graph using DSU

class Graph{
    int v;
    list<pair<int,int>>l;
    public:
    Graph(int v)
    {
        this->v=v;
    }
    void addedge(int x,int y)
    {
        l.push_back({x,y});
    }
    int find (int i,vector<int>parent)
    {
        if(parent[i]==-1)return i;
        // what we have to do is to every time we have to
        // to keep on  updating the parent of the element'
        parent[i]=find(parent[i],parent);
        return parent[i];
    }
    void union_set(int x,int y,vector<int>&parent)
    {
        int a=find(x,parent);
        int b=find(y,parent);
        if(a!=b)
        {
            parent[b]=a;
        }
    }
    bool contain_cycle()
    {
        //  dsu logic
        vector<int>parent(v,-1);
        for(auto edge:l)
        {
            int i=edge.first;
            int j=edge.second;
            int s1=find(i,parent);
            int s2=find(j,parent);
            if(s1!=s2)
            {
                union_set(i,j,parent);
            }
            else return true;
        }
        return false;
    }
};
int main()
{
    int v,e;
    cin>>v>>e;
    Graph g(v);
    int x,y;
    while(e--)
    {
        cin>>x>>y;
        g.addedge(x,y);
    }
    cout<<g.contain_cycle();
}