package ������;

import java.util.*;
import Ա�����.Staff;
import Ա�����.Manager;
import Ա�����.CEO;
import ˳���.SqList_Staff;
import ˳���.SqList_Manager;
import ˳���.SqList_CEO;

public class test
{
	static int Menu()
	{
		System.out.println("\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
		System.out.println("\t*                                                           *");
		System.out.println("\t*                    ���׵���ҵ��Ա��Ϣ����ϵͳ                          *");
		System.out.println("\t*                                  ����������2018146016    �����    *");
		System.out.println("\t*                        1.���Ա����Ϣ                                       *");
		System.out.println("\t*                        2.�鿴����Ա����Ϣ                                *");
		System.out.println("\t*                        3.���㹤�����                                       *");
		System.out.println("\t*                        0.�˳�                                                     *");
		System.out.println("\t*                                                           *");
		System.out.println("\t*          ��ѡ����еĲ�����0��4����                                            *");
		System.out.println("\t*                                                           *");
		System.out.println("\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
		Scanner in = new Scanner(System.in);
		int choose = in.nextInt();
		while (choose < 0 || choose > 3)	//�ж��û������Ƿ�Ϸ�
		{
			System.out.print( "\t���������������������룡");
			choose = in.nextInt();
		}
		return choose;
	}
	
	static int show()
	{
		System.out.println( "\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" );
		System.out.println( "\t*                   ��ѡ���������Ա���ࣺ                                 *" );
		System.out.println( "\t*                                                          *" );
		System.out.println( "\t*            1.��ͨԱ��         2.����           3.CEO               *" );
		System.out.println( "\t*            0.�˳�                                                                         *" );
		System.out.println( "\t*                                                          *" );
		System.out.println( "\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" );
		Scanner in = new Scanner(System.in);
		int choose = in.nextInt();
		while(choose < 0 || choose > 3)			//�ж��û������Ƿ�Ϸ�
		{
			System.out.print( "\t���������������������룡");
			choose = in.nextInt();
		}
		return choose;
	}
	
	static void Add(SqList_Staff S,SqList_Manager M,SqList_CEO C)	//���Ա����Ϣ
	{
		switch(test.show())
		{
		case 1:S.InsertList(S);		break;
		case 2:M.InsertList(M);		break;
		case 3:C.InsertList(C);		break;
		}
		if(test.show() != 0)
			System.out.println("\t��ӳɹ���");
	}
	
	static void Print(SqList_Staff S,SqList_Manager M,SqList_CEO C)	//�鿴����Ա����Ϣ
	{
		System.out.println("��ǰ����" + (S.Length + M.Length + C.Length) + "λԱ��");
		S.OutputList();
		M.OutputList();
		C.OutputList();
	}
	static void Calculate(SqList_Staff S,SqList_Manager M,SqList_CEO C)	//���㹤�����
	{
		switch(test.show())
		{
		case 1:
			{
				System.out.println("��ͨԱ��δ��ʮ��Ĺ��������");
				for(int num = 0;num < S.Length;num++)
					for(int workage = 0;workage < 10;workage++)
						System.out.println("\t��һ�꣺" + S.Calcu(S.Data[num], workage));
				break;
			}
		case 2:
		{
			System.out.println("����δ��ʮ��Ĺ��������");
			for(int num = 0;num < M.Length;num++)
				for(int workage = 0;workage < 10;workage++)
					System.out.println("\t��һ�꣺" + M.Calcu(M.Data[num], workage));
			break;
		}
		case 3:
		{
			System.out.println("CEOδ��ʮ��Ĺ��������");
			for(int num = 0;num < C.Length;num++)
				for(int workage = 0;workage < 10;workage++)
					System.out.println("\t��һ�꣺" + C.Calcu(C.Data[num], workage));
			break;
		}
		}
			
	}
	
	public static void main(String []Args)
	{
		SqList_Staff Staff_Data = new SqList_Staff();
		SqList_Manager Manager_Data = new SqList_Manager();
		SqList_CEO CEO_Data = new SqList_CEO();
		Scanner in = new Scanner(System.in);
		
		Staff S1 = new Staff("123","qwe",3,3100);
		Staff_Data.InsertList(Staff_Data,S1);
		Manager M1 = new Manager("456","asd",3,4600);
		Manager_Data.InsertList(Manager_Data,M1);
		CEO C1 = new CEO("123456","zxc",3,9500);
		CEO_Data.InsertList(CEO_Data,C1);

		while(true)
		{			
			switch (test.Menu())
			{
			case 1:test.Add(Staff_Data,Manager_Data,CEO_Data);		break;				//���Ա����Ϣ
			case 2:test.Print(Staff_Data,Manager_Data,CEO_Data);	break;				//�鿴����Ա����Ϣ
			case 3:test.Calculate(Staff_Data,Manager_Data,CEO_Data);break;				//���㹤�����
			case 0:System.out.print( "\t���˳�����л����ʹ��^-^" );		System.exit(0);
			}
		}
	}
}