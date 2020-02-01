/*
创建者	:	XTT
功能	:

时间	:	2020/02/01
*/
#include "Snake.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <atltrace.h>
 
static int snake_length = 3;//蛇的长度(蛇身)
static int s = 0;

TCHAR s1[] = _T("贪吃蛇");
TCHAR s2[] = _T("记分板:");

Food food;  //定义食物的结构

char map[N][M];//地图数组

//创建贪吃蛇的地图
void Map()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (i == 0 || i == N - 1 || j == 0 || j == M - 1)
				map[i][j] = '*';
			else
				map[i][j] = ' ';
		}
	}
	printMap();
	//map[2][3] = '@';
	//map[2][4] = '+';
}


//更新地图
void Show_map()
{
	BeginBatchDraw();
	rectangle(0, 0, 400, 600);
	setcolor(RED);
	outtextxy(480, 50, s1);
	setcolor(WHITE);
	outtextxy(450, 90, s2);

	
	scores[0] = s / 100;
	scores[1] = (s / 10) % 10;
	scores[2] = s % 10;

	UCHAR s = scores[2] + '0';	//个位
	outtextxy(550, 90, s);
	s = scores[1] + '0';		//十位
	outtextxy(540, 90, s);
	s = scores[0] + '0';		//百位
	outtextxy(530, 90, s);

	rectangle(0, 0, 400, 600);
	//循环绘制每一个方块
	for (int i = 0; i < N; i++)		//y轴方向 480/20 这里得转过来
	{
		for (int j = 0; j < M; j++)	//x轴方向 取到400 留点记分板400/20
		{
			char ch = map[i][j];
			switch (ch)
			{
			case '*'://墙
				rectangle(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1);
				break;
			case '@'://蛇头
				solidroundrect(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1, 10, 10);
				break;
			case '+'://蛇身
				pie(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1, 10, 90);
				break;
			case '$'://食物
				ellipse(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1);
				break;
			case ' '://清空
				clearrectangle(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1);
				break;
			case 'X'://蛇尾
				solidroundrect(j * 20 + 1, i * 20 + 1, j * 20 + 20 - 1, i * 20 + 20 - 1, 50, 50);
				break;
			default:
				break;
			}
		}
	}
	FlushBatchDraw();
	Sleep(100);
	EndBatchDraw();
}

//刷新食物
void Refresh_food(char ch,list<Snake>& S)
{
	if ((food.x == S.front().x) && (food.y == S.front().y))
	{
		map[food.y][food.x] = ' ';
		s++;
		food.x = rand() % (M - 2) + 1;
		food.y = rand() % (N - 2) + 1;
		TracePrint("刷新食物成功");
		snake_length++;
		Growth_snake(ch, S);	
	}
	map[food.y][food.x] = '$';
	TracePrint(_T("食物 x = %d ,y = %d\n"), food.x, food.y);
}

//创建蛇
void Create_snake(list<Snake>& S)
{
	list<Snake> _S(S);					//临时链表容器
	srand((unsigned)time(NULL));				//产生随机种子
	Snake* snake = new Snake[snake_length];		//申请蛇头-蛇身-蛇尾 总共三节点
									//整头蛇
	//int x = rand() % (N - 2) + 1;
	//int y = rand() % (M - 5) + 1;
	for (int i = 0; i < snake_length; i++)
	{
		int _x = 10;
		int _y = 10 - i - 1;

		snake[i].x = _x;							//坐标赋值到蛇节点上
		snake[i].y = _y;

		_S.push_back(snake[i]);						//塞进链表
	}
#if 0
	TracePrint(_T("临时蛇\n"));
	printList(_S);
#endif // 0
	S = _S;										//返回给原来的链表
	TracePrint(_T("创建蛇成功\n"));	
#if 0
	TracePrint(_T("实际蛇\n"));
	printList(S);
#endif // 0
}
//录用蛇
void Entry_snake(list<Snake>& S)
{

	if (S.empty())
	{
		TracePrint(_T("录用蛇节点为空\n"));
		return;
	}
	else
	{
		int num = 0;
		list<Snake> _S(S);							//临时链表容器
		map[S.front().y][S.front().x] = '@';
		for (list<Snake>::iterator it = S.begin(); it != S.end(); it++)
		{
			char _x = it->x;
			char _y = it->y;
			if (0 == num)		//蛇头
			{
				map[_y][_x] = '@';
			}
			else if (snake_length == num)
			{
				map[_y][_x] = ' ';
			}
			else
			{
				map[_y][_x] = '+';
			}
			num++;
		}
	}
}

//蛇节点接
void Connect_snake(list<Snake>& S)
{
	char _x, _y, _x1, _y1;
	_x = S.front().x;
	_y = S.front().y;
	list<Snake>::iterator it = S.begin();
	//it++;
	for (; it != S.end(); it++)
	{
		_x1 = it->x;
		_y1 = it->y;
		it->x = _x;
		it->y = _y;
		_x = _x1;
		_y = _y1;
	}
	TracePrint("连接蛇\n");
	printList(S);
}


//对蛇的身体进行定位
void Growth_snake(char ch, list<Snake>& S)
{
	Snake s1;					//蛇全身节点
	S.push_back(s1);
	for (list<Snake>::iterator it = S.begin(); it != S.end(); it++)
	{
		char _x = it->x;
		char _y = it->y;
		switch (ch)
		{
		case 'w':
			it->x = _x;
			it->y = ++_y;
			break;
		case 's':
			it->x = _x;
			it->y = --_y;
			break;
		case 'a':
			it->x = ++_x;
			it->y = _y;
			break;
		case 'd':
			it->x = --_x;
			it->y = _y;
			break;
		default:
			break;
		}
	}
}
void Control_snake(char ch, list<Snake>& S)
{
	
	char c = ch;
	list<Snake>::iterator it = S.begin();		//使用迭代器
	switch (c)
	{
	case 'w':	it->y--;	break;
	case 's':	it->y++;	break;
	case 'a':	it->x--;	break;
	case 'd':	it->x++;	break;
	default:				break;
	}
//	TracePrint("控制蛇移动\n");
//	printList(S);
	Connect_snake(S);	
}

/*
功能: 	- 打印list容器
		@const list<Snake>& L
		@param
		@param
描述	:
示例	:	printList(L4);
*/
void printList(const list<Snake>& L)
{
	if (L.empty())
	{
		TracePrint("打印蛇链表为空");
		return;
	}
	else
	{
		for (list<Snake>::const_iterator it = L.begin(); it != L.end(); it++)
		{
			TracePrint("x = %d,y = %d\n", it->x, it->y);
		}
		//TracePrint(_T("蛇链表长度%d\n"),L.size());
	}
}

void printMap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			TracePrint("%c ", map[i][j]);
		}
		TracePrint("\n");
	}
}

//输出打印到输出窗口宽字符
void TracePrint(TCHAR* format, ...)
{
	TCHAR buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	wvsprintf(buffer, format, argptr);
	va_end(argptr);
	OutputDebugString(buffer);
}
//输出打印到输出窗口
void TracePrint(char* format, ...)
{
	char buffer[1024];
	va_list argptr;
	va_start(argptr, format);
	vsprintf_s(buffer, format, argptr);
	va_end(argptr);
	OutputDebugStringA(buffer);
}


