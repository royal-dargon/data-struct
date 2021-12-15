// 利用字典树来实现一个小型全文检索系统
// 值得注意的是每个单词的结尾使用的是$来表示一个单词的结束
/*
我打算采取的思路是在文件中先将文章的内容给提取出来每个单词的提取
然后单独对文章中的内容构建一个字典树，然后开始统计每个单词出现的频率 
*/
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <algorithm>

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
        bool flag;
        Trie *next[26];
        // 记录这个单词出现的次数的函数
        int num;
    public:
        Trie() {
            int i;
            for(i = 0;i < 26;i ++) {
                num = 0;
                next[i] = NULL;
                flag = false;
            }
        }; // 构造函数
        // 主要是用来对文档内部内容进行插入的操作
        void Insert(string word);
        // 主要是用来展示所有的单词
        void Show(string res);
        void dfs(string s, Trie* node);
};


int main() {
    Trie temp;
    // temp.Insert("hello");
    // temp.Insert("world");
    // temp.Insert("happy");
    // temp.Insert("word");
    // 下面开始循环向文件中读取文字存入到键树中。
    ifstream infile;
    string word;
    infile.open("word.txt");
    cout << "现在开始从文件中读取单词。" << endl;
    while(infile.good() && infile.peek() != EOF) {
        infile >> word;
        transform(word.begin(),word.end(),word.begin(),::tolower);
        temp.Insert(word);
    }
    string res;
    temp.dfs(res, &temp);
    return 0;
}


// 通过输入的单词对文档进行插入
void Trie::Insert(string word) {
    int i;
    Trie *node = this;
    for(i = 0;i < word.size();i ++) {
        char c = word[i];
        //cout << c << " ";
        if(node->next[c-'a'] == NULL) {
            node->next[c-'a'] = new Trie();
        }
        // if(i < word.size()-1) {
            node = node->next[c-'a'];
        // }
    }
    node->flag = true;
    node->num = node->num + 1;
    //cout << node->num;
}

// 展示所有单词的函数
// 在这个函数内部我想采取的方式是通过深度遍历的方式进行遍历
void Trie::Show(string res) {
    int i;
    Trie *node;
    for(i = 0;i < 26;i ++) {
        if(next[i] != NULL) {
            char c = i + 'a';
            //cout << c << " ";
            res = res + c;
            //cout << res << " ";
            node = this->next[i];
            ///cout << flag << " ";
            if(this->flag == 1) {
                cout << res << ":" << this->num << " ";
            }
            node->Show(res);
            res.erase(res.size()-1);
          
        }
    }

    
}

void Trie::dfs(string s, Trie *node) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < 26; i++) {
        Trie *child = node->next[i];
        if (child != NULL) {
            char c = i+'a';
            string newStr = s+c;
            if (child->flag == true) {
                cout << newStr << ":" << child->num << " ";
            }
            dfs(newStr, child);
        }
    }

}

// 总结一下：目前没解决的问题主要是还有符号的问题还是没有解决
// 同时当多个首字母出现一样的时候，会出现报错主要是三个以上时会出现问题
// 同时在出现an a的时候会出现问题
// 同时在只有一个字母的时候也是会出现问题