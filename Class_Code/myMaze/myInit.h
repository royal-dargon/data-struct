// 这是我的创建迷宫的一些辅助函数
struct maze {
    // 设置迷宫的行数
    int  Row;
    // 设置迷宫的列数
    int Col;
    // 表示迷宫的二维数组
    int **Pic;
};

struct point {
    int x,y;
};

// 创建一个我的队列的类对接下来的一系列操作进行辅助
class myQueue { 
    private:
        point elem[];
        int front, frear;
    public:
        myQueue() {
            elem = new point[500];
            front = frear = 1;
        }
        // 入队列的操作
        void Push(point e) {
            elem[front] = e;
            front ++;
        }
        // 出队列的操作
        int Pop() {
            int res = elem[frear++];
            return res;
        }
        // 检测队列是否为空的函数
        bool IsEmpty() {
            if(front == frear) {
                return true;
            }
            return false;
        }
};

maze creatMaze();
// 用来判断这个迷宫是否可以走的函数，如果这个迷宫是可以走的那么就可以返回一个true
bool IsSuccess(maze temp);