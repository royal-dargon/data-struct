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

int main() {
    MyStudent<string,int,100> group1;
    group1.append("10086",100);
    group1.append("233",85);
    group1.DisPlay();
    group1.Delete("10086");
    group1.DisPlay();
    return 0;
}