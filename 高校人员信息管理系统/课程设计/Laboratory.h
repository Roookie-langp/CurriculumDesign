#pragma once
#include "people.h"
#define Max 10000

static int Lab_num = 0;					//���ݿ�����Ա������,����Ϊ��̬���������Ҹ�Ĭ��ֵΪ0
extern int Lab_NUM();
class Laboratory :
	public People
{
public:
	Laboratory(string ="0",string ="0",string ="0",int  =0,string ="0",string ="0");			//���캯��

	friend istream &operator>>(istream &cin,Laboratory &L);					//�������������
	friend ostream &operator<<(ostream &cout,Laboratory &L);					//���

	int Lab_add();										//��Ӻ���
	int Lab_delete();									//ɾ������
	int Lab_edit();								    	//�༭����
	int Lab_search();									//��������
	int Lab_save();									    //���溯��
	int Lab_read();                                    //��ȡ����
	int Lab_menu();									    //�ṩLaboratory��Ŀɹ������Ĳ˵�
	int Lab_count();								    //ͳ�ƺ���
	int Lab_output();

	string Lab_room,duty;								//����ʵ���ң�ְ��
}; 