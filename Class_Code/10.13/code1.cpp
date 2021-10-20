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
// 用来提供对链表的删除的作用
void Delete_Things(Node *head);
// 一个对修改信息总的分支
void ChangeInfo(Node *head);
// 用来对链表中的货物的价格进行修改的函数
void Change_Things_Price(Node *head);
// 用来对存储的商品的名称进行修改
void Change_Things_Name(Node *head);
// 用来对存储的商品的型号进行修改
void Change_Things_Model(Node *head);
// 用来对存储的商品的数量进行修改
void Change_Things_Num(Node *head);
// 对购物车进行查看的操作
void Look_Buying(Buying *res);
// 对购物车进行修改的操作
void Change_Buying(Buying *res,Node *head,double *sum);
// 对购物车内商品进行删除的操作
void Delete_Buying(Buying *res,Node *head,double *sum);
// 用来继续添加购物车
void Add_Buying(Buying *res,Node *head, double *sum);

int main()
{
    cout << "--------------欢迎来到超市管理系统---------------" << endl;
    Node *head = Creat();
    // 用来识别身份的值
    int role;
    cout << "请输入您的身份: 1.超市管理员  2.购物者" << endl;
    cin >> role;
    if(role == 1) {
        // temp 用来描述管理员对下一步操作的选择
        int temp, flag = 1;
        while(flag) {
            cout << "管理员，请输入您接下来想要进行的操作: 1.查询库房内的商品 2.添加商品 3.删除商品 4.修改信息 5.退出"<<endl;
            cin >> temp;
            if(temp == 1) {
                Show_commodity(head);
            }
            else if(temp == 2) {
                CreatByUser(head);
            }
            else if(temp == 3) {
                Delete_Things(head);
            }
            else if(temp == 4) {
                ChangeInfo(head);
            } else {
                cout << "辛苦了，管理员！" << endl;
                flag = 0;
            }
        }
        //CreatByUser(head);
        //Show_commodity(head);
    }
    else if(role == 2) {
        cout << "尊敬的顾客请输入您要进行的操作：1.查看商品 2.选购商品 3.查看购物车 4.修改购物车 5.结账(离开)" << endl;
        int choice = 0;
        Buying *res;
        double sum = 0;
        cin >> choice;
        if(choice == 1) {
            Show_commodity(head);
        }
        else if(choice == 2) {
            Show_commodity(head);
            res = Buy_Things(head,&sum);
        }
        else if(choice == 3) {
            Look_Buying(res);
        }
        else if(choice == 4) {
            Change_Buying(res,head,&sum);
        } else {
            Show_shopres(res,sum);
        }
    }
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
    cout << "------------------收营小票-----------------"<<endl; 
    Buying *p;
    p = head->next;
    while(p != NULL) {
        cout<<"商品名称："<< p->name <<"\t"<<"商品型号："<<p->model<<"\t"<<"商品单价: "<<p->price<<endl;
        cout<<endl;
        p = p->next;
    }
    cout << "the sum is "<<sum<<endl;
}


// 通过对输入的Id进行判断，然后进行对链表的遍历，然后进行删除操作。
void Delete_Things(Node *head) {
    cout << "-----------现在是删除界面------------" << endl;
    Show_commodity(head);
    cout << "请输入您要删除的商品的Id：" << endl;
    int id;
    cin >> id;
    Node *p = head;
    while(p->next != NULL) {
        if(p->next->Id == id) {
            break;
        }
        p = p->next;
    }
    if(p == NULL) {
        cout << "您输入的Id在当前系统中是不存在的! " << endl;
        return;
    } else {
        Node *temp,*q;
        temp = p->next->next;
        q = p->next;
        p->next = temp;
        delete q;
    }
    cout << "删除成功" << endl;
}

//用来对下一步具体要修改什么信息的确定
void ChangeInfo(Node *head) {
    cout << "现在是修改界面" << endl;
    // 用来存储具体需要进行那个操作
    int choice = 0;
    cout << "请选择您要修改的信息 1.商品名称 2.商品的型号 3.商品的价格 4.商品的数量 5.放弃修改" << endl;
    cin >> choice;
    if(choice == 1) {

    }
    else if(choice == 2) {

    }
    else if(choice == 3) {
        Change_Things_Price(head);
    }
    else if(choice == 4) {

    } else {
        cout << "成功放弃本次修改！" << endl;
    }
    return;
}

// 用来给管理员对链表中存储的商品的价格进行修改的操作
void Change_Things_Price(Node *head) {
    cout << "----------------现在是对商品价格进行修改的操作---------------" << endl;
    Show_commodity(head);
    cout << "请输入您需要修改商品的id" << endl;
    // 用来对临时存储修改商品的id
    int cid;
    cin >> cid;
    Node *p = head->next;
    // 用来对需要修改的位置进行确定
    while(p != NULL) {
        if(p->Id == cid) {
            break;
        }
        p = p->next;
    }
    if(p == NULL) {
        cout << "您输入了错误的id，这个id尚且不存在!" << endl;
        return;
    }
    cout << "您需要修改的商品的价格当前为：" << p->price << endl;
    double cprice = p->price;
    cout << "请输入您要修改为的价格 ：" ;
    cin >> cprice;
    p->price = cprice;
    cout << "修改成功！" << endl;
}

// 修改商品的名称
void Change_Things_Name(Node *head) {

}

// 修改商品的型号
void Change_Things_Model(Node *head) {

}

// 修改商品的数量
void Change_Things_Num(Node *head) {

}

// 查看购物车
void Look_Buying(Buying *res) {

}

// 修改购物车
void Change_Buying(Buying *res,Node *head,double *sum) {
    cout << "----------------现在是修改购物车的界面----------------- " << endl;
    cout << "尊敬的客户请选择您接下来需要进行的操作：1.删除商品 2.继续添加商品 3.离开 " << endl;
    int choice = 0;
    cin >> choice;
    if(choice == 1) {
        Delete_Buying(res,head,sum);
    }
    else if(choice == 2) {
        Add_Buying(res,head,sum);
    } else {
        cout << "放弃修改购物车!" << endl;
    }
    return;
}

// 对购物车内商品进行删除的操作
void Delete_Buying(Buying *res,Node *head,double *sum) {

}

// 用来继续添加购物车
void Add_Buying(Buying *res,Node *head, double *sum) {

}



