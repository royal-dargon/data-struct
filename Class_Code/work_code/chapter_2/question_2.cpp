// 第二章第二道题
// L是无表头节点的单链表，且P节点既不是首元节点，也不是尾元节点，写出在p节点后插入s节点的核心语句序列
#include <iostream>

using namespace std;

struct Node {
    int elem;
    Node *next;
};


// place表示插入的位置，具体的表示是这是第几个节点，在本题中默认此节点是存在的
void Insert(Node *head,int Nelem,int place) {
    Node *p;
    p = head;
    while(place) {
        p = p ->next;
        place --;
    }
    Node *pnew = new struct Node;
    pnew->elem = Nelem;
    Node *temp;
    temp = p->next;
    p->next = pnew;
    pnew->next = temp;
}