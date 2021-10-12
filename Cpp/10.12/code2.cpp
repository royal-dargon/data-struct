// 教材第266页 第七大题第七小题
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

void getNext(char str[],int next[]);
bool KMP(char str[],char tar[]);

class String {
    private:
        char * Str;
    public:
        String(char *str) {
            int lenth = strlen(str);
            Str = new char[lenth+1];
            strcpy(Str,str);
            cout<<Str<<endl;
        }
        bool IsSubstring(char *str) {
            bool res = KMP(Str,str);
            cout<<res<<endl;
            return res;
        }
        bool IsSubstring(const String & str) {
            bool res = KMP(Str,str.Str);
            cout<<res<<endl;
            return res;
        }
        int str2num() {
            int res = 0,i;
            int lenth = strlen(Str);
            int temp = lenth;
            for(i = 0;i < lenth;i ++) {
                res = (Str[i]-48)*pow(10,temp-1) + res;
                temp --;
            }
            return res;
        }
        void toUppercase() {
            int lenth = strlen(Str);
            int i;
            for(i = 0;i < lenth;i ++) {
                if(Str[i] >= 'a' && Str[i] <= 'z') {
                    Str[i] = Str[i] - 32;
                }
            }
            cout<<Str<<endl;
        }
};

int main() 
{
    char temp[] = "abccc";
    char temp2[] = "12";
    String str1(temp);
    String str2(temp2);
    String tmp(temp);
    char temp1[] = "cb";
    str1.IsSubstring(temp1);
    str1.IsSubstring(str2);
    int res = str2.str2num();
    cout<<res<<endl;
    str1.toUppercase();
    return 0;
}

void getNext(char str[],int next[]) {
    int j = 0;
    int i,k,m;
    int flag;
    for(i = 0;i < strlen(str);i ++) {
        for(k = i;k > 0;k --) {
            for(m = 0;m < k;m ++) {
                if(str[m] != str[i+1-k+m])
                    break;
            }
             if(m == k)
            {
                next[i] = k;
                break;
            }
        }
    }
}

bool KMP(char str[],char tar[])
{
    int i = 0;
    int j = 0;
    int lengh;
    int next[100];
    bool res = false;
    lengh = strlen(tar);
    memset(next,0,100*sizeof(int));
    getNext(tar, next);
    while(str[i] != '\0')
    {
        if(str[i] == tar[j])
        {
            i ++;
            j ++;
        } else {
            if(j == 0)
            {
                i ++;
            }
            j = next[j];
        }
        if(j == lengh)
        {
            res = true;
            return res;
        }
    }
    return res;
}
