// 书上第六章的编程题第四题
#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        string sex;
        string Id;
        string birthday;
    public:
        Person(string name,string sex,string Id,string birthday) {
            this->name = name;
            this->sex = sex;
            this->Id = Id;
            this->birthday = birthday;
        }
        void Show_Person() {
            cout << "姓名是：" << name << endl;
            cout << "性别是：" << sex << endl;
            cout << "身份证号是：" << Id << endl;
            cout << "生日是：" << birthday  << endl;
        }
};

class Student:virtual public Person {
    private:
        string stu_card;
        double score;
    public:
        Student(string name,string sex,string Id,string birthday,string stu_card,double score):Person(name,sex,Id,birthday) {
            this->stu_card = stu_card;
            this->score = score;
        }
        void Show_Stu() {
            Show_Person();
            cout << "学号是：" << stu_card << endl;
            cout << "成绩是：" << score << endl;
        }
};

class Teacher:virtual public Person {
    private:
        string position;
    public: 
        Teacher(string name,string sex,string Id,string birthday,string position):Person(name,sex,Id,birthday) {
            this->position = position;
        }
        void Show_Tech() {
            Show_Person();
            cout << "职称是：" << position << endl;
        }
};

class Stu_Tech:public Student,public Teacher {
    public:
        Stu_Tech(string name,string sex,string Id,string birthday,string stu_card,double score,string position):Person(name,sex,Id,birthday),Student(name,sex,Id,birthday,stu_card,score),Teacher(name,sex,Id,birthday,position) {
            Show_Stu();
            Show_Tech();
        }
};

int main() {
    string name = "汤先宁";
    string sex = "男";
    string Id = "320902200204130002";
    string birthday = "2002年4月13日";
    string stu_card = "2020213694";
    double score = 99;
    string position = "教授助理";
    Stu_Tech tmp(name,sex,Id,birthday,stu_card,score,position);
}