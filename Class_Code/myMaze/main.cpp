// 这是我将要去完成的一个迷宫作业
#include <iostream>
#include "myInit.h"

using namespace std;

int main() {
    maze temp;
    int count = 1;
    temp = creatMaze();
    while (!IsSuccess(&temp))
    {
        count ++;
        temp = creatMaze();
        //cout << count << " ";
    }
    int i,j;
    for(i = 0;i < temp.Row;i ++){
        for(j = 0;j < temp.Col;j ++) {
            //cout << temp.Pic[i][j] << " ";
            if(temp.Pic[i][j] == 1) {
                cout << "*" << " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << temp.Col << endl;
    cout << "创建了" << count << "次" << endl;
    return 0;
}