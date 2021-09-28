#include<stdio.h>

#include<stdlib.h>

#include<time.h>



#define NUM 9

int sort_data[NUM];



void mix_data(int *index,int num);//获得随机的排列

void bogo_sort(int *data,int num);

int main(void)

{
      int i;

      clock_t start,end;//时间测试，start和end



      for(i=0;i<NUM;i++)

      {
             sort_data[i]=rand();

      }



      start=clock();//计时开始



      bogo_sort(sort_data,NUM);



      end=clock();//计时结束



      printf("elapse time is %d",end-start);

      return 0;

}



void mix_data(int *index,int num)//得到随机索引数组

{
      int i,j;

      int temp;

      int *flag;

      int flag_random=0;

      flag=(int *)malloc(sizeof(int)*num);

      for(i=0;i<num;i++)

      {
             flag[i]=-1;

      }



      i=0;

      while(1)

      {


             temp=rand()%num;

             if(-1==flag[temp])

             {
                    flag[temp]=temp;

                    index[i]=temp;

                    i++;

             }

             for(j=0;j<num;j++)

             {
                    if(j!=flag[j])

                           break;

             }

             if(num==j)

                    break;

      }



}



void bogo_sort(int*data,int num)

{
      int *index;

      int i;

      int flag=0;



      if(1==num)

             return;

      index=(int *)malloc(sizeof(int)*num);



      for(i=0;i<num;i++)//只是对索引数组的排序，不移动原来的数据

      {
             index[i]=-1;

      }

      while(1)

      {
             mix_data(index,num);

             for(i=1;i<num;i++)

             {
                    if( data[index[i]] <data[index[i-1]] )

                    {
                           break;

                    }



             }

             if(i==num)

                    break;

      }



      for(i=0;i<num;i++)//输出排序后的数组

      {
             printf("%d\n",data[index[i]]);

      }



      free(index);

      index=NULL;



}