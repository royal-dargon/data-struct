// 第二次实验 书上379实习三 至少三个队列
// 理发师分为三个等级对应不同的服务费
// 顾客进入后选择理发师，如果这个级别的理发师没有空闲的，那么就要进入排队等候的状态
// 在本实验中，我选择使用的是链队列
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

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
                p = p->next;
            }
        }
        // 用来查看这条队列是否为空的函数
        bool isEmpty() {
            if(front == rear) {
                return false;
            }
            return true;
        }
        // 如果这条队列不为空就把排在最前面的理发师取出，用来给顾客提供服务
        string giveService() {
            if(front->next->next == NULL) {
                Barber *q;
                q = front->next;
                front = rear;
                string name = q->name;
                delete q;
                return name;
            }
            Barber *temp = front->next->next;
            Barber *q = front->next;
            front->next = temp;
            string name = q->name;
            delete q;
            return name;
        }
};
class Customer {
    public:
        int durtime;
        int intertime;
        int select;
        Customer() {
            srand((int)time(0));
            durtime = rand() % 100;
            intertime = rand() % 100;
            select = rand() % 3 + 1;
        }
        void changeGrade() {
            cout << "请输入您想要更换为的等级：" ;
            int grade = select;
            cin >> grade;
            select = grade;
        }
        int getSelect() {
            return select;
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
// 用来表示开始服务的函数
void startService(Barber3List &grade1,Barber3List &grade2,Barber3List &grade3,Customer &user,Barber *front);
// 一个用来修复超市链表会在初始化出现错误的函数
void fixList(Barber *head);


int main() {
    cout << "欢迎来到理发店管理系统！" << endl;
    Barber *front,*rear;
    Init_queue(&front,&rear);
    fixList(front);
    Barber3List Grade1(1);
    Grade1.getListByGrade(front);
    Barber3List Grade2(2);
    Grade2.getListByGrade(front);
    Barber3List Grade3(3);
    Grade3.getListByGrade(front);
    cout << "请输入您的身份：1.顾客 2.管理员" << endl;
    int role = 1;
    cin >> role;
    if(role == 1) {
        cout << "尊敬的顾客，请选择您接下来想要进行的操作-------" << endl;
        Customer user;
        cout << "您当前的服务等级是：" << user.getSelect() << endl;
        while (1)
        {
            cout << "1.查看理发师 2.更换服务的等级 3.选择服务 4.退出" << endl;
            int choice = 1;
            cin >> choice;
            if(choice == 1) {
                cout << "尊敬的顾客请选择您想要查看的理发师的等级：" ;
                int grade = 1;
                cin >> grade;
                if(grade == 1) {
                    Grade1.Show2Customer();
                }
                else if(grade == 2) {
                    Grade2.Show2Customer();
                } else {
                    Grade3.Show2Customer();
                }
            } 
            else if(choice == 2){
                user.changeGrade();
                cout << "您当前的服务等级是：" << user.select << endl;
            } 
            else if(choice == 3) {
                startService(Grade1,Grade2,Grade3,user,front);
            } else {
                cout << "欢迎下次光临！" << endl;
                break;
            }
        }
    } else {
        cout << "尊敬的管理员，请选择您接下来想要进行的操作-----" << endl;
        while (1)
        {
            cout << "1.查看理发师类别 2.修改理发师的等级 3.增加一个理发师 4.退出" << endl;
            int choice = 1;
            cin >> choice;
            if(choice == 1) {
                showBarber(front,rear);
            } 
            else if(choice == 2) {
                changeGrade(front,rear);
            }
            else if(choice == 3) {
                barberCreate(front,&rear);
            } else {
                cout << "辛苦了，管理员！" << endl;
                break;
            }
        }
    }
    End_queue(front);
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

void startService(Barber3List &grade1,Barber3List &grade2,Barber3List &grade3,Customer &user,Barber *front) {
    cout << "现在正在为您预约理发师>>>" << endl;
    string name;
    Barber *p = front->next;
    if(user.select == 1) {
        if(grade1.isEmpty() == 1) {
            cout << "即将开始服务！" << endl;
            name = grade1.giveService();
        } else {
            cout << "该等级的理发师都在工作中！" << endl;
        }
    } 
    else if(user.select == 2) {
        if(grade2.isEmpty() == 1) {
            cout << "即将开始服务！" << endl;
            name = grade2.giveService();
        } else {
            cout << "该等级的理发师都在工作中！" << endl;
        }
    } else {
        if(grade3.isEmpty() == 1) {
            cout << "即将开始服务！" << endl;
            name = grade3.giveService();
        } else {
            cout << "该等级的理发师都在工作中！" << endl;
        }
    }
    while(p != NULL) {
        if(p->name == name) {
            cout << "已经在系统中找到这个理发师！" << endl;
            break;
        }
        p = p -> next;
    }
    if(p == NULL) {
        cout << "没有在系统中找到这个理发师！" << endl;
        return;
    }
    p->revenue = p->revenue + (4-user.select) * user.durtime * 0.4;
    cout << "您本次需要付费 " << (4-user.select) * user.durtime * 0.4 << "元" << endl;
}

void fixList(Barber *head) {
    if(head->next == NULL) {
        cout << "目前理发师的列表为空！" << endl;
        return;
    }
    Barber *p = head;
    // 用来遍历到链表最后一个元素的前一个
    while(p->next->next != NULL) {
        p = p->next;
    }
    Barber *q;
    q = p->next;
    p->next = NULL;
    delete q;
}
