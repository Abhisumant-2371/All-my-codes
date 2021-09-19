#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int a[10];
    int size;

    int length;
};
void Display(struct Array);
void append(struct Array *, int);
int delete (struct Array *, int);
int binary_search(struct Array, int);
void left_rotation(struct Array *);
void insert_sorted(struct Array *, int);
void one_side(struct Array *);


void Display(struct Array a1)
{
    for (int i = 0; i < a1.length; i++)
    {
        printf("element %d:", i + 1);
        printf(" %d \n", a1.a[i]);
    }
}
void append(struct Array *ar, int x)
{
    if (ar->length < ar->size)
    {
        ar->a[ar->length] = x;
        ar->length++;
    }
    else
        printf("array is full");
}
int binary_search(struct Array ar, int key)
{
    int l = 0, h = ar.length - 1;
    int mid = (l + h) / 2;
    while (l <= h)
    {
        if (ar.a[mid] == key)
        {
            return mid;
        }
        else
        {
            if (ar.a[mid] < key)
            {
                l = mid + 1;
                mid = (l + h) / 2;
            }
            else
            {
                h = mid - 1;
                mid = (l + h) / 2;
            }
        }
    }
    return -1;
}
int delete (struct Array *ar, int index)
{
    int num;
    num = ar->a[index];
    for (int i = index; i < (ar->length) - 1; i++)
    {
        ar->a[i] = ar->a[i + 1];
    }
    (ar->length)--;
    return num;
}
void left_rotation(struct Array *ar)
{
    int temp;
    for (int i = 0; i < ar->length - 1; i++)
    {
        if (i == 0)
        {
            temp = ar->a[i];
            ar->a[i] = ar->a[i + 1];
        }
        else if (i + 1 == ar->length - 1)
        {
            ar->a[i] = ar->a[i + 1];
            ar->a[i + 1] = temp;
        }
        else
            ar->a[i] = ar->a[i + 1];
    }
}
void insert_sorted(struct Array *ar, int x)
{
    
        int temp, flag = 0;
        for (int i = 0; i < ar->length + 1; i++)
        {
            if ((ar->a[i]) < x && flag == 0)
            {

                continue;
            }
            else
            {
                flag=1;
                temp=ar->a[i];
                ar->a[i]=x;
                x=temp;


            }
        }
    
    ar->length++;
}
void one_side(struct Array * ar)
{
    int i=0,temp,j=ar->length-1;
    while(i<=j)
    {
        while(ar->a[i]<0)
        {i++;} 
        while(ar->a[j]>0){j--;}
        if(i<j)
        {
            temp=ar->a[i];
            ar->a[i]=ar->a[j];
            ar->a[j]=temp;
        }
    }
}

int main()
{
    struct Array ar = {{2, 3, 4,-8, -5, -6, 9, -12}, 10, 8};
    // append(&ar,10);
    // Display(ar);
    // printf("deleted element : %d \n",delete(&ar,3));
    // Display(ar);
    // printf("%d",binary_search(ar,4));
    // left_rotation(&ar);
    Display(ar);
    one_side(&ar);
    
    printf("After seperating the positive and negative element one side the new array will be like this\n");
    Display(ar);

    return 0;
}
