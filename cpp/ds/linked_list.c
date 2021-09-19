#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *third = NULL;

void display(struct Node *);
void insert(struct Node *, int);
int count(struct Node *);
int sum(struct Node *h);
int max(struct Node *h);
struct Node *search(struct Node *, int);
void move_to_head(struct Node *, struct Node *);
void insert_index(struct Node *, int, int);
void sorted(struct Node *, int);
int delete (struct Node *, int);
bool is_sort(struct Node *);
void duplicate(struct Node *);
void reverse_ll(struct Node *);
void reverse_node(struct Node *, struct Node *);
void concatenate(struct Node *, struct Node *);
void merge_ll(struct Node *, struct Node *);
bool check_circular(struct Node *);
void make_circular(struct Node *, int);
void delete_circular(struct Node *);
void disp_circular(struct Node *);
void insert_circular(struct Node *,int,int);
void appendknodes(struct Node * head,int k);
int main()
{

    insert_index(first, 0, 1);
    insert_index(first, 1, 2);
    insert_index(first, 2, 10);
    insert_index(first, 3, 12);
    insert_index(first, 4, 12);
    insert_index(first, 5, 14);
    insert_index(first, 6, 16);
    insert_index(first, 7, 17);

    display(first);
    printf("After reversing the linked list\n");
    reverse_ll(first);
    display(first);

    return 0;
}
void insert(struct Node *h, int x)
{
    if (h)
    {
        while (h->next != NULL)
        {
            h = h->next;
        }
        struct Node *a1, *p1;
        p1 = h;
        a1 = (struct Node *)malloc(sizeof(struct Node));
        a1->data = x;
        a1->next = NULL;
        p1->next = a1;
        p1 = a1;
    }
    else
    {
        struct Node *a = (struct Node *)malloc(sizeof(struct Node));
        a->data = x;
        third = a;
        a->next = NULL;
    }
}

void display(struct Node *a)
{

    while (a)
    {
        printf("%d ", a->data);
        a = a->next;
    }
    printf("\n");
}

int count(struct Node *h)
{
    int c = 0;
    while (h)
    {
        c++;
        h = h->next;
    }
    return c;
}
int sum(struct Node *h)
{
    int s = 0;
    while (h)
    {
        s += h->data;
        h = h->next;
    }
    return s;
}

int max(struct Node *h)
{
    int m = h->data;
    h = h->next;
    while (h)
    {
        if ((h->data) > m)
        {
            m = h->data;
        }
        h = h->next;
    }
    return m;
}

struct Node *search(struct Node *h, int key)
{
    while (h)
    {
        if (h->data == key)
            return h;
        h = h->next;
    }
    return NULL;
}

void move_to_head(struct Node *h, struct Node *t)
{
    int temp = h->data;
    h->data = t->data;
    t->data = temp;
}

void insert_index(struct Node *h, int index, int key)
{
    if (index == 0)
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->next = first;
        first = p;
    }
    else if (index > 0 && index < count(first) + 1)
    {
        struct Node *p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;

        struct Node *p1;
        p1 = h;

        for (int i = 0; i < index; i++)
        {
            p1 = h;
            h = h->next;
        }
        p1->next = p;
        p->next = h;
    }
    else
    {
        printf("invalid index\n");
    }
}
void sorted(struct Node *h, int key)
{
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = key;
    new->next = NULL;
    struct Node *p1 = NULL;
    if (first == NULL)
    {
        first = new;
    }
    while (h)
    {
        if (h->data < key)
        {
            p1 = h;
            if (h->next == NULL)
            {
                p1->next = new;
                new->next = NULL;
                break;
            }
            h = h->next;
        }
        else
        {
            if (p1 == NULL)
            {
                first = new;
                new->next = h;
                break;
            }
            else
            {
                p1->next = new;
                new->next = h;
                break;
            }
        }
    }
}
int delete (struct Node *h, int index)
{
    if (index == 1)
    {
        first = first->next;
        int x = h->data;
        free(h);
        return x;
    }
    else
    {

        if (index > 1 && index <= count(first))
        {
            int c = 1, x;
            struct Node *p = NULL;
            while (h)
            {

                if (c == index)
                {
                    p->next = h->next;
                    h->next = NULL;
                    x = h->data;
                    free(h);
                    break;
                }
                p = h;
                h = h->next;
                c++;
            }
            return x;
        }
        else
        {
            printf("invalid index");
            return -1;
        }
    }
}

bool is_sort(struct Node *h)
{
    if (h)
    {
        struct Node *p = NULL;
        int a = h->data;
        while (h && a <= h->data)
        {
            a = h->data;
            h = h->next;
        }
        if (h == NULL)
            return true;
        else
            return false;
    }
    else
        return true;
}

void duplicate(struct Node *h)
{
    if (count(first) > 1)
    {
        struct Node *p;
        p = h;
        h = h->next;
        while (h)
        {
            if (p->data == h->data)
            {
                p->next = h->next;
                free(h);
                h = p->next;
            }
            else
            {
                p = h;
                h = h->next;
            }
        }
    }
}
void reverse_ll(struct Node *h)
{
    struct Node *p = NULL, *q = NULL;
    while (h)
    {
        q = p;
        p = h;
        h = h->next;
        p->next = q;
    }
    first = p;
}
void reverse_node(struct Node *p, struct Node *q)
{
    if (p != NULL)
    {
        reverse_node(p->next, p);
        p->next = q;
    }
    else
        first = q;
}
void concatenate(struct Node *p, struct Node *q)
{
    while (p->next)
    {
        p = p->next;
    }
    p->next = q;
}
void merge_ll(struct Node *a, struct Node *b)
{
    while (a && b)
    {
        if (a->data > b->data)
        {
            insert(third, b->data);
            b = b->next;
        }
        else
        {
            insert(third, a->data);
            a = a->next;
        }
    }
    while (b)
    {
        insert(third, b->data);
        b = b->next;
    }
    while (a)
    {
        insert(third, a->data);
        a = a->next;
    }
}
bool check_circular(struct Node *head)
{
    struct Node *fast = head;
    struct Node *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}
void make_circular(struct Node *head, int pos)
{
    if (!head)
    {
        printf("cann't be circular");
        return;
    }
    struct Node *temp = head;
    int c = 1;
    while (head->next != NULL)
    {

        if (c == pos)
        { 
            temp = head;
        }
        head = head->next;
        c++;
    }
    head->next = temp;
}
void delete_circular(struct Node *head)
{
    struct Node *fast, *slow;
    fast = head;
    slow = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
        {
            break;
        }
    }
    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}
void disp_circular(struct Node *head)
{
    static int c = 0;
    if (c > 0 && head == first)
    {
        c = 0;
        return;
    }
    else
    {
        printf("%d ", head->data);
        c++;
        disp_circular(head->next);
    }
}
void insert_circular(struct Node *head,int index,int key)
{   struct Node * temp=head;
    if(index==1)
    {
        while(temp->next!=head && temp)
            temp=temp->next;
        struct Node * a=(struct Node *)malloc(sizeof(struct Node));
        a->data=key;
        a->next=head;
        temp->next=a;
        first=a;

    }
    else{
        int c=2;
        struct Node * a=(struct Node *)malloc(sizeof(struct Node));
        a->data=key;
        while(index!=c)
        {
            c++;
            temp=temp->next;

        }
        a->next=temp->next;
        temp->next=a;
        
    }
}
void appendknodes(struct Node * head,int k)
{
      struct Node * temp=head;
      int c=0;
      while(temp)
      {
          c++;
          temp=temp->next;

      }
      temp=head;
      c=c-k;
      int i=1;
      while(c!=i)
      {
          temp=temp->next;
          i++;
      }
      struct Node *a=temp->next;
      temp->next=NULL;
      struct Node *b=a;
      while(a->next)
      {
          a=a->next;
      }
      a->next=head;
      first=b;
}