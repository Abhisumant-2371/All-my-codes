#include <bits/stdc++.h>
using namespace std;
int smallestwt=INT_MAX;
string smallestpath="";
string largestpath="";
int largestwt=INT_MIN;
class Graph
{
    list <pair<int,int>> *l;
    int v;
public:
    Graph(int v)
    {
        this->v=v;
        l=new list<pair<int,int>>[v];
    }
    void addedge(int x,int y,int wt)
    {
        l[x].push_back({y,wt});
        l[y].push_back({x,wt});
    }
    void dfs(int src,vector<bool>&visi,vector<int>&comp)
    {
        visi[src]=true;
        comp.push_back(src);
        for(auto nbr:l[src])
        {
            if(!visi[nbr.first])
                dfs(nbr.first,visi,comp);
        }

    }
    void getconnected_comp()
    {
        vector<vector<int>> result;
        vector<bool>visi(v,false);
        for(int i=0;i<v;i++)
        {
            if(visi[i]==false)
                {

                    vector<int>comp;
                    dfs(i,visi,comp);
                    result.push_back(comp);
                }
        }
        for(int i=0;i<result.size();i++)
        {
            cout<<"Component "<<i+1<<" :";
            for(int j=0;j<result[i].size();j++)
                cout<<result[i][j]<<", ";
            cout<<endl;
        }
    }

};
int main()
{
    int vertex,edge;
    cin>>vertex>>edge;
    Graph g(vertex);
    for(int i=0;i<edge;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        g.addedge(x,y,z);
    }
    g.getconnected_comp();

}
// Input for the code
// 7 5
// 0 1 10
// 2 3 10
// 4 5 10 
// 5 6 10
// 4 6 10
