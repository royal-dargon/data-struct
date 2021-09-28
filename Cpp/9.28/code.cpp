#include <iostream>
#include <math.h>

using namespace std;

class Ctriangle{
    private:
        int a;
        int b;
        int c;
        int lenth;
        float area;
    public:
        Ctriangle(int x,int y,int z)
        {
            a = x;
            b = y;
            c = z;
            lenth = x + y + z;
            float p = float(lenth)/2;
            area = sqrt(p*(p-a)*(p-b)*(p-c));
        }
        void Show();
};


class Point{
    private:
        int x;
        int y;
    public:
        Point(int a,int b)
        {
            x = a;
            y = b;
        }
        double Distance(Point & temp)
        {
            double res;
            res = sqrt(pow(double(temp.x-x),2)+pow(double(temp.y-y),2));
            cout<<"the distance is "<<res<<endl;
        }
};

class CData{
    private:
        int year;
        int month;
        int day;
    public:
        CData(int a,int b,int c)
        {   
            year = a;
            month = b;
            day = c;
            cout<<" year "<<year<<" month "<<month<<" day "<<day<<endl;
        }
        void NewDay()
        {
            if(day == 28||day == 29||day == 30||day == 31)
            {
                if(month == 1||month == 3||month == 5||month == 7||month == 8||month == 10||month == 12)
                {
                    if(day == 31){
                        day = 1;
                        if(month == 12)
                        {
                            month = 1;
                            year ++;
                        } else {
                            month ++;
                        }
                    } else {
                        day ++;
                    }

                }
                else if(month == 4||month == 6||month == 9||month == 11)
                {
                    if(day == 30)
                    {
                        day = 1;
                        month ++;
                    } else {
                        day ++;
                    }
                } else {
                    if(day == 28 && year % 4 != 0)
                    {
                        day = 1;
                        month ++;
                    }
                    else if(day == 28 && year % 100 == 0 && year % 400 != 0)
                    {
                        day = 1;
                        month ++;
                    } else if(day == 29){   
                        month ++;
                        day = 1;
                    }
                    else if(day == 28 && year % 400 == 0)
                    {
                        day ++;
                    } else {
                        month++;
                        day = 1;
                    }
                }
            } else {
                day ++;
            }
            cout<<" year "<<year<<" month "<<month<<" day "<<day<<endl;
        }
};


void Ctriangle::Show()
{
    cout<<"the triangle is "<<a<<" "<<b<<" "<<c<<endl;
    cout<<"the lenth is "<<lenth<<" the area is "<<area<<endl;
}

int main()
{
    Ctriangle temp(3,4,5);
    temp.Show();
    Point a(1,1);
    Point b(1,1);
    a.Distance(b);
    CData p(1999,12,31);
    p.NewDay();
    return 0;
}