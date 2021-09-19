#include <stdio.h>
#include <string.h>

int main(){

    char a[50];
    int x=0;
    printf("enter expression\n");
    gets(a);
    for(int i=0;i<strlen(a);i++)
    {
        if(a[i]=='(')
            x++;
        else if(a[i]==')')
            x--;

    }
    if(x==0)
    {
        printf("perfect");
    }
    else
        printf("invalid expression\n");
    return 0;
}
