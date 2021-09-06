#include <stdio.h>

void Way1()
{
    int i,j,k;
    int count = 0;
    for(i = 0;i <= 100;i ++)
    {
        for(j = 0;j <= 100;j ++)
        {
            count ++;
            k = 100-i-j;
            if(5*i+j*3+k/3 == 100&&k%3 == 0){
                printf("a is %d,b is %d,c is %d\t",i,j,k);
                printf("find in %d\n",count);
            }
        }
    }
}

void Way2()
{
    int i,j,k;
    int count = 0;
    for(i = 0;i <= 12;)
    {
        count ++;
        j = 25-i/4*7;
        k = 100-i-j;
        if(5*i+3*j+k/3==100&&k%3==0)
        {
            printf("a is %d,b is %d,c is %d\t",i,j,k);
            printf("find in %d\n",count);
        }
        i = i + 4;
    }
}

int main()
{
    Way1();
    Way2();
}