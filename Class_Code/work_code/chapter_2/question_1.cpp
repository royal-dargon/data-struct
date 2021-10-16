// 这是第二章的第一道编程题
// 写出在顺序结构下将线性表逆置的算法
#include <iostream>

using namespace std;

class Solution {
    private:
        int *elem;
        int number;
        int MaxSize;
    public:
        Solution() {
            elem = new int[10];
            number = 0;
            MaxSize = 10;
        }
        void Insert(int p) {
            if(number == MaxSize) {
                cout<<"the memery is not enough!"<<endl;
                return;
            } else {
                elem[number] = p;
                number = number + 1;
            }
        }
        void Show() {
            int i;
            for(i = 0;i < number;i ++) {
                cout<<elem[i]<<" ";
            }
            cout<<endl;
        }
        void Do_list() {
            int rear = number-1;
            int front = 0;
            while(rear > front) {
                int temp = elem[rear];
                elem[rear] = elem[front];
                elem[front] = temp;
                rear --;
                front ++;
            }
        }
};

int main()
{
    Solution tmp;
    tmp.Insert(1);
    tmp.Insert(2);
    tmp.Insert(3);
    tmp.Insert(4);
    tmp.Show();
    tmp.Do_list();
    tmp.Show();
    return 0;
}