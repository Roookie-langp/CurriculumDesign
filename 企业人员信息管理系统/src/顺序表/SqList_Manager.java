package 顺序表;

import java.util.Scanner;
import 员工组成.Manager;
import 员工组成.Staff;

/*
 * 此文件定义了存储经理类（Manager）的顺序表
 */

public class SqList_Manager
{
	static final int MaxLen = 100;			//设顺序表最大容量为100
	static final int OK = 1;
	static final int ERROR = 0;				

	public SqList_Manager()	{}
	public Manager Data[] = new Manager[MaxLen];
											//定义存储数据的数组
	public int Length;								//顺序表的当前长度
	
	int InitList(SqList_Manager Sql)			//顺序表初始化
	{
		Sql.Length = 0;			//令顺序表长度为0
		return OK;
	}
		
	boolean EmptyList(SqList_Manager Sql)			//判断顺序表是否为空
	{
		if(Sql.Length == 0)
			return true;
		return false;
	}
	
	boolean MaxList(SqList_Manager Sql)				//判断顺序表是否已满
	{
		if(Sql.Length >= MaxLen)
			return false;
		return true;
	}
	
	boolean Judge_ID(SqList_Manager Sql,Manager S) 	//判断输入的ID是否重复
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
	
	boolean Judge_Salary(Manager S)					//判断输入的工资是否合适
	{
		if(S.startsalary >= 4000 && S.startsalary <= 6000)
			return true;				//根据设定，经理起始工资为4000到6000之间
		return false;
	}
	
	public int InsertList(SqList_Manager Sql,Manager S)	//重载插入函数
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("人数已达上限，无法录入信息！");
			return ERROR;
		}
		Sql.Data[Length] = S;		Length++;		//人员数量加1
		return OK;
	}
	public int InsertList(SqList_Manager Sql)			//向顺序表中插入元素
	{
		if(MaxList(Sql) == false)
		{
			System.out.print("人数已达上限，无法录入信息！");
			return ERROR;
		}
		Scanner in = new Scanner(System.in);
		Manager S = new Manager();
		System.out.print("以下请输入经理的信息：\n");
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
		System.out.println("经理：");
		for(int i = 0;i < Length;i++)
			Data[i].Output();
	}
	
	public float Calcu(Manager M,int workage)
	{
		return (M.startsalary + workage * Staff.IncreaseSalary_Staff);
	}
}


