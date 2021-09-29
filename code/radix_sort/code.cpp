#include <iostream>

using namespace std;

int maxbit(int *temp,int n);
void radixSort(int *temp,int n);

int main()
{
    int i;
    int temp[] = {1,8,9,5,16,24,12,19};
    int n = sizeof(temp)/sizeof(int);
    //cout<<n;
     for(i = 0;i < n;i ++)
    {
        cout<<" "<<temp[i];
    }
    cout<<endl;
    radixSort(temp,n);
    for(i = 0;i < n;i ++)
    {
        cout<<" "<<temp[i];
    }
    return 0;
}

//find the max bit
int maxbit(int *temp,int n){
    int maxdata = 0;
    int i;
    int count = 0;
    for(i = 0;i < n;i ++)
    {
        if(temp[i] > maxdata)
            maxdata = temp[i];
    }
    while(maxdata != 0)
    {
        maxdata = maxdata / 10;
        count ++;
    }
    return count;
}

void radixSort(int *temp,int n)
{
    int Maxbit = maxbit(temp,n);
    int *tmp = new int[n];
    int *count = new int[10];
    int i = 0,j,m,k;
    int radix = 1;
    // 进行 maxbit 趟排序
    //cout<<Maxbit;
    for(i = 1;i <= Maxbit;i ++)
    {
        // 每次排序前将计数器变为零
        for(j = 0;j < 10;j ++)
            count[j] = 0;
        for(m = 0;m < n;m ++)
        {
            k = (temp[m] / radix) % 10;
            count[k] ++;
        }
        for(m = 1;m < 10;m ++)
        {
            count[m] = count[m] + count[m-1];
        }
        for(j = n-1;j >= 0;j --)
        {
            k = (temp[j] / radix) % 10;
            tmp[count[k] - 1] = temp[j];
            count[k] --;
        }
        for(m = 0;m < n;m ++)
        {
            temp[m] = tmp[m];
        }
        radix = radix * 10;
    }
    delete tmp;
    delete count;
}