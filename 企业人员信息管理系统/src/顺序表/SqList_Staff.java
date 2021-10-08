package 顺序表;

import java.util.Scanner;
import 员工组成.Staff;

/*
 * 此文件定义了存储普通员工类（Staff）的顺序表
 */

public class SqList_Staff
{
	static final int MaxLen = 100;			//设顺序表最大容量为100
	static final int OK = 1;
	static final int ERROR = 0;				

	public SqList_Staff()	{}
	public Staff Data[] = new Staff[MaxLen + 1];
											//定义存储数据的数组,第一个元素来充当哨兵
	public int Length;								//顺序表的当前长度
	
	int InitList(SqList_Staff Sql)			//顺序表初始化
	{
		Sql.Length = 0;			//令顺序表长度为0
		return OK;
	}
		
	boolean EmptyList(SqList_Staff Sql)				//判断顺序表是否为空
	{
		if(Sql.Length == 0)
			return true;
		return false;
	}
	
	boolean MaxList(SqList_Staff Sql)				//判断顺序表是否已满
	{
		if(Sql.Length >= MaxLen)
			return false;
		return true;
	}
	
	boolean Judge_ID(SqList_Staff Sql,Staff S) 		//判断输入的ID是否重复
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
//											//从后往前依次寻找
//		if (num == 0)
//			return false;
//		else	return true;
		
	}
	
	boolean Judge_Salary(Staff S)					//判断输入的工资是否合适
	{
		if(S.startsalary >= 3000 && S.startsalary <= 4000)
			return true;				//根据设定，普通员工起始工资为3000到4000之间
		return false;
	}
	
	public int InsertList(SqList_Staff Sql,Staff S)	//重载插入函数
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("人数已达上限，无法录入信息！");
			return ERROR;
		}
		Sql.Data[Length] = S;		Length++;		//人员数量加1
		return OK;
	}
	
	public int InsertList(SqList_Staff Sql)			//向顺序表中插入元素
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("人数已达上限，无法录入信息！");
			return ERROR;
		}
		Scanner in = new Scanner(System.in);
		Staff S = new Staff();
		System.out.print("以下请输入普通员工的信息：\n");
		System.out.print("ID：");
		S.ID = in.nextLine();
		while(Judge_ID(Sql,S) == true)
		{
			System.out.print("您输入的ID已存在，请重新输入：");
			S.ID = in.nextLine();
		}				//判断ID是否重复
		System.out.print("姓名：");
		S.name = in.nextLine();
		System.out.print("工龄：");
		S.workage = in.nextInt();
		System.out.print("起始工资：");
		S.startsalary = in.nextFloat();
		while(Judge_Salary(S) == false)
		{
			System.out.print("您输入的起始工资不符合要求，请重新输入：");
			S.startsalary = in.nextFloat();
		}				//判断输入的工资是否符合要求
		Sql.Data[Length] = S;		Length++;		//人员数量加1
		return OK;
	}
	
	public void OutputList()								//输出所有人员信息
	{
		System.out.println("普通员工：");
		for(int i = 0;i < Length;i++)
			Data[i].Output();
	}
	
	public float Calcu(Staff S,int workage)
	{
		return (S.startsalary + workage * Staff.IncreaseSalary_Staff);
	}
}


