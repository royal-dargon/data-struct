#include <iostream>
using namespace std;

class Solution{
    private:
        int *elem;
        int lenth;
        int listSize;
    public:
        Solution(){
            lenth = 0;
            elem = new int[10];
            listSize = 10;
        }
        void Insert(int Elem);
        void Show(){
            int i;
            for(i = 0;i < lenth;i ++)
            {
                cout<<elem[i]<<" ";
            }
            cout<<"\n";
        }
        void Pop_sort();
};

int main()
{
    Solution a1;
    a1.Insert(2);
    a1.Insert(3);
    a1.Insert(8);
    a1.Insert(9);
    a1.Insert(1);
    a1.Insert(5);
    a1.Show();
    a1.Pop_sort();
    a1.Show();
    return 0;
}

void Solution::Insert(int Elem)
{
    elem[lenth] = Elem;
    lenth ++;
    //cout<<lenth;
}


// 复杂度O(n*n)
void Solution::Pop_sort()
{
    int i,j;
    i = lenth;
    while (i > 1)
    {
        int Last = 1;
        for(j = 1;j < i;j ++)
        {
            if(elem[j] > elem[j-1])
            {
                int temp = elem[j];
                elem[j] = elem[j-1];
                elem[j-1] = temp;
                Last = j;
            }
        }
        i = Last;
    }   
}