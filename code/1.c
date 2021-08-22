#include <stdio.h>

void PrintN(int n);

void main()
{
    int a;
    scanf("%d",&a);
    PrintN(a);
}

void PrintN(int n)
{
    if(n){
        PrintN(n-1);
        printf("%d ",n);
    }
}