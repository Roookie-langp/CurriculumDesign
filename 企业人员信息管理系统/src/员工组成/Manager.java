package Ա�����;
import java.util.Scanner;

/*
 * ���ļ������˾���Manager���࣬�̳��Ը���People��
 */

public class Manager extends People
{
	static final float IncreaseSalary_Manager = 450;
								//����ÿ��Ĺ������Ϊ450Ԫ
	public Manager()		{}
	public Manager(String ID,String name,int workage,float start_salary)
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
		System.out.print("ÿ�깤����ɣ�" + IncreaseSalary_Manager + "\n");
		System.out.print("Ӧ�ù��ʣ�" + (startsalary + workage * IncreaseSalary_Manager) + "\n\n");
												//��������Ӧ�ù��� = ��ʼ���� + ���� * ÿ�깤�����
	}
}