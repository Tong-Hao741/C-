//�������Ļ��������㷨
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node 
{	
	ElemType data;			//����Ԫ��
	struct node *lchild;	//ָ�����ӽڵ�
	struct node *rchild;	//ָ���Һ��ӽڵ�
} BTNode;
 
================================================================================= 
void CreateBTree(BTNode * &b,char *str)	//����������
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//�����Ķ�������ʼʱΪ��
	ch=str[j];
	while (ch!='\0')  	//strδɨ����ʱѭ��
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		//Ϊ���ӽڵ�
		case ')':top--;break;
		case ',':k=2; break;                      		//Ϊ���ӽڵ��ҽڵ�
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (b==NULL)                    	 	//*pΪ�������ĸ��ڵ�
					b=p;
				else  								//�ѽ������������ڵ�
				{	
					switch(k) 
					{
					case 1:St[top]->lchild=p;break;
					case 2:St[top]->rchild=p;break;
					}
				}
		}
		j++;
		ch=str[j];
	}
}
==================================================================================== 
void DestroyBTree(BTNode *&b)
{	if (b!=NULL)
	{	DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
BTNode *FindNode(BTNode *b,ElemType x) 
{
	BTNode *p;
	if (b==NULL)
		return NULL;
	else if (b->data==x)
		return b;
	else  
	{
		p=FindNode(b->lchild,x);
		if (p!=NULL) 
			return p;
		else 
			return FindNode(b->rchild,x);
	}
}
BTNode *LchildNode(BTNode *p)
{
    return p->lchild;
}
BTNode *RchildNode(BTNode *p)
{
    return p->rchild;
}
int BTHeight(BTNode *b) 
{
   	int lchildh,rchildh;
   	if (b==NULL) return(0); 				//�����ĸ߶�Ϊ0
   	else  
	{
		lchildh=BTHeight(b->lchild);	//���������ĸ߶�Ϊlchildh
		rchildh=BTHeight(b->rchild);	//���������ĸ߶�Ϊrchildh
		return (lchildh>rchildh)? (lchildh+1):(rchildh+1);
   	}
}
void DispBTree(BTNode *b) 
{
	if (b!=NULL)
	{	printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{	printf("(");						//�к��ӽڵ�ʱ�����(
			DispBTree(b->lchild);				//�ݹ鴦��������
			if (b->rchild!=NULL) printf(",");	//���Һ��ӽڵ�ʱ�����,
			DispBTree(b->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽڵ�ʱ�����)
		}
	}
}
//ǰ�� 
void PreOrder(BTNode *b)
{
	if(b)
	{
		printf("%c",b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
//ǰ��ǵݹ����
void PreOrder2(BTNode *b)
{
	BTNode *St[MaxSize];
	int top = -1;
	top++;
	St[top] = b;
	while(top!=-1){
		b = St[top];
		printf("%c",b->data);
		top--;
		if(b->rchild!=NULL){
			top++;
			St[top] = b->rchild;
		}
		if(b->lchild!=NULL){
			top++;
			St[top] = b->lchild;
		}
	}
} 
//���� 
void InOrder(BTNode *b)
{
	if(b)
	{
		InOrder(b->lchild);
		printf("%c",b->data);
		InOrder(b->rchild);
	}
}
//����ǵݹ����
void InOrder2(BTNode *b)
{
	BTNode *St[MaxSize];
	int top = -1;
	while(b!=NULL||top!=-1){
		if(b){
			top++;
			St[top] = b;
			b = b->lchild;
			
		}
		else{
			b = St[top];
			printf("%c",b->data);
			top--;
			b = b->rchild;
		}
	}
} 
//���� 
void PostOrder(BTNode *b)
{
	if(b)
	{
		
		PostOrder(b->lchild);
		PostOrder(b->rchild);
		printf("%c",b->data);
	}
}
int main()
{
	BTNode *b;
	CreateBTree(b,"A(B(D,E),C(,F))");
	printf("���Ľṹ��");DispBTree(b);
	printf("\n");
	printf("ǰ�����У�");PreOrder(b);printf("\n");
	printf("�������У�");InOrder(b);printf("\n");
	printf("�������У�");PostOrder(b);printf("\n");
	printf("%d",BTHeight(b));
	printf("\n");
	InOrder2(b);printf("\n");
	PreOrder2(b);
	return 0;
}

