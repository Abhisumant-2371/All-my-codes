#include <bits/stdc++.h>
using namespace std;
class Graph
{
    unordered_map<int,list<int >>l;
    public:
    void addedge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void printgraph()
    {
        for(auto a:l)
        {
            cout<<a.first<<"-:";
            for(auto x:a.second)
            {
                cout<<x<<",";
            }
            cout<<endl;
        }
    }
    void bfs(int startnode)
    {    queue <int > q;
        unordered_map<int,int> visited;
        q.push(startnode);
        visited[startnode]=1;
        while(!q.empty())
        {
            int x=q.front();
            cout<<x<<" ";
            list<int >m=l[x];
            q.pop();
            for(auto n:m)
            {
                if(!visited[n])
                    {
                        q.push(n);
                        visited[n]=1;
                    }
            }
        }
    }
    void shortest_path_using_bfs(int src)
    {
        queue <int > q;
        unordered_map <int ,int > dist;
        for (auto a:l)
        {
            dist[a.first]=INT_MAX;
        }
        q.push(src);
        dist[src]=0;
        while(!q.empty())
        {
            int n=q.front();
            q.pop();
            for(auto listele:l[n])
            {
                if(dist[listele]==INT_MAX)
                {
                    dist[listele]=dist[n]+1;
                    q.push(listele);
                }
            }
        }
        for(auto a:l)
        {
            cout<<"Distance of "<<a.first<<" from the vertex "<<src<<" ="<<dist[a.first]<<"\n";
        }

    }
};

int main()
{
    Graph g;
    g.addedge(1,2);
    g.addedge(1,0);
    g.addedge(3,0);
    g.addedge(3,2);
    g.addedge(3,4);
    g.addedge(4,5);
    g.shortest_path_using_bfs(0);
}