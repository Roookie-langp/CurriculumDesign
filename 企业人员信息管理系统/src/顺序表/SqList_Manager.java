package ˳���;

import java.util.Scanner;
import Ա�����.Manager;
import Ա�����.Staff;

/*
 * ���ļ������˴洢�����ࣨManager����˳���
 */

public class SqList_Manager
{
	static final int MaxLen = 100;			//��˳����������Ϊ100
	static final int OK = 1;
	static final int ERROR = 0;				

	public SqList_Manager()	{}
	public Manager Data[] = new Manager[MaxLen];
											//����洢���ݵ�����
	public int Length;								//˳���ĵ�ǰ����
	
	int InitList(SqList_Manager Sql)			//˳����ʼ��
	{
		Sql.Length = 0;			//��˳�����Ϊ0
		return OK;
	}
		
	boolean EmptyList(SqList_Manager Sql)			//�ж�˳����Ƿ�Ϊ��
	{
		if(Sql.Length == 0)
			return true;
		return false;
	}
	
	boolean MaxList(SqList_Manager Sql)				//�ж�˳����Ƿ�����
	{
		if(Sql.Length >= MaxLen)
			return false;
		return true;
	}
	
	boolean Judge_ID(SqList_Manager Sql,Manager S) 	//�ж������ID�Ƿ��ظ�
	{
		for(int i = 0;i <= Sql.Length ;i++)
		{
			int num = 0;
			if(S.ID.equals(Sql.Data[i].ID) == false);
				num++;
			if(num == Length)
				return false;
		}
		return true;
	}
	
	boolean Judge_Salary(Manager S)					//�ж�����Ĺ����Ƿ����
	{
		if(S.startsalary >= 4000 && S.startsalary <= 6000)
			return true;				//�����趨��������ʼ����Ϊ4000��6000֮��
		return false;
	}
	
	public int InsertList(SqList_Manager Sql,Manager S)	//���ز��뺯��
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("�����Ѵ����ޣ��޷�¼����Ϣ��");
			return ERROR;
		}
		Sql.Data[Length] = S;		Length++;		//��Ա������1
		return OK;
	}
	public int InsertList(SqList_Manager Sql)			//��˳����в���Ԫ��
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("�����Ѵ����ޣ��޷�¼����Ϣ��");
			return ERROR;
		}
		Scanner in = new Scanner(System.in);
		Manager S = new Manager();
		System.out.print("���������뾭�����Ϣ��\n");
		System.out.print("ID��");
		S.ID = in.nextLine();
		while(Judge_ID(Sql,S) == true)
		{
			System.out.print("�������ID�Ѵ��ڣ����������룺");
			S.ID = in.nextLine();
		}				//�ж�ID�Ƿ��ظ�
		System.out.print("������");
		S.name = in.nextLine();
		System.out.print("���䣺");
		S.workage = in.nextInt();
		System.out.print("��ʼ���ʣ�");
		S.startsalary = in.nextFloat();
		while(Judge_Salary(S) == false)
		{
			System.out.print("���������ʼ���ʲ�����Ҫ�����������룺");
			S.startsalary = in.nextFloat();
		}				//�ж�����Ĺ����Ƿ����Ҫ��
		Sql.Data[Length] = S;		Length++;		//��Ա������1
		return OK;
	}
	
	public void OutputList()								//���������Ա��Ϣ
	{
		System.out.println("����");
		for(int i = 0;i < Length;i++)
			Data[i].Output();
	}
	
	public float Calcu(Manager M,int workage)
	{
		return (M.startsalary + workage * Staff.IncreaseSalary_Staff);
	}
}


