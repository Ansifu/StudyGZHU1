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
		////����ѡ����Ϣ�Ƿ�������ʼ��
		//for (map<int, speaker>::iterator it = m.m_Speaker.begin(); it != m.m_Speaker.end(); it++)
		//{
		//	cout << "ѡ�ֱ��Ϊ:" << it->first
		//		<< "\tѡ������Ϊ:" << it->second.m_Name
		//		<< "\tѡ�ֳɼ�Ϊ:" << it->second.m_Score[0] << endl;
		//}
		m.show_Menu();

		cout << "����������ѡ��:" << endl;

		cin >> choice;

		switch (choice)
		{
		case 0:
			//�˳�ϵͳ
			m.ExitSystem();
			break;
		case 1:
			//��ʼ����
			m.startSpeech();
			break;
		case 2:
			//�鿴�����¼
			break;
		case 3:
			//��ռ�¼
			break;
		default:
			cout << "�Ƿ����룬����������" << endl;
			system("pause");
			system("cls");
			continue;
		}
		
		
	}


	system("pause");
	return 0;

}