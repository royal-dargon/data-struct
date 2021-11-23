// 这是我将要去完成的一个迷宫作业
#include <iostream>
#include "myInit.h"

using namespace std;

int main() {
    maze temp;
    temp = creatMaze();
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
    return 0;
}