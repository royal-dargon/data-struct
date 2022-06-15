// This experiment uses a simulation of a job scheduling algorithm to implement an operating system.
#include <stdio.h>

int JCB[7][2] = {{800, 50}, {815, 30}, {830, 25}, {835, 20}, {845, 15}, {900, 10}, {1030, 5}}; 

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
void HNR();

int main() {
    FCFS();
    SJF();
    HNR();
    return 0;
}

// 这个是一个将时间表达式转换为固定格式的函数
int time2format(int ori_time, int add_time) {
    int hour = ori_time / 100;
    int min  = ori_time % 100;
    int add_h = add_time / 60;
    int add_min = add_time % 60;
    int temp = add_min + min;
    add_h = add_h + temp / 60;
    add_min = temp % 60;
    return (hour + add_h) * 100 + add_min;
}

// 这个是用来计算两个时间之差的函数, a > b
int time2sub(int time_a, int time_b) {
    int hour_a = time_a / 100;
    int min_a = time_a % 100;
    int hour_b = time_b / 100;
    int min_b = time_b % 100;
    return (hour_a * 60 + min_a) - (hour_b * 60 + min_b);
}

void FCFS() {
    printf("这是FCFS：\n");
    // 整个time是用来标记现在进行作业调度时刻的时间
    int time = JCB[6][0];
    struct outPut res[7];
    int i;
    for(i = 0;i < 7;i ++){
        res[i].i = i + 1;
        if(time < JCB[i][0]) {
            res[i].osTime = JCB[i][0];
            time = JCB[i][0];
        } else {
            res[i].osTime = time;
        }
        res[i].inTime = JCB[i][0];
        res[i].time = JCB[i][1];
        res[i].acTime = time2format(time, JCB[i][1]);
        time = res[i].acTime;
    }
    for(i = 0;i < 7;i ++) {
        printf("第%d个作业,进入系统的时间是%d,进入内存的时间是%d,持续的时间是%d,结束的时间是%d \n",res[i].i, res[i].inTime, res[i].osTime, res[i].time, res[i].acTime);
    }
}

// 这是用来实现短作业优先的算法
void SJF() {
    int i, j, k, min_job;
    printf("这是SJF：\n");
    // 这是设置最开始的时间
    // 表示调度开始的时间
    int time = JCB[6][0];
    struct outPut res[7];
    // 建立一个辅助数组，用来判断这个作业是否被完成
    int is_act[7];
    for(i = 0;i < 7;i ++) {
        is_act[i] = 0;
    }
    for(i = 0;i < 7;i ++) {
        // 这里具体的做法是从这个遍历到的作业开始遍历，发现可以已经进入系统的，并且时间短的优先运行
        for(k = 0;k < 7;k ++) {
            if(is_act[k] == 0) {
                min_job = k;
                break;
            }
        }
        for(j = min_job;j < 7;j ++) {
            if(JCB[j][0] < time) {
                if(is_act[j] == 1) {
                    continue;
                } else {
                    if(JCB[j][1] < JCB[min_job][1]) {
                        min_job = j;
                    }
                }
            } else {
                break;
            }
        }
        if(JCB[min_job][0] > time) {
            time = JCB[min_job][0];
        }
        res[min_job].inTime = JCB[min_job][0];
        res[min_job].osTime = time;
        res[min_job].time = JCB[min_job][1];
        res[min_job].i = min_job + 1;
        res[min_job].acTime = time2format(time, JCB[min_job][1]);
        is_act[min_job] = 1;
        time = res[min_job].acTime;
    }
    // 这个是输出部分
    for(i = 0;i < 7; i ++) {
        printf("第%d个作业，进入系统的时间是%d，进入内存的时间是%d，持续的时间是%d，结束的时间是%d \n", res[i].i, res[i].inTime, res[i].osTime, res[i].time, res[i].acTime);
    }
}

void HNR() {
    int i, k, j, max_job;
    printf("这是HNR:\n");
    int time = JCB[6][0];
    struct outPut res[7];
    int is_act[7];
    for(i = 0;i < 7;i ++) {
        is_act[i] = 0;
    }
    for(i = 0;i < 7; i ++) {
        for(k = 0;k < 7;k ++) {
            if(is_act[k] == 0) {
                max_job = k;
                break;
            }
        }
        for(j = max_job;j < 7; j ++) {
            if(is_act[j] == 1) {
                continue;
            }
            if((float)(time2sub(time, JCB[max_job][0]) / JCB[max_job][1]) < (float)(time2sub(time, JCB[j][0]) / JCB[j][1])) {
                max_job = j;
            }
        }
        res[max_job].inTime = JCB[max_job][0];
        res[max_job].i = max_job + 1;
        res[max_job].osTime = time;
        res[max_job].time = JCB[max_job][1];
        res[max_job].acTime = time2format(time, JCB[max_job][1]);
        is_act[max_job] = 1;
        time = res[max_job].acTime;
    }
    for(i = 0;i < 7; i ++) {
        printf("第%d个作业，进入系统的时间是%d，进入内存的时间是%d，持续的时间是%d，结束的时间是%d \n", res[i].i, res[i].inTime, res[i].osTime, res[i].time, res[i].acTime);
    }
}





