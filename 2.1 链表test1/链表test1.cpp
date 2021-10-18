// 链表test1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L)
{
	//不带头节点
	/*L = NULL;
	return true;*/
	L = (LNode *)malloc(sizeof(LNode));
	if (L==NULL)
	{
		return false;
	}
	L->next = NULL;//节点尾部设置NULL
	return true;
}

bool IsEmpty(LinkList &L)
{
	//不带头节点
	//return (L == NULL);
	return(L->data == NULL);
}

bool InsertNextNode(LNode* p, int e)//把e插在p后面
{
	if (p == NULL)
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));//插入
	if (s == NULL)
	{
		return false;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;

	return true;
}

bool InsertPriorNode(LNode* p, int e)//前插操作
{
	if (p == NULL)
	{
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if (s == NULL)
	{
		return false;
	}
	s->next = p->next;//节点操作
	p->next = s;

	//插入e
	s->data = p->data;
	p->data = e;

	return true;
}

LNode* GetElem(LinkList& L, int i)//位查找
{
	if (i < 0)
	{
		return NULL;
	}

	LNode* p;
	p = L;
	int j = 0;
	while (p != NULL && j < i)//寻找i节点
	{
		p = p->next;
		j++;
	}
	return p;
}

LNode* GetValueElem(LinkList& L, int e)//值查找
{
	LNode* p = L->next;
	if (p!=NULL && p->data!=e)
	{
		p = p->next;
	}
	return p;
}

int GetListLength(LinkList& L)//list 长度
{
	int len = 0;
	LNode* p = L;
	while (p->next != NULL)//从头到尾 查找
	{
		p = p->next;
		len++;
	}
	return len;
}

bool ListInsert(LinkList &L, int i, int e)
{
	
	LNode* p = GetElem(L, i-1);
	return InsertNextNode(p, e);

}

bool DeleteNode(LNode* p)//指定节点删除
{
	if (p==NULL)
	{
		return false;
	}
	LNode* q = p->next;//只是删除了p的值
	p->data = q->data;
	p->next = q->next;
	free(q);

	return true;
}

bool ListDelete(LinkList& L, int i, int& e)//指定位置删除
{
	LNode* p = GetElem(L, i-1);

	if (p==NULL || p->next==NULL)
	{
		return false;
	}
	LNode* q = p->next;
	e = q->data;
	p->next = q->next;
	free(q);


	return true;
}

LinkList ListTailInsert(LinkList& L, int x)
{
	
	
	InitList(L);
	int tail = GetListLength(L);
	LNode* p = GetElem(L, tail);
	InsertNextNode(p, x);

	return L;
}

LinkList ListHeadInsert(LinkList& L, int x)
{
	InitList(L);
	InsertNextNode(L, x);
	return L;

}

int main()
{
	LinkList L;
	InitList(L);
    
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
