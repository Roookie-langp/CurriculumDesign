#pragma once
#include "people.h"
#define Max 10000

extern int TP_NUM();
static int TP_num = 0;					//���ݿ�����Ա������,����Ϊ��̬���������Ҹ�Ĭ��ֵΪ0
class TeaPoli :
	public People
{
public:
	TeaPoli(string ="0",string ="0",string ="0",int  =0,string ="0",string ="0",string ="0",string ="0");			//���캯��
	friend istream &operator>>(istream &cin,TeaPoli &TL);					//����
	friend ostream &operator<<(ostream &cout,TeaPoli &TL);					//���

	int TP_add();										//��Ӻ���
	int TP_delete();									//ɾ������
	int TP_edit();										//�༭����
	int TP_search();									//��������
	int TP_save();										//���溯��
	int TP_read();									    //��ȡ����
	int TP_menu();										//�ṩTeacher��Ŀɹ������Ĳ˵�
	int TP_count();									    //ͳ�ƺ���
	int TP_output();

	string department,specialty,title,position;					//����ϵ����רҵ��ְ�ƣ�������ò
};
