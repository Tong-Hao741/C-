//二叉树的基本运算算法
#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;
typedef struct node 
{	
	ElemType data;			//数据元素
	struct node *lchild;	//指向左孩子节点
	struct node *rchild;	//指向右孩子节点
} BTNode;
 
================================================================================= 
void CreateBTree(BTNode * &b,char *str)	//创建二叉树
{
	BTNode *St[MaxSize],*p=NULL;
	int top=-1,k,j=0;  
	char ch;
	b=NULL;				//建立的二叉树初始时为空
	ch=str[j];
	while (ch!='\0')  	//str未扫描完时循环
	{
   	   	switch(ch) 
		{
		case '(':top++;St[top]=p;k=1; break;		//为左孩子节点
		case ')':top--;break;
		case ',':k=2; break;                      		//为孩子节点右节点
		default:p=(BTNode *)malloc(sizeof(BTNode));
				p->data=ch;p->lchild=p->rchild=NULL;
				if (b==NULL)                    	 	//*p为二叉树的根节点
					b=p;
				else  								//已建立二叉树根节点
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
   	if (b==NULL) return(0); 				//空树的高度为0
   	else  
	{
		lchildh=BTHeight(b->lchild);	//求左子树的高度为lchildh
		rchildh=BTHeight(b->rchild);	//求右子树的高度为rchildh
		return (lchildh>rchildh)? (lchildh+1):(rchildh+1);
   	}
}
void DispBTree(BTNode *b) 
{
	if (b!=NULL)
	{	printf("%c",b->data);
		if (b->lchild!=NULL || b->rchild!=NULL)
		{	printf("(");						//有孩子节点时才输出(
			DispBTree(b->lchild);				//递归处理左子树
			if (b->rchild!=NULL) printf(",");	//有右孩子节点时才输出,
			DispBTree(b->rchild);				//递归处理右子树
			printf(")");						//有孩子节点时才输出)
		}
	}
}
//前序 
void PreOrder(BTNode *b)
{
	if(b)
	{
		printf("%c",b->data);
		PreOrder(b->lchild);
		PreOrder(b->rchild);
	}
}
//前序非递归遍历
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
//中序 
void InOrder(BTNode *b)
{
	if(b)
	{
		InOrder(b->lchild);
		printf("%c",b->data);
		InOrder(b->rchild);
	}
}
//中序非递归遍历
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
//后序 
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
	printf("树的结构：");DispBTree(b);
	printf("\n");
	printf("前序序列：");PreOrder(b);printf("\n");
	printf("中序序列：");InOrder(b);printf("\n");
	printf("后序序列：");PostOrder(b);printf("\n");
	printf("%d",BTHeight(b));
	printf("\n");
	InOrder2(b);printf("\n");
	PreOrder2(b);
	return 0;
}

