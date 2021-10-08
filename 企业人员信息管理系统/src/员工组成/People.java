package 员工组成;

/**
 * 此文件定义了父类People类，派生出其余三种子类
 *
 */
abstract class People 
{	
	public String name;				//姓名
	public String ID;				//员工ID，是唯一的
	public int workage;				//员工工龄
	public float startsalary;		//员工的起始工资
	
	void Output()	{}				//输出人员信息
	
//	void Edit();
//	void Add();
//	void Search();
//	void Delete();
}