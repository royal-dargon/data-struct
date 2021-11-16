//��ѭ������һ��Ԫ�ؿռ䡱��Լ��
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef BiTree QElemType;
typedef int Boolean; // Boolean�ǲ�������,��ֵ��TRUE��FALSE
 
#define TRUE 1
#define FALSE 0

typedef struct
{
	QElemType * elem;
	int front;
	int rear;
	int queuesize;
	int incrementsize;
}SqQueue;

void InitQueue_Sq(SqQueue &Q, int elenum)    //elenumΪ�������洢��Ԫ�ظ���
{
	Q.elem = new QElemType[elenum+1];  //����ʵ��ռ�õĴ洢�ռ�������һ��Ԫ�ؿռ�δ�ã�
	Q.queuesize = elenum+1;  //ģ�Ĵ�С
	Q.front = Q.rear = 0;
}

int QueueLength_Sq(SqQueue Q)
{
	return (Q.rear - Q.front + Q.queuesize) % Q.queuesize;
}

void incrementQueuesize(SqQueue &Q)
{
	int k;
	QElemType * a = new QElemType[Q.queuesize + Q.incrementsize];
	for(k = 0 ; k < Q.queuesize - 1 ; k++)
		a[k] = Q.elem[(Q.front + k ) % Q.queuesize];  //��Ųԭѭ�������е�����Ԫ��
	delete []Q.elem;   //�ͷ�ԭռ����ռ�
	Q.elem = a;      //ΪQ.elem�����µ�����λ��
	Q.front = 0;     //�����µ�ͷ��β��ָ�롱 
	Q.rear = Q.queuesize - 1;
	Q.queuesize += Q.incrementsize;
}

void EnQueue_Sq(SqQueue &Q, BiTree e)
{
	if((Q.rear + 1) % Q.queuesize == Q.front )
		incrementQueuesize(Q);
	Q.elem[Q.rear] = e;
	Q.rear = (Q.rear + 1) % Q.queuesize;
}

Boolean DeQueue_Sq(SqQueue &Q, QElemType &e)
{
	if ( Q.front == Q.rear)
		return FALSE;
	e = Q.elem[Q.front];
	Q.front = (Q.front + 1) % Q.queuesize;
	return TRUE;
}

Boolean GetHead_Sq(SqQueue Q, QElemType &e)
{
	if ( Q.front == Q.rear)
		return FALSE;
	e = Q.elem[Q.front];
	return TRUE;
}

Boolean QueueEmpty(SqQueue Q)
{
	if(Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}