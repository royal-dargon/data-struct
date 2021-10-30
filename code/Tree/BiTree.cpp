// 这个文件主要是为了实现二叉树的一些基本操作
// 主要是为了实现二叉树的链式存储
#include <iostream>

using namespace std;

// 构建一个表示二叉树的节点的结构体
struct BiTree
{
    int elem;
    BiTree *left,*right;
};

class Tree {
    public:
        // 创建节点的方式
        BiTree* initTree();
        // 通过先序的方式对二叉树进行遍历
        void PreShow(BiTree *Node);
        // 通过中序遍历的方式遍历二叉树
        void InShow(BiTree *Node);
        // 通过后序遍历二叉树
        void PostShow(BiTree *Node);
};

int main(){
    Tree temp;
    BiTree *Node = temp.initTree();
    temp.PostShow(Node);
    return 0;
}

// 这里采用的是先序遍历的方式去构建一个二叉树
BiTree* Tree::initTree() {
    cout << "creating-----" << endl;
    cout << "please put in a number " << endl;
    int data;
    cin >> data;
    BiTree *Node = new struct BiTree;
    Node->elem = data;
    cout << "do you want to continue!(1/0)" << endl;
    int temp = 1;
    cin >> temp;
    if(temp == 1) {
        Node->left = initTree();
        Node->right = initTree();
    } else {
        Node->left = NULL;
        Node->right = NULL;
    }
    return Node;
}

void Tree::PreShow(BiTree *Node) {
    //cout << "this is the way of preshow!" << endl;
    if(Node) {
        cout << Node->elem << endl;
        PreShow(Node->left);
        PreShow(Node->right);
    }
}

void Tree::InShow(BiTree *Node) {
    if(Node) {
        InShow(Node->left);
        cout << Node->elem << " ";
        InShow(Node->right);
    }
}

void Tree::PostShow(BiTree *Node) {
    if(Node) {
        PostShow(Node->left);
        PostShow(Node->right);
        cout << Node->elem << " ";
    }
}