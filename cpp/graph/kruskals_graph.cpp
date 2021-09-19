#include <bits/stdc++.h>
using namespace std;
//Minimun spanning tree:Subset of edges of connected,edge weighted undirected graph
// with all vertices connected without any cycle using minimum no of edges weight possible
//---------------------------------------------------------------------------------------
//Approach to solve this problem:=
//
//solving this problem uses dsu approach what we need to 
// do is to sort all edges according to there weight and 
// then in ascending order keeps on adding the edges between the vertices 
// as we done it in the dsu
// then we need to ignore those edges which are making a cycle
// that's how we will obtain the final MST using kruskal's algorithm
struct dsu
{
    int v;
    vector<int> parent;
    list<pair<int, int>> l;
    dsu(int v)
    {

        for (int i = 0; i < v; i++)
            parent.push_back(-1);
        this->v = v;
    }
    int find(int a)
    {
        if (parent[a] == -1)
            return a;
        parent[a] = find(parent[a]);
        return parent[a];
    }
    bool union_set(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (s1 != s2)
        {
            parent[s2] = s1;
            return true;
        }
        return false;
    }
};
int main()
{
    vector<vector<int>> g;
    int e, v, w, x, y;
    cin >> e;
    int max = 0;
    for (int i = 0; i < e; i++)
    {
        cin >> x >> y >> w;
        int a;
        a = (x > y) ? x : y;
        max = max > a ? max : a;
        g.push_back({w, x - 1, y - 1});
    }
    cout<<max<<"\n";
    dsu d(max);
    sort(g.begin(), g.end());

    int ans = 0;
    for (int i = 0; i < e; i++)
    {
        if (d.union_set(g[i][1], g[i][2]))
        {
            ans += g[i][0];
            cout<<"wt:"<<g[i][0]<<"=>"<<g[i][1]<<" "<<g[i][2]<<" \n";
        }
    }
    cout << ans;
}