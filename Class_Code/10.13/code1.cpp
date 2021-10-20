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

struct Buying {
    string name;
    string model;
    double price;
    Buying *next;
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
Buying* Buy_Things(Node *head,double *sum);
// 用来展示小票的服务
void Show_shopres(Buying *head, double sum);

int main()
{
    Node *head = Creat();
    CreatByUser(head);
    Show_commodity(head);
    double sum = 0;
    Buying* res = Buy_Things(head,&sum);
    Show_shopres(res,sum);
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
    while(infile.good() && infile.peek() != EOF) {
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
    cout<<endl;
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
    head = p;
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

Buying* Buy_Things(Node *head,double *sum) {
    int flag = 1;
    int id;
    Buying *res = new struct Buying;
    Buying *pnew, *tail;
    res->next = NULL;
    tail = res;
    cout << "--------购买界面-----------" << endl;
    cout << endl;
    while(flag) {
        cout << "请输入您要购买商品的ID: ";
        cin >> id;
        Node *p = head;
        int flag1 = 1;
        while(p != NULL && flag1 == 1) {
            if(p->Id == id) {
                if(p->number == 0) {
                    cout << "the number of the thing is not enough!" << endl;
                    break;
                }
                p->number = p->number - 1;
                flag1 = 0;
                pnew = new struct Buying;
                pnew->name = p->name;
                pnew->model = p->model;
                pnew->price = p->price;
                *sum = *sum + p->price;
                pnew->next = NULL;
                tail->next = pnew;
                tail = pnew;
            }
            p = p->next;
        }
        if(flag1 == 1) {
            cout << "you put in wrong Id!"<<" please put in again!"<<endl;
        }
        cout << "do you want continue to buy (1/0): ";
        cin >> flag;
    }
    return res;
}

// 先通过链表显示所购买的商品，最后显示最后的收款总额
void Show_shopres(Buying *head,double sum) {
    cout << endl;
    cout << "-----------收营小票--------------"<<endl; 
    Buying *p;
    p = head->next;
    while(p != NULL) {
        cout<<"商品名称："<<p->name<<"\t"<<"商品型号："<<p->model<<"\t"<<"商品单价: "<<p->price<<endl;
        cout<<endl;
        p = p->next;
    }
    cout << "the sum is "<<sum<<endl;
}