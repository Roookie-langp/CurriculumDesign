#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#define Status int
#define OK 1
#define ERROR 0
#define Maxsize 1000		//����˳����е��������Ϊ1000��

typedef struct 
{
	string name, gender, ID, number, subject;		//�������Ա����֤�š����š����Կ�Ŀ
	int age;										//����
}Test_Stu;			/* ������Ķ��� */

typedef struct {
	Test_Stu* elem;
	int length;				//˳���ǰ����
}SqList;

Status InitList(SqList&);							//˳����ʼ��
bool EmptyList(SqList&);							//�ж�˳����Ƿ�Ϊ��
istream& operator>>(istream& cin, Test_Stu& L);		//���������������
ostream& operator<<(ostream& cout, Test_Stu& L);	//��������ȡ�����
Status InsertList(SqList& L);						//��˳����в����Ա

void InsertList(SqList& L, Test_Stu);				//���������в���ʾ����Ϣ
Status Verify(SqList& L);							//��֤�����Ƿ���

Status Search_number(SqList& L);					//�������֤�Ų���
Status Sort_age(SqList& L);							//������������
Status Delete(SqList& L);							//ɾ����Ա
Status Edit(SqList& L);								//�༭��Ա��Ϣ
Status SaveFile(SqList& L);							//��������Ϣ���浽�ļ���
void ReadFile(SqList& L);							//���ļ��ж�ȡ��Ϣ
//void Statistic(SqList& L);						//ͳ�Ƹ��Ʊ�������
Status Display(SqList& L);							//���ȫ����Ϣ
void MainMenu(SqList& L);							//��ʾ������Ĳ˵�
void ManagerMenu(SqList& L);						//�ʺϹ����߲����ĵڶ����˵�