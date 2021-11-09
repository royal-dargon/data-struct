// 试题二 利用基类，派生类等技术编写一个计算点point，圆形circle，圆柱体cylinder的表面积
#include <iostream>

const double PI = 3;

using namespace std;

class Point {
    private:   
        int x,y;
    public:
        Point(int x,int y) {
            this->x = x;
            this->y = y;
        }
        void Show() {
            cout << x << "," << y << endl;
        }
};

class Circle:virtual public Point {
    private:
        double radius;
    public:
        Circle(int x,int y,int r):Point(x,y) {
            radius = r;
        }
        double Area() {
            return PI*PI*radius;
        }
        double GetRadius() {
            return radius;
        }
};

class cylinder:public Circle {
    private:
        int high;
    public:
        cylinder(int x,int y,int r,int h):Point(x,y),Circle(x,y,r) {
            high = h;
        }
        double AreaSum() {
            double res;
            double radius = GetRadius();
            //cout << radius << endl;
            res = high * 2 * PI * radius  + 2 * Area();
            return res; 
        }
};

int main() {
    cylinder temp(0,0,2,4);
    cout << temp.AreaSum() << endl;
    return 0;
}