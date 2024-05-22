#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>
//学校里，主要有四类人员：大学本科学生、教师、研究生和助教。
//大学本科生每周有固定的学时数。。
//人员的基本信息包括姓名、编号、性别、身份证号、总学时数以及每周固定学时数。各个人员之间的关系：
//people类派生出student 类和teacher类，student 类派生出graduate类， graduate类和teacher类派生出TA类。

//people类
class people
{
	friend class student;
	friend class teacher;
	friend class graduate;
	friend class TA;

	friend class showmanagel;
public:
	virtual void showinfo() = 0;
private:
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
	friend class graduate;
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
private:

};
//教师除了固定的学时数外，还有每周的教学时数。
//教师类
class teacher : virtual public people
{
	friend class TA;
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
		cout << "该教学姓名为:" << this->m_name
			<< "\t编号为:" << this->m_num;
		if (this->m_sex == 1)cout << "\t性别为:男生";
		else cout << "\t性别为:女生";

		cout << "\t身份证号为" << this->m_id
			<< "\t总学时数为:" << this->m_sumtime
			<< "\t每周固定学时数为:" << this->m_weektime
			<< "\t每周教学时数为:" << this->m_weekTeatime<< endl;
	}
private:
	int m_weekTeatime;

};
// 研究生除了固定的学时数外，每周还可以自由做一定的研究。
//研究生类
//要先构造父类确定内存，而多态运行阶段确定内存
class graduate : public student
{
	friend class TA;
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
private:
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
private:

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
class campuspeoplemanage
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
				addstudent();
				break;
			case 2:
				addteacher();
				break;
			case 3:
				addgraduat();
				break;
			case 4:
				addTA();
				break;
			}
			system("cls");
		}
	}
	//显示信息
	void showmanage()
	{
		for_each(v.begin(), v.end(), showmanagel());
		/*for (vector<people*>::iterator it = v.begin(); it != v.end(); it++)
		{
			(*it)->showinfo();
		}*/
		system("pause");
		system("cls");
	}
	
private:
	vector<people*>v;
};
int main()
{
	campuspeoplemanage m1;
	int choice = 0;
	while (true)
	{
		m1.show_menu();
		cout << "请输入您的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			m1.addpeople();
			break;
		case 2:
			m1.showmanage();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << "非法输入，请重新输入" << endl;
			cin >> choice;
			break;
		}
	}

	return 0;
}

void campuspeoplemanage::addstudent()
{
	    cout << "请输入该学生姓名:" << endl;
		string name = {};
	    cin >> name;

		cout<< "请输入该学生编号:" << endl;
		int num=0;
		cin >> num;

		cout<< "请输入该学生性别:" <<endl
			<<"1--男性，2--女性" << endl;
		int sex = 0;
		cin >> sex;

		cout<< "请输入该学生身份证号:" << endl;
		string id = {};
		cin >> id;

		cout<< "请输入该学生总学时数:" << endl;
		int sumtime = 0;
		cin >> sumtime;

		cout<< "请输入该学生每周固定学时数:" << endl;
		int weektime = 0;
		cin >> weektime;

		people* p1 = new student(name, num, sex, id, sumtime, weektime);
		this->v.push_back(p1);
		
}
void campuspeoplemanage::addteacher()
{
	cout << "请输入该教师姓名:" << endl;
	string name = {};
	cin >> name;

	cout << "请输入该教师编号:" << endl;
	int num = 0;
	cin >> num;

	cout << "请输入该教师性别:" << endl
		<< "1--男性，2--女性" << endl;
	int sex = 0;
	cin >> sex;

	cout << "请输入该教师身份证号:" << endl;
	string id = {};
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

void campuspeoplemanage::addgraduat()
{
	cout << "请输入该研究生姓名:" << endl;
	string name = {};
	cin >> name;

	cout << "请输入该研究生编号:" << endl;
	int num = 0;
	cin >> num;

	cout << "请输入该研究生性别:" << endl
		<< "1--男性，2--女性" << endl;
	int sex = 0;
	cin >> sex;

	cout << "请输入该研究生身份证号:" << endl;
	string id = {};
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

void campuspeoplemanage::addTA()
{
	cout << "请输入该助教姓名:" << endl;
	string name = {};
	cin >> name;

	cout << "请输入该助教编号:" << endl;
	int num = 0;
	cin >> num;

	cout << "请输入该助教性别:" << endl
		<< "1--男性，2--女性" << endl;
	int sex = 0;
	cin >> sex;

	cout << "请输入该助教身份证号:" << endl;
	string id = {};
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