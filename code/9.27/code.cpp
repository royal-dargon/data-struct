#include  <iostream>
using namespace std;

class Solution{
    private:
        int elem;
        int *value;
        int res;
    public:
        Solution(int i)
        {
            value = new int[10];
            elem = i;
            res = i;
        }
        bool IsTrue()
        {
            bool flag = true;
            int count = 0;
            int i,j;
            while(elem != 0)
            {   
                int temp = elem % 10;
                value[count++] = temp;
                elem = elem/10;
            }
            j = count-1;
            for(i = 0;i <= j;i++)
            {
                if(value[i] != value[j])
                {
                    flag = false;
                    break;
                }
                j --;
            }
            return flag;
        }
};

int main()
{
    int i = 11;
    while(i <= 999)
    {
        bool flag1,flag2,flag3;
        Solution temp1(i);
        flag1 = temp1.IsTrue();
        Solution temp2(i*i);
        flag2 = temp2.IsTrue();
        Solution temp3(i*i*i);
        flag3 = temp3.IsTrue();
        if(flag1 == true&&flag2 == true&&flag3 == true)
        {
            cout<<i<<" ";
        }
        i++;
    }
    return 0;
}