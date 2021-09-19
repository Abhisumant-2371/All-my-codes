// Bellman ford algorithm
// key points :-
// Single source shortest path algorithm
// In this we can use the negative edges also
// Time complexity of this (VE)
// Can be applied on directed and undirected graph
//

// This algo fails when there is cycle of -ve weight is present in the graph
// undirected graph with the negative edge cannot be used as it will automatically form a cycle
// worst path length from source to destination will always contain n-1 edges or n vertices with no cycle becoz positive cycle will unnecessarily increase the path length and the negative cycle will trap us in the infinite code.

// FOR BOTH BELLMAN FORD AND DETECTING THE NEGATIVE CYCLE IN THE GRAPH
#include <bits/stdc++.h>
using namespace std;
void bellman_ford(int v, vector<vector<int>> edges)
{
    vector<int> dist(v, INT_MAX);
    dist[0] = 0;
    int flag = 0;
    bool contain_negative = false;
    for (int i = 0; i < v; i++)
    {
        // int i=0;
        flag = 0;
        for (auto a : edges)
        {
            int from, to, w;
            from = a[0];
            to = a[1];
            w = a[2];
            if (dist[to] > (dist[from] + w))
            {
                dist[to] = dist[from] + w;
                flag = 1;
            }
        }
        if (flag == 0 && (v - 1) > i)
            break;
        else if (flag == 1 && i >= v - 1)
        {
            contain_negative = true;
            break;
        }
        // i++;
    }
    for (int i = 0; i < v; i++)
    {
        cout << i << "==>" << dist[i] << endl;
    }
    if (contain_negative)
        cout << "yes negative cycle detected";
    else
        cout << " no negative cycle";
}
int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> edges;
    for (int i = 0; i < e; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        edges.push_back({x, y, w});
    }
    bellman_ford(v, edges);
}