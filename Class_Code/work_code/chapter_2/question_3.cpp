// 第二章的编程题
// 实现单链表的存储，并且计算单链表中的节点数
#include <iostream>

using namespace std;

struct Node {
    int elem;
    Node *next;
};

class Solution {
    private:
        Node *head;
        int count;
    public:
        void Link_Init();
        void Link_Insert();
        void Link_Show();
};

int main() {
    Solution tmp;
    tmp.Link_Init();
    tmp.Link_Insert();
    tmp.Link_Show();
    return 0;
}

void Solution::Link_Init() {
    head = new struct Node;
    head->next = NULL;
    count = 0;   
}

void Solution::Link_Insert() {
    int m;
    Node *tail, *pnew;
    int flag = 1;    
    tail = head;
    while(flag) {
        cout<<"please input a number: ";
        cin >> m;
        pnew = new struct Node;
        pnew->elem = m;
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
        count ++;
        cout<<"please input a number(1/0): ";
        cin >> flag;
    }
}


void Solution::Link_Show() {
    cout<<count;
}