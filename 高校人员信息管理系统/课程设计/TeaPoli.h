#pragma once
#include "people.h"
#define Max 10000

extern int TP_NUM();
static int TP_num = 0;					//数据库中人员的数量,设置为静态变量，并且赋默认值为0
class TeaPoli :
	public People
{
public:
	TeaPoli(string ="0",string ="0",string ="0",int  =0,string ="0",string ="0",string ="0",string ="0");			//构造函数
	friend istream &operator>>(istream &cin,TeaPoli &TL);					//输入
	friend ostream &operator<<(ostream &cout,TeaPoli &TL);					//输出

	int TP_add();										//添加函数
	int TP_delete();									//删除函数
	int TP_edit();										//编辑函数
	int TP_search();									//搜索函数
	int TP_save();										//保存函数
	int TP_read();									    //读取函数
	int TP_menu();										//提供Teacher类的可供操作的菜单
	int TP_count();									    //统计函数
	int TP_output();

	string department,specialty,title,position;					//所在系部，专业，职称，政治面貌
};
