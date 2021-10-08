#pragma once
#include "people.h"
#define Max 10000

extern int Teac_NUM();
static int Teac_num = 0;					//数据库中人员的数量,设置为静态变量，并且赋默认值为0
class Teacher :
	public People
{
public:
	Teacher(string ="0",string ="0",string ="0",int  =0,string ="0",string ="0",string ="0");			//构造函数

	friend istream &operator>>(istream &cin,Teacher &T);					//输入
	friend ostream &operator<<(ostream &cout,Teacher &T);					//输出

	int Teac_add();										//添加函数
	int Teac_delete();									//删除函数
	int Teac_edit();									//编辑函数
	int Teac_search();									//搜索函数
	int Teac_save();									//保存函数
	int Teac_read();                                   //读取函数
	int Teac_menu();									//提供Teacher类的可供操作的菜单
	int Teac_count();								    //统计函数
	int Teac_output();

	string department,specialty,title;						//所在系部，专业，职称
};