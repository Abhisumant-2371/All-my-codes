#include <bits/stdc++.h>
using namespace std;
class node
{

public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BST
{
public:
    bool search(node *root,int key);
    node *insert(node *root, int key);
    node *recur_insert(node *root, int key);
    void display(node *root);
    node *deleteinBST(node *root, int key);
    node *inordersucc(node *root);
    node* constructBST(int pre[], int *index, int key, int min, int max, int n);
    bool isbst(node *root,int min,int max);
};

int main()
{

    BST t;
    node*root=NULL;
    int n, a;
    cout << "Enter the no. of element to be inserted \n";
    cin >> a;
    cout << "now enter the elements\n";
    for (int i = 0; i < a; i++)
    {
        cin >> n;
        root = t.insert(root, n);
    }
    cout << "After inserting the element the inorder display would be\n";
    t.display(root);
    cout << "\nEnter the element to be deleted\n";
    cin >> n;
    root = t.deleteinBST(root, n);
    // Array for constructing a BST from preorder 
    int pre[]={7,5,4,6,8,9};
    cout<<t.isbst(root,INT_MIN,INT_MAX);
    t.display(root);
}
node *BST::insert(node *root, int key)
{

    node *temp = root;
    node *tail = NULL;
    int l_o = -1;
    while (1)
    {

        if (!temp)
        {
            node *t;
            t = new node(key);
            if (tail)
            {
                if (l_o == 0)
                    tail->left = t;
                else
                    tail->right = t;
                return root;
            }
            else
            {
                return t;
            }
        }
        if (temp->data == key)
            return root;
        else if (temp->data > key)
        {
            tail = temp;
            temp = temp->left;
            l_o = 0;
        }
        else
        {
            tail = temp;
            temp = temp->right;
            l_o = 1;
        }
    }
    return root;
}

node *BST::recur_insert(node *root, int key)
{
    if (root == NULL)
    {
        node *temp = new node(key);
        return temp;
    }
    if (root->data == key)
        return root;
    else if (root->data > key)
    {
        root->left = recur_insert(root->left, key);
    }
    else
    {
        root->right = recur_insert(root->right, key);
    }
    return root;
}

void BST::display(node *root)
{
    if (root == NULL)
        return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}
node *BST::inordersucc(node *root)
{
    node *p = root;
    while (p && p->left)
    {
        p = p->left;
    }
    return p;
}
node *BST::deleteinBST(node *root, int key)
{
    // most important
    if (root == NULL)
        return root;
    if (root->data > key)
        root->left = deleteinBST(root->left, key);
    else if (root->data < key)
        root->right = deleteinBST(root->right, key);
    else if (root->data == key)
    {
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = inordersucc(root->right);
        root->data = temp->data;
        root->right = deleteinBST(root->right, temp->data);
    }
    return root;
}
bool BST:: search(node *root, int key)
{
    if (root == NULL)
        return 0;
    else if (root->data == key)
        return 1;
    if (search(root->left, key))
        return true;
    if (search(root->right, key))
        return true;
    return false;
}
node* BST::constructBST(int pre[], int *index, int key, int min, int max, int n)
{
    if(*index>=n)return NULL;
    node *root=NULL;
    if(key>min && key<max)
    {
        int a=pre[*index];
        root=new node(a);
        *index=*index+1;
        if(*index<n)
        root->left=constructBST(pre,index,pre[*index],min,a,n);
        if(*index<n)
        root->right=constructBST(pre,index,pre[*index],a,max,n);
        
    }
    return root;
}
bool BST::isbst(node *root,int min,int max)
{
    if(root==NULL)return true;
    if(root->data<=min || root->data>=max)
        return false;
    if(!isbst(root->left,min,root->data))return false;
    if(!isbst(root->right,root->data,max))return false;
    return true;
}