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
    bool dfs_cycle_helper(int a,vector<int>&visi,int parent)
    {
        if(visi[a]==true)return true;
        visi[a]=true;
        for(auto x:l[a])
        {
            if(x!=parent)
            {
                if(visi[x]==true)
                {
                    return true; 
                }
                else if(visi[x]==false && dfs_cycle_helper(x,visi,a))
                {
                    return true;
                }
            }
        }
        return false;
    }
    void iscycle_dfs()
    {
        vector<int>visi(v,false);
        int flag=0;
        for(int i=0;i<v;i++)
        {
            if(visi[i]==false && dfs_cycle_helper(i,visi,-1))
                {
                    cout<<"This graph contain cycle\n";
                    flag=1;
                
                }

        }
        if(flag!=1)
        cout<<"The graph doesn't have any cycle\n";
    }
    bool bfs_cycle_helper(int src,vector<int>& visi)
    {
        queue<int>q;
        q.push(src);
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            if(visi[x]==true)return true;
            else
            {
                visi[x]=true;
                for(auto nbr:l[x])
                {
                    if(visi[nbr]==false)
                    q.push(nbr);
                }
            }
        }
        return false;
    }
    void iscycle_bfs()
    {
        vector<int>visi(v,false);
        int flag=0;
        for(int i=0;i<v;i++)
        {
            if(visi[i]==false && bfs_cycle_helper(i,visi))
            {
                flag=1;
                cout<<"graph is cyclic";
            }

        }
        if(!flag)cout<<"the graph is not cyclic";

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
    g.iscycle_dfs();
    g.iscycle_bfs();

}