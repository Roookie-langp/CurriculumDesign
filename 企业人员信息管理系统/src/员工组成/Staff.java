package Ա�����;
import java.util.*;

/*
 * ���ļ���������ͨԱ����Staff���࣬�̳��Ը���People��
 */

public class Staff extends People
{
	public static final float IncreaseSalary_Staff = 150;
										//��ͨԱ��ÿ��Ĺ������Ϊ150Ԫ
	
	public Staff()		{}
	public Staff(String ID,String name,int workage,float start_salary)
	{
		this.ID = ID;
		this.name = name;
		this.workage = workage;
		this.startsalary = start_salary;
	}
	
	public void Output()						//���������Ա���е���Ϣ
	{
		System.out.print("ID��" + ID + "\n");
		System.out.print("������" + name + "\n");
		System.out.print("���䣺" + workage + "\n");
		System.out.print("ÿ�깤����ɣ�" + IncreaseSalary_Staff + "\n");
		System.out.print("Ӧ�ù��ʣ�" + (startsalary + workage * IncreaseSalary_Staff) + "\n\n");
												//��ͨԱ������Ӧ�ù��� = ��ʼ���� + ���� * ÿ�깤�����
	}
}