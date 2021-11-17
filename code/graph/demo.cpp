// 本文件是对图的一些基本的尝试，主要的功能是实现对图的信息的存储和图的遍历
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;


// 用作广度优先搜索的辅助队列
class List {
    private:
        int temp[100];
        int rear,front;
    public:
        List() {
            memset(temp,0,sizeof(int)*100);
            rear = 0;
            front = 0;
        }
        bool Isempty() {
            if(rear == front) {
                return true;
            }
            return false;
        }
        void Push(int e) {
            temp[rear] = e;
            rear ++;
        }
        int Pop() {
            int res = temp[front];
            front ++;
            return res;
        }
};

// 这个主要是对图的邻接矩阵存储的尝试
const int MaxSize = 20;
// 存放节点信息的结构体，Id是用来存放节点在存储的数组内的下标
struct Node {
    int Id;
    Node *next;
};

struct MainNode {
    char value;
    Node *first;
    Node *tail;
};

// 值得注意的是暴露给用户的序号全是位序，不是存在数据内的下标
class Graph {
    private:
        MainNode *arr;
        // 分别用来存放顶点数和弧的数量的两个值
        int venum, arcnum;
        // 用来辅助遍历的数组里面存储的是布尔类型的值，如果发生了遍历就会被变为false，如果还没有被遍历到就会是true
        bool visit[100];
    public:
        Graph() {
            int num;
            cout << "please put in how many arr you want to add !" << endl;
            cin >> num;
            arr = new struct MainNode[num];
            //arr = (MainNode*)malloc(sizeof(MainNode) * num);
            venum = num;
            arcnum = 0;
        }
        void Graph_Init() {
            cout << "用来初始化邻接表的各个顶点的初始值" << endl;
            int i;
            for(i = 0;i < venum;i ++) {
                cin >> arr[i].value;
                arr[i].first = new struct Node;
                arr[i].first->next = NULL;
                arr[i].tail = arr[i].first;
            }
            cout << "下面开始构建邻接表各个顶点之间的关系 " << endl;
            for(i = 0;i < venum;i ++) {
                char temp;
                cout << "现在开始构建第" << i+1 << "个顶点的邻接点" << endl;
                cin >> temp;
                while(temp != '#') {
                    int num;
                    Node *pnew = new struct Node;
                    cout << "现在开始输入与该顶点邻接的顶点的序号" << endl;
                    cin >> num;
                    pnew -> Id = num;
                    pnew->next = NULL;
                    //cout << arr[i].value;
                    //pnew->next = arr[i].first->next;
                    //arr[i].first->next = pnew;
                    arr[i].tail->next = pnew;
                    arr[i].tail = pnew;
                    arcnum ++;
                    //cout << venum;
                    cin >> temp;
                    //cout << venum;
                }
            }
            cout << "success!" << endl;
        }
        void VisitFunc(int v) {
            cout << arr[v].value << " ";
            //visit[v-1] = false;
        }
        /*
        void InitVisit() {
            cout << "现在正在初始化辅助空间！" << endl;
            visit = new bool[venum];
            //memset(visit,true,sizeof(bool)*venum);
        }
        */
        // 这是对图的深度优先搜索，从第i个顶点开始遍历整个图
        void DFS(int v) {
            visit[v] = true;
            VisitFunc(v);
            Node *p = arr[v].first->next;
            while(p) {
                if(!visit[p->Id-1]) {
                    DFS(p->Id-1);
                }
                p = p->next;
            }
        }
        // 开始对图进行深度优先遍历的入口
        void DFSTraver() {
            int i;
            for(i = 0;i < venum;i ++) {
                visit[i] = false;
            }
            //cout << visit[0] << endl;
            for(i = 0;i < venum;i ++) {
                if(visit[i] == false) {
                    DFS(i);
                }
            }
        }
        // 对图进行BFS遍历的算法的实践
        void BFSTraver() {
            int i;
            for(i = 0;i < venum;i ++) {
                visit[i] = false;
            }
            // 开始初始化队列
            List myList;
            for(i = 0;i < venum;i ++) {
                if(!visit[i]) {
                    visit[i] = true;
                    VisitFunc(i);
                    myList.Push(i);
                    while(!myList.Isempty()) {
                        int tmp = myList.Pop();
                        Node *p;
                        for(p = arr[tmp].first->next;p != NULL;p = p->next) {
                            if(!visit[p->Id-1]) {
                                visit[p->Id-1] = true;
                                VisitFunc(p->Id-1);
                                myList.Push(p->Id-1);
                            }
                        }
                    }
                }
            }
        }
};

int main() {
    Graph temp;
    temp.Graph_Init();
    //temp.InitVisit();
    temp.DFSTraver();
    cout << endl;
    temp.BFSTraver();
    return 0;
}