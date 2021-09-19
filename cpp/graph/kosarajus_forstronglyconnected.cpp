#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iterator>
using namespace std;
class Graph
{
    int v;
    list<int> *l;
    list<int>*rev;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
        rev=new list<int>[v];
    }
    void edge(int x, int y)
    {
        l[x].push_back(y);
        rev[y].push_back(x);
    }
    void dfs(int src, vector<bool> &visi, vector<int> &order)
    {
        // if(visi[src]==true)return;
        visi[src] = true;
        for (auto nbr : l[src])
        {
            if (!visi[nbr])
            {
                dfs(nbr, visi, order);
            }
        }
        order.push_back(src);
    }
    void reverse_graph()
    {
        for (int i = 0; i < v; i++)
        {
            while(l[i].size()>0)
            {
                int a=l[i].front();
                l[i].pop_front();
                l[a].push_back(i);
            }
        }
    }
    void comp_helper(int src, vector<bool> &visi, vector<int> &comp)
    {
        if (visi[src])
            return;
        visi[src] = true;
        comp.push_back(src);
        for (auto nbr : rev[src])
        {
            if (!visi[nbr])
                comp_helper(nbr, visi, comp);
        }
    }
    void print()
    {
        for(int i=0;i<v;i++)
        {
            for(auto a:l[i])
                cout<<a<<",";
            cout<<endl;
        }
    }
};
int main()
{
    int v, e;
    cin >> v >> e;
    Graph g(v);
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        g.edge(x, y);
    }
    vector<bool> visi(v, false);
    vector<int> order;
    for (int i = 0; i < v; i++)
    {
        if (visi[i] != true)
        {
            g.dfs(i, visi, order);
        }
    }

    for(int i=0;i<v;i++)
        visi[i]=false;

    vector<vector<int>> result;
    int count=0;
    cout<<"order of the graph is"<<" \n";
    for(auto a:order)
    cout<<a<<" ";
    cout<<endl;

    for(int i=order.size()-1;i>=0;i--)
    {
        if(visi[order[i]]!=true)
        {
            vector<int>comp;
            g.comp_helper(order[i],visi,comp);
            result.push_back(comp);
            count++;

        }
    }
    cout<<count<<endl;
    for(int i=0;i<result.size();i++)
    {
        cout<<"SCC:"<<i+1<<"-->";
        for(auto a:result[i])
        {
            cout<<a<<", ";
        }
        cout<<endl;
    }
}