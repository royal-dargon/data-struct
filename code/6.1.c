// 本题要求实现一个函数，实现单链表逆转
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

typedef struct Node List;

List* Read();
List* Reverse(List* l1);
void Print(List* head);

int main()
{
    List *l1,*l2;
    l1 = Read();
    Print(l1);
    l2 = Reverse(l1);
    Print(l2);
    return 0;
}

List* Read()
{
    List* head,*tail,*pnew;
    head = (List*)malloc(sizeof(List));
    if(head == NULL){
        printf("the memery is not enough!\n");
        return NULL;
    }
    head->next = NULL;
    tail = head;
    int temp;
    while(1){
        printf("the value is");
        scanf("%d",&temp);
        if(temp > 9){
            break;
        }
        pnew = (List*)malloc(sizeof(List));
        pnew->value = temp;
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
    }
    return head;
}

void Print(List* head)
{
    List *temp;
    temp = head->next;
    while(temp != NULL)
    {
        printf("%d ",temp->value);
        temp = temp->next;
    }
    printf("\n");
}

List* Reverse(List* l1)
{
    List* temp,* r;
    temp = l1->next;
    if(temp == NULL)
    {
        return NULL;
    }
    l1 -> next = NULL;
    while(temp != NULL){
        r = temp->next;
        temp->next = l1->next;
        l1->next = temp;
        temp = r;
    }
    return l1;
}