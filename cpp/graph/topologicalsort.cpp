#include <bits/stdc++.h>
using namespace std;

// Topological sort is done for the directed acyclic graph 
class Graph
{   // v denotes the no. of vertex in the graph
    int v;
    list<int> *l;
    public:
    Graph(int v)
    {
        this->v=v;
        l=new list<int>[v+1];
    }
    void addedge(int x,int y,vector<int> &indeg)
    {
        l[x].push_back(y);
        ++indeg[y];
    }
    void topological_sort(int n,vector<int> indeg)
    {
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            if(indeg[i]==0)q.push(i);
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            cout<<x<<" ";
            for(auto a:l[x])
            {
                indeg[a]--;
                if(indeg[a]==0)q.push(a);
            }
        }

    }
    void topologicalsort_dfs(int src,vector<bool>&visi,stack<int>&s)
    {
        visi[src]=true;
        for(auto nbr:l[src])
        {
            if(!visi[nbr])
            {
                topologicalsort_dfs(nbr,visi,s);
            }
        }
        s.push(src);
    }
    void topo_dfs()
    {
        stack <int>s;
        vector<bool>visi(v,false);
        for(int i=0;i<v;i++)
        {
            if(visi[i]!=true)
            {
                topologicalsort_dfs(i,visi,s);
            }
        }
        while(!s.empty())
        {
            cout<<s.top()<<"\n";
            s.pop();
        }
    }
};
int main()
{
    int n,m;
    cout<<"enter the no of vertex and edges\n";
    cin>>n>>m;
    Graph g(n);
    vector<int> indeg(n+1,0);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cout<<" enter the values\n";
        cin>>x>>y;
        g.addedge(x,y,indeg);
    }
    g.topo_dfs();
}