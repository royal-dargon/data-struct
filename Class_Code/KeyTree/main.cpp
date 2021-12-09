// 利用字典树来实现一个小型全文检索系统
// 值得注意的是每个单词的结尾使用的是$来表示一个单词的结束
/*
我打算采取的思路是在文件中先将文章的内容给提取出来每个单词的提取
然后单独对文章中的内容构建一个字典树，然后开始统计每个单词出现的频率 
*/
#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
    string elem;
    // 用来存放兄弟节点的指针
    Node *next;
    // 用来存放第一个子树的指针
    Node *first;
};


int main() {
    return 0;
}