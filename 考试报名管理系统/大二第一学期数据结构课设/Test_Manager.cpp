#include "Test_Manager.h"

Status InitList(SqList& L)						/* ˳����ʼ�� */
{
	L.elem = new Test_Stu[Maxsize + 1];	/* ��˳�������СΪMaxSize+1
										   �Ŀռ�,�±�Ϊ0��Ԫ����Ϊ�ڱ� */
	L.length = 0;						//��ʼ��ʱ˳���ǰ����Ϊ0
	return OK;
}

bool EmptyList(SqList& L)							/* �ж�˳����Ƿ�Ϊ�� */
{
	if (L.length == 0)
		return true;					//��Ϊ���򷵻�true
	return false;
}

istream& operator>>(istream& cin, Test_Stu& stu)
{
	cout << "������";			cin >> stu.name;
	cout << "�Ա�";			cin >> stu.gender;
	cout << "���䣺";			cin >> stu.age;
	cout << "���֤�ţ�";		cin >> stu.ID;
	cout << "���Կ�Ŀ��";		cin >> stu.subject;
	return cin;
}

ostream& operator<<(ostream& cout, Test_Stu& stu)
{
	cout << "\t��������������������������������������������������������������������������������������������������������\n";
	cout << "\t" << stu.number << "\t\t" << stu.name << "\t\t" << stu.gender << "\t\t"
		<< stu.age << "\t\t" << stu.ID << "\t\t" << stu.subject << "\n";
	return cout;
}

Status InsertList(SqList& L)					      	/* �����������Զ�Ϊ�������ɿ��� */
{
	if (L.length == Maxsize + 1)
	{
		cout << "\t��������������";
		return ERROR;
	}
	cout << "\t�����뿼����Ϣ��" << endl;
	Test_Stu stu;		cin >> stu;
	string str;
	str = std::to_string((long double)L.length + 1);		//to_string()������long double��ת��Ϊ�ַ���
	stu.number = "19120" + str;
	L.elem[L.length + 1] = stu;
	L.length++;
	cout << "\t�����ɹ���"<<endl;
	cout << "���Ŀ���Ϊ��" << L.elem[L.length].number << "�������μ����Ŀ��ţ�"<<endl;
	return OK;
}

void InsertList(SqList& L, Test_Stu stu)
{
	L.elem[L.length + 1] = stu;
	L.length++;
}

Status Search_number(SqList& L)							/* �������֤�Ų��� */
{
	cout << "������Ҫ���ҿ����Ŀ����ţ�";
	string key;		cin >> key;			//�������֤��
	L.elem[0].number = key;				//��Ҫ����Ԫ�ص�ֵ�����ڱ�
	int num;
	for (num = L.length; L.elem[num].number != key; num--);
										//�Ӻ���ǰ����Ѱ��
	if (num == 0)
	{
		cout << "\t��������������������������������������������������������������������������������������������������������\n";
		cout << "\t" << "����\t\t����\t\t�Ա�\t\t����\t\t���֤��\t\t\t���Կ�Ŀ\n";
		cout << "\t��������������������������������������������������������������������������������������������������������\n";
		cout << "\t�ܱ�Ǹ��δ�ҵ��ÿ�����Ϣ��" << endl;
		return ERROR;
	}
	else {
		cout << "\t��Ҫ���ҵĿ�������Ϣ���£�" << endl;
		cout << "\t��������������������������������������������������������������������������������������������������������\n";
		cout << "\t" << "����\t\t����\t\t�Ա�\t\t����\t\t���֤��\t\t\t���Կ�Ŀ\n";
		cout << L.elem[num];
		cout << "\t��������������������������������������������������������������������������������������������������������\n";
	}
	return OK;
}

Status Verify(SqList& L)							/* ��֤�����Ƿ��� */
{
	cout << "�����뿼��������";
	string key;		cin >> key;			//��������
	L.elem[0].name = key;				//��Ҫ����Ԫ�ص�ֵ�����ڱ�
	int num;
	for (num = L.length; L.elem[num].name != key; num--);
										//�Ӻ���ǰ����Ѱ��
	if (num == 0)
		cout << "\t�ܱ�Ǹ��δ�ҵ�������Ϣ��" << endl;
	else
		cout << "\t���ѱ�����" << endl;
	return OK;
}

Status Sort_age(SqList& L)								/* ������������ */
{
	Test_Stu Stu[Maxsize];	int j;
	for (int i = 0; i <= L.length; i++)
		Stu[i] = L.elem[i];
	for (int i = 2; i <= L.length; i++)
		if (Stu[i].age < Stu[i - 1].age)
		{
			Stu[0] = Stu[i];
			Stu[i] = Stu[i - 1];
			for (j = i - 2; Stu[0].age < Stu[j].age; j--)
				Stu[j + 1] = Stu[j];
			Stu[j + 1] = Stu[0];
		}
	cout << "\t��������������������������������������������������������������������������������������������������������\n";
	cout << "\t" << "����\t\t����\t\t�Ա�\t\t����\t\t���֤��\t\t\t���Կ�Ŀ\n";
	for (int i = 1; i <= L.length; i++)						//����ź����Ԫ��
		cout << Stu[i];
	cout << "\t��������������������������������������������������������������������������������������������������������\n";
	return OK;
}

Status Delete(SqList& L)									/* ɾ��ָ����Ϣ */
{
	if(EmptyList(L) == true)	
	{		cout << "\t�������ݣ��޷�ɾ����" << endl;		return ERROR;		}
	cout << "������Ҫɾ������Ա�����ţ�";
	string key;		cin >> key;
	L.elem[0].number = key;				//��Ҫ����Ԫ�ص�ֵ�����ڱ�
	int num;
	for (num = L.length; L.elem[num].number != key; num--);
											//�Ӻ���ǰ����Ѱ��
	if (num == 0)
		cout << "\tδ�ҵ��ÿ�����Ϣ���������Ƿ�������ȷ"<<endl;
	else {
		cout << "\t������������������������������������������������������������" << endl;
		cout << "\t��          ����Ա��Ϣ���£��Ƿ�Ҫȷ��ɾ������Ա��Ϣ��     ��" << endl;
		cout << "\t��                   ȷ���밴Y��ȡ���밴N                  ��" << endl;
		cout << "\t��                                                         ��" << endl;
		cout << "\t��          ��       ��                    ��       ��         ��" << endl;
		cout << "\t��            �ǣ�Y��                      ��N��         ��" << endl;
		cout << "\t��          ��       ��                    ��       ��         �� " << endl;
		cout << "\t������������������������������������������������������������" << endl;
		cout << "\t��������������������������������������������������������������������������������������������������������\n";
		cout << "\t" << "����\t\t����\t\t�Ա�\t\t����\t\t���֤��\t\t\t���Կ�Ŀ\n";
		cout << L.elem[num];
		cout << "\t��������������������������������������������������������������������������������������������������������\n";
		char ch;	cin >> ch;
		while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')			//�ж��û������Ƿ�Ϸ�
		{
			cout << "���������������������룡";
			cin >> ch;
		}
		switch (ch)
		{
		case'y':
		case'Y':
			for (int i = num; i < L.length + 1; i++)
				L.elem[i] = L.elem[i + 1];
			L.length--;							//ɾ����ɺ󳤶ȼ�1
			cout << "\tɾ���ɹ���" << endl;
			break;
		case'n':
		case'N':cout << "\t���˳���" << endl;	break;
		}
	}
	return OK;
}

Status Edit(SqList& L)											/* �༭ָ����Ϣ */
{
	if (EmptyList(L) == true)
	{
		cout << "�������ݣ��޷�ɾ����" << endl;		return ERROR;
	}
	cout << "������Ҫ�༭����Ա�����ţ�";
	string key;		cin >> key;
	L.elem[0].number = key;				//��Ҫ����Ԫ�ص�ֵ�����ڱ�
	int num;
	for (num = L.length; L.elem[num].number != key; num--);
										//�Ӻ���ǰ����Ѱ��
	if (num == 0)
		cout << "δ�ҵ��ÿ�����Ϣ���������Ƿ�������ȷ"<<endl;
	else {
		cout << "\t������������������������������������������������������������" << endl;
		cout << "\t��          ����Ա��Ϣ���£��Ƿ�Ҫȷ���޸ĸ���Ա��Ϣ��     ��" << endl;
		cout << "\t��                   ȷ���밴Y��ȡ���밴N                  ��" << endl;
		cout << "\t��                                                         ��" << endl;
		cout << "\t��          ��       ��                    ��       ��         ��" << endl;
		cout << "\t��            �ǣ�Y��                      ��N��         ��" << endl;
		cout << "\t��          ��       ��                    ��       ��         �� " << endl;
		cout << "\t������������������������������������������������������������" << endl;
		cout << "\t��������������������������������������������������������������������������������������������������������\n";
		cout << "\t" << "����\t\t����\t\t�Ա�\t\t����\t\t���֤��\t\t\t���Կ�Ŀ\n";
		cout << L.elem[num];
		cout << "\t��������������������������������������������������������������������������������������������������������\n";
		char ch;	cin >> ch;
		while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N')			//�ж��û������Ƿ�Ϸ�
		{
			cout << "���������������������룡";
			cin >> ch;
		}
		switch (ch)
		{
		case'y':
		case'Y':
			cin >> L.elem[num];
			cout << "\t�༭�ɹ���" << endl;
			break;
		case'n':
		case'N':cout << "\t���˳���" << endl;	break;
		}
	}
	return OK;
}

Status SaveFile(SqList& L)
{
	if (EmptyList(L) == true)
	{		cout << "����δ������ݣ��޷����浽�ļ���"<<endl;		return ERROR;		}
	ofstream outfile;							//����ofstream��Ķ���outfile
	outfile.open("Manager.txt", ios::app);		//���ļ�Manager.txt��������
	for (int i = 1; i < L.length+1; i++)				//���ļ���д������
		outfile << "\n" << L.elem[i].number << "\t\t" << L.elem[i].name << "\t\t" << L.elem[i].gender << "\t\t" << L.elem[i].age << "\t\t"
		<< L.elem[i].ID << "\t\t" << L.elem[i].subject << "\n";
	outfile.close();							//ȡ�����ļ��Ĺ���
	cout << "\t��Ϣ����ɹ���" << endl;;
	return OK;
}

void ReadFile(SqList& L)
{
	ifstream infile;							//��������
	infile.open("Manager.txt",ios::in);			//���ļ�Manager.txt��������
	for(;;)
	{
		string number,name,gender,age,ID,subject;
		infile>>number>>name>>gender>>age>>ID>>subject;		//��ȡ�ļ��е���Ϣ
		if(number=="\0"&&name=="\0"&&gender=="\0"&&age=="\0"&&ID=="\0"&&subject=="\0") break;
															//�����ж϶�ȡ����Ϣ�Ƿ�Ϊ�գ�����ϢΪ�գ������ѭ��
		else{
			cout << "\t��������������������������������������������������������������������������������������������������������\n";
			cout << "\t" << number << "\t\t" << name << "\t\t" << gender << "\t\t"
					<< age << "\t\t" << ID << "\t\t" << subject << "\n";
		}
	}
	cout << "\t��������������������������������������������������������������������������������������������������������\n";
}

Status Display(SqList& L)										/* ���ȫ����Ϣ */
{
	if (L.length == 0)
	{
		cout << "������Ϣ��" << endl;		return ERROR;
	}
	cout << "\t��������������������������������������������������������������������������������������������������������\n";
	cout << "\t" << "����\t\t����\t\t�Ա�\t\t����\t\t���֤��\t\t\t���Կ�Ŀ\n";
	for (int i = 1; i <= L.length; i++)
		cout << L.elem[i];
	cout << "\t��������������������������������������������������������������������������������������������������������\n";
	return OK;
}

void MainMenu(SqList& L)											/* ʵ��������˵�����ʵ����Ӧ���� */
{
		cout << "\t��* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *��" << endl;
		cout << "\t*                     ��                   ��                   *" << endl;
		cout << "\t*                       ��ª�Ŀ�������ϵͳ                    *" << endl;
		cout << "\t*                     ��                   ��                   *" << endl;
		cout << "\t*                        1.��ʼ����                           *" << endl;
		cout << "\t*                        2.��ѯ�Ƿ���                       *" << endl;
		cout << "\t*                        3.�����ѱ�����Ϣ                     *" << endl;
		cout << "\t*                        0.�رմ���                           *" << endl;
		cout << "\t*                                                             *" << endl;
		cout << "\t*      ��ѡ����еĲ�����0��3����                             *" << endl;
		cout << "\t*                                                             *" << endl;
		cout << "\t��* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *��" << endl;
		int choose;		cin >> choose;
		while (choose < 0 || choose > 3)	//�ж��û������Ƿ�Ϸ�
		{
			cout << "���������������������룡";
			cin >> choose;
		}
		switch (choose)
		{
		case 1:InsertList(L);	break;									//����
		case 2:Verify(L);		break;
		case 3:ManagerMenu(L);	break;		//�����Ӳ˵�
		case 0:cout << "\t��л����ʹ��^-^" << endl;		exit(0);
		}
		system("pause");
		system("cls");	
}

void ManagerMenu(SqList& L)											/* �����߲˵� */
{
	string password;
	cout << "\t������������룺";			cin >> password;
	if (password == "pass")
	{
		cout << "\t������ȷ��" << endl;
		system("pause");		system("cls");
		while (1)
		{
			cout << "\t���� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ����" << endl;
			cout << "\t��                     ��                   ��                  ��" << endl;
			cout << "\t��                           ����˵�                         ��" << endl;
			cout << "\t��                     ��                   ��                  ��" << endl;
			cout << "\t��                                                            ��" << endl;
			cout << "\t��                     1.�鿴�ѱ���������Ϣ                   ��" << endl;
			cout << "\t��                     2.ɾ��ָ����Ա��Ϣ                     ��" << endl;
			cout << "\t��                     3.���ݿ��Ų�����Ա��Ϣ                 ��" << endl;
			cout << "\t��                     4.�༭ָ����Ա��Ϣ                     ��" << endl;
			cout << "\t��                     5.������Ա��Ϣ���ļ�                   ��" << endl;
			cout << "\t��                     6.��ȡ�ļ��ڵ���Ϣ                     ��" << endl;
			cout << "\t��                     7.����������鿴������Ա��Ϣ           ��" << endl;
			//cout << "\t��                     8.ͳ�Ƹ��Ʊ�������                     ��" << endl;
			cout << "\t��                     0.�����ϼ��˵�                         ��" << endl;
			cout << "\t��      ��ѡ����еĲ�����0��7����                            ��" << endl;
			cout << "\t��                                                            ��" << endl;
			cout << "\t���� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ����" << endl;
			int choose;		cin >> choose;
			string password;
			while (choose < 0 || choose > 7)	//�ж��û������Ƿ�Ϸ�
			{
				cout << "���������������������룡";
				cin >> choose;
			}
			switch (choose)
			{
			case 1:Display(L);		break;
			case 2:Delete(L);		break;
			case 3:Search_number(L);	break;
			case 4:Edit(L);			break;
			case 5:SaveFile(L);		break;
			case 6:ReadFile(L);		break;
			case 7:Sort_age(L);		break;
				//case 8:Statistic(L);	break;
			case 0:break;
			}
			if (choose == 0)	break;			//������һ���˵�
			system("pause");
			system("cls");
		}
	}
	else
		cout << "\t������󣬾ܾ����ķ��ʣ�" << endl;
}
