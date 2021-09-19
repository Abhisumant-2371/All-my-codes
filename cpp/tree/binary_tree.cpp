#include <bits/stdc++.h>
using namespace std;
int n;
class Treenode
{
public:
	int data;
	Treenode *lchild;
	Treenode *rchild;
};

class Tree
{
public:
	Treenode *makenode(int x)
	{
		Treenode *t;
		t = new Treenode();
		t->data = x;
		t->lchild = NULL;
		t->rchild = NULL;
		return t;
	}
	Treenode *creat()
	{
		queue<Treenode *> st;
		Treenode *temp, *p, *root;
		int a;
		cout << "Enter the root node value " << endl;
		cin >> a;
		if (a != -1)
		{
			root = makenode(a);
			p = root;
			st.push(p);
			temp = st.front();
		}
		else
		{
			return NULL;
		}
		do
		{
			st.pop();
			cout << "Enter the lchild value of" << temp->data << endl;
			cin >> a;
			if (a != -1)
			{
				p = makenode(a);
				temp->lchild = p;
				st.push(p);
			}
			else
			{
				temp->lchild = NULL;
			}
			cout << "Enter the rchild value of" << temp->data << endl;
			cin >> a;
			if (a != -1)
			{
				p = makenode(a);
				temp->rchild = p;
				st.push(p);
			}
			else
			{
				temp->rchild = NULL;
			}
			temp = st.front();

		} while (!st.empty());

		return root;
	}
	void display(Treenode *p)
	{
		if (p == NULL)
			return;
		display(p->lchild);
		cout << p->data << " ";

		display(p->rchild);
	}

	void iterative_order(Treenode *p)
	{
		stack<Treenode *> st;
		while (!(p == NULL && st.empty()))
		{
			if (p != NULL)
			{
				st.push(p);
				p = p->lchild;
			}
			else
			{
				p = st.top();
				cout << p->data;
				st.pop();
				p = p->rchild;
			}
		}
	}
	void lvldisplay(Treenode *p)
	{
		queue<Treenode *> q;
		q.push(p);
		do
		{
			q.pop();
			cout << p->data << " ";
			if (p->lchild != NULL)
			{
				q.push(p->lchild);
			}
			if (p->rchild != NULL)
			{
				q.push(p->rchild);
			}
			p = q.front();

		} while (!q.empty());
	}

	void special_lvl_order(Treenode *p)
	{
		if (p == NULL)
			return;
		queue<Treenode *> q;
		q.push(p);
		q.push(NULL);
		while (!q.empty())
		{
			Treenode *node = q.front();
			q.pop();
			if (node != NULL)
			{
				cout << node->data << " ";
				if (node->lchild)
					q.push(node->lchild);
				if (node->rchild)
					q.push(node->rchild);
			}
			else if (!q.empty())
			{
				q.push(NULL);
			}
		}
	}
	int find(int order[], int n, int x)
	{
		int i;
		for (i = 0; i < n; i++)
		{
			if (x == order[i])
				break;
		}
		return i;
	}
	Treenode *build(int pre[], int inorder[], int s, int e)
	{

		static int i = n - 1;
		if (s > e)
			return NULL;
		int temp = pre[i];
		cout << temp;
		int index = find(inorder, n, temp);
		i--;
		Treenode *root = makenode(temp);
		if (s == e)
		{

			return root;
		}
		root->rchild = build(pre, inorder, index + 1, e);
		root->lchild = build(pre, inorder, s, index - 1);

		return root;
	}
	int height(Treenode *p)
	{
		if (p->lchild == NULL && p->rchild == NULL)
			return 1;
		int x, y;
		x = height(p->lchild) + 1;
		y = height(p->rchild) + 1;
		return x > y ? x : y;
	}
	int sum(Treenode *p, int k)
	{
		queue<Treenode *> q;
		q.push(p);
		int lvl = 0;
		int sum = 0;
		q.push(NULL);
		while (!q.empty())
		{
			Treenode *node = q.front();
			q.pop();
			if (node != NULL)
			{
				if (lvl == k)
				{
					sum += node->data;
				}
				if (node->lchild)
					q.push(node->lchild);
				if (node->rchild)
					q.push(node->rchild);
			}
			else if (!q.empty())
			{
				q.push(NULL);
				lvl++;
			}
		}
		return sum;
	}
	bool isbst(Treenode *root, int min, int max)
	{
		if (root == NULL)
			return true;
		if (root->data <= min || root->data >= max)
			return false;
		if (!isbst(root->lchild, min, root->data))
			return false;
		if (!isbst(root->rchild, root->data, max))
			return false;
		return true;
	}
	// GENERATING THE TREE FROM THE TRAVERSALS
};
int main()
{
	Tree t;
	Treenode *root = t.creat();
	cout<<"the height of the tree is: "<<t.height(root)<<endl;
	cout<<t.isbst(root,INT_MIN,INT_MAX);
}
