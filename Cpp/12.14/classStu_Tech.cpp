#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        string sex;
        string birthday;
        string ID;
    public:
        Person(string name,string sex,string birthday,string ID) {
            this->name = name;
            this->sex = sex;
            this->birthday = birthday;
            this->ID = ID;
        }
        void Show_Info() {
            cout << "the name is " << name << endl;
            cout << "the sex is " << sex << endl;
            cout << "the birthday is " << birthday << endl;
            cout << "the ID is " << ID << endl;
        }

};

class Student:virtual public Person {
    private:
        int mark;
    public:
        Student(string name,string sex,string birthday,string ID,int mark):Person(name,sex,birthday,ID) {
            this->mark = mark;
        }
        void Show_mark() {
            cout << "the mark is " << mark << endl;
        }
        // void Show() {
        //     this->Show_Info();
        // }
   
};

class Teacher:virtual public Person {
    private:
        string position;
    public:
        Teacher(string name,string sex,string birthday,string ID,string position):Person(name,sex,birthday,ID) {
            this->position = position;
        }
        void Show_Pos() {
            cout << "the position is " << position << endl;
        }
};

class Stu_Teacher:public Teacher,public Student {
    public:
        Stu_Teacher(string name,string sex,string birthday,string ID,int mark,string position):Person(name,sex,birthday,ID),Teacher(name,sex,birthday,ID,position),Student(name,sex,birthday,ID,mark) {}
        void Show() {
            this->Show_Info();
            this->Show_mark();
            this->Show_Pos();
        }
};

int main() {
    Stu_Teacher temp("张旷","女","五月一号","10086",100,"教授");
    temp.Show();
    return 0;
}