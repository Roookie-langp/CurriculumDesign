#include "StdAfx.h"
#include "Teacher.h"
#include <iomanip>
#include <fstream>

Teacher Numb[Max];				//定义一个Teacher类数组来作为缓存数据库，以存储(只是存储，程序结束，若未保存，则会丢失)保存之前的缓存数据。必须放在cpp文件里，否则报错

Teacher::Teacher(string num,string name,string sex,int age,string department,string specialty,string title)
	:People(num,name,sex,age)											//构造函数的定义
{
	this->department = department;
	this->specialty = specialty;
	this->title = title;
}


istream & operator>>(istream &cin,Teacher &T)							//重载流插入运算符，以实现对象的输入功能
{
	cout<<"\t请输入编号：";				cin>>T.num;
	cout<<"\t请输入姓名：";				cin>>T.name;
	cout<<"\t请输入性别：";				cin>>T.sex;
	cout<<"\t请输入年龄：";				cin>>T.age;
	cout<<"\t请输入系部：";				cin>>T.department;
	cout<<"\t请输入专业：";				cin>>T.specialty;
	cout<<"\t请输入职称：";				cin>>T.title;
	return cin;
}

ostream & operator<<(ostream &cout,Teacher &T)							//重载流提取运算符，以实现对象的输出功能
{
	cout<<setw(8)<<T.num<<setw(15)<<T.name<<setw(10)<<T.sex<<setw(10)<<T.age<<setw(20)
		<<T.department<<setw(20)<<T.specialty<<setw(20)<<T.title<<endl;
	return cout;
}

extern int Teac_NUM()
{
	return Teac_num;
}

int Teacher::Teac_output()											//定义一个函数用于输出当前缓存数据库里的所有成员，显示当前中所有记录
{
	if(Teac_num == 0)
	{
		cout<<"\t……………………………………………………………………………"<<endl;
		cout<<"\t:   错误！您还未向缓存数据库中添加数据，无法执行该操作！ :"<<endl;
		cout<<"\t……………………………………………………………………………"<<endl;
		return 0;
	}
	else
	{
		cout<<"\t当前数据库中有"<<Teac_num<<"个人"<<endl;
		cout<<"\t·—————————————————————————————·"<<endl;
		cout<<"\t|                是否要查看当前数据库里的人员？              |"<<endl;
		cout<<"\t|                   查看请按Y，取消查看请按N                 |"<<endl;
		cout<<"\t|                                                            |"<<endl;
		cout<<"\t|            是（Y）                         否（N)          |"<<endl;	
		cout<<"\t·—————————————————————————————·"<<endl;	
		char ch;
		for(int j = 0;j<4;j++)						//最多四次选择输入的机会
		{
			cin>>ch;
			if(ch == 'Y'||ch == 'y')
			{
				cout<<"_____________________________________________________________________________________________________________\n\n";
				cout<<setw(10)<<"编号"<<setw(15)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<setw(20)
					<<"系部"<<setw(20)<<"专业"<<setw(20)<<"职称"<<"\n";
				for(int i =0;i < Teac_num;i++)
				{
					cout<<"_____________________________________________________________________________________________________________\n\n";
					cout<<Numb[i];
					
				}
				cout<<"_____________________________________________________________________________________________________________\n";
				
				return 0;						//暂停退出
			}
			else if(ch == 'N'||ch == 'n')
			{	cout<<"\t——————————————————————————————"<<endl;
				cout<<"\t|                           已退出！                       |"<<endl;
				cout<<"\t——————————————————————————————"<<endl;
				return 0;						//暂停退出
			}
			else 
			{	cout<<"\t——————————————————————————————"<<endl;
				cout<<"\t|                         请重新输入!                      |"<<endl;
				cout<<"\t——————————————————————————————"<<endl;
			}
		}
	}
	return 0;
}

int Teacher::Teac_add()														//添加函数
{
	cout<<"\t——————————————————————————————"<<endl;
	cout<<"\t|                  请输入要添加的人员信息！                |"<<endl;
	cout<<"\t——————————————————————————————"<<endl;	
	cin>>*this;									//用户输入学生信息
	int i;
	for(i=0;i<Teac_num+1;i++)					//查找用户输入的人员编号是否与数据库中数据重复
	{
		if(num == Numb[i].num)					//如果重复，则提示用户，并退出
		{
			cout<<"\t———————————————————————————"<<endl;
			cout<<"\t|   该人员信息已存在，信息未添加成功，系统强行退出!  |"<<endl;
			cout<<"\t———————————————————————————"<<endl;
			return 0;
		}
		else if(i == Teac_num)
		{
			Numb[Teac_num] = *this;						//未找着就开始添加
			Teac_num++;									//添加成功后数据库中的人加1
			cout<<"\t——————————————————————————————"<<endl;
			cout<<"\t|                        添加成功!                         |"<<endl;
			cout<<"\t——————————————————————————————"<<endl;	
			return 0;
		}
	}
	cout<<"\t——————————————————————————————"<<endl;
	cout<<"\t|                        信息未添加！                      |"<<endl;
	cout<<"\t——————————————————————————————"<<endl;
	return 0;
}


int Teacher::Teac_delete()													//删除函数
{
	if(Teac_num == 0)															//如果人员数量为0，则说明数据库为空
	{
		cout<<"\t……………………………………………………………………………"<<endl;
		cout<<"\t:  错误！您还未向缓存数据库中添加数据，无法进行删除操作！:"<<endl;
		cout<<"\t……………………………………………………………………………"<<endl;
		return 0;
	}																//提示给用户，并退出程序
	else
	{
		cout<<"\t——————————————————————————————"<<endl;
		cout<<"\t|                  请输入要删除的人员编号！                |"<<endl;
		cout<<"\t——————————————————————————————"<<endl;	
		string nu;			cin>>nu;						//用户输入删除编号
		int i;											//i表示要删除人员在数组中的下标

		for(i = 0;i<Teac_num+1;i++)							//查找删除编号在数据库中是否存在
		{
			if(nu == Numb[i].num)							//当找到相同编号的时候，让用户选择是否删除
			{
				cout<<"\t·————————————————————————————·"<<endl;
				cout<<"\t|            已找到该人员信息，是否要确认删除该人员？      |"<<endl;
				cout<<"\t|                   确认请按Y，取消请按N                   |"<<endl;
				cout<<"\t|                                                          |"<<endl;
				cout<<"\t|            是（Y）                         否（N)        |"<<endl;	
				cout<<"\t·————————————————————————————·"<<endl;
				char ch;
				for(int j = 0;j < 2;j++)							//最多两次选择输入的机会
				{
					cin>>ch;
					switch(ch)
					{
					case 'y':
					case 'Y':
						{	for(int m = i;m < Teac_num;m++)					//开始进行删除操作
							{
								Numb[i] = Numb[i+1];					//后一个数组赋给前一个数组						
							}
							Teac_num = Teac_num - 1;					//删除成功后人员数量减1
							cout<<"\t——————————————————————————————"<<endl;
							cout<<"\t|                        删除成功!                         |"<<endl;
							cout<<"\t——————————————————————————————"<<endl;	
							return 0;
						}break;
					case 'n':
					case 'N':
						{	cout<<"\t——————————————————————————————"<<endl;
							cout<<"\t|                         已退出!                          |"<<endl;
							cout<<"\t——————————————————————————————"<<endl;	
							return 0;						//暂停退出
						}
					default:{	cout<<"\t——————————————————————————————"<<endl;
								cout<<"\t|                       请重新输入！                       |"<<endl;
								cout<<"\t——————————————————————————————"<<endl;	
							}break;
					}
				}
			}
			else if(i == Teac_num)							//没找到用户输入的编号
			{
				cout<<"\t……………………………………………………………………………"<<endl;
				cout<<"\t:              未找到该人员信息，程序已退出！            :"<<endl;
				cout<<"\t……………………………………………………………………………"<<endl;						//未找着就进行提示
			}
		}
	}
	return 0;
}


int Teacher::Teac_edit()														//编辑函数
{
	if(Teac_num == 0)									//如果人员数量为0，则说明数据库为空
	{	cout<<"\t……………………………………………………………………………"<<endl;
		cout<<"\t:  错误！您还未向缓存数据库中添加数据，无法进行编辑操作！:"<<endl;
		cout<<"\t……………………………………………………………………………"<<endl;
		return 0;										//提示给用户，并退出程序
	}
	else
	{
		cout<<"\t——————————————————————————————"<<endl;
		cout<<"\t|                  请输入要编辑的人员编号！                |"<<endl;
		cout<<"\t——————————————————————————————"<<endl;	


		string nu;				cin>>nu;				//用户输入编号

		for(int i = 0;i<Teac_num+1;i++)					//查找要编辑的编号在数据库中是否存在
		{
			if(nu == Numb[i].num)						//当找到相同编号的时
			{
				cout<<"\t·————————————————————————————·"<<endl;
				cout<<"\t|          该人员信息如下，是否要确认修改该人员信息？      |"<<endl;
				cout<<"\t|                   确认请按Y，取消请按N                   |"<<endl;
				cout<<"\t|                                                          |"<<endl;
				cout<<"\t|            是（Y）                         否（N)        |"<<endl;
				cout<<"\t·————————————————————————————·"<<endl;
				cout<<"_____________________________________________________________________________________________________________\n\n";
				cout<<setw(10)<<"编号"<<setw(15)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<setw(20)
						<<"系部"<<setw(20)<<"专业"<<setw(20)<<"职称"<<endl;
				cout<<"_____________________________________________________________________________________________________________\n\n";
				cout<<Numb[i];
				cout<<"_____________________________________________________________________________________________________________\n";
				char ch;
				for(int j = 0;j < 4;j++)				//最多四次选择输入的机会
				{
					cin>>ch;
					switch(ch)
					{
					case 'y':
					case 'Y':
						{	cin>>*this;							//用户输入修改后的信息
							Numb[i] = *this;					//把用户输入的值重新赋给找到数组成员，即完成编辑修改操作	
							cout<<"\t——————————————————————————————"<<endl;
							cout<<"\t|                        编辑成功!                         |"<<endl;
							cout<<"\t——————————————————————————————"<<endl;		//提示编辑成功
							return 0;
						}break;
					case 'n':
					case 'N':
						{	cout<<"\t——————————————————————————————"<<endl;
							cout<<"\t|                           已退出！                       |"<<endl;
							cout<<"\t——————————————————————————————"<<endl;
							return 0;							//暂停退出
						}
					default:{	cout<<"\t——————————————————————————————"<<endl;
								cout<<"\t|                         请重新输入!                      |"<<endl;
								cout<<"\t——————————————————————————————"<<endl;
							}break;
					}
				}
			}
			else if(i == Teac_num)								//搜索完全部人员信息还未找到用户输入的编号时
			{
				cout<<"\t……………………………………………………………………………"<<endl;
				cout<<"\t:              未找到该人员信息，程序已退出！            :"<<endl;
				cout<<"\t……………………………………………………………………………"<<endl;					//未找着就进行提示
			}
		}
	}
	return 0;
}



int Teacher::Teac_search()													//搜索函数
{
	
	if(Teac_num == 0)									//如果人员数量为0，则说明数据库为空
	{
		cout<<"\t……………………………………………………………………………"<<endl;
		cout<<"\t:  错误！您还未向缓存数据库中添加数据，无法进行搜索操作！:"<<endl;
		cout<<"\t……………………………………………………………………………"<<endl;
		return 0;										//提示给用户，并退出程序
	}
	else
	{
		cout<<"\t·—————————————————————————————·"<<endl;
		cout<<"\t|                   请选择要用何种方式查询：                 |"<<endl;
		cout<<"\t|                        1.编号查询                          |"<<endl;
		cout<<"\t|                        2.姓名查询                          |"<<endl;
		cout<<"\t|                        0.退出                              |"<<endl;
		cout<<"\t·—————————————————————————————·"<<endl;
		int a;						cin>>a;
		switch(a)
		{
		case 1:																//根据编号进行查找
			{
				cout<<"\t——————————————————————————————"<<endl;
				cout<<"\t|                  请输入要搜索的人员编号！                |"<<endl;
				cout<<"\t——————————————————————————————"<<endl;	
				string nu;				cin>>nu;											//用户输入编号
				for(int i = 0;i <Teac_num + 1;i++)
				{
					if(Numb[i].num == nu)
					{
						cout<<"\t根据编号已找到相关信息，以下是该人员信息："<<endl;
						cout<<"_____________________________________________________________________________________________________________\n\n";
						cout<<setw(10)<<"编号"<<setw(15)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<setw(20)
							<<"系部"<<setw(20)<<"专业"<<setw(20)<<"职称"<<endl;
						cout<<"_____________________________________________________________________________________________________________\n\n";
						cout<<Numb[i];														//输出已找到的人员信息
						cout<<"_____________________________________________________________________________________________________________\n";
						return 0;															//并返回到函数调用处
					}
					else if(i == Teac_num)													//搜索完全部人员信息还未找到用户输入的编号时
					{
						cout<<"\t……………………………………………………………………………"<<endl;
						cout<<"\t:              未找到该人员信息，程序已退出！            :"<<endl;
						cout<<"\t……………………………………………………………………………"<<endl;
						return 0;															//未找着就进行提示
					}
				}
			}break;
		case 2:																	//根据姓名进行查找
			{
				cout<<"\t——————————————————————————————"<<endl;
				cout<<"\t|                  请输入要搜索的人员姓名：                |"<<endl;
				cout<<"\t——————————————————————————————"<<endl;	
				string na;				cin>>na;											//用户输入姓名
				for(int i = 0;i <Teac_num + 1;i++)
				{
					if(Numb[i].name == na)
					{
						cout<<"\t根据姓名已找到相关信息，以下是该人员信息："<<endl;
						cout<<"_____________________________________________________________________________________________________________\n\n";
						cout<<setw(10)<<"编号"<<setw(15)<<"姓名"<<setw(10)<<"性别"<<setw(10)<<"年龄"<<setw(20)
							<<"系部"<<setw(20)<<"专业"<<setw(20)<<"职称"<<endl;
						cout<<"_____________________________________________________________________________________________________________\n\n";
						cout<<Numb[i];														//输出已找到的人员信息
						cout<<"_____________________________________________________________________________________________________________\n";
						return 0;																	//并返回到函数调用处
					}
					else if(i == Teac_num)													//搜索完全部人员信息还未找到用户输入的编号时
					{
						cout<<"\t……………………………………………………………………………"<<endl;
						cout<<"\t:              未找到该人员信息，程序已退出！            :"<<endl;
						cout<<"\t……………………………………………………………………………"<<endl;
						return 0;															//未找着就进行提示，并退出程序
					}
				}
			}break;
		case 0:	return 0; break;								//用户选择退出		
		default:{	cout<<"\t……………………………………………………………………………"<<endl;
					cout<<"\t:                   输入错误，程序已退出！               :"<<endl;
					cout<<"\t……………………………………………………………………………"<<endl;
				}break;
		}
	}
	return 0;
}


int Teacher::Teac_save()										//保存函数,将缓存数据库中的数据保存到文件中
{
	if(Teac_num == 0)
	{
		cout<<"\t……………………………………………………………………………"<<endl;
		cout<<"\t:  错误！您还未向缓存数据库中添加数据，无法进行保存操作！:"<<endl;
		cout<<"\t……………………………………………………………………………"<<endl;
		return 0;
	}
	else{
			ofstream outfile;							//建立ofstream类的对象outfile
			outfile.open("Teacher.txt",ios::app);		//与文件Teacher.txt建立关联
			for(int i = 0;i < Teac_num;i++)				//向文件内写入数据
			{
				//string num,name,sex,age,department,specialty,title;
				outfile<<"\n"<<setw(10)<<Numb[i].num<<setw(15)<<Numb[i].name<<setw(10)<<Numb[i].sex<<setw(10)<<Numb[i].age<<setw(20)
					<<Numb[i].department<<setw(20)<<Numb[i].specialty<<setw(20)<<Numb[i].title;
			}
			outfile.close();							//取消与文件的关联
			cout<<"\t——————————————————————————————"<<endl;
			cout<<"\t|                       保存信息成功!                      |"<<endl;
			cout<<"\t——————————————————————————————"<<endl;		//提示保存成功
		}
	return 0;
}

int Teacher::Teac_read()										//读取文件里的信息
{
	ifstream infile;							//建立对象
	infile.open("Teacher.txt",ios::in);			//与文件Teacher.txt建立关联
	for(;;)
	{
		string num,name,sex,age,department,specialty,title;
		infile>>num>>name>>sex>>age>>department>>specialty>>title;		//读取文件中的信息
		if(num=="\0"&&name=="\0"&&sex=="\0"&&department=="\0"&&specialty=="\0"&&title=="\0") break;
																						//用于判断读取的信息是否为空，若信息为空，则结束循环
		else
		{
		cout<<"_____________________________________________________________________________________________________________\n\n";
		cout<<setw(8)<<num<<setw(15)<<name<<setw(10)<<sex<<setw(10)<<age<<setw(20)
			<<department<<setw(20)<<specialty<<setw(20)<<title<<endl;				//输出到屏幕上
		}
	}
	cout<<"_____________________________________________________________________________________________________________\n";
	infile.close();														//取消与文件的关联
	cout<<"\t——————————————————————————————"<<endl;
	cout<<"\t|                       读取信息成功!                      |"<<endl;
	cout<<"\t——————————————————————————————"<<endl;		//提示读取成功
	return 0;
}

int Teacher::Teac_count()										//统计函数
{
		cout<<"\t……………………………………………………………………………"<<endl;
		cout<<"\t:              当前缓存数据库中有"<<Teac_num<<"个人员信息             :"<<endl;
		cout<<"\t……………………………………………………………………………"<<endl;
	return 0;
}

int Teacher::Teac_menu()										//提供并实现Teacher类的可供操作的菜单
{
	
	int ch;
	for(;;)
	{
		
		cout<<"\t·* * * * * * * * * * * * * * * * * * * * * * * * * * * * *·"<<endl;
		cout<<"\t*                       教师信息管理                        *"<<endl;
		cout<<"\t*            1.添加人员信息        2.删除人员信息           *"<<endl;
		cout<<"\t*            3.查找人员信息        4.编辑人员信息           *"<<endl;
		cout<<"\t*            5.保存人员信息        6.读取文件内的信息       *"<<endl;
		cout<<"\t*            7.显示人员信息        8.统计人员数量           *"<<endl;
		cout<<"\t*                           0.退出                          *"<<endl;
		cout<<"\t*      请选择进行的操作（0到8）：                           *"<<endl;
		cout<<"\t·* * * * * * * * * * * * * * * * * * * * * * * * * * * * *·"<<endl;
		cin>>ch;
		switch(ch)
		{
		case 0:
			{
				cout<<"\t——————————————————————————————"<<endl;
				cout<<"\t|                       谢谢您的使用^-^                    |"<<endl;
				cout<<"\t——————————————————————————————"<<endl;
				system("pause");		system("cls");		return 0;
			} break;
		case 1:this->Teac_add(); break;
		case 2:this->Teac_delete(); break;
		case 3:this->Teac_search(); break;
		case 4:this->Teac_edit(); break;
		case 5:this->Teac_save(); break;
		case 6:this->Teac_read(); break;
		case 7:this->Teac_output(); break;
		case 8:this->Teac_count();break;
		default:	
			{	cout<<"\t……………………………………………………………………………"<<endl;
				cout<<"\t:                   输入错误，请重新输入！               :"<<endl;
				cout<<"\t……………………………………………………………………………"<<endl;
				system("pause");		system("cls");		return 0;
			} break;
		}
		system("pause");				system("cls");
	}
	return 0;
}