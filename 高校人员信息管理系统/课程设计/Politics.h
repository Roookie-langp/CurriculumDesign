#pragma once
#include "people.h"
#define Max 10000

static int Poli_num = 0;					//���ݿ�����Ա������,����Ϊ��̬����
extern int Poli_NUM();
class Politics :
	public People
{
public:
	Politics(string ="0",string ="0",string ="0",int  =0,string ="0",string ="0");			//���캯��

	friend istream &operator>>(istream &cin,Politics &P);					//�������������
	friend ostream &operator<<(ostream &cout,Politics &P);					//���

	int Poli_add();										//��Ӻ���
	int Poli_delete();									//ɾ������
	int Poli_edit();								  	//�༭����
	int Poli_search();									//��������
	int Poli_save();								    //���溯��
	int Poli_read();                                    //��ȡ����
	int Poli_menu();								    //�ṩLaboratory��Ŀɹ������Ĳ˵�
	int Poli_count();								    //ͳ�ƺ���
	int Poli_output();									//����û�

	string position,title;								//������ò��ְ��	
};

