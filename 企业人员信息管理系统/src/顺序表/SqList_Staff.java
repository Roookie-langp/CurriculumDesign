package ˳���;

import java.util.Scanner;
import Ա�����.Staff;

/*
 * ���ļ������˴洢��ͨԱ���ࣨStaff����˳���
 */

public class SqList_Staff
{
	static final int MaxLen = 100;			//��˳����������Ϊ100
	static final int OK = 1;
	static final int ERROR = 0;				

	public SqList_Staff()	{}
	public Staff Data[] = new Staff[MaxLen + 1];
											//����洢���ݵ�����,��һ��Ԫ�����䵱�ڱ�
	public int Length;								//˳���ĵ�ǰ����
	
	int InitList(SqList_Staff Sql)			//˳����ʼ��
	{
		Sql.Length = 0;			//��˳�����Ϊ0
		return OK;
	}
		
	boolean EmptyList(SqList_Staff Sql)				//�ж�˳����Ƿ�Ϊ��
	{
		if(Sql.Length == 0)
			return true;
		return false;
	}
	
	boolean MaxList(SqList_Staff Sql)				//�ж�˳����Ƿ�����
	{
		if(Sql.Length >= MaxLen)
			return false;
		return true;
	}
	
	boolean Judge_ID(SqList_Staff Sql,Staff S) 		//�ж������ID�Ƿ��ظ�
	{	
		for(int i = 0;i < Sql.Length ;i++)
		{
			int num = 0;
			if(S.ID.equals(Sql.Data[i].ID) == false);
				num++;
//			if(num == Length)
//				return false;
		}
		return false;
//		int num;
//		for (num = Sql.Length; S.ID.equals(Sql.Data[num].ID) == false;num--);
//											//�Ӻ���ǰ����Ѱ��
//		if (num == 0)
//			return false;
//		else	return true;
		
	}
	
	boolean Judge_Salary(Staff S)					//�ж�����Ĺ����Ƿ����
	{
		if(S.startsalary >= 3000 && S.startsalary <= 4000)
			return true;				//�����趨����ͨԱ����ʼ����Ϊ3000��4000֮��
		return false;
	}
	
	public int InsertList(SqList_Staff Sql,Staff S)	//���ز��뺯��
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("�����Ѵ����ޣ��޷�¼����Ϣ��");
			return ERROR;
		}
		Sql.Data[Length] = S;		Length++;		//��Ա������1
		return OK;
	}
	
	public int InsertList(SqList_Staff Sql)			//��˳����в���Ԫ��
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("�����Ѵ����ޣ��޷�¼����Ϣ��");
			return ERROR;
		}
		Scanner in = new Scanner(System.in);
		Staff S = new Staff();
		System.out.print("������������ͨԱ������Ϣ��\n");
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
		System.out.println("��ͨԱ����");
		for(int i = 0;i < Length;i++)
			Data[i].Output();
	}
	
	public float Calcu(Staff S,int workage)
	{
		return (S.startsalary + workage * Staff.IncreaseSalary_Staff);
	}
}


