// 这是对myInit文件的定义部分
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "myInit.h"

using namespace std;

// 初始化迷宫的的内容
maze creatMaze() {
    srand((int)time(0));
    maze temp;
    int i,j;
    temp.Col = rand() % 20;
    if(temp.Col < 10) {
        temp.Col += 10;
    }
    temp.Row = temp.Col;
    temp.Pic = new int*[temp.Row];
    for(i = 0;i < temp.Row;i ++) {
        temp.Pic[i] = new int[temp.Col];
    }
    for(i = 0;i < temp.Row;i ++) {
        for(j = 0;j < temp.Col;j ++) {
            temp.Pic[i][j] = rand() % 2;
        }
    }
    temp.Pic[0][0] = 0;
    temp.Pic[temp.Col-1][temp.Row-1] = 0;
    return temp;
}

bool IsSuccess(maze temp) {
    bool visit[temp.Row][temp.Col];
    int i,j;
    myQueue queues;
    for(i = 0;i < temp.Row;i ++) {
        for(j = 0;j < temp.Col;j ++) {
            visit[i][j] = false;
        }
    }
    point e;
    e.x = 0;
    e.y = 0;
    queues.Push(e);
    return true;
}