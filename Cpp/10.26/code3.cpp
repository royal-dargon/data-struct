// 书上第六章编程题第六题
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
        void changeSecond(int temp) {
            s = temp;
        }
        void changeMinute(int temp) {
            m = temp;
        }
        void changeHour(int temp) {
            h = temp;
        }
};

class Date {
    private:
        string  dateTime; 
    public:
        Date(string dateTime){
            this->dateTime = dateTime;
        }
        string GetDateTime() {
            return dateTime;
        }
};

class ClockWithDate:public Clock,public Date {
    public:
        ClockWithDate(int h,int m,int s,string dateTime):Clock(h,m,s),Date(dateTime){}
        void AddSecond() {
            cout << "请输入您要增加的秒数：";
            int addS;
            cin >> addS;
            int s = getSecond();
            int temp = (s+addS)/60;
            if(temp == 0) {
                changeSecond(addS+s);
            } else {
                changeSecond((s+addS)%60);
            }
            int m = getMinute();
            int temp2 = (m + temp)/60;
            if(temp2 == 0) {
                changeMinute(m+temp);
            } else {
                changeMinute((m+temp)%60);
            }
            int h = getHour();
            changeHour(temp2+h);
        }
        void Show() {
            cout << GetDateTime() <<","<< getHour() <<","<< getMinute() <<","<< getSecond() << endl;
        }
};

int main() {
    string str = "2002年4月13日";
    ClockWithDate tmp(10,22,35,str);
    tmp.Show();
    tmp.AddSecond();
    tmp.Show();
}