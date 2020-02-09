/*
创建者	:	XTT
功能	:

时间	:	2020/02/01
*/
#include "Snake.h"
#include <stdlib.h>
#include <ctime>
#include <conio.h>
#include <iostream>

using namespace std;

void Test();
void SnakeTest();

int main()
{
	initgraph(ScreenWidth, ScreenHeight);

	Test();
	cleardevice();

	closegraph();
	system("pause");
	return 0;
}

void Test()
{
	Map();

	list<Snake> S;
	Snake* s1 = new Snake[3];					//蛇全身节点

	S.push_back(*s1);						//塞给链表
	Create_snake(S);
	Refresh_food('w',S);

	while (1)
	{
		char C = _getch();
		TracePrint(_T("按下%c键\n"),C);
		Control_snake(C, S);
		Refresh_food(C,S);
//		Connect_snake(S);
//		////Growth_snake(C, S);
		Entry_snake(S);
//
		Show_map();
	}



}

void SnakeTest()
{
	list<Snake> S;
	int x = rand() % (N - 2) + 1;
	int y = rand() % (M - 5) + 1;
	Snake s1(x, y);
	Snake s2(x, y - 1);
	Snake s3(x, y - 2);
	S.push_back(s1);
	S.push_back(s2);
	S.push_back(s3);
	printList(S);
}