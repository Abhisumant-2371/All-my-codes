//constructing a generic tree
#include <iostream >
#include <vector>
#include <stack>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    vector<Node *> v;
};
class Gentree
{
    public:
    Node *constructgentree()
    {
        int a;
        stack<Node *> s;
        
        cin >> a;
        Node *root = new Node;
        root->data = a;
        s.push(root);
        while (!s.empty())
        {
            
            cin >> a;
            Node *temp = new Node;
            temp->data = a;
            if (a == -1)
            {
                s.pop();
                continue;
            }
            else
            {
                s.top()->v.push_back(temp);
                s.push(temp);
            }
        }
        return root;
    }
    void display(Node *root)
    {
        if (root->v.size() == 0)
        {
            cout << root->data << "-> ";
            return;
        }
        // Placing the statement of the root->data below the 
        //for loop here make it preorder display
        for (int i = 0; i < (root->v.size()); i++)
        {
            display(root->v[i]);
        }
        cout << root->data << "-> ";
    }
    int size_of_tree(Node* root )
    {
        if(root->v.size()==0)return 1;
        int sum =0;
        for(int i=0;i<(root->v.size());i++)
        {
            sum+=size_of_tree(root->v[i]);
        }
        return sum+1;
    }
    int max(Node* root)
    {
        if(root->v.size()==0)
        {
            return root->data;
        }
        int m=0;
        for(int i=0;i<root->v.size();i++)
        {
            int a;
            a=max(root->v[i]);
            if(m<a)m=a;
        }
        return m;
    }
    int height(Node*root)
    {
        if(root->v.size()==0)return 0;
        int m=0;
        for(int i=0;i<root->v.size();i++)
        {
            int a;
            a=height(root->v[i]);
            if(m<a)m=a;
        }
        return m+1;
    }
    void levelorder(Node* root)
    {
        queue <Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {
            if(q.front())
            {
                Node* temp=q.front();
                cout<<temp->data<<" ";
                q.pop();
                for(int i=0;i<temp->v.size();i++)
                {
                    q.push(root->v[i]);
                }
            }
            else
            {
                q.pop();
                if(q.empty()==true)
                {
                    break;
                }
                else
                    q.push(NULL);
            }

        }
    }
};
int main()
{
    Gentree t;
    Node *root = t.constructgentree();
    t.display(root);
    cout<<endl;
    cout<<"Total no. of nodes in this generic tree are "<<t.size_of_tree(root);
    cout<<"\nThe maximum element of the generic tree is "<<t.max(root);
    cout<<"\nThe height of the tree is "<<t.height(root);
    cout<<"\n";
    cout<<"lvl order traversal ->";
    t.levelorder(root);
    return 0;
}