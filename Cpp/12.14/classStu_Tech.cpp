#include <iostream>
#include <string>
#include <fstream>

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
        void Write_Info(ofstream &infile) {
            cout << "现在开始写入这个用户的基本信息" << endl;
            //ofstream infile;
            //infile.open("info.dat",ios::app);
            infile << this->name << endl;
            infile << this->sex << endl;
            infile << this->birthday << endl;
            infile << this->ID << endl;
            //infile.close();
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
        void Write_Mark(ofstream &outfile) {
            cout << "Mark" << endl;
            //ofstream outfile;
            //outfile.open("info.dat");
            outfile << mark << endl;
            //outfile.close();
        }
   
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
        void Write_Pos(ofstream &outfile) {
            cout << "Pos" << endl;
            //ofstream outfile;
            //outfile.open("info.dat");
            outfile << position << endl;
            //outfile.close();
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
        void Write(ofstream &infile) {
            //ofstream infile;
            this->Write_Info(infile);
            this->Write_Mark(infile);
            this->Write_Pos(infile);
        }
};

class MyString {
    public:
        char Str[20];
        MyString();
};

int main() {
    string name, sex, birthday,id,pos;
    int mark;
    ofstream infile;
    infile.open("info.dat",ios::app);
    Stu_Teacher temp1("张旷","女","五月一号","10086",100,"教授");
    Stu_Teacher temp2("张三","男","十月一号","3209",99,"导师");
    temp1.Show();
    temp1.Write(infile);
    temp2.Write(infile);
    infile.close();
    ifstream outfile;
    outfile.open("info.dat");
    while(outfile.peek() != EOF) {
        outfile >> name;
        if(outfile.eof()) {
            break;
        }
        outfile >> sex;
        outfile >> birthday;
        outfile >> id;
        outfile >> mark;
        outfile >> pos;
        cout << name << " " << sex << " " << birthday << " " << id << " " << mark << " " << pos << endl;
    }
    outfile.close();
    return 0;
}