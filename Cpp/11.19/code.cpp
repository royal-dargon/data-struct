// 这是在Zhang Yong 班上听的一节实验课，主要需要实现的需求是是一个多态性
// 指针的作用减少了内存的开销
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define PI 3.1415926

//class Comparer;
//class Sorter;
//class XComparer;
//class YComparer;
//class AreaComparer;
//class BubbleSorter;
//class SelectSorter;



class Point {
    private:
        int x, y;
    public:
        Point(int x,int y) {
            this->x = x;
            this->y = y;
        }
        int getX() {
            return x;
        }
        int getY() {
            return y;
        }
};

class Shape {
    public:
        virtual double area() = 0;
        virtual void show() = 0;
};

class Rect:public Shape {
    private:
        Point a, b;
    public:
        Rect(int x1,int y1,int x2,int y2):a(x1,y1),b(x2,y2) {
            cout << "create success!" << endl;
        }   
        double area() {
            return abs(a.getX() - b.getX()) * abs(a.getY() - b.getY());
        }
        void show() {
            cout << "the point one is " << a.getX() << "," << a.getY() << endl;
            cout << "the point one is " << b.getX() << "," << b.getY() << endl;
        }
};

class Circle:public Shape {
    private:
        Point pin;
        double radius;
    public:
        Circle(int x,int y,double r):pin(x,y) {
            radius = r;
        }
        double area() {
            return PI * radius * radius;
        }
        void show() {
            cout << "the point of the circle is " << pin.getX() << "," << pin.getY() << endl;
            cout << "the radius of the circle is " << radius << endl;
        }
};

class Triangle:public Shape {
    private:    
        Point a,b,c;
    public:
        Triangle(int x1,int y1,int x2,int y2,int x3,int y3):a(x1,y1),b(x2,y2),c(x3,y3) {

        }
        double area() {
            double l1 = sqrt(pow(a.getX()-b.getX(),2) + pow(a.getY() - b.getY(),2));
            double l2 = sqrt(pow(a.getX()-c.getX(),2) + pow(a.getY() - c.getY(),2));
            double l3 = sqrt(pow(c.getX()-b.getX(),2) + pow(c.getY() - b.getY(),2));
            double temp = (l1 + l2 + l3) / 2;
            double res = temp * (temp - l1) * (temp - l2) * (temp - l3);
            res = sqrt(res);
            return res;
        }
        void show() {
            cout << "the point a is " << a.getX() << "," << a.getY() << endl; 
            cout << "the point b is " << b.getX() << "," << b.getY() << endl;
            cout << "the point c is " << c.getX() << "," << c.getY() << endl;
        }
};

class Comparer {
    public: 
        virtual bool cmp(Shape *a,Shape *b) = 0;
};

class CompareX:public Comparer {
    public:
        bool cmp(Shape *a,Shape *b) {
            
        }
};

int main() {
    int count = 10,i,choice;
    Shape *ps[10];
    srand((int)time(0));
    for(i = 0;i < 10;i ++) {
        choice = rand() % 3;
        if(choice == 0) {
            ps[i] = new Rect(rand()%100,rand()%100,rand()%100,rand()%100);
        }
        else if(choice == 1) {
            ps[i] = new Circle(rand()%100,rand()%100,rand()%100);
        } else {
            ps[i] = new Triangle(rand()%100,rand()%100,rand()%100,rand()%100,rand()%100,rand()%100);
        }
    }
    for(i = 0;i < 10;i ++) {
        cout << ps[i]->area() << endl;
    }
    return 0;
}

