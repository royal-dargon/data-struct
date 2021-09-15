#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elem;
    int length;     // 当前顺序表的长度
    int listsize;   // 当前分配的大小
} SqList;

void InitList_Sq(SqList* L,int size);
// 实现插入操作，参数为一个指向顺序表的指针，第二个是插入的位置，第三个是插入的值
void Insert_sq(SqList* L,int i,int elem);
// 实现展示顺序表信息的操作
void ShowSq(SqList* L);
// 如果顺序表空间不足，则对顺序表进行增加分配的函数
void Increament_Sq(SqList* L);
// 实现寻找顺序表中的一个特定元素的功能
int LocateElem_Sq(SqList* L,int p);

int main()
{
    SqList* L = (SqList*)malloc(sizeof(SqList));
    InitList_Sq(L,5);
    Insert_sq(L,1,2);
    Insert_sq(L,1,3);
    Insert_sq(L,1,4);
    Insert_sq(L,1,5);
    Insert_sq(L,1,6);
    Insert_sq(L,1,7);
    Insert_sq(L,1,8);
    ShowSq(L);
    Insert_sq(L,2,9);
    Insert_sq(L,2,10);
    Insert_sq(L,2,11);
    Insert_sq(L,3,12);
    ShowSq(L);
    int resP = LocateElem_Sq(L,3);
    printf("%d\n",resP);
    return 0;
}


// 实现初始化顺序表
void InitList_Sq(SqList* L,int size)
{
    L->elem = (int*)malloc(sizeof(int)*(size));
    L->length = 0;
    L->listsize = size;
}

// 实现插入操作
void Insert_sq(SqList* L,int i,int elem)
{
    if(i > L->length+1 || i <= 0)
    {
        printf("插入的位置是不合法的\n");
        return;
    }
    if(i > L->listsize||L->listsize<=L->length)
    {
        printf("内存分配不足,下面开始重新分配内存\n");
        Increament_Sq(L);
    }
    int j;
    for(j = L->length;j >= i;j --)
    {
        L->elem[j] = L->elem[j-1]; 
    }
    L->elem[j] = elem;
    //L->elem[j] = temp;
    L->length ++;
}

void ShowSq(SqList* L)
{
    int i;
    printf("value in the sq：\n");
    for(i = 0;i < L->length;i ++)
    {
        printf("%d ",L->elem[i]);
    }
    printf("\n");
    printf("the length of sq is %d,the listsize of sq is %d\n",L->length,L->listsize);
}

// 对内存进行增加分配
void Increament_Sq(SqList* L)
{
    int* temp = (int*)malloc(sizeof(int)*(L->listsize+5));
    //int temp[L->listsize+5];
    int i;
    for(i = 0;i < L->length;i ++)
    {
        temp[i] = L->elem[i];
    }
    free(L->elem);
    L->elem = temp;
    L->listsize += 5;
}

// 实现寻找顺序表中的一个特定元素
int LocateElem_Sq(SqList* L,int p)
{
    int i;
    for(i = 0;i < L->length;i ++)
    {
        if(L->elem[i] == p)
        {
            return (i+1);
        }
    }
    printf("not found the value\n");
    return 0;
}
