// union by rank optimisation
// what we need to do is to store that how many element/nodes
// are there in the particular set and then take the union of the 
// set with higher no. of element/node
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
        return find(parent[i],parent);
    }
    void union_set(int x,int y,vector<int>&parent,vector<int>siz)
    {
        int s1=find(x,parent);
        int s2=find(y,parent);
        if(s1!=s2)
        {
            if(siz[s1]<siz[s2])
            {
                parent[s1]=s2;
                siz[s2]+=siz[s1];
            }
            else {
                parent[s2]=s1;
                siz[s1]+=siz[s2];
            }
        }
    }
    bool contain_cycle()
    {
        //  dsu logic
        vector<int>parent(v,-1);
        vector<int>siz(v,1);
        for(auto edge:l)
        {
            int i=edge.first;
            int j=edge.second;
            int s1=find(i,parent);
            int s2=find(j,parent);
            if(s1!=s2)
            {
                union_set(i,j,parent,siz);
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