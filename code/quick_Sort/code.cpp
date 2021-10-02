/*
this is the code about quick sort
*/

#include <iostream>
#include <unistd.h>

using namespace std;

int Partition(int elem[],int low,int high);
void Qsort(int elem[], int low,int high);

int main()
{
    int elem[] = {49,38,65,97,76,13,7,49};
    int lenth = sizeof(elem)/sizeof(int);
    //cout<<lenth;
    int i;
    for(i =0 ;i < lenth;i ++)
    {
        cout<<elem[i]<<" ";
    }
    cout<<endl;
    Qsort(elem,0,lenth-1);
    for(i = 0;i < lenth;i ++)
    {
        cout<<elem[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void Qsort(int elem[],int low,int high)
{
    if(low < high)
    {
        int res = Partition(elem,low,high);
        Qsort(elem,low,res-1);
        Qsort(elem,res+1,high);
    }
}

int Partition(int elem[],int low,int high)
{
    int temp = elem[low];
    //cout<<elem[low];
    //sleep(3e8);
    while(low < high){
        while(low < high && elem[high] >= temp)
        {
            high = high -1;
        }
        if(low < high){
            elem[low] = elem[high];
            low = low + 1;
        }
        while(low < high && elem[low] <= temp)
        {
            low = low + 1;
        }
        if(low < high){
            elem[high] = elem[low];
            high = high - 1;
        }
    }
    //sleep(3e6);
    elem[low] = temp;
    //cout<<low<<endl;
    return low;
}