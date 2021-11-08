/*
用来应付期中考试的文件
类包含函数的结构体
默认的访问控制权限是private
*/
#include <iostream>

using namespace std;

class Clock {
    private:
        int H, M, S;
    public:
        void SetTime(int h,int m,int s) {
            H = (h >= 0 && h <= 24) ? h:0;
            M = (m >= 0 && m <= 60) ? m:0;
            S = (s >= 0 && s <= 60) ? s:0;
        }
        void ShowTime() {
            cout << H << "," << M << "," << S << endl;
        }
        void AddSecond(int s);
};

int main() {
    Clock temp;
    temp.ShowTime();
    temp.SetTime(0,0,0);
    temp.ShowTime();
    return 0;
}

// 在类外面定义函数
void Clock::AddSecond(int s) {
    S = S + s;
}