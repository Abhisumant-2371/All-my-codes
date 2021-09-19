#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
} * a;
class stack
{
    Node *head;
    int top;

public:
    stack()
    {
        head = NULL;
        top = -1;
    }

    Node *gethead()
    {
        return head;
    }

    void push(int);
    void elements();
    void pop();
    bool isEmpty();
    void display();
    int gettop()
    {
        return top;
    }
};
int main()
{
    stack st;
    while (1)
    {
        int choice;
        cout << "1. Creating .....\n";
        cout << "2. Pushing.......\n";
        cout << "3. Poping.......\n";
        cout << "4. Display.......\n";
        cout << "5. Is Stack Empty.......\n";
        cout << "6. Elements in stack.......\n";
        cout << "7. Exit.......\n";
        cout << "Enter your choice\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "....Stack Is Created....\n";
            break;
        case 2:
            cout << "Enter the no. to entered in stack\n";
            int x;
            cin >> x;
            st.push(x);
            break;

        case 3:
            if(st.gettop()!=-1)
            cout << "Element is poped.....\n";
            st.pop();
            break;

        case 4:
            a = st.gethead();
            st.display();

            break;
        case 5:
            st.isEmpty() ? cout << "true\n" : cout << "False\n";
            break;
        case 6:
            st.elements();
            break;
        case 7:
            cout<<"Program Ended Successfully\n";
            exit(1);
        default:
            cout << "Wrong choice entered";
            break;
        }
    }

    return 0;
}
void stack::elements()
{
    cout << "the elements in stack are\n"
         << top + 1 << endl;
}
bool stack ::isEmpty()
{
    return top == -1;
}
void stack::push(int x)
{
    Node *a = new Node;
    a->data = x;
    a->next = head;
    head = a;
    top++;
}
void stack ::pop()
{
    if (top == -1)
    {
        cout << "Stack Under flow\n";
        return;
    }
    Node *a = head;
    head = head->next;
    a->next = nullptr;
    delete a;
    top--;
}
void stack::display()
{
    if (!a)
    {
        cout << "no elements\n";
        return;
    }
    while (a)
    {
        cout << a->data << " \n";
        a = a->next;
    }
}
