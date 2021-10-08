package ˳���;

import java.util.Scanner;
import Ա�����.CEO;
import Ա�����.Staff;

/*
 * ���ļ������˴洢CEO���˳���
 */

public class SqList_CEO
{
	static final int MaxLen = 100;			//��˳����������Ϊ100
	static final int OK = 1;
	static final int ERROR = 0;				

	public SqList_CEO()	{}
	public CEO Data[] = new CEO[MaxLen];
											//����洢���ݵ�����
	public int Length;								//˳���ĵ�ǰ����
	
	int InitList(SqList_CEO Sql)			//˳����ʼ��
	{
		Sql.Length = 0;			//��˳�����Ϊ0
		return OK;
	}
		
	boolean EmptyList(SqList_CEO Sql)				//�ж�˳����Ƿ�Ϊ��
	{
		if(Sql.Length == 0)
			return true;
		return false;
	}
	
	boolean MaxList(SqList_CEO Sql)					//�ж�˳����Ƿ�����
	{
		if(Sql.Length >= MaxLen)
			return false;
		return true;
	}
	
	boolean Judge_ID(SqList_CEO Sql,CEO S) 						//�ж������ID�Ƿ��ظ�
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
	
	boolean Judge_Salary(CEO S)						//�ж�����Ĺ����Ƿ����
	{
		if(S.startsalary >= 8000 && S.startsalary <= 12000)
			return true;				//�����趨��CEO��ʼ����Ϊ8000��12000֮��
		return false;
	}
	
	public int InsertList(SqList_CEO Sql,CEO S)	//���ز��뺯��
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("�����Ѵ����ޣ��޷�¼����Ϣ��");
			return ERROR;
		}
		Sql.Data[Length] = S;		Length++;		//��Ա������1
		return OK;
	}
	public int InsertList(SqList_CEO Sql)			//��˳����в���Ԫ��
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("�����Ѵ����ޣ��޷�¼����Ϣ��");
			return ERROR;
		}
		Scanner in = new Scanner(System.in);
		CEO S = new CEO();
		System.out.print("����������CEO����Ϣ��\n");
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
	
	public void OutputList()						//���������Ա��Ϣ
	{
		System.out.println("CEO��");
		for(int i = 0;i < Length;i++)
			Data[i].Output();
	}
	
	public float Calcu(CEO C,int workage)
	{
		return (C.startsalary + workage * Staff.IncreaseSalary_Staff);
	}
}


