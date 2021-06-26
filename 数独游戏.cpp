// 数独游戏.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "process.h"
using namespace std;
void Find_srand(int root[],int size);
void Generating_sudoku(int accord[4][4], int sque[][4], int root[4], int answer[][4]);
int Find_element(int root[], int accord[][4], int i, int j);
void Print_new(int sque[][4]);
void Show();
void Random_space(int space[][4], int x);
void Print_puzzle(int sque[][4], int space[][4]);
int main()
{
	
	Show();
}
/*Show函数  作为界面菜单*/
void Show()
{
	while (1)
	{
		int sque[4][4] = { {3,1,4,2},{4,2,3,1},{1,3,2,4},{2,4,1,3} };
		int accord[4][4] = { {3,1,4,2},{4,2,3,1},{1,3,2,4},{2,4,1,3} };
		int root[4] = { 0 };
		int answer[4][4] = { 0 };
		int space[4][4] = { 0 };
		cout << "***********************自动生成4*4数独***********************" << endl;
		cout << "***********************1、简单模式    ***********************" << endl;
		cout << "***********************2、中等模式    ***********************" << endl;
		cout << "***********************1、困难模式    ***********************" << endl;
		cout << "请输入你的选择：";
		int choose;
		char choose2, choose3;
		cin >> choose;
		Find_srand(root, 4);
		Generating_sudoku(accord, sque, root, answer);
		Random_space(space, choose);
		Print_puzzle(sque, space);

		cout << "是否显示答案：Y/N" << endl;
		cin >> choose2;
		if (choose2 == 'Y' || choose2 == 'y')
		{
			Print_new(sque);
			system("pause");
		}
		else if (choose2 == 'N' || choose2 == 'n')
		{
			system("pause");
		}
		
		system("cls");
	}

}
/*进行游戏难度选择，数独的空格数控制*/
void Random_space(int space[][4],int x)
{
	if (x == 1)/*难度为简单 有6个空格*/
	{

		int k = 0;
		int i, j = 0;
		unsigned seed;
		seed = time(0);
		srand(seed);
		for (k = 0;k < 6;)
		{
			i = rand() % 4 ;
			j = rand() % 4 ;
			if (space[i][j] != 1)
			{
				space[i][j] = 1;
				k++;
			}
		}
	}
	else if (x == 2)/*难度为中等 有9个空格*/
	{
		int k = 0;
		int i, j = 0;
		unsigned seed;
		seed = time(0);
		srand(seed);
		for (k = 0;k < 9;)
		{
			i = rand() % 4;
			j = rand() % 4;
			if (space[i][j] != 1)
			{
				space[i][j] = 1;
				k++;
			}
		}
	}
	else if (x == 3)/*难度为简单 有12个空格*/
	{
		int k = 0;
		int i, j = 0;
		unsigned seed;
		seed = time(0);
		srand(seed);
		for (k = 0;k < 12;)
		{
			i = rand() % 4 ;
			j = rand() % 4 ;
			if (space[i][j] != 1)
			{
				space[i][j] = 1;
				k++;
			}
		}
	}
	else
	{
		cout << "非法选择，请重新选择" << endl;
	}
}
/*随机数独的构建*/
void Generating_sudoku(int accord[4][4], int sque[][4], int root[4],int answer[][4])
{
	int i, j = 0;
	for (i = 0;i < 4;i++)
	{
		for (j = 0;j < 4;j++)
		{
			int a = Find_element(root, accord, i, j);
			if (a >= 4)
			{
				answer[i][j] = root[a % 4];
			}
			else
			{
				answer[i][j] = root[a];
			}
		}
	}
}
/*获取四宫格每一个数*/
int Find_element(int root[], int accord[][4], int i, int j)
{
	int element, k = 0;
	for (k = 0;k < 4;k++)
	{
		if (accord[i][j] == root[k])
		{
			
			return (k + 1);
			
		}
	}
}
/*对比长度为4的root数组是否有数据重复*/
void Find_srand(int root[],int size)
{
	
	for (int i = 0;i < 4;i++)
	{
		unsigned seed;
		seed = time(0);
		srand(seed);
		int iTem = rand() % 4 + 1;
		bool testRepetition(int root[], int newNum, int ilength);//定义函数 判断新产生的随机数是否与前面有重复值3
		while (!testRepetition(root, iTem, 4))
		{
			iTem = rand() % 4 + 1;
		}
		root[i] = iTem;
	}
}
/*判断重复数，为Find_srand的判定*/
bool testRepetition(int root[], int newNum, int ilength)
{
	for (int i = 0;i < 4;i++)
	{
		if (root[i] == newNum)
		{
			return false;
		}
	}
	return true;
	
}
/*展示随机构成的数独*/
void Print_new(int sque[][4])
{
	int i, j = 0;
	cout << "\n随机生成的数独的答案" << endl;
	for (i = 0;i < 4;i++)
	{
		for (j = 0;j < 4;j++)
		{
				cout << sque[i][j] << " ";
		}
		cout << endl;
	}
}
/*展示数独谜题*/
void Print_puzzle(int sque[][4], int space[][4])
{
	int i, j = 0;
	cout << "随机生成的简单数独" << endl;
	for (i = 0;i < 4;i++)
	{
		
		for (j = 0;j < 4;j++)
		{
			if (space[i][j] == 1)
			{
				cout << "  ";
			}
			else
			{
				cout << sque[i][j] << " ";
			}
			
		}
		cout << endl;
	}
}
