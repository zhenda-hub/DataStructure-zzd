// 双链表test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

typedef struct DNode
{
    int data;
    struct DNode* prior, * next;
}DNode, *Dlinklist;

bool InitDLinklist(Dlinklist& L)
{
    L = (DNode*)malloc(sizeof(DNode));//一个头节点

    if (L == NULL)
    {
        return false;
    }

    L->prior = NULL;
    L->next = NULL;
    return true;
}

bool IsEmptyDLinklist(const Dlinklist& L)
{
    if (L->next == NULL)
    {
        return true;
    }
    return false;

}

bool InsertsDNode(DNode* p, DNode* s)
{
    if (p==NULL || s==NULL)
    {
        return false;
    }
    s->next = p->next;//s和下一个节点
    if (p->next != NULL)
    {
        p->next->prior = s;
    }

    s->prior = p;//s和上一个节点
    p->next = s;
    return true;
    
}

bool DeleteNextDNode(DNode *p)//删除next节点
{
    if (p == NULL)
    {
        return false;
    }
    DNode* q = p->next;//创建
    if (q == NULL)
    {
        return false;
    }

    if (q->next != NULL)
    {
        q->next->prior = p;//1
    }
    p->next = q->next;//2
 
    free(q);//3
    return true;
    
}

bool DestroyDLinklist(Dlinklist& L)
{
    while (L->next != NULL)
    {
        DeleteNextDNode(L);
    }
    free(L);
    L = NULL;
    return true;
    
}

int main()
{
    Dlinklist L;
    InitDLinklist(L);
    IsEmptyDLinklist(L);

    DestroyDLinklist(L);
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
