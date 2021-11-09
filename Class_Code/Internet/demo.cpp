// 一个对树的二叉链表孩子-兄弟表示法的测试
// 树节点的两个指针域分别指向其最左的孩子节点和右边的兄弟节点
#include <iostream>
#include <string>

using namespace std;

struct CSNode {
    string elem;
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

class CSTree {
    private:
        CSNode *root;
    public:
        // 初始化一棵孩子兄弟树
        CSTree() {
            root = new struct CSNode;
            root->firstChild = NULL;
            root->nextSibling = NULL;
        }
        // 下面是如何创建一个孩子兄弟链表树的结点的操作
        // 根据先到先建的原则，我们采取了队列的方式进行辅助创建
        void CreatTree() {
            string fa,ch;
            CSNode *r = root;
            Queue myQueue;
            // 创建的一个循环
            for(cin >> ch;ch != "#"; cin >> ch) {
                cin >> fa;
                CSNode *pnew = new struct CSNode;
                pnew->elem = ch;
                pnew->firstChild = pnew->nextSibling = NULL;
                myQueue.Push(pnew);
                if(fa == "#") {
                    root->firstChild = pnew;
                    r = pnew;
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
};

int main() {
    CSTree myTree;
    myTree.CreatTree();
    CSNode *root = myTree.getRoot();
    myTree.PreShow(root);
    return 0;
}
