#include <stdio.h>
#include <stdlib.h>

// 这是通过链表实现的顺序表
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode,*LinkList;

LinkList InitLink();
void Show(LNode* head);
//void Insert(LNode* head,int elem,int p);
LinkList InitLink_pre();
LinkList Do_Link(LNode* L);

int main()
{
    LNode* head,* head1;
    head = InitLink();
    Show(head);
    head1 = InitLink_pre();
    Show(head1);
    head1 = Do_Link(head1);
    Show(head1);
    return 0;
}

LinkList InitLink()
{
    LNode *head, *tail, *pnew;
    head = (LNode*)malloc(sizeof(LNode));
    if(head == NULL)
    {
        printf("the memory is not enough!\n");
        return NULL;
    }
    head->next = NULL;
    tail = head;
    while(1)
    {
        int temp;
        char a;
        printf("please input a number:\n");
        scanf("%d",&temp);
        pnew =(LNode*)malloc(sizeof(LNode));
        if(pnew == NULL)
        {
            printf("the memery is not enough!\n");
            return NULL;
        }
        pnew->next = NULL;
        pnew->data = temp;
        tail->next = pnew;
        tail = pnew;
        printf("y/n continue: ");
        scanf("%s",&a);
        if(a == 'n')
        {
            break;
        }
    }
    return head;
}

void Show(LNode* head)
{
    LNode* p;
    p = head->next;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

/*
void Insert(LNode* head,int elem,int p)
{
    LNode* pnew = (LNode*)malloc(sizeof(LNode));
    pnew->data = elem;
}
*/

LinkList InitLink_pre()
{
    LNode *head,*tail,*pnew;
    head = (LNode*)malloc(sizeof(LNode));
    if(head == NULL)
    {
        printf("the memery is not enough!\n");
        return NULL;
    }
    head->next = NULL;
    tail = NULL;
    while(1)
    {
        int temp;
        char a;
        printf("please input a number: ");
        scanf("%d",&temp);
        pnew = (LNode*)malloc(sizeof(LNode));
        pnew->data = temp;
        head->next = pnew;
        pnew->next = tail;
        tail = pnew;
        printf("y/n continue: ");
        scanf("%s",&a);
        if(a == 'n')
        {
            break;
        }
    }
    return head;
}

// 实现单链表的原地逆置
LinkList Do_Link(LNode* L)
{
    LNode *r,*p;
    p = L->next;
    L->next =NULL;
    while(p != NULL)
    {   
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}