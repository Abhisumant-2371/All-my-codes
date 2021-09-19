#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *ar;
    int length;
    int top;
};
void push(struct stack *, int);
void display(struct stack );
void pop(struct stack *);
int main()
{   int i=0;
    while (1)
    {   
        printf("enter your choice ?\n");
        printf("1.creat\n");
        printf("2.push\n");
        printf("3.pop\n");
        printf("4.display\n");
        printf("5.exit\n");

        int x, y;
        struct stack s;
        scanf("%d", &x);
        switch (x)
        {
        case 1:

            s.length = 0;
            s.top = -1;
            printf("created \n");
            break;
        case 2:

            printf("enter the element to be pushed \n");
            scanf("%d", &y);
            i++;
            if (i == 1)
            {
                s.ar = (int *)malloc(sizeof(int));
                s.ar[i-1]=y;
                s.length++;
                s.top++;
                
                printf("%d",s.ar[i-1]);
            }
            else
            {   
                realloc(s.ar, i * sizeof(int));
                push(&s, y);
                printf("%d",s.ar[i-2]);
            }
            break;
        case 3:
            pop(&s);
            i--;
           
            
            break;
        case 4:
            display(s);
            
            break;
        case 5:
            free(s.ar);
            exit(0);
        default:
            printf("invalid input\n");
            break;
        }
    }

    return 0;
}

void push(struct stack *a, int x)
{
    if (a->length < 9)
    {
        a->ar[a->length] = x;
        a->length++;
        a->top++;
    }
    else
        printf("stack over flow \n");
}
void pop(struct stack *a)
{
    if (a->top != -1)
    {
        printf("Deleted element is :- %d\n",a->top);
        a->top--;
        a->length--;
    }
    else
        printf("stack is empty\n");
}
void display(struct stack s)
{ printf("the elements are\n");
    for (int i = 0; i < s.length; i++)
        printf("%d. %d\n",i+1, s.ar[i]);
}
