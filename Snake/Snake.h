/*
创建者	:	XTT
功能	:

时间	:	2020/02/01
*/
#pragma once
#include<atltrace.h>
#include <list>
#include <graphics.h>



//#define DEBUG 1
//
//#if DEBUG
//#define TRACE(s) OutputDebugString(s)
//#endif

using namespace std;

const short ScreenWidth = 640;
const short ScreenHeight = 480;

const int num[10] = { 0,1,2,3,4,5,6,7,8,9 };
static int scores[3] = { 4,2,3 };

#define N 24  //地图的宽    Y轴 行数
#define M 20  //地图的长	X轴	列数
//(24-2)*(20-2)-3 = 393

//蛇的结构
class Snake
{
public:
	Snake()
	{
		x = 10;
		y = 10;
	}
	Snake(int _x, int _y)
	{
		x = _x;
		y = _y;
	};
	int x;
	int y;
};

//食物的结构
struct Food
{
	char x = 2;
	char y = 4;
};


//贪吃蛇的地图
void Map();

//输出函数
void Show_map();

//刷新食物
void Refresh_food(char ,list<Snake>&);

void Create_snake(list<Snake>&);

void Entry_snake(list<Snake>&);

void Connect_snake(list<Snake>&);

void Growth_snake(char ch, list<Snake>& S);

void Control_snake(char ch,list<Snake>&);

void printList(const list<Snake>&);			//打印

void printMap();

void TracePrint(TCHAR*,...);

void TracePrint(char*, ...);


