#include "Test_Manager.h"

void main()
{
	SqList L;	InitList(L);
	Test_Stu stu_1, stu_2;
	stu_1.age = 33;			stu_1.gender = "��";		stu_1.ID = "123456789987654321";
	stu_1.name = "����";	stu_1.subject = "��ѧ";		stu_1.number = "191201";
	stu_2.age = 29;			stu_2.gender = "Ů";		stu_2.ID = "987654321123456789";
	stu_2.name = "��÷";	stu_2.subject = "����";		stu_2.number = "191202";
	InsertList(L, stu_1);			InsertList(L, stu_2);		//��������ӵ�ʾ����Ϣ
	while(1)
		MainMenu(L); 
}