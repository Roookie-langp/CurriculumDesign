#pragma once
#include "people.h"
#define Max 10000

static int Poli_num = 0;					//数据库中人员的数量,设置为静态变量
extern int Poli_NUM();
class Politics :
	public People
{
public:
	Politics(string ="0",string ="0",string ="0",int  =0,string ="0",string ="0");			//构造函数

	friend istream &operator>>(istream &cin,Politics &P);					//重载输入运算符
	friend ostream &operator<<(ostream &cout,Politics &P);					//输出

	int Poli_add();										//添加函数
	int Poli_delete();									//删除函数
	int Poli_edit();								  	//编辑函数
	int Poli_search();									//搜索函数
	int Poli_save();								    //保存函数
	int Poli_read();                                    //读取函数
	int Poli_menu();								    //提供Laboratory类的可供操作的菜单
	int Poli_count();								    //统计函数
	int Poli_output();									//输出用户

	string position,title;								//政治面貌，职称	
};

