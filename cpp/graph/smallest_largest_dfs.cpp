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
    void multisolver(int src,int dest,string result,int wtsf,vector<bool>visi)
    {
        if(src==dest)
        {
            if(wtsf>largestwt)
            {
                largestpath=result+to_string(src);
                largestwt=wtsf;
            }
            if(wtsf<smallestwt)
            {
                smallestpath=result+to_string(src);
                smallestwt=wtsf;
            }
            return ;
        }
        visi[src]=true;
        for(auto a:l[src])
        {
            if(!visi[a.first])
            multisolver(a.first,dest,result+to_string(src),wtsf+a.second,visi);
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
    int src,dest;
    string temp="";
    cin>>src>>dest;
    vector<bool>visi(vertex,false);
    g.multisolver(src,dest,temp,0,visi);
    cout<<"the largest path was "<<largestpath<<" with distance "<<largestwt<<"\n";
    cout<<"the smallest path was "<<smallestpath<<" with distance"<<smallestwt<<"\n";

}
// Input for this code is 
// 7 8
// 0 1 10
// 1 2 10 
// 2 3 10
// 3 0 40
// 3 4 2
// 4 5 3 
// 5 6 3
// 4 6 8
// 0 6