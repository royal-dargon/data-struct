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
        void Write_Info() {
            cout << "现在开始写入这个用户的基本信息" << endl;
            ofstream infile;
            infile.open("info.dat");
            infile << this->name << endl;
            infile << this->sex << endl;
            infile << this->birthday << endl;
            infile << this->ID << endl;
            infile.close();
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
        void Write_Mark() {
            ofstream outfile;
            outfile.open("info.dat");
            outfile << mark << endl;
            outfile.close();
        }
   
};

template<class TNO, class TScore, int num>
class MyStudent {
    private:
        int n;
        TNO StudentID[num];
        TScore score[num];
    public: 
        void append(TNO ID,TScore s) {
            if(n < num) {
                StudentID[n] = ID;
                score[n] = s;
                n ++;
            }
        }
        void Delete(TNO ID);
        void DisPlay() {
            int i;
            for(i = 0;i < n;i ++) {
                cout << "the Id is " << StudentID[i] << " " << "the score is " << score[i] << endl;
            }
        }
        MyStudent() {
            n = 0;
        }
};



template<class TNO,class TScore, int num>
void MyStudent<TNO,TScore,num>::Delete(TNO ID) {
    int i,j;
    for(i = 0;i < n;i ++) {
        if(StudentID[i] == ID) {
            for(j = i;j < n;j ++) {
                StudentID[j] = StudentID[j+1];
                score[j] = score[j+1];
            }
            n--;
        }
    }
}

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
        void Write_Pos() {
            ofstream outfile;
            outfile.open("info.dat");
            outfile << position << endl;
            outfile.close();
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
        void Write() {
            this->Write_Info();
            this->Write_Mark();
            this->Write_Pos();
        }
};

class MyString {
    public:
        char Str[20];
        MyString();
};

int main() {
    Stu_Teacher temp("张旷","女","五月一号","10086",100,"教授");
    temp.Show();
    temp.Write();
    MyStudent<string,int,100> group1;
    group1.append("10086",100);
    group1.append("233",85);
    group1.DisPlay();
    group1.Delete("10086");
    group1.DisPlay();
    return 0;
}