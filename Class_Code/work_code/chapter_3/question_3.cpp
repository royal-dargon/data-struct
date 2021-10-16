// 第三章编程题第三题 判断一个以@结尾的字符序列是否为回文数列
#include <iostream>

using namespace std;

class Solution {
    public:
        bool Method(char str[]);
};

int main() {
    cout<<"11";
    char str[] = "12321@";
    Solution tmp;
    bool res = tmp.Method(str);
    cout<<res<<endl;
    return 0;
}

bool Solution::Method(char str[]) {
    bool res = false;
    int i = 0;
    // 用来遍历到字符串的@处
    int rear = 0;
    while(str[i] != '@') {
        rear = rear + 1;
    }
    cout << rear;
    rear = rear - 1;
    for(i = 0;i <= rear;i ++) {
        if(str[i] != str[rear]) {
            res = false;
            return res;
        }
        rear = rear - 1;
    }
    res = true;
    return res;
}