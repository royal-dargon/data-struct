// 第二次实验 书上379实习三 至少三个队列
// 理发师分为三个等级对应不同的服务费
// 顾客进入后选择理发师，如果这个级别的理发师没有空闲的，那么就要进入排队等候的状态
// 在本实验中，我选择使用的是链队列
#include <iostream>
#include <string>

using namespace std;

// 一个定义理发师的结构体
struct Barber {
    string name;
    int grade;
    double revenue;
    Barber *next;
};

// 用来初始化链表
void Init_queue();
// 用来给管理员提供服务的函数，主要的作用是可以让管理员创建一个理发师的信息
void barberCreate();

int main() {
    return 0;
}