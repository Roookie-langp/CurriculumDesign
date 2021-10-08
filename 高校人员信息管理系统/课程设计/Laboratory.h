#pragma once
#include "people.h"
#define Max 10000

static int Lab_num = 0;					//数据库中人员的数量,设置为静态变量，并且赋默认值为0
extern int Lab_NUM();
class Laboratory :
	public People
{
public:
	Laboratory(string ="0",string ="0",string ="0",int  =0,string ="0",string ="0");			//构造函数

	friend istream &operator>>(istream &cin,Laboratory &L);					//重载输入运算符
	friend ostream &operator<<(ostream &cout,Laboratory &L);					//输出

	int Lab_add();										//添加函数
	int Lab_delete();									//删除函数
	int Lab_edit();								    	//编辑函数
	int Lab_search();									//搜索函数
	int Lab_save();									    //保存函数
	int Lab_read();                                    //读取函数
	int Lab_menu();									    //提供Laboratory类的可供操作的菜单
	int Lab_count();								    //统计函数
	int Lab_output();

	string Lab_room,duty;								//所在实验室，职务
}; 