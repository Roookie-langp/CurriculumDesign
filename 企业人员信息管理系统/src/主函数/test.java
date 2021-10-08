package 主函数;

import java.util.*;
import 员工组成.Staff;
import 员工组成.Manager;
import 员工组成.CEO;
import 顺序表.SqList_Staff;
import 顺序表.SqList_Manager;
import 顺序表.SqList_CEO;

public class test
{
	static int Menu()
	{
		System.out.println("\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
		System.out.println("\t*                                                           *");
		System.out.println("\t*                    简易的企业人员信息管理系统                          *");
		System.out.println("\t*                                  —————2018146016    邓庆峰    *");
		System.out.println("\t*                        1.添加员工信息                                       *");
		System.out.println("\t*                        2.查看所有员工信息                                *");
		System.out.println("\t*                        3.计算工资情况                                       *");
		System.out.println("\t*                        0.退出                                                     *");
		System.out.println("\t*                                                           *");
		System.out.println("\t*          请选择进行的操作（0到4）：                                            *");
		System.out.println("\t*                                                           *");
		System.out.println("\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
		Scanner in = new Scanner(System.in);
		int choose = in.nextInt();
		while (choose < 0 || choose > 3)	//判断用户输入是否合法
		{
			System.out.print( "\t您的输入有误，请重新输入！");
			choose = in.nextInt();
		}
		return choose;
	}
	
	static int show()
	{
		System.out.println( "\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" );
		System.out.println( "\t*                   请选择操作的人员种类：                                 *" );
		System.out.println( "\t*                                                          *" );
		System.out.println( "\t*            1.普通员工         2.经理           3.CEO               *" );
		System.out.println( "\t*            0.退出                                                                         *" );
		System.out.println( "\t*                                                          *" );
		System.out.println( "\t * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *" );
		Scanner in = new Scanner(System.in);
		int choose = in.nextInt();
		while(choose < 0 || choose > 3)			//判断用户输入是否合法
		{
			System.out.print( "\t您的输入有误，请重新输入！");
			choose = in.nextInt();
		}
		return choose;
	}
	
	static void Add(SqList_Staff S,SqList_Manager M,SqList_CEO C)	//添加员工信息
	{
		switch(test.show())
		{
		case 1:S.InsertList(S);		break;
		case 2:M.InsertList(M);		break;
		case 3:C.InsertList(C);		break;
		}
		if(test.show() != 0)
			System.out.println("\t添加成功！");
	}
	
	static void Print(SqList_Staff S,SqList_Manager M,SqList_CEO C)	//查看所有员工信息
	{
		System.out.println("当前共有" + (S.Length + M.Length + C.Length) + "位员工");
		S.OutputList();
		M.OutputList();
		C.OutputList();
	}
	static void Calculate(SqList_Staff S,SqList_Manager M,SqList_CEO C)	//计算工资情况
	{
		switch(test.show())
		{
		case 1:
			{
				System.out.println("普通员工未来十年的工资情况：");
				for(int num = 0;num < S.Length;num++)
					for(int workage = 0;workage < 10;workage++)
						System.out.println("\t第一年：" + S.Calcu(S.Data[num], workage));
				break;
			}
		case 2:
		{
			System.out.println("经理未来十年的工资情况：");
			for(int num = 0;num < M.Length;num++)
				for(int workage = 0;workage < 10;workage++)
					System.out.println("\t第一年：" + M.Calcu(M.Data[num], workage));
			break;
		}
		case 3:
		{
			System.out.println("CEO未来十年的工资情况：");
			for(int num = 0;num < C.Length;num++)
				for(int workage = 0;workage < 10;workage++)
					System.out.println("\t第一年：" + C.Calcu(C.Data[num], workage));
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
			case 1:test.Add(Staff_Data,Manager_Data,CEO_Data);		break;				//添加员工信息
			case 2:test.Print(Staff_Data,Manager_Data,CEO_Data);	break;				//查看所有员工信息
			case 3:test.Calculate(Staff_Data,Manager_Data,CEO_Data);break;				//计算工资情况
			case 0:System.out.print( "\t已退出，感谢您的使用^-^" );		System.exit(0);
			}
		}
	}
}