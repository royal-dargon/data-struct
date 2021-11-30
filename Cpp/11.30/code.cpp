// 书上编程题 300页 第二题，第五题，第六题
#include <iostream>
#include <string>

const double PI = 3.14159;

using namespace std;

class Location {
    private:
        int x,y;
    public: 
        Location(int x,int y) {
            this->x = x;
            this->y = y;
        }
        void DisPlay() {
            cout << "the x is " << x << endl;
            cout << "the y is " << y << endl;
        }
        Location operator +(Location B) {
            return Location(x + B.x, y + B.y);
        }
        Location operator -(Location B) {
            return Location(x - B.x,y - B.y);
        }
};

class vehicle {
    public: 
        int power;
    public: 
        vehicle(int power) {
            this->power = power;
        }
        virtual void Show() {
            cout << "the power is " << power << endl;
        }
};

class car:public vehicle {
    private:
        int power;
    public: 
        car(int power):vehicle(power) {
            //peopelNum = pnum;
            this->power = power;
        }
        void Show() {
            cout << "the name is car !" << endl;
            //cout << "the people is " << peopelNum << endl;
            cout << "the power is " << power << endl;  
        }
};

class truck:public vehicle {
    private:   
        string name;
    public: 
        truck(string name,int power):vehicle(power) {
            this->name = name;
        }
        void Show() {
            cout << "the kind is truck" << endl;
            cout << "the name is " << name << endl;
        }
};

class ship:public vehicle{
    private:   
        string kind;
    public:
        ship(string kind, int power):vehicle(power){
            this->kind = kind;
        }
        void Show() {
            cout << "the name is ship !" << endl;
            cout << "the kind is " << kind << endl;
        }
};

class Shape {
    public: 
        virtual double area() = 0;
        virtual void show() = 0;
};

class Rect:public Shape {
    private:
        long Longth;
        long Shorth;
    public: 
        Rect(long Longth,long Shorth) {
            this->Longth = Longth;
            this->Shorth = Shorth;
        }
        double area() {
            return Longth * Shorth;
        }
        void show() {
            cout << "the long is " << Longth << " the short is " << Shorth << endl;
        }
};

class Circle:public Shape {
    private:    
        double radious;
    public:
        Circle(double radios) {
            this->radious = radios;
        }
        void show() {
            cout << "the radious is " << radious << endl;
        }
        double area() {
            return PI * radious * radious;
        }
};

int main() {
    Location point1(1,1);
    Location point2(2,2);
    point1 = point1 + point2;
    point1.DisPlay();
    vehicle *temp;
    ship water("swim",100);
    temp = &water;
    temp->Show();
    Shape *q;
    Circle t1(3.2);
    q = &t1;
    q->show();
    cout << "the area is " << q->area() << endl;
    return 0;
}