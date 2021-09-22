/*
This file is about a circle linklist.
We use these code to solve the problem like merge.
*/
#include <iostream>

using namespace std;

class Node{
    public:
        int elem;
        Node* next;  
};

class Circle_list{
    public:
        Node* head;
        Circle_list(){
            head = new Node;
            head->elem = 0;
            head->next = NULL;
        }
        void List_init();
        void Show();
        void union_OL(Circle_list & list);
};

int main()
{
    Circle_list list1,list2;
    list1.List_init();
    list1.Show();
    list2.List_init();
    list2.Show();
    list1.union_OL(list2);
    list1.Show();
}

void Circle_list::List_init()
{
    Node *pnew, *tail;
    tail = head;
    while(1)
    {
        int temp;
        char a;
        cout<<"please put in a number ";
        cin>>temp;
        pnew = new Node;
        pnew->next = NULL;
        pnew->elem = temp;
        tail->next = pnew;
        tail = pnew;
        cout<<"do you want to continue(y/n) ";
        cin>>a;
        if(a == 'n')
        {
            pnew->next = head;
            break;
        }
    }
}

void Circle_list::Show()
{
    Node* p;
    p = head->next;
    while (p != head)
    {
        cout<<p->elem<<" ";
        p = p->next;
    }
    cout<<endl;
}

void Circle_list::union_OL(Circle_list & list)
{
    Node *pa,*pb,*rc;
    pa = head->next;
    pb = list.head->next;
    rc = head;
    //cout<<pb->elem;
    while (pa != head && pb != list.head)
    {
        if(pa->elem<pb->elem)
        {
            rc->next = pa;
            rc = pa;
            pa = pa->next;
        }
        else if(pa->elem<pb->elem)
        {
            rc->next = pb;
            rc = pb;
            pb = pb->next; 
        } else {
            rc->next = pa;
            rc = pa;
            pa = pa->next;
            Node *pq;
            pq = pb;
            pb = pb->next;
            delete pq;
        }
    }
    while(pa != head)
    {
        rc->next = pa;
        rc = pa;
        pa = pa->next;
    }
    while(pb != list.head)
    {
        rc->next = pb;
        rc = pb;
        pb = pb->next;
    }
    rc->next = head;
    delete pb;
}