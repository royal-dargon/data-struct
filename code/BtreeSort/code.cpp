// 按照书上的案例实现二叉树排序
#include <iostream>

using namespace std;

struct BiTree {
    int data;
    BiTree *lchild, *rchild;
};

void Insert_BST(BiTree **T,int value) {
    BiTree *s = new struct BiTree;
    s->data = value;
    s->lchild = NULL;
    s->rchild = NULL;
    //cout << "i" << " ";
    if(*T == NULL) {
        *T = s;
    } else {
        //cout << "i ";
        BiTree *p = *T;
        //cout << p->data << " ";
        BiTree *f;
        // 遵循左小右大
        // 查找插入的位置
        while(p) {
            //cout << "! ";
            if(value < p->data) {
                f = p;
                p = p->lchild;
            } else {
                f = p;
                p = p->rchild;
            }
        }
        if(value < f->data) {
            f->lchild = s;
        } else {
            f->rchild = s;
        }
        //cout << value << " ";
    }
}

void InShow(BiTree *Node) {
    if(Node) {
        InShow(Node->lchild);
        cout << Node->data << " ";
        InShow(Node->rchild);
    }
}

void BTSort(int arr[],int lenth) {
    BiTree *T = NULL;
    int i;
    for(i = 0;i < lenth;i ++) {
        //cout << arr[i] << " ";
        Insert_BST(&T,arr[i]);
    }
    // 中序遍历
    InShow(T);
}


int main() {
    int arr[] = {1,5,8,9,14,16,2,3};
    for(int i = 0;i < 8;i ++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    BTSort(arr,8);
    //for(int i = 0;i < 8;i ++) {
    //    cout << arr[i] << " ";
    //}
    return 0;
}