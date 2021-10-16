#include <bits/stdc++.h>
using namespace std;
void makegraph(vector<int>*g)
{
    int edge;
    cin>>edge;
    for(int i=0;i<edge;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}
vector<int> dfs(vector<int>*g,int src,bool *visi,vector<int>&ele )
{
    if(visi[src]!=false){

        return ele;
    }
    ele.push_back(src);
    visi[src]=true;
    for(auto nbr:g[src]){
        ele=dfs(g,nbr,visi,ele);
    }
    return ele;
}
void findcomp(vector<int>*g,int src,int n)
{
    bool visi[n];
    for(int i=0;i<n;i++)
    visi[i]=false;
    for(int i=0;i<n;i++)
    {
        if(visi[i]!=true){
            vector<int>result;
            result=dfs(g,i,visi,result);
            for(auto a:result)cout<<a<<" ,";
            cout<<endl;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    vector<int>g[n];
    makegraph(g);
    findcomp(g,0,n);
    
}