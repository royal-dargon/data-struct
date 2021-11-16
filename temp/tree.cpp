#include "Queue_Sq.h"

void CreateBiTree(BiTree &T){
	char ch;
	cin>>ch;
	if(ch=='#') T=NULL;
	else{
		T=new BiTNode;
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

void Inorder(BiTree T){
	if(T){
		Inorder(T->lchild);
		cout<<T->data;
		Inorder(T->rchild);
	}
}

void Postorder(BiTree T){
	if(T){
		Postorder(T->lchild);
		Postorder(T->rchild);
		cout<<T->data;
	}
}

void Levelorder(BiTree T){
	SqQueue q;
	BiTree p;
	//cout << T->data << endl;
	if(T){
		InitQueue_Sq(q,100);
		EnQueue_Sq(q,T);
		while(!QueueEmpty(q))
		{
			DeQueue_Sq(q, p);
			cout<<p->data;
			if(p->lchild) EnQueue_Sq(q,p->lchild);
			if(p->rchild) EnQueue_Sq(q,p->rchild);
			//cout << "1" << endl;
		}
	}
}

int main(){
	BiTree T;
	cout<<"����������룺";
	CreateBiTree(T);
	cout<<"������������";
	Inorder(T);
	cout<<endl<<"������������";
	Postorder(T);
  	cout<<endl<<"��α��������";
  	Levelorder(T);
	cout<<endl;
	return 0;
}