#include<iostream>
#define max 50
static int Top=0;                    //表示数组下标
using namespace std;

struct person            //定义person类型结构体
{
    int num;
    char name[40];
    int age;
    char sex[10];
    char nation[10];
    int score;
}stu[50];                  //定义结构体数组stu[50];

void Input(struct person)       //定义输入函数
{
    cout<<"请重新输入学号：";          cin>>stu[Top].num;
    cout<<"姓名：";          cin>>stu[Top].name;
    cout<<"年龄：";          cin>>stu[Top].age;
    cout<<"性别：";          cin>>stu[Top].sex;
    cout<<"民族：";          cin>>stu[Top].nation;
    cout<<"成绩：";          cin>>stu[Top].score;
};

void Output(struct person)         //定义输出函数
{
    int  s=0;
    cout<<"学号："<<stu[s].num<<"\t";
    cout<<"姓名："<<stu[s].name<<"\t";
    cout<<"年龄："<<stu[s].age<<"\t";
    cout<<"性别："<<stu[s].sex<<"\t";
    cout<<"民族："<<stu[s].nation<<"\t";
    cout<<"成绩："<<stu[s].score<<"\n";
}

int Decide()            //定义一个函数判断数据库是否为空
{
    if(Top==0)
    {
        cout<<"该数据库暂无成员!"<<endl;    
     }
     return 1;
     
}

int Add()                              //定义添加函数
{
    struct person S;
    int i;
    if(Top>=max)
    {
    cout<<"该数据库人数已满!"<<endl;
    }
    cout<<"请输入要添加的学生学号：";
    cin>>stu[Top+1].num;
    for(i=0;i<=Top;i++)
    {
        if(stu[Top+1].num==stu[Top].num)
        {
            cout<<"该学生信息已存在，请重新输入！"<<endl;
            return 0;
        } 
     }
        Input(S);
        stu[Top]=S;          Top++;
        cout<<"添加成功！"<<endl; 
        return 1;
}

void Search()                          //定义搜索函数
{
    int i;
    cout<<"请输入要查询的学生学号：";
    cin>>stu[Top+1].num;
    for(i=0;i<Top;i++)
    {
        if(stu[i].num==stu[Top+1].num)   
        cout<<"该学生信息已找到！"<<endl;
        break;
     }
        if(i==Top)
        {
            cout<<"该学生信息不存在！"<<endl;
         }
        else
         {     
              Output(stu[i]);
         }
}  

void Show()
{
    Decide();
    for(int i=0;i<Top;i++)
    {
        Output(stu[i+1]);
        cout<<endl;
    }
}

void Edit()                             //定义编辑函数
{
    struct person S;
    int NUM,i;
    Decide();
    cout<<"请输入要编辑的学生的学号：";
    cin>>NUM;
    for(i=0;i<Top;i++)
    {
        if(stu[i].num==NUM)  break;
     }
     cout<<"请重新输入学生信息：";
     Input (S);    S=stu[Top+1];
     cout<<"编辑成功！"<<endl;
}

void Statistic()                        //定义统计函数
{
    Decide();
    cout<<"当前数据库中共有"<<Top<<"个学生信息"<<endl;
}
        
void Delete()                         //定义删除函数
{
    person S;    
    int NUM,i;
    Decide();
    cout<<"请输入要删除的学生的学号：";
    cin>>NUM;
    for(i=0;i<Top;i++)
    {
        if(stu[i].num==NUM)  break;
    }
    if(i==Top)
    {
        cout<<"该学生信息不存在！"<<endl;    
    }
    for(i;i<Top;i++)
    {
        stu[i]=stu[i+1];
    }
    Top--;
    cout<<"删除成功！"<<endl;
}

void Showmenu()        //定义显示菜单函数
{
	cout<<"******************************************************"<<endl;
    cout<<"\t\t欢迎使用562班人员管理系统"<<endl;
    cout<<"\t\t制作人：182056241 王浪平"<<endl;
	cout<<"******************************************************"<<endl;
}

void Choosemenu()       //定义选择菜单函数
{
    cout<<"\t\t\t1.添加"<<"\n\t\t\t2.查询"<<"\n\t\t\t3.显示"<<"\n\t\t\t4.编辑"<<"\n\t\t\t5.统计"<<"\n\t\t\t6.删除"<<endl;
	cout<<"******************************************************"<<endl;
}

int main()
{
    int a;
    Showmenu(); 
    do
    { 
    Choosemenu(); 
    cout<<"请输入相应数字以选择要执行的操作：";
    cin>>a;
    switch(a)
    {
    case 1:Add();break;
    case 2:Search();break;
    case 3:Show();break;
    case 4:Edit();break;
    case 5:Statistic();break;
    case 6:Delete();break;
    default:
        cout<<"选择错误！请重新选择！"<<endl;
    }
    }
    while(1);
}