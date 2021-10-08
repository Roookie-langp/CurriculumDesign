#pragma once
#include <iostream>
#include <string>
using namespace std;

class People
{
public:
	People(string ="0",string ="0",string ="0",int =0);				//构造函数，并赋默认值
	~People(void);

	string num,name,sex;							//学号，姓名，性别
	int age;										//年龄
};

