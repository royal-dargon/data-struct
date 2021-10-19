// 第六章编程题第三题
#include <iostream>
#include <string.h>

using namespace std;

class Table {
    private:
        int height;
    public:
        Table(int h) {
            height = h;
        }
        int Get_height() {
            return height;
        }
};

class Circle {
    private:
        int radius;
    public:
        Circle(int r) {
            radius = r;
        }
        int Get_radius() {
            return radius;
        }
};

class RountTable:public Circle,public Table {
    private:
        char* color;
    public:
        RountTable(char color1[],int h,int r):Circle(r),Table(h) {
            int lenth = strlen(color1);
            color = new char[lenth+1];
            strcpy(color,color1);
        }
        void Show() {
            cout<<"the color is "<<color<<endl;
            cout<<"the redius is "<<Get_radius()<<endl;
            cout<<"the height is "<<Get_height()<<endl;
        }
};

int main() {
    char str[] = "red";
    RountTable tmp(str,2,3);
    tmp.Show();
    return 0;
}