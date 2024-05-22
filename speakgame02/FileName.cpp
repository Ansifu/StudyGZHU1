#include<iostream>
using namespace std;
#include"SpeechManager.h"
#include<ctime>

int main()
{ 
	srand((unsigned int)time(NULL));
	SpeechManager m;

	

	int choice = 0;

	while (true)
	{
		//m.createSpeaker();
		////测试选手信息是否正常初始化
		//for (map<int, speaker>::iterator it = m.m_Speaker.begin(); it != m.m_Speaker.end(); it++)
		//{
		//	cout << "选手编号为:" << it->first
		//		<< "\t选手姓名为:" << it->second.m_Name
		//		<< "\t选手成绩为:" << it->second.m_Score[0] << endl;
		//}
		m.show_Menu();

		cout << "请输入您的选择:" << endl;

		cin >> choice;

		switch (choice)
		{
		case 0:
			//退出系统
			m.ExitSystem();
			break;
		case 1:
			//开始比赛
			m.startSpeech();
			break;
		case 2:
			//查看往届记录
			break;
		case 3:
			//清空记录
			break;
		default:
			cout << "非法输入，请重新输入" << endl;
			system("pause");
			system("cls");
			continue;
		}
		
		
	}


	system("pause");
	return 0;

}