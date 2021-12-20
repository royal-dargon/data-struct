#include <iostream>
#include <string>

using namespace std;

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
        void sort();
        // 通过 id 对这个学生的信息进行搜索的函数
        void search(TNO id);
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

template<class TNO,class TScore, int num>
void MyStudent<TNO,TScore,num>::sort() {
    int i,j;
    for(i = 0;i < n-1;i ++) {
        for(j = 0;j < n-1;j ++) {
            if(score[j] < score[j+1]) {
                TNO temp = StudentID[j];
                StudentID[j] = StudentID[j+1];
                StudentID[j+1] = temp;
                TScore temp2 = score[j];
                score[j] = score[j+1];
                score[j+1] = temp2;
            }
        }
    }
}

template<class TNO,class TScore, int num>
void MyStudent<TNO,TScore,num>::search(TNO id) {
    int i = 0;
    while(i < n) {
        if(StudentID[i] == id) {
            break;
        }
        i ++;
    }
    if(i == n) {
        cout << "can not find the student!" << endl;
        return;
    }
    cout << "the id is " << StudentID[i] << " the score is " << score[i] << endl;
}

int main() {
    MyStudent<string,int,100> group1;
    group1.append("10086",100);
    group1.append("233",85);
    group1.DisPlay();
    group1.Delete("10086");
    group1.DisPlay();
    group1.append("202021",88);
    group1.search("10086");
    group1.search("202021");
    group1.append("202122",93);
    group1.sort();
    group1.DisPlay();
    return 0;
}