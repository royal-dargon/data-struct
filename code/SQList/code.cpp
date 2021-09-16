#include <iostream>

using namespace std;

class SqList{
    private:
        int* elem;
        int  length;
        int  listsize;
    public:
        void InitList_Sq();
        SqList(){
            length = 0;
            listsize = 0;
        }
        void Insert_Sq(SqList & L,int i,int Elem);
        void Show_Sq();
        void Increatment(SqList & L);
        // find a element if successful return the place else return NuLL
        int Local_Sq(int Elem);
        // delete a number in the list. return the number
        int List_Delete_Elem(int p);
};

int main()
{
    SqList L;
    L.InitList_Sq();
    L.Insert_Sq(L,1,1);
    L.Insert_Sq(L,1,2);
    L.Insert_Sq(L,1,3);
    L.Insert_Sq(L,1,4);
    L.Insert_Sq(L,1,5);
    L.Insert_Sq(L,1,6);
    L.Insert_Sq(L,1,7);
    L.Show_Sq();
    cout<<"the place of the value is "<<L.Local_Sq(5)<<endl;
    cout<<"the delete number is "<<L.List_Delete_Elem(L.Local_Sq(5))<<endl;
    L.Show_Sq();
    cout<<"the place of the value is "<<L.Local_Sq(5)<<endl;
}

void SqList::InitList_Sq()
{
    length = 0;
    listsize = 5;
    elem = new int[listsize];
    cout<<"init is successfully! "<<"The listsize is "<<listsize<<endl;
}

void SqList::Insert_Sq(SqList & L,int i,int Elem)
{
    if(i > length+1 || i <= 0)
    {
        cout<<"the place is invalid"<<endl;
        return;
    }
    if(length >= listsize){
        cout<<"the memery will be allocated again！"<<endl;
        Increatment(L);
    }
    int j;
    for(j = length;j >= i;j --)
    {
        elem[j] = elem[j-1];
    }
    length ++;
    elem[j] = Elem;
}

void SqList::Show_Sq()
{
    int i;
    cout<<"the list value is "<<endl;
    for(i = 0;i < length;i ++)
    {
        cout<<elem[i]<<"\t";
    }
    cout<<endl;
    cout<<"the length is "<<length<<" the listsize is "<<listsize<<endl;
}

void SqList::Increatment(SqList & L)
{
    int* a;
    a = new int[L.listsize + 5];
    int i;
    for(i = 0;i < L.length;i ++)
    {
        a[i] = L.elem[i];
    }
    L.elem = a;
    L.listsize = L.listsize + 5;
}

int SqList::Local_Sq(int Elem)
{
    int i;
    for(i = 0;i < length;i ++)
    {
        if(elem[i] == Elem)
            return (i+1);
    }
    cout<<"not found "<<endl;
    return NULL;
}

int SqList::List_Delete_Elem(int p)
{
    if(p <= 0 || p > length)
    {
        cout<<"the place is invalid "<<endl;
        return NULL;
    }
    int i;
    int temp = elem[p-1];
    for(i = p;i < length;i ++)
    {
        elem[i-1] = elem[i];
    }
    length --;
    return temp;
}