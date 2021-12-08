// 这是一个需要来实现教务课程设计的实践
#include <iostream>
#include <string>
#include <fstream>
#include <string.h>

using namespace std;

// 构建邻接表的基本定义

// 用来记录每个节点的信息
struct MainNode {
    // 这里的id主要是为了存放每个节点的id
    int id;
    string className;
    MainNode *next;
};

// 邻接表的实现主要是一个存放每个链表表头的数组，然后还有有一个就是每个链表中存储的节点
struct Node {
    string Name;
    MainNode *head;
};

// 创建一个起到辅助作用的队列
class List {
    private:    
        int Tid[20];
        int frear,front;
    public:
        List() {
            frear = front = 0;
        }
        // 实现入队列的操作
        void Push(int id) {
            Tid[front] = id;
            front ++;
        }
        // 实现出队列的操作，注意只是返回值但是不把这个值给去掉
        int Top() {
            return Tid[frear];
        }
        // 实现消除队头的元素的操作
        void Pop() {
            frear ++;
        }
        // 判断队列是否为空的操作
        bool IsEmpty() {
            if(front == frear) {
                return true;
            } else {
                return false;
            }
        }
};


class ListDG {
    private:
        // 记录课程数的变量
        int num;
        Node *arr;
        // 用来辅助遍历的bool类型的数组
        bool *visit;
    public:
        // 初始化邻接表的函数
        ListDG() {
            num = 0;
            // 通过文件读形式进行打开
            ifstream infile;
            string name;
            int i = 0;
            infile.open("classNum.txt");
            cout << "现在开始从文件中读出我们需要的课程数。" << endl;
            // 对于文件存储的形式我们采取的方式：
            // 是先输入我们需要多少个课程，文件的第一行写的就是这个，然后下面将是对这些文件名的读写
            while(infile.good() && infile.peek() != EOF) {
                infile >> num;
                arr = new struct Node[num];
            }
            infile.close();
            // 打开获取课程名称的文件，文件名称按照顺序进行存储
            infile.open("className.txt");
            cout << "开始导入所有课程的名称。" << endl;
            while(infile.good() && infile.peek() != EOF) {
                infile >> name;
                arr[i].Name = name;
                arr[i].head = new struct MainNode;
                arr[i].head->next = NULL;
                i ++;
            }
            infile.close();
            //Show();
            // 下面开始构建课程之间的关系
            infile.open("classRela.txt");
            cout << "开始输入课程之间的关系。" << endl;
            // 定义两个名称，分别表示前面一个课程的名称还有一个是后面课程的名称
            string fname, cname;
            MainNode *pnew;
            while(infile.good() && infile.peek() != EOF) {
                infile >> fname;
                infile >> cname;
                // 下面在函数中需要完成的操作是对已经记录的课程进行遍历
                // 然后找到合适的课程进行插入
                //cout << "1";
                //cout << fname;
                int i = 0;
                while(1) {
                    if(i == num) {
                        cout << "在寻找父亲课程时出现了问题！" << endl;
                        return;
                    }
                    if(arr[i].Name == fname) {
                        break;
                    } else {
                        i ++;
                    }
                }
                int j = 0;
                while(1) {
                    if(j == num) {
                        cout << "在寻找后继课程时出现了问题！" << endl;
                        return;
                    }
                    if(arr[j].Name == cname) {
                        break;
                    } else {
                        j ++;
                    }
                }
                // 当找到父课程的位置后，就开始把这个课程插在父课程的最前面
                pnew = new struct MainNode;
                //cout << "1";
                pnew->className = cname;
                pnew->id = j;
                //cout << cname;
                pnew->next = arr[i].head->next;
                //cout << i;
                arr[i].head->next = pnew;
                //cout << arr[i].head->next->className;
            }
            infile.close();
        }
        // 用于展示的函数
        void Show();
        // 用于测试时展示与指定一门课程相关课程的函数
        void TestShow();
        // 拓扑排序
        void topologicalSort();
};

int main() {
    ListDG temp;
    temp.Show();
    temp.TestShow();
    temp.topologicalSort();
    return 0;
}

// 用来遍历的函数
void ListDG::Show() {
    int i;
    for(i = 0;i < num;i ++) {
        cout << arr[i].Name << endl;
    }
}

//用于测试时展示与指定一门课程相关课程的函数
void ListDG::TestShow() {
    int i;
    for(i = 0;i < num;i ++) {
        MainNode *p = arr[i].head->next;
        while(p) {
            cout << p->className << p->id << " ";
            p = p -> next;
        }
        cout << endl;
    }
}

// 拓扑排序
// 构造一个队列Q(queue)和拓扑排序的结果队列T
// 把所有没有依赖顶点的节点放入Q
// 当Q还有顶点的时候，执行下面步骤
// 从Q中取出一个顶点，将这个顶点从Q中删除，并且将它加到结果队列中
// 去掉与他相关的每一条边
// 如果m没有依赖的顶点，那么就把m放入Q中
void ListDG::topologicalSort() {
    List myList;
    // 记录结果的数组
    int res[num];
    int count = 0;
    // 创建一个可以计算每个节点入度的数组
    int  visit[num];
    MainNode *temp;
    memset(visit,0,sizeof(int)*num);
    memset(res,0,sizeof(int)*num);
    int i;
    // 第一遍遍历一遍所有的值，记录每个节点的入度
    for(i = 0;i < num;i ++) {
        MainNode *p = arr[i].head->next;
        while(p) {
            visit[p->id] ++;
            p = p -> next;
        }
    }
    i = 0;
    // 把所有入度为0的节点放进队列
    while(1) {
        if(visit[i] == 0) {
            myList.Push(i);
        }
        i ++;
        if(i == num) {
            break;
        }
    }
    // 开始出对列
    // 如果存储入度为0的队列为空则退出
    while(!myList.IsEmpty()) {
        int j = myList.Top();
        res[count++] = j;
        temp = arr[j].head->next;
        while (temp)
        {
            visit[temp->id] --;
            if(visit[temp->id] == 0) {
                myList.Push(temp->id);
            }
            temp = temp->next; 
        }
        myList.Pop();
    }
    for(i = 0;i < num;i ++) {
        cout << arr[res[i]].Name << " ";
    }   
    cout << endl;
}