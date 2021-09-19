// Prim's algorithm
// Steps required to solve or get the spanning tree
//1.select any vertex to start the algo.\
//2.We have to take a min heap  for which we use priority queue
//3.This priority queue will contain the active egde (which can be the part of the spanning tree)
//4.from the edge mark that vertex visited and add all the active edge in the priority queue (only those edge whose vertex aren't visited yet)
//5.After adding all the active edges now take out the minimum weight edge from the priority queue and then vertex of that edge if not visited will become the MST vertex
//6.But in some case for an MST vertex we didn't find any edge the we will just simply leave it and move to remove the next edge
#include <bits/stdc++.h>
using namespace std;
class Compare
{
public:
    bool operator()(pair<int, int> x, pair<int, int> y)
    {
        return x.first >= y.first;
    }
};
class Prims
{
    vector<pair<int, int>> *g;

public:
    Prims(int v)
    {
        g = new vector<pair<int, int>>[v];
    }
    void addedge(int &x, int &y, int &w)
    {
        g[x].push_back({y, w});
        g[y].push_back({x, w});
    }
    bool cmp(pair<int, int> x, pair<int, int> y)
    {
        if (x.first >= y.first)
            return (x.first >= y.first);
        else
            return (y.first > x.first);
    }
    int MST(vector<int> &visi, int src)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> p;
        int sum = 0;
        visi[src] = true;
        for (auto npair : g[src])
        {
            if (!visi[npair.first])
            {
                p.push({npair.second, npair.first});
            }
        }
        while (!p.empty())
        {
            pair<int, int> sam = p.top();
            p.pop();
            if (visi[sam.second] == true)
            {
                continue;
            }
            else
            {
                sum += sam.first;
                visi[sam.second] = true;
                for (auto x : g[sam.second])
                {
                    if (!visi[x.first])
                    {
                        p.push({x.second,x.first});
                    }
                }
            }
        }
        return sum;
    }
    int result(int v)
    {
        vector<int> visi(v, false);
        return MST(visi,0);
    }
};
int main()
{
    int v, e;
    cin >> v >> e;
    Prims g(v);
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.addedge(x, y, w);
    }
    cout<<"The cost of the spanning tree is\n";
    cout<<g.result(v);
}