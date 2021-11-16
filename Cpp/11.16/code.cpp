/*
第六章编程题第七题。本题的主要目的是去扩充string类，比如替换某个字符，替换某个字串，删除某个字符，删除某个字串
*/
#include <iostream>
#include <string.h>
//#include <string>

using namespace std;

class String {
    private:    
        char elem[100];
        int tos;
    public:
        String(char value[]) {
            int lenth = strlen(value);
            if(lenth >= 100) {
                cout << "the memery is not enough!" << endl;
            }
            strcpy(elem,value);
            tos = lenth+1;
        }
        void Show() {
            cout << elem <<  " " << tos << endl;
        }
        void swapChar(int place,char word) {
            if(place > tos-1) {
                cout << "you put in the wrong place!" << endl;
                return;
            }
            elem[place-1] = word;
        }
        void swapString(int start,char p[]) {
            int i;
            if(start > tos - 1) {
                cout << "you put in the wrong place!" << endl;
                return;
            }
            int lenth = strlen(p);
            start = start - 1;
            for(i = 0;i < lenth;i ++) {
                elem[start++] = p[i];
            }
        }
        void delChar(int place) {
            int i = place;
            for(;i < tos;i ++) {
                elem[i-1] = elem[i];
            }
            tos --;
        }
        void delString(int start,int finish) {
            int i = finish;
            int j = start - 1;
            for(;i < tos;i ++) {
                elem[j] = elem[i];
                j ++;
            }
            tos = tos - finish + start -1;
        }
};

int main() {
    char value[] = "hello world!";
    String temp(value);
    temp.Show();
    temp.swapChar(12,'s');
    temp.Show();
    char tmp[] = "boys";
    temp.swapString(7,tmp);
    temp.Show();
    temp.delChar(12);
    temp.Show();
    temp.delString(9,11);
    temp.Show();
    return 0;
}