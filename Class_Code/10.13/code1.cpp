// 实验三 书上378页实习一 人，货，厂，客
// 设计思路程序每次启动，从一个txt文件中读取信息，然后创建一个链表
// 分为管理者与购买者的模块
// 在管理者方面有对货物添加的功能
// 在购买者方面，每次的购买要自动对链表中的数据进行处理
// 在关闭程序的时候又要向文件中写入本次更新后的信息，值得注意的是需要选择一个队文件中的数据进行完全清空的方式
#include <iostream>
#include <string.h>
#include <string>
#include <fstream>

using namespace std;

struct Node {
    int Id;
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

// 这种方法用于每次对文档的数据进行读入
Node* Creat();
// 这种方法用于每次的手动添加
void CreatByUser(Node* head);
void Show_commodity(Node *head);
// 通过这种方式在程序结束的时候向文件中写入本次链表的内容
void Write_File(Node *head);
// 购买者的函数，购买者通过查看链表的Id对商品进行购买
void Buy_Things(Node *head);

int main()
{
    Node *head = Creat();
    CreatByUser(head);
    //cout << "!";
    Show_commodity(head);
    Write_File(head);
    return 0;
}

// 用来初始化链表的函数
// 同过文件的形式向文件进行读出
Node* Creat() {
    Node *head,*pnew,*tail;
    string fname,fmodel;
    int fnum,fid;
    double fprice;
    //int fnum;
    head = new struct Node;
    head->next = NULL;
    tail = head;
    //int n = 2;
    // 通过文件读的模式将文件进行打开
    ifstream infile;
    infile.open("shop.txt");
    cout << "Reading from the file" << endl;
    while(!infile.eof()) {
        pnew = new struct Node;
        infile >> fid;
        pnew->Id = fid;
        infile >> fname;
        pnew->name = fname;
        //strcpy(pnew->name,fname);
        infile >> fmodel;
        pnew->model = fmodel;
        //strcpy(pnew->model,fmodel);
        infile >> fnum;
        pnew->number = fnum;
        infile >> fprice;
        pnew->price = fprice;
        tail->next = pnew;
        pnew->next = NULL;
        tail = pnew;
    }
    infile.close();
    return head;
}

void Show_commodity(Node *head) {
    Node *p;
    p = head->next;
    while (p != NULL)
    {
        cout<<"-------------------"<<endl;
        cout<<"ID："<<p->Id<<endl;
        cout<<"商品名称:"<<p->name<<endl;
        cout<<"商品型号:"<<p->model<<endl;
        cout<<"商品价格:"<<p->price<<endl;
        cout<<"商品数量:"<<p->number<<endl;
        p = p->next;
    }
}

void CreatByUser(Node *head) {
    Node *pnew,*p,*tail;
    p = head;
    int flag = 1;
    int id;
    // 这一步用来将链表遍历到可以添加数据的地方
    while (p->next != NULL)
    {
        p = p->next;   
    }
    tail = p;
    id = p->Id;
    cout<<id<<endl;
    cout<<"下面开始输入您要录入的信息"<<endl;
    while(flag) {   
        string fname;
        string fmodel;
        int fnumber;
        double fprice;
        cout<<"请输入商品的名字: ";
        cin>>fname;
        cout<<"请输入商品的型号: ";
        cin>>fmodel;
        cout<<"请输入商品的数量: ";
        cin>>fnumber;
        cout<<"请输入商品的单价：";
        cin>>fprice;
        pnew = new struct Node;
        id ++;
        pnew->Id = id;
        pnew->name = fname;
        pnew->model = fmodel;
        pnew->number = fnumber;
        pnew->price = fprice;
        pnew->next = NULL;
        tail->next = pnew;
        tail = pnew;
        cout<<"do you want to continue:(1/0) ";
        cin >> flag;
    }
}

void Write_File(Node *head) {
    // the mode to write
    ofstream outfile;
    outfile.open("shop.txt");
    cout << "write to the file" << endl;
    Node *p;
    p = head->next;
    while(p != NULL) {
        outfile << p->Id << endl;
        outfile << p->name << endl;
        outfile << p->model << endl;
        outfile << p->number << endl;
        outfile << p->price << endl;
        p = p->next;
    }
    outfile.close();
}