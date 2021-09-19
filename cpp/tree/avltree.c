#include <stdio.h>
#include <stdlib.h>
struct Node
{
   struct Node* left;
   struct Node* right;
   int data;
   int height;
}*head=NULL;
int height_tree(struct Node *root)
{
    if(root==NULL)return 0;
    int x=root && root->left?root->left->height:0;
    int y=root && root->right?root->left->height:0;

    return x>y?x+1:y+1;

}
int balance_fac(struct Node* root)
{
    if(!root)return 0;
    int lh,rh;
    lh=root->left?root->left->height:0;
    rh=root->right?root->right->height:0;
    return (lh-rh);
}
// recursive function for the insertion of node in binary search tree
struct Node *recur_insert(struct Node* root,int key)
{
    if(root==NULL)
    {
        struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
        temp->data=key;
        temp->left=NULL;
        temp->right=NULL;
        temp->height=0;
        return temp;
    }
    if(root->data ==key)
        return root;
    else if(root->data > key)
    {
        root->left=recur_insert(root->left,key);
    }
    else
    {
        root->right=recur_insert(root->right,key);
    }
    root->height=height_tree(root);
    if(balance_fac(root)==2 && balance_fac(root->left)==1)
        LLRotation(root);
    else if(balance_fac(root)==2 && balance_fac(root->left)==-1)
        LRRotation(root);
    else if(balance_fac(root)==-2 && balance_fac(root->right)==-1)
        return RRRotation(root);
    else if(balance_fac(root)==-2 && balance_fac(root->right==1))
        return RLRotation(root);


    return root;
}

int main()
{

    return 0;
}