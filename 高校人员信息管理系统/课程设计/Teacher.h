#pragma once
#include "people.h"
#define Max 10000

extern int Teac_NUM();
static int Teac_num = 0;					//���ݿ�����Ա������,����Ϊ��̬���������Ҹ�Ĭ��ֵΪ0
class Teacher :
	public People
{
public:
	Teacher(string ="0",string ="0",string ="0",int  =0,string ="0",string ="0",string ="0");			//���캯��

	friend istream &operator>>(istream &cin,Teacher &T);					//����
	friend ostream &operator<<(ostream &cout,Teacher &T);					//���

	int Teac_add();										//��Ӻ���
	int Teac_delete();									//ɾ������
	int Teac_edit();									//�༭����
	int Teac_search();									//��������
	int Teac_save();									//���溯��
	int Teac_read();                                   //��ȡ����
	int Teac_menu();									//�ṩTeacher��Ŀɹ������Ĳ˵�
	int Teac_count();								    //ͳ�ƺ���
	int Teac_output();

	string department,specialty,title;						//����ϵ����רҵ��ְ��
};