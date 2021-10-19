// 第六章编程题第一题
#include <iostream>
const double PI = 3.14159;

using namespace std;

class Point{
    private:
        int x,y;
    public:
        Point(int x,int y) {
            this->x = x;
            this->y = y;
        }
        void Show() {
            cout<<"("<<x<<","<<y<<")"<<endl;
        }
};

class Circle:public Point {
    private:
        double radius;
    public:
        Circle(double r,int x,int y):Point(x,y) {
            radius = r;
        }
        double area() {
            return PI*radius*radius;
        }
        void ShowCircle() {
            cout<<"the centre of the circle: ";
            Show();
            cout<<"the radius is "<<radius<<endl;
        }
};

class Rectangle:public Point {
    private:
        int lenth,weith;
    public:
        Rectangle(int x,int y):Point(x,y) {
            lenth = x;
            weith = y;
        }
        int area() {
            return lenth*weith;
        }
};


int main() {
    Circle tmp(2,1,5);
    cout<<"the area of the circle is "<<tmp.area()<<endl;
    tmp.ShowCircle();
    Rectangle tmp2(2,3);
    cout<<"the area of the rectangle is "<<tmp2.area()<<endl;
    return 0;
}