#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>


//people类
class people
{
	

	friend class showmanagel;
public:
	virtual void showinfo() = 0;

	
protected://使用保护继承，使得子类可以继承
	string m_name;
	int m_num;
	int m_sex;
	string m_id;
	int m_sumtime;
	int m_weektime;

};
//学生类
class student : virtual public people
{
public:
	student() {};
	student(string name, int num, int sex, string id, int sumtime, int weektime)
	{
		this->m_name = name;
		this->m_num = num;
		this->m_sex = sex;
		this->m_id = id;
		this->m_sumtime = sumtime;
		this->m_weektime = weektime;
	}
	virtual void showinfo()
	{
		cout << "该学生姓名为:" << this->m_name
			<< "\t编号为:" << this->m_num;
		if (this->m_sex == 1)cout << "\t性别为:男生";
		else cout << "\t性别为:女生";

		cout << "\t身份证号为" << this->m_id
			<< "\t总学时数为:" << this->m_sumtime
			<< "\t每周固定学时数为:" << this->m_weektime<< endl;
	}

	
protected:

};
//教师除了固定的学时数外，还有每周的教学时数。
//教师类
class teacher : virtual public people
{
public:
	teacher() {};
	teacher(string name, int num, int sex, string id, int sumtime, int weektime,int weekTeatime)
	{
		this->m_name = name;
		this->m_num = num;
		this->m_sex = sex;
		this->m_id = id;
		this->m_sumtime = sumtime;
		this->m_weektime = weektime;
		this->m_weekTeatime = weekTeatime;
	}
	virtual void showinfo()
	{
		cout << "该教师姓名为:" << this->m_name
			<< "\t编号为:" << this->m_num;
		if (this->m_sex == 1)cout << "\t性别为:男生";
		else cout << "\t性别为:女生";

		cout << "\t身份证号为" << this->m_id
			<< "\t总学时数为:" << this->m_sumtime
			<< "\t每周固定学时数为:" << this->m_weektime
			<< "\t每周教学时数为:" << this->m_weekTeatime<< endl;
	}

	

protected:
	int m_weekTeatime;

};
// 研究生除了固定的学时数外，每周还可以自由做一定的研究。
//研究生类
//要先构造父类确定内存，而多态运行阶段确定内存
class graduate : public student
{
public:
	graduate() {};
	graduate(string name, int num, int sex, string id, int sumtime, int weektime, int weekGratime)
	{
		this->m_name = name;
		this->m_num = num;
		this->m_sex = sex;
		this->m_id = id;
		this->m_sumtime = sumtime;
		this->m_weektime = weektime;
		this->m_weekGratime = weekGratime;
	}
	virtual void showinfo()
	{
		cout << "该研究生姓名为:" << this->m_name
			<< "\t编号为:" << this->m_num;
		if (this->m_sex == 1)cout << "\t性别为:男生";
		else cout << "\t性别为:女生";

		cout << "\t身份证号为" << this->m_id
			<< "\t总学时数为:" << this->m_sumtime
			<< "\t每周固定学时数为:" << this->m_weektime
			<< "\t每周研究时数为:" << this->m_weekGratime << endl;
	}

	
protected:
	int m_weekGratime;
};
//助教生除了上课外，还要做研究和一定的教学工作
//助教类
class TA :  public graduate,  public teacher
{
public:
	TA(string name, int num, int sex, string id, int sumtime, int weektime, int weekTeatime,int weekGratime)
	{
		this->m_name = name;
		this->m_num = num;
		this->m_sex = sex;
		this->m_id = id;
		this->m_sumtime = sumtime;
		this->m_weektime = weektime;
		this->m_weekTeatime = weekTeatime;
		this->m_weekGratime = weekGratime;
	}
	virtual void showinfo()
	{
		cout << "该助教姓名为:" << this->m_name
			<< "\t编号为:" << this->m_num;
			if (this->m_sex == 1)cout << "\t性别为:男生";
			else cout << "\t性别为:女生";

		cout<< "\t身份证号为" << this->m_id 
			<< "\t总学时数为:" << this->m_sumtime 
			<< "\t每周固定学时数为:" << this->m_weektime 
			<< "\t每周教学时数为:" << this->m_weekTeatime
			<< "\t每周研究时数为:" << this->m_weekGratime << endl;
	}

	
protected:

};
//打印仿函数
class showmanagel
{
public:
	void operator()(people* p)
	{
		p->showinfo();
	}
};
//校园管理系统类
class campusPeopleManage
{
public:
	//显示菜单
	void show_menu()
	{
		cout << "*************欢迎使用校园人员管理系统************" << endl
			<< "*************请输入您的选择**********************" << endl
			<< "***1--人员录入   2--查看人员信息   0--退出系统***" << endl
			<< "**************************************************" << endl;
	}
	//人员信息录入
	void addstudent();
	void addteacher();
	void addgraduat();
	void addTA();

	//录入人员
	void addpeople()
	{
		int num = 0;
		cout << "请选择您要录入的人数" << endl;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			int choice = 0;
			cout << "请选择录入人员身份:" << endl
				<< "1--学生，2--教师，3--研究生，4--助教" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				addstudent();//添加学生
				break;
			case 2:
				addteacher();//添加教师
				break;
			case 3:
				addgraduat();//添加研究生
				break;
			case 4:
				addTA();//添加TA
				break;

			default://预防
				cout << "非法输入，请重新输入" << endl;
				i--;
				break;
			}
			cout << endl;
		}
		system("pause");
		system("cls");
	}
	//显示信息
	void showmanage()
	{
		for_each(v.begin(), v.end(), showmanagel());//遍历数组，打印人员信息
		system("pause");
		system("cls");
	}
	
	//析构函数--将堆区释放
	~campusPeopleManage()
	{
		if (!this->v.empty())
		{
			for (vector<people*>::iterator it = v.begin(); it != v.end(); it++)
			{
				delete* it;
				*it = NULL;
			}
		}
	}
private:
	vector<people*>v;//储存people类调用其他派生类（多态）
};
int main()
{
	campusPeopleManage m1;
	int choice = 0;
	while (true)
	{
		//菜单函数
		m1.show_menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//录入人员
			m1.addpeople();
			break;
		case 2:
			//显示人员信息
			m1.showmanage();
			break;
		case 0://退出程序
			exit(0);
			break;
		default:
			cout << "非法输入，请重新输入" << endl;

			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}
//添加学生类
void campusPeopleManage::addstudent()
{
	    cout << "请输入该学生姓名:" << endl;
		string name = "";
	    cin >> name;

		cout<< "请输入该学生编号:" << endl;
		int num=0;
		cin >> num;

		cout<< "请输入该学生性别:" <<endl
			<<"1--男性，2--女性" << endl;
		int sex = 0;
		cin >> sex;

		cout<< "请输入该学生身份证号:" << endl;
		string id = "";
		cin >> id;

		cout<< "请输入该学生总学时数:" << endl;
		int sumtime = 0;
		cin >> sumtime;

		cout<< "请输入该学生每周固定学时数:" << endl;
		int weektime = 0;
		cin >> weektime;
		//开辟堆区，使用基类指针指向派生类对象
		people* p1 = new student(name, num, sex, id, sumtime, weektime);
		this->v.push_back(p1);
		
}
//添加教师类
void campusPeopleManage::addteacher()
{
	cout << "请输入该教师姓名:" << endl;
	string name = "";
	cin >> name;

	cout << "请输入该教师编号:" << endl;
	int num = 0;
	cin >> num;

	cout << "请输入该教师性别:" << endl
		<< "1--男性，2--女性" << endl;
	int sex = 0;
	cin >> sex;

	cout << "请输入该教师身份证号:" << endl;
	string id = "";
	cin >> id;

	cout << "请输入该教师总学时数:" << endl;
	int sumtime = 0;
	cin >> sumtime;

	cout << "请输入该教师每周固定学时数:" << endl;
	int weektime = 0;
	cin >> weektime;

	cout<< "请输入该教师每周教学时数为:" << endl;
	int weekTeatime = 0;
	cin >> weekTeatime;

	people* p1 = new teacher(name, num, sex, id, sumtime, weektime, weekTeatime);
	this->v.push_back(p1);

}
//添加研究生类
void campusPeopleManage::addgraduat()
{
	cout << "请输入该研究生姓名:" << endl;
	string name = "";
	cin >> name;

	cout << "请输入该研究生编号:" << endl;
	int num = 0;
	cin >> num;

	cout << "请输入该研究生性别:" << endl
		<< "1--男性，2--女性" << endl;
	int sex = 0;
	cin >> sex;

	cout << "请输入该研究生身份证号:" << endl;
	string id = "";
	cin >> id;

	cout << "请输入该研究生总学时数:" << endl;
	int sumtime = 0;
	cin >> sumtime;

	cout << "请输入该研究生每周固定学时数:" << endl;
	int weektime = 0;
	cin >> weektime;

	cout << "请输入该研究生每周研究时数为:"  << endl;
	int weekGratime = 0;
	cin >> weekGratime;



	people* p1 = new graduate(name, num, sex, id, sumtime, weektime,weekGratime);
	this->v.push_back(p1);

}
//添加TA类
void campusPeopleManage::addTA()
{
	cout << "请输入该助教姓名:" << endl;
	string name = "";
	cin >> name;

	cout << "请输入该助教编号:" << endl;
	int num = 0;
	cin >> num;

	cout << "请输入该助教性别:" << endl
		<< "1--男性，2--女性" << endl;
	int sex = 0;
	cin >> sex;

	cout << "请输入该助教身份证号:" << endl;
	string id = "";
	cin >> id;

	cout << "请输入该助教总学时数:" << endl;
	int sumtime = 0;
	cin >> sumtime;

	cout << "请输入该助教每周固定学时数:" << endl;
	int weektime = 0;
	cin >> weektime;

	cout << "请输入该助教每周教学时数为:" << endl;
	int weekTeatime = 0;
	cin >> weekTeatime;

	cout << "请输入该研究生每周研究时数为:" << endl;
	int weekGratime = 0;
	cin >> weekGratime;

	people* p1 = new TA(name, num, sex, id, sumtime, weektime, weekTeatime,weekGratime);
	this->v.push_back(p1);

}