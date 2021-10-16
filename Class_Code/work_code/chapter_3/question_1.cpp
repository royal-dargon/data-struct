// 第三章节第一道编程题
// 本题主要是利用栈先入后出的特性来实现一个有效括号的判断
#include <iostream>
#include <string.h>

using namespace std;

class Solution {
    private:
        int number;
        char *elem;
    public:
        void correct(char exp[],bool *tag);
};

int main()
{
    bool res = true;
    char exp[] = "{(2+1)*(3-2)}";
    Solution tmp;
    tmp.correct(exp,&res);
    cout<<res<<endl;
    return 0;
}

void Solution::correct(char exp[],bool *tag) {
    number = 0;
    int lenth = strlen(exp);
    //cout<<lenth;
    elem = new char[lenth+1];
    int i;
    for(i = 0;i < lenth;i ++) {
        //cout<<exp[i]<<" ";
        if(exp[i] == '{' || exp[i] == '[' || exp[i] == '(') {
            elem[number] = exp[i];
            number = number + 1;
        }
        if(exp[i] == '}') {
            if(elem[number-1] != '{') {
                //cout<<number;
                *tag = false;
                return;
            }
            number = number - 1;
        }
        if(exp[i] == ']') {
            if(elem[number-1] != '[') {
                *tag = false;
                return;
            }
            number = number - 1;
        }
        if(exp[i] == ')') {
            if(elem[number-1] != '(') {
                *tag = false;
                return;
            }
            number = number - 1;
        }
    }
    if(number != 0){
        *tag = false;
    }
}