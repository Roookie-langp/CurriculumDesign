package Ա�����;
import java.util.Scanner;

/*
 * ���ļ�������CEO�࣬�̳��Ը���People��
 */

public class CEO extends People
{
	static final float IncreaseSalary_CEO = 700;
								//CEOÿ��Ĺ������Ϊ700Ԫ
	public CEO()		{}
	public CEO(String ID,String name,int workage,float start_salary)
	{
		this.ID = ID;
		this.name = name;
		this.workage = workage;
		this.startsalary = start_salary;
	}
	
	public void Output()						//�����Ա������Ϣ
	{
		System.out.print("ID��" + ID + "\n");
		System.out.print("������" + name + "\n");
		System.out.print("���䣺" + workage + "\n");
		System.out.print("ÿ�깤����ɣ�" + IncreaseSalary_CEO + "\n");
		System.out.print("Ӧ�ù��ʣ�" + (startsalary + workage * IncreaseSalary_CEO) + "\n\n");
												//CEO����Ӧ�ù��� = ��ʼ���� + ���� * ÿ�깤�����
	}
}
