package 员工组成;
import java.util.Scanner;

/*
 * 此文件定义了CEO类，继承自父类People类
 */

public class CEO extends People
{
	static final float IncreaseSalary_CEO = 700;
								//CEO每年的工资提成为700元
	public CEO()		{}
	public CEO(String ID,String name,int workage,float start_salary)
	{
		this.ID = ID;
		this.name = name;
		this.workage = workage;
		this.startsalary = start_salary;
	}
	
	public void Output()						//输出人员所有信息
	{
		System.out.print("ID：" + ID + "\n");
		System.out.print("姓名：" + name + "\n");
		System.out.print("工龄：" + workage + "\n");
		System.out.print("每年工资提成：" + IncreaseSalary_CEO + "\n");
		System.out.print("应得工资：" + (startsalary + workage * IncreaseSalary_CEO) + "\n\n");
												//CEO现在应得工资 = 起始工资 + 工龄 * 每年工资提成
	}
}
