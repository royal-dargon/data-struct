#include <iostream>
#include <string.h>

using namespace std;

struct MainNode
{
    int id;
    int value;
    MainNode *next;
};

struct Node
{
    int value;
    MainNode *head;
};

// 创建一个辅助队列
class List {
    private:
        int Tid[20];
        int frear, front;
    public:
        List() {
            int i;
            frear = front = 0;
            for(i = 0;i < 20; i ++) {
                Tid[i] = 0;
            }
        }
        // 实现入队列的操作
        void Push(int id) {
            Tid[front] = id;
            front ++;
        }
        // 实现出队列的效果，但是值得注意的是这个地方的返回值而不是将这个值给去掉
        int Top() {
            return Tid[frear];
        }
        // 实现消除队列头元素的操作
        void Pop() {
            frear ++;
        }
        // 判断队列是否为空的操作
        bool IsEmpty() {
            if(frear == front) {
                return true;
            } else {
                return false;
            }
        }
};

// 创建一个图的类
class Graph {
    private:
        // 分别用来体现最大顶点数与边数的数值
        int maxPoint;
        int maxLiner;
        // 用来辅助记录目前表中加入了多少顶点的辅助变量
        int mem;
        // 用来存储每条边的入度情况的
        int *Info;
        // 邻接表
        Node *arc;
    public:
        Graph(int maxPoint, int maxLiner) {
            this->maxPoint = maxPoint;
            this->maxLiner = maxLiner;
            Info = new int[this->maxPoint];
            arc = new struct Node[this->maxPoint];
            int i;
            //cout << maxPoint << endl;
            for(i = 0; i < maxPoint;i ++) {
                Info[i] = 0;
                arc[i].head = new struct MainNode;
                arc[i].head->next = NULL;
            }
            mem = 0;
        }
        // 用来判断这个点的值目前是否在这个邻接表中
        int checkPoint(int value) {
            int i;
            for(i = 0; i < mem; i ++) {
                if(arc[i].value == value) {
                    return i;
                }
            }
            arc[i].value = value;
            int res = mem;
            mem ++;
            return res;
        }
        // 将本次得到的数据插入到这个邻接表中的对应的位置
        void InsertValue(int place, int elem) {
            MainNode *p;
            p = arc[place].head;
            // 寻找到这条链表的最末端，然后进行添加的尝试
            while(p->next) {
                p = p->next;
            }
            int tid = checkPoint(elem);
            MainNode *pnew;
            pnew = new struct MainNode;
            pnew->value = elem;
            pnew->id = tid;
            pnew->next = NULL;
            p->next = pnew;
        }
        // 这是拓扑排序输出的函数
        void topologicalSort();
};

int main() {
    int n, m,i;
    cout << "请输入顶点数和边数：";
    cin >> n;
    cin >> m;
    Graph pic(n,m);
    for(i = 0;i < m;i ++) {
        // 每次输入都是一个边的起始地址和结束位置
        int start, end;
        cout << "请输入每条边的起始地址和结束地址：";
        cin >> start >> end;
        int place = pic.checkPoint(start);
        pic.InsertValue(place, end);
    }
    // 下面开始拓扑排序输出结果
    pic.topologicalSort();
    return 0;
}

void Graph::topologicalSort() {
    int count = 0;
    //MainNode *temp;
    cout << "现在开始拓扑排序进行输出！" << endl;
    // 首先先创建一个辅助的队列
    List myList;
    int res[maxPoint];
    //int count = 0;
    //memset(res,0,sizeof(int)*maxPoint);
    int i;
    for(i = 0;i < maxPoint;i ++) {
        res[i] = 0;
    }
    // 第一遍先遍历一遍所有的值，记录每个节点的入度
    for(i = 0;i < maxPoint;i ++) {
        MainNode *p = arc[i].head->next;
        while(p) {
            Info[p->id] ++;
            p = p->next;
        }
    }
    //cout << "111";
    // for(i = 0;i < maxPoint;i ++) {
    //     cout << arc[i].value << " ";
    // }
    for(i = 0;i < maxPoint;i ++) {
        if(Info[i] == 0) {
            //cout << i;
            myList.Push(i);
        }
    }
    // 开始出队列，如果存储入度为0的队列为空则退出
    while(!myList.IsEmpty()) {
        //cout << "111";
        MainNode *temp;
        int j = myList.Top();
        res[count++] = j;
        temp = arc[j].head->next;
        while(temp) {
            Info[temp->id] --;
            //cout << temp->id;
            if(Info[temp->id] == 0) {
                myList.Push(temp->id);
            }
            temp = temp -> next;
        }
        myList.Pop();
    }
    for(i = 0;i < maxPoint;i ++) {
        cout << arc[res[i]].value << " ";
    }
    cout << endl;
}