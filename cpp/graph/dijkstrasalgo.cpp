//Dijkstra's Algorithm

// for the weighted graph
// No negative edges weight
// Edges can be bidirectional and single directional
// vector<pair<int,int>>g[vertex];that's what we use to store the weight of the edges also
//
// Steps for the algorithm:-
// 1.Maintain a distance vector and the mark src at 0 dist and other at infinity distance
// 2.firtly take the src node and update their distance according to their edge weight
// 3.Insert all the neighbour of the src into the priority queue
// 4.Also a visited array will be required
// 5.Only those vertex will be marked visited which will be remover or poped from the pqueue
// 6.Then remove the vertex containing there distance and move to their neighbour if the new distance is less than the old one then update but put all the vertex neighbour in the pqueue



// Time Complexity (vlogE)

#include <bits/stdc++.h>
using namespace std;
void dijkstra(int v, vector<int> &visi, vector<pair<int, int>> g[], int src)
{
    vector<int> dist(v, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;
    for(auto a:g[src])
    {
        dist[a.second]=a.first+dist[src];
        p.push(a);
    }
    visi[src]=true;
    while(!p.empty())
    {
        pair<int,int>ele=p.top();
        p.pop();
        visi[ele.second]=true;
        for(auto x:g[ele.second])
        {
            if(visi[x.second]==false)
            {
                if(dist[x.second]>(dist[ele.second]+x.first))
                {
                    dist[x.second]=dist[ele.second]+x.first;
                }
                p.push({dist[x.second],x.second});
            }
        }
    }
    for(int i=0;i<v;i++)
    {
        cout<<"Distance of "<<i<<" from "<<src<<" is "<<dist[i]<<endl;
    }
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> g[v];
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> w >> y;
        g[x].push_back({w, y});
    }
    vector<int>visi(v,false);

    dijkstra(v, visi, g, 0);
}