#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>


//people��
class people
{
	

	friend class showmanagel;
public:
	virtual void showinfo() = 0;

	
protected://ʹ�ñ����̳У�ʹ��������Լ̳�
	string m_name;
	int m_num;
	int m_sex;
	string m_id;
	int m_sumtime;
	int m_weektime;

};
//ѧ����
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
		cout << "��ѧ������Ϊ:" << this->m_name
			<< "\t���Ϊ:" << this->m_num;
		if (this->m_sex == 1)cout << "\t�Ա�Ϊ:����";
		else cout << "\t�Ա�Ϊ:Ů��";

		cout << "\t���֤��Ϊ" << this->m_id
			<< "\t��ѧʱ��Ϊ:" << this->m_sumtime
			<< "\tÿ�̶ܹ�ѧʱ��Ϊ:" << this->m_weektime<< endl;
	}

	
protected:

};
//��ʦ���˹̶���ѧʱ���⣬����ÿ�ܵĽ�ѧʱ����
//��ʦ��
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
		cout << "�ý�ʦ����Ϊ:" << this->m_name
			<< "\t���Ϊ:" << this->m_num;
		if (this->m_sex == 1)cout << "\t�Ա�Ϊ:����";
		else cout << "\t�Ա�Ϊ:Ů��";

		cout << "\t���֤��Ϊ" << this->m_id
			<< "\t��ѧʱ��Ϊ:" << this->m_sumtime
			<< "\tÿ�̶ܹ�ѧʱ��Ϊ:" << this->m_weektime
			<< "\tÿ�ܽ�ѧʱ��Ϊ:" << this->m_weekTeatime<< endl;
	}

	

protected:
	int m_weekTeatime;

};
// �о������˹̶���ѧʱ���⣬ÿ�ܻ�����������һ�����о���
//�о�����
//Ҫ�ȹ��츸��ȷ���ڴ棬����̬���н׶�ȷ���ڴ�
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
		cout << "���о�������Ϊ:" << this->m_name
			<< "\t���Ϊ:" << this->m_num;
		if (this->m_sex == 1)cout << "\t�Ա�Ϊ:����";
		else cout << "\t�Ա�Ϊ:Ů��";

		cout << "\t���֤��Ϊ" << this->m_id
			<< "\t��ѧʱ��Ϊ:" << this->m_sumtime
			<< "\tÿ�̶ܹ�ѧʱ��Ϊ:" << this->m_weektime
			<< "\tÿ���о�ʱ��Ϊ:" << this->m_weekGratime << endl;
	}

	
protected:
	int m_weekGratime;
};
//�����������Ͽ��⣬��Ҫ���о���һ���Ľ�ѧ����
//������
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
		cout << "����������Ϊ:" << this->m_name
			<< "\t���Ϊ:" << this->m_num;
			if (this->m_sex == 1)cout << "\t�Ա�Ϊ:����";
			else cout << "\t�Ա�Ϊ:Ů��";

		cout<< "\t���֤��Ϊ" << this->m_id 
			<< "\t��ѧʱ��Ϊ:" << this->m_sumtime 
			<< "\tÿ�̶ܹ�ѧʱ��Ϊ:" << this->m_weektime 
			<< "\tÿ�ܽ�ѧʱ��Ϊ:" << this->m_weekTeatime
			<< "\tÿ���о�ʱ��Ϊ:" << this->m_weekGratime << endl;
	}

	
protected:

};
//��ӡ�º���
class showmanagel
{
public:
	void operator()(people* p)
	{
		p->showinfo();
	}
};
//У԰����ϵͳ��
class campusPeopleManage
{
public:
	//��ʾ�˵�
	void show_menu()
	{
		cout << "*************��ӭʹ��У԰��Ա����ϵͳ************" << endl
			<< "*************����������ѡ��**********************" << endl
			<< "***1--��Ա¼��   2--�鿴��Ա��Ϣ   0--�˳�ϵͳ***" << endl
			<< "**************************************************" << endl;
	}
	//��Ա��Ϣ¼��
	void addstudent();
	void addteacher();
	void addgraduat();
	void addTA();

	//¼����Ա
	void addpeople()
	{
		int num = 0;
		cout << "��ѡ����Ҫ¼�������" << endl;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			int choice = 0;
			cout << "��ѡ��¼����Ա���:" << endl
				<< "1--ѧ����2--��ʦ��3--�о�����4--����" << endl;
			cin >> choice;
			switch (choice)
			{
			case 1:
				addstudent();//���ѧ��
				break;
			case 2:
				addteacher();//��ӽ�ʦ
				break;
			case 3:
				addgraduat();//����о���
				break;
			case 4:
				addTA();//���TA
				break;

			default://Ԥ��
				cout << "�Ƿ����룬����������" << endl;
				i--;
				break;
			}
			cout << endl;
		}
		system("pause");
		system("cls");
	}
	//��ʾ��Ϣ
	void showmanage()
	{
		for_each(v.begin(), v.end(), showmanagel());//�������飬��ӡ��Ա��Ϣ
		system("pause");
		system("cls");
	}
	
	//��������--�������ͷ�
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
	vector<people*>v;//����people��������������ࣨ��̬��
};
int main()
{
	campusPeopleManage m1;
	int choice = 0;
	while (true)
	{
		//�˵�����
		m1.show_menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			//¼����Ա
			m1.addpeople();
			break;
		case 2:
			//��ʾ��Ա��Ϣ
			m1.showmanage();
			break;
		case 0://�˳�����
			exit(0);
			break;
		default:
			cout << "�Ƿ����룬����������" << endl;

			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}
//���ѧ����
void campusPeopleManage::addstudent()
{
	    cout << "�������ѧ������:" << endl;
		string name = "";
	    cin >> name;

		cout<< "�������ѧ�����:" << endl;
		int num=0;
		cin >> num;

		cout<< "�������ѧ���Ա�:" <<endl
			<<"1--���ԣ�2--Ů��" << endl;
		int sex = 0;
		cin >> sex;

		cout<< "�������ѧ�����֤��:" << endl;
		string id = "";
		cin >> id;

		cout<< "�������ѧ����ѧʱ��:" << endl;
		int sumtime = 0;
		cin >> sumtime;

		cout<< "�������ѧ��ÿ�̶ܹ�ѧʱ��:" << endl;
		int weektime = 0;
		cin >> weektime;
		//���ٶ�����ʹ�û���ָ��ָ�����������
		people* p1 = new student(name, num, sex, id, sumtime, weektime);
		this->v.push_back(p1);
		
}
//��ӽ�ʦ��
void campusPeopleManage::addteacher()
{
	cout << "������ý�ʦ����:" << endl;
	string name = "";
	cin >> name;

	cout << "������ý�ʦ���:" << endl;
	int num = 0;
	cin >> num;

	cout << "������ý�ʦ�Ա�:" << endl
		<< "1--���ԣ�2--Ů��" << endl;
	int sex = 0;
	cin >> sex;

	cout << "������ý�ʦ���֤��:" << endl;
	string id = "";
	cin >> id;

	cout << "������ý�ʦ��ѧʱ��:" << endl;
	int sumtime = 0;
	cin >> sumtime;

	cout << "������ý�ʦÿ�̶ܹ�ѧʱ��:" << endl;
	int weektime = 0;
	cin >> weektime;

	cout<< "������ý�ʦÿ�ܽ�ѧʱ��Ϊ:" << endl;
	int weekTeatime = 0;
	cin >> weekTeatime;

	people* p1 = new teacher(name, num, sex, id, sumtime, weektime, weekTeatime);
	this->v.push_back(p1);

}
//����о�����
void campusPeopleManage::addgraduat()
{
	cout << "��������о�������:" << endl;
	string name = "";
	cin >> name;

	cout << "��������о������:" << endl;
	int num = 0;
	cin >> num;

	cout << "��������о����Ա�:" << endl
		<< "1--���ԣ�2--Ů��" << endl;
	int sex = 0;
	cin >> sex;

	cout << "��������о������֤��:" << endl;
	string id = "";
	cin >> id;

	cout << "��������о�����ѧʱ��:" << endl;
	int sumtime = 0;
	cin >> sumtime;

	cout << "��������о���ÿ�̶ܹ�ѧʱ��:" << endl;
	int weektime = 0;
	cin >> weektime;

	cout << "��������о���ÿ���о�ʱ��Ϊ:"  << endl;
	int weekGratime = 0;
	cin >> weekGratime;



	people* p1 = new graduate(name, num, sex, id, sumtime, weektime,weekGratime);
	this->v.push_back(p1);

}
//���TA��
void campusPeopleManage::addTA()
{
	cout << "���������������:" << endl;
	string name = "";
	cin >> name;

	cout << "����������̱��:" << endl;
	int num = 0;
	cin >> num;

	cout << "������������Ա�:" << endl
		<< "1--���ԣ�2--Ů��" << endl;
	int sex = 0;
	cin >> sex;

	cout << "��������������֤��:" << endl;
	string id = "";
	cin >> id;

	cout << "�������������ѧʱ��:" << endl;
	int sumtime = 0;
	cin >> sumtime;

	cout << "�����������ÿ�̶ܹ�ѧʱ��:" << endl;
	int weektime = 0;
	cin >> weektime;

	cout << "�����������ÿ�ܽ�ѧʱ��Ϊ:" << endl;
	int weekTeatime = 0;
	cin >> weekTeatime;

	cout << "��������о���ÿ���о�ʱ��Ϊ:" << endl;
	int weekGratime = 0;
	cin >> weekGratime;

	people* p1 = new TA(name, num, sex, id, sumtime, weektime, weekTeatime,weekGratime);
	this->v.push_back(p1);

}