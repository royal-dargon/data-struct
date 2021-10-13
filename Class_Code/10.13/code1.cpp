// 实验三 书上378页实习一 人，货，厂，客
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

struct Node {
    string name;
    string model;
    double price;
    int number;
    Node *next;
};

class User {
    private:
        char* name;
        int rightId;
    public:
        User(char uname[]) {
            int lenth = strlen(uname);
            name = new char[lenth+1];
            strcpy(name,uname);
        }
};

class Commodity {
    public:
        // 这种方法用于每次对文档的数据进行读入
        Node* Creat();
        // 这种方法用于每次的手动添加
        void CreatByUser(Node* head);
        void Show_commodity(Node *head);
};

int main()
{
    Commodity tmp;
    Node *head = tmp.Creat();
    tmp.CreatByUser(head);
    tmp.Show_commodity(head);
    return 0;
}

// 用来初始化链表的函数
Node* Commodity::Creat() {
    Node *head,*pnew,*tail;
    head = new struct Node;
    head->next = NULL;
    tail = head;
    int n = 2;
    while(n) {
        pnew = new struct Node;
        pnew->name = "冰箱";
        pnew->model = "松下";
        //int lenth1 = strlen(tmp1);
        //int lenth2 = strlen(tmp2);
        //pnew->name = new char[lenth1+1];
        //pnew->model = new char[lenth2+1];
        //strcpy(pnew->name,tmp1);
        //strcpy(pnew->model,tmp2);
        pnew->number = 100;
        pnew->price = 200.5;
        tail->next = pnew;
        pnew->next = NULL;
        tail = pnew;
        n = n - 1;
    }
    return head;
}

void Commodity::Show_commodity(Node *head) {
    Node *p;
    p = head->next;
    while (p != NULL)
    {
        cout<<"商品名称:"<<p->name<<endl;
        cout<<"商品型号:"<<p->model<<endl;
        cout<<"商品价格:"<<p->price<<endl;
        cout<<"商品数量:"<<p->number<<endl;
        p = p->next;
    }
}

void Commodity::CreatByUser(Node *head) {
    Node *pnew,*p,*tail;
    p = head->next;
    // 这一步用来将链表遍历到可以添加数据的地方
    while (p->next != NULL)
    {
        p = p->next;   
    }
    tail = p;
    int n = 2;
    cout<<"下面开始输入您要录入的信息"<<endl;
    while(n) {   
        string name;
        string model;
        int number;
        double price;
        cout<<"请输入商品的名字: ";
        cin>>name;
        cout<<"请输入商品的型号: ";
        cin>>model;
        cout<<"请输入商品的数量: ";
        cin>>number;
        cout<<"请输入商品的单价：";
        cin>>price;
        pnew = new struct Node;
        pnew->name = name;
        pnew->model = model;
        pnew->number = number;
        pnew->price = price;
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
        n = n -1;
    }
}