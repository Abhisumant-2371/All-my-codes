#include <bits/stdc++.h>
using namespace std;
class Graph
{
    map<int,list<int>>m;
    public:
    void addedge(int x,int y)
    {
        m[x].push_back(y);
        m[y].push_back(x);
    }
    void dfshelper(int src,map<int ,bool>&visi)
    {
        if(visi[src]==true)return ;
        cout<<src<<" " ;
        visi[src]=true;
        for(auto a:m[src])
        {
            dfshelper(a,visi);
        }
    }
    void dfstraversal()
    {
        map<int,bool>visi;
        for(auto a:m)
        {
            visi[a.first]=false;

        }
        dfshelper(0,visi);
    }
    
    void connectedcomp_using_dfs()
    {
        map<int ,bool>visi;
        for(auto a:m)
        {
            visi[a.first]=false;
        }
    
        for(auto a:m)
        {
            // No of times this function is called will represent the 
            // the no of connected components in the graph
            dfshelper(a.first,visi);
            //from a particular call we can find the size of single 
            // component of the graph
            cout<<endl;
        }
    }
    

};
int main()
{
    Graph g;
    g.addedge(0,1);
    g.addedge(0,4);
    g.addedge(2,1);
    g.addedge(0,3);
    g.addedge(2,3);
    g.addedge(7,6);
    g.addedge(6,5);
    
    g.dfstraversal();
}