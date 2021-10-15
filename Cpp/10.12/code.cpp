// 教材266 第七大题第五小题
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

struct Sub_score {
    char* SubName;
    double score;
};

class Student {
    private:
        int Id;
        char* Name;
        struct Sub_score Info[5];
        // 用来存储记录的学科数
        int count;
    public:
        Student(int id,char* name) {
            Id = id;
            int temp = strlen(name);
            Name = new char[temp+1];
            strcpy(Name,name);
            count = 0;
            //cout<<Id<<" "<<Name<<endl;
        }
        void Push_Sore(char* sname,double score);
        void ShowInfo();
        void get_average() {
            int i;
            double sum = 0;
            for(i = 0;i < count;i ++) {
                sum = sum + Info[i].score;
            }
            cout<<"平均成绩："<<sum/count<<endl;
        }
};

int main() 
{
    char Name[] = "张三";
    Student stu1(10001,Name);
    char Sub1[] = "语文";
    char Sub2[] = "数学";
    char Sub3[] = "英语";
    stu1.Push_Sore(Sub1,88);
    stu1.Push_Sore(Sub2,89.5);
    stu1.Push_Sore(Sub3,90);
    stu1.ShowInfo();
    stu1.get_average();
    return 0;
}

void Student::Push_Sore(char* sname,double scores) {
    if(count >= 5) {
        cout<<"all subjects has been used"<<endl;
        return;
    }
    int lenth = strlen(sname);
    Info[count].SubName = new char[lenth+1];
    strcpy(Info[count].SubName,sname);
    Info[count].score = scores;
    count = count + 1;
}

void Student ::ShowInfo() {
    cout<<Id<<" "<<Name<<endl;
    int i;
    for(i = 0;i < count;i ++) {
        cout<<Info[i].SubName<<" "<<Info[i].score<<endl;
    }
}