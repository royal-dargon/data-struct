// This experiment uses a simulation of a job scheduling algorithm to implement an operating system.
#include <stdio.h>

int JCB[7][2] = {{800, 50}, {815, 30}, {830, 25}, {835, 20}, {845, 15}, {900, 10}, {920, 5}}; 

struct outPut
{
    int i;
    int osTime;     // 进入内存的时间
    int inTime;     // 进入系统的时间
    int time;       // 作业执行的时长
    int acTime;     // 结束时间
};


void FCFS();
void SJF();

int main() {
    int i = 0;
    for(i = 0; i < 7; i ++) {
        printf("%d, %d\n", JCB[i][0], JCB[i][1]);
    }
    FCFS();
    return 0;
}

void FCFS() {
    printf("这是FCFS：\n");
    // 整个time是用来标记现在进行作业调度时刻的时间
    int time = JCB[0][0];
    struct outPut res[7];
    int i;
    for(i = 0;i < 7;i ++){
        res[i].i = i + 1;
        if(time < JCB[i][0]) {
            res[i].osTime = JCB[i][0];
        } else {
            res[i].osTime = time;
        }
        res[i].inTime = JCB[i][0];
        res[i].time = JCB[i][1];
        // 这里结束的时间表示的格式需要有意的去处理一下
        int time_h = time / 100;
        int time_m = time % 100;
        int add_h = JCB[i][1] / 60;
        int add_m = JCB[i][1] % 60;
        time_m += add_m;
        time_h = time_h + add_h + time_m / 60;
        time_m = time_m % 60;
        res[i].acTime = 100 * time_h + time_m; 
        time = res[i].acTime;
    }
    for(i = 0;i < 7;i ++) {
        printf("第%d个作业,进入系统的时间是%d,进入内存的时间是%d,持续的时间是%d,结束的时间是%d \n",res[i].i, res[i].inTime, res[i].osTime, res[i].time, res[i].acTime);
    }
}

// 这是用来实现短作业优先的算法
void SJF() {
    int i;
    printf("这是SJF：\n");
    // 这是设置最开始的时间
    int time = JCB[0][0];
    struct outPut res[7];
    res[0].i = 1;
    res[0].inTime = JCB[0][0];
    res[0].osTime = JCB[0][0];
    res[0].time = JCB[0][1];
    // 这个是输出部分
    for(i = 0;i < 7; i ++) {
        printf("第%d个作业，进入系统的时间是%d，进入内存的时间是%d，持续的时间是%d，结束的时间是%d \n", res[i].i, res[i].inTime, res[i].osTime, res[i].time, res[i].acTime);
    }
}

