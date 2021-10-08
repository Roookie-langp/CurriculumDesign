package 员工组成;
import java.util.*;

/*
 * 此文件定义了普通员工（Staff）类，继承自父类People类
 */

public class Staff extends People
{
	public static final float IncreaseSalary_Staff = 150;
										//普通员工每年的工资提成为150元
	
	public Staff()		{}
	public Staff(String ID,String name,int workage,float start_salary)
	{
		this.ID = ID;
		this.name = name;
		this.workage = workage;
		this.startsalary = start_salary;
	}
	
	public void Output()						//输出单个人员所有的信息
	{
		System.out.print("ID：" + ID + "\n");
		System.out.print("姓名：" + name + "\n");
		System.out.print("工龄：" + workage + "\n");
		System.out.print("每年工资提成：" + IncreaseSalary_Staff + "\n");
		System.out.print("应得工资：" + (startsalary + workage * IncreaseSalary_Staff) + "\n\n");
												//普通员工现在应得工资 = 起始工资 + 工龄 * 每年工资提成
	}
}