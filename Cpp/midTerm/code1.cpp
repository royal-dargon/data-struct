/*
期中考试的代码
试题一 编写一个日期类Data，用函数NewDay()去实现日期增加一天的功能
*/
#include <iostream>

using namespace std;

class Date {
    private:    
        int year,month,day;
    public:
        Date(int y,int m,int d) {
            year = y;
            month = (m >= 1 && m <= 12)?m:1;
            day = (d >= 1 && d <= 31)?d:1;
        }
        void NewDay() {
            if(day == 30 || day == 31 || day == 29 || day == 28) {
                if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                    if(day == 31) {
                        day = 1;
                        month ++;
                    } else {
                        day ++;
                    }
                } 
                else if(month == 4 || month == 6 || month == 9 || month == 11) {
                    if(day == 30) {
                        day = 1;
                        month ++;
                    } else {
                        day ++;
                    }
                } else {
                    if(day == 28 && (year % 4 == 0 && year % 100 != 0)) {
                        day = 29;
                        //month ++;
                    } else {
                        day = 1;
                        month ++;
                    }
                }
            } else {
                day = day + 1;
            }
            if (month == 13) {
                month = 1;
                year ++;
            }
        }
        void Show() {
            cout << year << "," << month << "," << day << endl;
        }
};

int main() {
    Date temp(2008,12,31);
    temp.NewDay();
    temp.Show();
    return 0;
}