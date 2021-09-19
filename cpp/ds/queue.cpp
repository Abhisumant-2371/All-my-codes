#include <iostream>
using namespace std;
class queue
{
    int *arr;
    int length;
    int front;
    int back;

public:
    queue()
    {
        arr = new int[5];
        front = -1;
        back = -1;
        length = 0;
    }
    void enqueue(int x)
    {
        if (length == 0)
        {
            arr[length] = x;
            front = arr[length];
            back = front;
            length++;
        }
        else
        {
            if (length >= 5)
            {
                cout << "queue is full " << endl;
                return;
            }
            arr[length] = x;
            back = x;
            length++;
        }
    }
    void dequeue()
    {
        if (length == 1)
        {
            length--;
            front = back = -1;
            return;
        }
        else if (length == 0)
        {
            cout << "queue is already empty\n";
        }
        else
        {
            length--;
            back = arr[length - 1];
        }
    }
    void display()
    {
        for (int i = 0; i < length; i++)
            cout << i + 1 << ": " << arr[i] << endl;
    }
    void elements()
    {
        cout << "The elements in the queue are " << length << endl;
    }
};

int main()
{
    queue a;
    a.enqueue(23);
    a.enqueue(34);
    a.enqueue(88);
    a.enqueue(23);
    a.enqueue(34);
    a.enqueue(88);

    a.display();
    a.elements();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
    a.dequeue();
}