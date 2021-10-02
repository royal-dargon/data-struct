#include <iostream>
using namespace std;

class Stack{
    private:
        int *elem;
        int top;
        int stacksize;
    public:
        void InitStack();
        void ClearStack();
        void StackEmpty();
        int StackLength();
        int GetTop();
        void Push(int e);
        int Pop();
        void StackTraverse();
};

int main()
{
    Stack s;
    s.InitStack();
    s.Push(1);
    s.Push(2);
    s.StackTraverse();
    int res = s.Pop();
    s.StackTraverse();
    return 0;
}

void Stack::InitStack()
{
    this->top = -1;
    this->stacksize = 10;
    elem = new int[10];
}

void Stack::Push(int e)
{
    this->top = this->top + 1;
    elem[top] = e;
}

void Stack::StackTraverse(){
    int i;
    for(i = top;i >= 0;i --)
    {
        cout<<elem[i]<<" ";
    }
    cout<<endl;
}

int Stack::Pop()
{
    int res;
    res = elem[top];
    top = top - 1;
    return res;
}

void Stack::ClearStack()
{
    top = 0;
}