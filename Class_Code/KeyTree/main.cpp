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

// struct Node
// {
//     string elem;
//     // 用来存放兄弟节点的指针
//     Node *next;
//     // 用来存放第一个子树的指针
//     Node *first;
//     // 如果这个节点是一个单词的结束的位置，那么这个节点将会存储这个单词在全文中出现的次数
//     int Num;
// };

// 创建一个我的键树的类，里面将会有一系列的操作
class Trie {
    private:
        bool flag = false;
        Trie *next[26] = {nullptr};
        // 记录这个单词出现的次数的函数
        int num = 0;
    public:
        Trie() {}; // 构造函数
        // 主要是用来对文档内部内容进行插入的操作
        void Insert(string word);
        // 主要是用来展示所有的单词
        void Show();
};


int main() {
    return 0;
}


// 通过输入的单词对文档进行插入
void Trie::Insert(string word) {
    int i;
    Trie *node = this;
    for(i = 0;i < word.size();i ++) {
        char c = word[i];
        if(node->next[c-'a'] == nullptr) {
            node->next[c-'a'] = new Trie();
        }
        node = node->next[c-'a'];
    }
    node->flag = true;
}

// 展示所有单词的函数
// 在这个函数内部我想采取的方式是通过深度遍历的方式进行遍历
void Trie::Show() {
    int i;
    for(i = 0;i < 26;i ++) {
        if(next[i] != nullptr) {
            
        }
    }
}