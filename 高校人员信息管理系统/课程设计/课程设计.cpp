// �γ����.cpp : �������̨Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include "Teacher.h"
#include "Laboratory.h"
#include "Politics.h"
#include"TeaPoli.h"

void stastic()							//����һ������ͳ����Ա����
{
	cout<<"\t����������������������������������������������������������"<<endl;
	cout<<"\t:               ��ǰ���ݿ��й���"<<Lab_NUM()+Teac_NUM()+TP_NUM()+Poli_NUM()<<"����Ա��Ϣ               :"<<endl;
	cout<<"\t����������������������������������������������������������"<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{	
	
	int num = 0;
	Teacher T;	Politics P;	Laboratory L;	TeaPoli TP;
	for(;;)
	{
		cout<<"\t��* * * * * * * * * * * * * * * * * * * * * * * * * * * * *��"<<endl;
		cout<<"\t*                                                           *"<<endl;
		cout<<"\t*                   ��У��Ա��Ϣ����ϵͳ                    *"<<endl;
		cout<<"\t*                                 ����182056241  ����ƽ     *"<<endl;
		cout<<"\t*                                                           *"<<endl;
		cout<<"\t*          1.��ʦ��Ϣ����        2.������Ա��Ϣ����         *"<<endl;
		cout<<"\t*          3.ʵ��Ա��Ϣ����      4.��ʦ������Ա��Ϣ����     *"<<endl;
		cout<<"\t*          5.ͳ������Ա��        0.�˳�                     *"<<endl;
		cout<<"\t*                                                           *"<<endl;
		cout<<"\t*      ��ѡ����еĲ�����0��5����                           *"<<endl;
		cout<<"\t��* * * * * * * * * * * * * * * * * * * * * * * * * * * * *��"<<endl;	

		cin>>num;
		switch(num)
		{
		case 0:
			{
				cout<<"\t������������������������������������������������������������"<<endl;
				cout<<"\t|                       лл����ʹ��^-^                    |"<<endl;
				cout<<"\t������������������������������������������������������������"<<endl;
				exit(0);
			} break;
		case 1:system("cls");	T.Teac_menu(); break;
		case 2:system("cls");	P.Poli_menu(); break;
		case 3:system("cls");	L.Lab_menu(); break;
		case 4:system("cls");	TP.TP_menu(); break;
		case 5:system("cls");	stastic();	system("pause");	system("cls");	break;
		default:{
			system("cls");
			cout<<"\t��* * * * * * * * * * * * * * * * * * * * * * * * * * * * *��"<<endl;
			cout<<"\t*                   ����������������룡                  *"<<endl;
			cout<<"\t��* * * * * * * * * * * * * * * * * * * * * * * * * * * * *��"<<endl;
				}break;
		}
	}
	return 0;
}

