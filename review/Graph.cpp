// 这个主要是对图的遍历的一些练习，和过去主要的区别是这次的存储方式发生了改变
#include <iostream>

using namespace std;

// 这里主要是存放节点信息的结构体
struct Node {
    int id;
    int value;
    Node *next;
}

// 这里主要是存放每个邻接表的表头的信息
struct MainNode
{
    int value;
    Node *first;
    Node *tail
};

class Graph {
    private:
        // 存放邻接表的信息
        MainNode *arr;
        // 分别存放顶点信息和边数的信息
        int venum, arcnum;
};


int main() {
    return 0;
}