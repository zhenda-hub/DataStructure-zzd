// 线性表练习.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <stdlib.h>//malloc free 的头文件

#define InitSize 10
struct SCusto
{
	/*int Sum;
	int PhoneNum;*/
    int* data;
    int Maxsize;//顺序表最大容量
    int length;//顺序表当前长度
};

void InitList(SCusto &L)
{
    L.data = (int*)malloc(sizeof(int) * InitSize);
    L.Maxsize = InitSize;
    L.length = 0;
}

void AddListSize(SCusto &L, int len)//增加顺序表长度
{
    int* p = L.data;//用p临时存储之前data
    L.data = (int*)malloc(sizeof(int) * (L.Maxsize + len));//申请新的内存空间
    for (int i=0; i<L.length; i++)
    {
        L.data[i] = p[i];
    }
    L.Maxsize += len;
    free(p);
}

bool InsertList(SCusto& L, int index, int value)
{
    if (index>L.length||index<1)
    {
        return false;
    }


    for (int i=L.length; i>=index; i--)//移动元素,让地方
    {
        L.data[i] = L.data[i - 1];
    }
    L.data[index - 1] = value;//插入值
	L.length++;//当前长度+1


    return true;
}

bool DeleteList(SCusto& L, int i, int& e)
{
    if (i<1 ||  i>L.length)
    {
        return false;
    }

    e = L.data[i - 1];//显示被删除元素
    for (int j=i; j<L.length; j++)//前移动元素
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;



    return true;
}

int FindList(SCusto& L, int value)//返回位置 所以用 int函数
{
    for (int i=0; i<L.length; i++)
    {
        if (L.data[i] == value)
        {
            return i + 1;
        }
    }

}

int main()
{
    std::cout << "Hello World!\n";

    SCusto L;

    InitList(L);
    AddListSize(L, 5);
    InsertList(L, 3, 11);
    int e = -1;
    if (DeleteList(L, 3, e))
    {
        printf("delete ok, 元素是%d\n", e);
    }
    else
    {
        printf("i 不合法, delete NG");
    }
    FindList(L, 11);



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
