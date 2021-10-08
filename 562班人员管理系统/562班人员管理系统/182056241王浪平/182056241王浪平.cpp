#include<iostream>
#define max 50
static int Top=0;                    //��ʾ�����±�
using namespace std;

struct person            //����person���ͽṹ��
{
    int num;
    char name[40];
    int age;
    char sex[10];
    char nation[10];
    int score;
}stu[50];                  //����ṹ������stu[50];

void Input(struct person)       //�������뺯��
{
    cout<<"����������ѧ�ţ�";          cin>>stu[Top].num;
    cout<<"������";          cin>>stu[Top].name;
    cout<<"���䣺";          cin>>stu[Top].age;
    cout<<"�Ա�";          cin>>stu[Top].sex;
    cout<<"���壺";          cin>>stu[Top].nation;
    cout<<"�ɼ���";          cin>>stu[Top].score;
};

void Output(struct person)         //�����������
{
    int  s=0;
    cout<<"ѧ�ţ�"<<stu[s].num<<"\t";
    cout<<"������"<<stu[s].name<<"\t";
    cout<<"���䣺"<<stu[s].age<<"\t";
    cout<<"�Ա�"<<stu[s].sex<<"\t";
    cout<<"���壺"<<stu[s].nation<<"\t";
    cout<<"�ɼ���"<<stu[s].score<<"\n";
}

int Decide()            //����һ�������ж����ݿ��Ƿ�Ϊ��
{
    if(Top==0)
    {
        cout<<"�����ݿ����޳�Ա!"<<endl;    
     }
     return 1;
     
}

int Add()                              //������Ӻ���
{
    struct person S;
    int i;
    if(Top>=max)
    {
    cout<<"�����ݿ���������!"<<endl;
    }
    cout<<"������Ҫ��ӵ�ѧ��ѧ�ţ�";
    cin>>stu[Top+1].num;
    for(i=0;i<=Top;i++)
    {
        if(stu[Top+1].num==stu[Top].num)
        {
            cout<<"��ѧ����Ϣ�Ѵ��ڣ����������룡"<<endl;
            return 0;
        } 
     }
        Input(S);
        stu[Top]=S;          Top++;
        cout<<"��ӳɹ���"<<endl; 
        return 1;
}

void Search()                          //������������
{
    int i;
    cout<<"������Ҫ��ѯ��ѧ��ѧ�ţ�";
    cin>>stu[Top+1].num;
    for(i=0;i<Top;i++)
    {
        if(stu[i].num==stu[Top+1].num)   
        cout<<"��ѧ����Ϣ���ҵ���"<<endl;
        break;
     }
        if(i==Top)
        {
            cout<<"��ѧ����Ϣ�����ڣ�"<<endl;
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

void Edit()                             //����༭����
{
    struct person S;
    int NUM,i;
    Decide();
    cout<<"������Ҫ�༭��ѧ����ѧ�ţ�";
    cin>>NUM;
    for(i=0;i<Top;i++)
    {
        if(stu[i].num==NUM)  break;
     }
     cout<<"����������ѧ����Ϣ��";
     Input (S);    S=stu[Top+1];
     cout<<"�༭�ɹ���"<<endl;
}

void Statistic()                        //����ͳ�ƺ���
{
    Decide();
    cout<<"��ǰ���ݿ��й���"<<Top<<"��ѧ����Ϣ"<<endl;
}
        
void Delete()                         //����ɾ������
{
    person S;    
    int NUM,i;
    Decide();
    cout<<"������Ҫɾ����ѧ����ѧ�ţ�";
    cin>>NUM;
    for(i=0;i<Top;i++)
    {
        if(stu[i].num==NUM)  break;
    }
    if(i==Top)
    {
        cout<<"��ѧ����Ϣ�����ڣ�"<<endl;    
    }
    for(i;i<Top;i++)
    {
        stu[i]=stu[i+1];
    }
    Top--;
    cout<<"ɾ���ɹ���"<<endl;
}

void Showmenu()        //������ʾ�˵�����
{
	cout<<"******************************************************"<<endl;
    cout<<"\t\t��ӭʹ��562����Ա����ϵͳ"<<endl;
    cout<<"\t\t�����ˣ�182056241 ����ƽ"<<endl;
	cout<<"******************************************************"<<endl;
}

void Choosemenu()       //����ѡ��˵�����
{
    cout<<"\t\t\t1.���"<<"\n\t\t\t2.��ѯ"<<"\n\t\t\t3.��ʾ"<<"\n\t\t\t4.�༭"<<"\n\t\t\t5.ͳ��"<<"\n\t\t\t6.ɾ��"<<endl;
	cout<<"******************************************************"<<endl;
}

int main()
{
    int a;
    Showmenu(); 
    do
    { 
    Choosemenu(); 
    cout<<"��������Ӧ������ѡ��Ҫִ�еĲ�����";
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
        cout<<"ѡ�����������ѡ��"<<endl;
    }
    }
    while(1);
}