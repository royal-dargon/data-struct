// 试题三 定义一个字符栈类Stack
#include <iostream>
#include <string.h>

const int SIZE = 100;

using namespace std;

class Stack {
    private:
        char stckarry[SIZE];
        int tos;
    public:
        Stack() {
            memset(stckarry,0,sizeof(char) * SIZE);
            tos = -1;
        }
        void Push(char e) {
            if(tos < SIZE) {
                stckarry[++tos] = e;
            } else {
                cout << "the memery is not enough!" << endl;
            }
        }
        char Pop() {
            if(tos == -1) {
                cout << "the stack is empty!" << endl;
                return ' ';
            }
            return stckarry[tos--];
        }
        char min() {
            if(tos == -1) {
                cout << "the stack is empyt!" << endl;
                return ' ';
            }
            char res = stckarry[0];
            int i;
            for(i = 0;i <= tos;i ++) {
                if(stckarry[i] < res) {
                    res = stckarry[i];
                }
            }
            return res;
        }
};

int main() {
    Stack temp;
    char a = 'a';
    char b = 'b';
    temp.Push(a);
    temp.Push(b);
    temp.Push('c');
    cout << temp.min() << endl;
    cout << temp.Pop() << endl;
    cout << temp.Pop() << endl;
    cout << temp.Pop() << endl;
    cout << temp.Pop() << endl;
    return 0;
}