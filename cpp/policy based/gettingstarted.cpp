#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<string,null_type,less<string>,rb_tree_tag,
            tree_order_statistics_node_update>
            PBDS;

int main()
{
    PBDS St;
    St.insert("vimal");
    St.insert("sumit");
    St.insert("abhinav");
    St.insert("abhi");
    St.insert("raj");
    // find by order gives the kth largest element 
    // starting from the smallest element with indexing 0

    for(int i=0;i<St.size();i++)
    {
        cout<<i+1<<"->"<<*St.find_by_order(i)<<"\n";

    }
    // order_by_key is used to find the no of element 
    // which are samlller than the given element 

    
    return 0;
}