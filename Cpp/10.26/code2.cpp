// 书上第六章的编程题的第5题
#include <iostream>
#include <string>

using namespace std;

class Clock {
    private:
        int h,m,s;
    public:
        Clock(int h,int m,int s) {
            this->h = h;
            this->m = m;
            this->s = s;
        }
        int getHour() {
            return h;
        }
        int getMinute() {
            return m;
        }
        int getSecond() {
            return s;
        }
};

class newClock:public Clock {
    private:
        string moment;
    public:
        newClock(int h,int m,int s):Clock(h,m,s) {
            cout << "create successfully!" << endl;
        }
        void amAndPm() {
            int h = getHour();
            if(h < 12) {
                moment = "上午";
            } else {
                moment = "下午";
            }
        }
        void Show() {
            cout << "小时: " << getHour() << endl;
            cout << "分钟：" << getMinute() << endl;
            cout << "秒数：" << getSecond() << endl;
            cout << moment << endl;
        }
};

int main() {
    newClock tmp(13,25,45);
    tmp.amAndPm();
    tmp.Show();
    return 0;
}