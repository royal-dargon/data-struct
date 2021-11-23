// 这是对myInit文件的定义部分
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "myInit.h"

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {-1,1,0,0};

// 初始化迷宫的的内容
maze creatMaze() {
    srand((int)time(0));
    maze temp;
    int i,j;
    temp.Col = rand() % 8;
    if(temp.Col < 4) {
        temp.Col += 4;
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

// 判断是否有通路的函数
bool IsSuccess(maze temp) {
    int visit[temp.Row][temp.Col];
    int i,j;
    int k;
    myQueue queues;
    for(i = 0;i < temp.Row;i ++) {
        for(j = 0;j < temp.Col;j ++) {
            visit[i][j] = 0;
        }
    }
    point e;
    e.x = 0;
    e.y = 0;
    e.depth = 0;
    queues.Push(e);
    bool found = false;
    while(!found && !queues.IsEmpty()) {
        point p = queues.Pop();
        // 用来操作上下左右的四个方向
        if(p.x == temp.Col - 1 && p.y == temp.Row - 1) {
            return true;
        }
        for(k = 0;k < 4;k ++) {
            int nx = p.x + dx[k];
            int ny = p.y + dy[k];
            if(nx < 0 || nx > temp.Col - 1 || ny < 0 || ny > temp.Row) {
                continue;
            }
            // 已经访问过了
            if(visit[nx][ny]) {
                continue;
            }
            // 遇到墙了
            if(temp.Pic[nx][ny] == 1) {
                continue;
            }
            visit[nx][ny] = 1;
            point n = {nx,ny,p.depth+1};
            queues.Push(n);
        }
        queues.Del();
    }
    return false;
}