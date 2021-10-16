// 第三章第二题 编写一个循环队列
// 同时实现入队和出队的算法
#include <iostream>
using namespace std;

class Solution {
    private:
        // 头指针，指向队列的头节点
        int front;
        // 尾指针，指向队列的尾节点
        int rear;
        // 存储当前队列中的元素的个数
        int queueSize;
        // 表示队列的最大值
        int Maxsize;
        int *elem;
    public:
        Solution(){
            front = 0;
            rear = 0;
            queueSize = 0;
            Maxsize = 7;
            elem = new int[7];
        }
        int queue_pop();
        void queue_push(int p);
};

int main() {
    Solution tmp;
    tmp.queue_push(1);
    tmp.queue_push(2);
    int res = tmp.queue_pop();
    cout<<res<<endl;
    tmp.queue_push(3);
    cout<<tmp.queue_pop()<<" "<<tmp.queue_pop()<<endl;
    return 0;
}

int Solution::queue_pop() {
    if(queueSize == 0) {
        cout << "the memery do not have a number!" << endl;
        return 0;
    }
    int res = elem[rear];
    if(rear != 6){
        rear = rear + 1;
    } else {
        rear = 0;
    }
    queueSize = queueSize - 1;
    return res;
}

void Solution::queue_push(int p) {
    if(queueSize == 7) {
        cout << "memery is not enough!" << endl;
        return;
    }
    elem[front] = p;
    if(front != 6) {
        front ++;
    } else {
        front = 0;
    }
    queueSize = queueSize + 1;
    return;
}