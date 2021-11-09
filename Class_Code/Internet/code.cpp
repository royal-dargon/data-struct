// 本实验是利用树形结构的搜索算法模拟英特网域名的查询
// 建立树的存储结构使用的是孩子-兄弟链表
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct IpAndName {
    string name;
    string Ip;
};

struct CSNode {
    string elem;
    string IP;
    CSNode *firstChild, *nextSibling;
};

// 用来辅助创建孩子兄弟结点的队列
class Queue {
    private:
        CSNode *list[100];
        int front,frear;
    public:
        // 初始化队列用两个表示头和尾的标志进行辅助
        Queue() {
            front = 0;
            frear = 0;
        }
        void Push(CSNode *p) {
            list[front] = p;
            front ++;
        }
        CSNode* Pop() {
            if(front <= frear) {
                cout << "the queue is empty!" << endl;
                return NULL;
            }
            return list[frear];
        }
        void Del() {
            frear ++;
        }
};

// 用来辅助遍历的栈的结构
class Stack {
    private:
        string sta[100];
        int tos;
    public:
        Stack() {
            tos = -1;
        }
        void Push(string value) {
            tos ++;
            sta[tos] = value;
        }
        string Pop() {
            string res = sta[tos];
            tos --;
            return res;
        }
        void Traver() {
            int i;
            for(i = 0;i <= tos;i ++) {
                cout << sta[i] << ".";
            }
            cout << endl;
        }
        string Traver2() {
            int i;
            for(i = tos;i > 0;i --) {
                cout << sta[i] << ".";
            }
            cout << sta[0] << endl;
            string res = "";
            for(i = tos;i > 0;i --) {
                res = res + sta[i];
                res = res + ".";
            }
            res = res + sta[0];
            return res;
        }
};

class CSTree {
    private:
        CSNode *root;
        Stack myStack;
        IpAndName res[100];
        int count;
    public:
        // 初始化一棵孩子兄弟树
        CSTree() {
            root = new struct CSNode;
            root->firstChild = NULL;
            root->nextSibling = NULL;
            count = -1;
        }
        // 下面是如何创建一个孩子兄弟链表树的结点的操作
        // 根据先到先建的原则，我们采取了队列的方式进行辅助创建
        // 值得注意的是这种建立方式是必须采用按层次建立的方式进行构建
        void CreatTree() {
            string fa,ch,ip;
            CSNode *r = root;
            Queue myQueue;
            // 通过文件读的模式进行打开
            ifstream infile;
            infile.open("web.txt");
            cout << "reading from the file" << endl;
            // 创建的一个循环
            while(infile.good() && infile.peek() != EOF) {
                infile >> fa;
                infile >> ch;
                CSNode *pnew = new struct CSNode;
                if(ch == "www") {
                    infile >> ip;
                    pnew->IP = ip;
                }
                pnew->elem = ch;
                pnew->firstChild = pnew->nextSibling = NULL;
                myQueue.Push(pnew);
                if(fa == "#") {
                    root->firstChild = pnew;
                    //r = pnew;
                } else {
                    CSNode *temp = myQueue.Pop();
                    while(temp->elem != fa) {
                        myQueue.Del();
                        temp = myQueue.Pop();
                    }
                    if(!(temp->firstChild)) {
                        temp->firstChild = pnew;
                        r = pnew;
                    } else {
                        r->nextSibling = pnew;
                        r = pnew;
                    }
                }
            }
            
        }
        // 先序遍历的方式对树进行遍历
        void PreShow(CSNode *Node) {
            if(Node) {
                cout << Node->elem << endl;
                PreShow(Node->firstChild);
                PreShow(Node->nextSibling);
            }
        }
        CSNode* getRoot() {
            return root;
        }
        // 输出所有从根结点到叶子结点的路径
        void OutPath1(CSNode *Node) {
            while(Node) {
                myStack.Push(Node->elem);
                if(Node->firstChild == NULL) {
                    myStack.Traver();
                } else {
                    OutPath1(Node->firstChild);
                }
                myStack.Pop();
                Node = Node ->nextSibling;
            }
        }
        // 输出所有从叶子结点到根结点的路径
        void OutPath2(CSNode *Node) {
            while(Node) {
                myStack.Push(Node->elem);
                if(Node->firstChild == NULL && Node->elem == "www") {
                    count ++;
                    res[count].name = myStack.Traver2();
                    res[count].Ip = Node->IP;
                    cout << Node->IP << endl;
                } else {
                    OutPath2(Node->firstChild);
                }
                myStack.Pop();
                Node = Node ->nextSibling;
            }
        }
        // 实现搜索域名的功能
        void searchInternet() {
            cout << "please put in the string" << endl;
            string temp;
            cin >> temp;
            int i;
            for(i = 0;i <= count;i ++) {
                if(res[i].name == temp) {
                    cout << res[i].Ip << endl;
                    return;
                }
            }
            cout << "you put in the wrong name!" << endl;
        }
};

int main() {
    CSTree myTree;
    // 每次启动程序都开始获得文件中的内容构建英特网的域名
    myTree.CreatTree();
    CSNode *root = myTree.getRoot();
    //myTree.PreShow(root);
    myTree.OutPath2(root->firstChild);
    myTree.searchInternet();
    return 0;
}