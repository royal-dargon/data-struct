// 利用字典树来实现一个小型全文检索系统
// 值得注意的是每个单词的结尾使用的是$来表示一个单词的结束
/*
我打算采取的思路是在文件中先将文章的内容给提取出来每个单词的提取
然后单独对文章中的内容构建一个字典树，然后开始统计每个单词出现的频率 
*/
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

struct Node
{
    char elem;
    // 用来存放兄弟节点的指针
    Node *next;
    // 用来存放第一个子树的指针
    Node *first;
    // 如果这个节点是一个单词的结束的位置，那么这个节点将会存储这个单词在全文中出现的次数
    int Num;
};

// 创建一个我的键树的类，里面将会有一系列的操作
class MyTree {
    private:
        Node *root;
    public:
        MyTree() {
            cout << "creat my key tree!" << endl;
            root = NULL;
        }
        // 主要是用来对文档内部内容进行插入的操作
        void Insert();
};


int main() {
    return 0;
}