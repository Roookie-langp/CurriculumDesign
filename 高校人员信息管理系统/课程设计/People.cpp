#include "StdAfx.h"
#include "People.h"


People::People(string num,string name,string sex,int age)					//基类构造函数的定义
{
	this->num = num;
	this->name =name;
	this->sex = sex;
	this->age = age;
}


People::~People(void)
{
}
