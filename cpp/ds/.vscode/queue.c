#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int val;
    struct Node *next;
};
struct Queue
{
    struct Node* head;
    int front;
    int back;
    int length;
};
void creat(struct Queue *q, int x)
{
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->val = x;
    temp->next = NULL;
    q->front = x;
    q->back = x;
    q->length++;
    q->head=temp;
    printf("Queue is created with element :%d\n",x);
}
void push(struct Queue *q, int x)
{
    if (q->length == 0)
    {
        struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
        temp->val=x;
        temp->next=NULL;
        q->head=temp;
        q->length++;
        q->front=x;
        q->back=x;
    }
    else
    {
        struct Node *temp,*p;
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->val = x;
        temp->next = NULL;
        p=q->head;
        while(p->next)
        {
            p=p->next;
        }
        p->next=temp;
        q->back=x;
        q->length++;
        
    }
    printf("The element pushed in the queue is %d\n",x);
}

void pop(struct Queue *q)
{
    if (q->length == 0)
    {
        printf("Queue is empty\n");
    }
    else if (q->length == 1)
    {
        free(q->head);
        q->front=q->back=-1;
        q->length=0;
    }
    else
    {
        struct Node*temp=q->head,*tail=NULL;
        while(temp->next)
        {
            tail=temp;
            temp=temp->next;
        }
        printf("The deleted element is %d\n",temp->val);
        tail->next=NULL;
        free(temp);

    }
}

int main()
{
    struct Queue *q;
    creat(q,10);
    push(q,11);
    pop(q);
    pop(q);

    return 0;
}