// 课程设计.cpp : 定义控制台应用程序的入口点。
#include "stdafx.h"
#include "Teacher.h"
#include "Laboratory.h"
#include "Politics.h"
#include"TeaPoli.h"

void stastic()							//定义一个函数统计人员总数
{
	cout<<"\t……………………………………………………………………………"<<endl;
	cout<<"\t:               当前数据库中共有"<<Lab_NUM()+Teac_NUM()+TP_NUM()+Poli_NUM()<<"个人员信息               :"<<endl;
	cout<<"\t……………………………………………………………………………"<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{	
	
	int num = 0;
	Teacher T;	Politics P;	Laboratory L;	TeaPoli TP;
	for(;;)
	{
		cout<<"\t·* * * * * * * * * * * * * * * * * * * * * * * * * * * * *·"<<endl;
		cout<<"\t*                                                           *"<<endl;
		cout<<"\t*                   高校人员信息管理系统                    *"<<endl;
		cout<<"\t*                                 ——182056241  王浪平     *"<<endl;
		cout<<"\t*                                                           *"<<endl;
		cout<<"\t*          1.教师信息管理        2.行政人员信息管理         *"<<endl;
		cout<<"\t*          3.实验员信息管理      4.教师行政人员信息管理     *"<<endl;
		cout<<"\t*          5.统计总人员数        0.退出                     *"<<endl;
		cout<<"\t*                                                           *"<<endl;
		cout<<"\t*      请选择进行的操作（0到5）：                           *"<<endl;
		cout<<"\t·* * * * * * * * * * * * * * * * * * * * * * * * * * * * *·"<<endl;	

		cin>>num;
		switch(num)
		{
		case 0:
			{
				cout<<"\t——————————————————————————————"<<endl;
				cout<<"\t|                       谢谢您的使用^-^                    |"<<endl;
				cout<<"\t——————————————————————————————"<<endl;
				exit(0);
			} break;
		case 1:system("cls");	T.Teac_menu(); break;
		case 2:system("cls");	P.Poli_menu(); break;
		case 3:system("cls");	L.Lab_menu(); break;
		case 4:system("cls");	TP.TP_menu(); break;
		case 5:system("cls");	stastic();	system("pause");	system("cls");	break;
		default:{
			system("cls");
			cout<<"\t·* * * * * * * * * * * * * * * * * * * * * * * * * * * * *·"<<endl;
			cout<<"\t*                   输入错误，请重新输入！                  *"<<endl;
			cout<<"\t·* * * * * * * * * * * * * * * * * * * * * * * * * * * * *·"<<endl;
				}break;
		}
	}
	return 0;
}

