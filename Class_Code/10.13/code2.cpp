// 第二次实验 书上379实习三 至少三个队列
// 理发师分为三个等级对应不同的服务费
// 顾客进入后选择理发师，如果这个级别的理发师没有空闲的，那么就要进入排队等候的状态
// 在本实验中，我选择使用的是链队列
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// 一个定义理发师的结构体
struct Barber {
    string name;
    int grade;
    double revenue;
    Barber *next;
};

// 辅助创建对应三个级别的理发师队列
class Barber3List {
    public:
        Barber *front;
        Barber *rear;
        int grade;
        Barber3List(int grade) {
            this->grade = grade;
            front = new struct Barber;
            rear = front;
            front->next = NULL;
        }
        // 用来获得该等级的理发师队列的函数，实现方法是遍历传入的队列，然后寻找和该队列等级一样的理发师，最终传入
        void getListByGrade(Barber *head) {
            Barber *p,*pnew;
            p = head->next;
            while(p != NULL) {
                if(p->grade == this->grade) {
                    pnew = new struct Barber;
                    pnew->name = p->name;
                    pnew->grade = p->grade;
                    pnew->revenue = p->revenue;
                    pnew->next = NULL;
                    rear->next = pnew;
                    rear = pnew;
                }
                p = p->next;
            }
        }
        // 用来展示这个级别的理发师的队列(管理员进行查看的)
        void Show() {
            Barber *p;
            p = front->next;
            while(p != NULL) {
                cout << "理发师姓名：" << p->name << endl;
                cout << "理发师等级：" << p->grade << endl;
                cout << "理发师当前的收入：" << p->revenue << endl;
                cout << "--------------------------" << endl;
            }
        }
        // 用来给顾客查看理发师队列的函数
        void Show2Customer() {
            Barber *p;
            p = front->next;
            while(p != NULL) {
                cout << "理发师姓名：" << p->name << endl;
                cout << "理发师等级：" << p->grade << endl;
                //cout << "理发师当前的收入：" << p->revenue << endl;
                cout << "--------------------------" << endl;
            }
        }
};

// 用来初始化链表
void Init_queue(Barber **front, Barber **rear);
// 用来表示最后退出的时候向文件中写入的函数
void End_queue(Barber *front);
// 用来给管理员提供服务的函数，主要的作用是可以让管理员创建一个理发师的信息
void barberCreate(Barber *front,Barber **rear);
// 用来展示理发师的列表，注意这里是不区分理发师的等级的
void showBarber(Barber *front, Barber *rear);
// 用来提供给管理者来给理发师改变等级的函数,这里默认规定理发师的晋升不是立刻生效的
void changeGrade(Barber *front,Barber *rear);


int main() {
    cout << "欢迎来到理发店管理系统！" << endl;
    Barber *front,*rear;
    Init_queue(&front,&rear);
    //cout << rear->name << endl;
    //showBarber(front,rear);
    barberCreate(front,&rear);
    showBarber(front,rear);
    return 0;
}

// 用来初始化队列的函数 同时从文件中读出数据
void Init_queue(Barber **front,Barber **rear) {
    string fname;
    int fgrade;
    double frevenue;
    Barber *pnew;
    *front = new struct Barber;
    (*front) -> next = NULL;
    *rear = *front;
    // 通过文件读的模式进行打开
    ifstream infile;
    infile.open("barber.txt");
    cout << "reading from the file !" << endl;
    while(infile.good() && infile.peek() != EOF) {
        pnew = new struct Barber;
        infile >> fname;
        pnew->name = fname;
        infile >> fgrade;
        pnew->grade = fgrade;
        infile >> frevenue;
        pnew->revenue = frevenue;
        pnew->next = NULL;
        (*rear)->next = pnew;
        *rear = pnew;
    }
    //cout << front->next->name;
    infile.close();
    cout << "reading finished！" << endl;
}

// 用来向文件中写入今天的营业额的函数
void End_queue(Barber *front) {
    // the mode to wirte
    ofstream outfile;
    outfile.open("barber.txt");
    cout << "write to the file" << endl;
    Barber *p;
    p = front->next;
    while(p != NULL) {
        outfile << p->name << endl;
        outfile << p->grade << endl;
        outfile << p->revenue << endl;
        p = p->next;
    }
    outfile.close();
    cout << "write to the file has finished" << endl;
}

// 展示全部理发师的函数，不区分等级
void showBarber(Barber *front,Barber *rear) {
    cout << "-----------------现在正在展示全部的理发师------------------" << endl;
    cout << endl;
    Barber *p = front->next;
    //cout << p->name;
    while(p != NULL) {
        cout << "姓名：" << p->name << endl;
        cout << "级别：" << p->grade << endl;
        cout << "总收入：" << p->revenue << endl;
        cout << "----------------------------------" << endl;
        p = p -> next;
    }
    cout << endl;
}

// 用来增加理发师的函数
void barberCreate(Barber *front,Barber **rear) {
    cout << "-----------------尊敬的管理员现在是增加理发师的界面------------" << endl;
    cout << "现在开始增加理发师>>>" << endl;
    string name;
    int grade;
    double revenue;
    Barber *pnew;
    int flag = 1; 
    while(flag) {
        cout << "请输入您要添加的理发师的姓名：" ;
        cin >> name;
        cout << "请输入您要添加的理发师的等级：" ;
        cin >> grade;
        cout << "请输入您要添加的理发师的目前的收入：" ;
        cin >> revenue;
        pnew = new struct Barber;
        pnew->name = name;
        pnew->grade = grade;
        pnew->revenue = revenue;
        pnew->next = NULL;
        (*rear)->next = pnew;
        *rear = pnew;
        cout << "您是否要继续（1/0）：";
        cin >> flag;
    }
    //cout << (*rear)->name << endl;
    cout << "尊敬的管理员您正在退出目前的操作" << endl;
}

void changeGrade(Barber *front,Barber *rear) {
    cout << "----------------------尊敬的管理员，现在是给理发师改变等级的地方-------------------" << endl;
    int changeGrade;
    showBarber(front,rear);
    cout << "请输入您想要修改的理发师的姓名：";
    string name;
    cin >> name;
    cout << "正在修改的理发师的姓名是：" << name << endl;
    Barber *p = front -> next;
    while(p != NULL) {
        if(p->name == name) {
            cout << "已经找到了您要修改的理发师。"<< endl;
            break;
        }
        p = p->next;
    }
    if(p == NULL) {
        cout << "您输入的姓名在系统中是不存在的！" << endl;
        return ;
    }
    cout << "该理发师的当前等级是：" << p->grade << endl;
    changeGrade = p->grade;
    cout << "请输入您想要修改为的等级：" ;
    cin >> changeGrade;
    p->grade = changeGrade;
    cout << "已经修改完成！"<< endl;
}