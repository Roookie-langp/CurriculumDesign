#pragma once
#include <iostream>
#include <string>
using namespace std;

class People
{
public:
	People(string ="0",string ="0",string ="0",int =0);				//���캯��������Ĭ��ֵ
	~People(void);

	string num,name,sex;							//ѧ�ţ��������Ա�
	int age;										//����
};

