// 第六章编程题第二题
#include <iostream>

using namespace std;

class Building {
    private:
        int Id;
        int floot;
        int roomNum;
        int area;
    public:
        Building(int Id,int floot,int roomNum,int area) {
            this->Id = Id;
            this->floot = floot;
            this->roomNum = roomNum;
            this->area = area;
        }
        void Show_Info() {
            cout<<"the Id of the building is "<<Id<<endl;
            cout<<"the floot number of the building is "<<floot<<endl;
            cout<<"the room number of the building is "<<roomNum<<endl;
            cout<<"the area of the building is "<<area<<endl;
        }
};

class Teach_Building:public Building {
    private:
        int class_num;
    public:
        Teach_Building(int Id,int floot,int roomNun,double area,int classN):Building(Id,floot,roomNun,area) {
            class_num = classN;
        }
        void Show_Info2() {
            Show_Info();
            cout<<"the class numbers of the building is "<<class_num<<endl;
        }
};

class Dorm_Building:public Building {
    private:
        int stu_number;
    public:
        Dorm_Building(int Id,int floot,int roomNun,double area,int number):Building(Id,floot,roomNun,area) {
            stu_number = number;
        }
        void Show_Info3() {
            Show_Info();
            cout<<"the stu_number of the building is "<<stu_number<<endl;
        }
};  

int main() {
    Teach_Building tmp(1001,5,2,800,1);
    Dorm_Building tmp2(1002,5,2,1800,899);
    tmp.Show_Info2();
    tmp2.Show_Info3();
    return 0;
}