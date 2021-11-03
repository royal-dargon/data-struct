// 写一个堆排序的demo
#include <iostream>
#include <string.h>

using namespace std;

class SqlTable {
    public:
        int *elem;
        int lenth;
        int Maxsize;
        SqlTable(int maxsize) {
            // 表示现在顺序表里面还是没有添加一个元素
            lenth = 0;
            Maxsize = maxsize;
            elem = new int[maxsize];
        }
        void Insert(int arr[],int len) {
            // 测量传入的数组的长度
            //int len = sizeof(arr)/sizeof(arr[0]);
            int i;
            //cout << len << endl; 
            for(i = 0;i < len;i ++) {
                elem[i] = arr[i];
            }
            lenth = len;
        }
        void Show() {
            int j;
            for(j = 0;j < lenth;j ++) {
                cout << elem[j] << " ";
            }
            cout << endl;
        }
        // 将每个树变成大顶堆的函数
        // 这是一个自上而下的过程
        void HeapAdjust(int begin,int len) {
            // 先计入这个根元素
            int temp = elem[begin];
            int j;
            for(j = begin * 2 + 1;j < len;j *= 2 + 1) {
                // 指向较大的子节点
                if(j + 1 < len && elem[j+1] > elem[j]) {
                    j ++;
                }
                if(elem[j] > temp) {
                    elem[begin] = elem[j];
                    begin = j;
                } else {
                    break;
                }
            }       
            elem[begin] = temp;
        }
        // 进行堆排序的函数
        void HeapSort() {
            int tmp = lenth;
            // 确定最后一个非叶子节点
            int i;
            // 自下而上构成大顶堆
            for(i = lenth/2 - 1;i >= 0;i --) {
                HeapAdjust(i,lenth);
            }
            // 交换最后一个和第一个
            int temp = elem[0];
            elem[0] = elem[tmp-1];
            elem[tmp-1] = temp;
            for(i = lenth-1; i > 0; i --) {
                HeapAdjust(0,i);
                temp = elem[0];
                elem[0] = elem[i-1];
                elem[i-1] = temp; 
            }
        }
};

int main() {
    SqlTable temp(100);
    int arr[] = {1,8,9,7,6,4,5,2,3};
    temp.Insert(arr,9);
    temp.Show();
    temp.HeapSort();
    temp.Show();
    return 0;
}