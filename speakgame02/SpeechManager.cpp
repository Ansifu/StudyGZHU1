#include"SpeechManager.h"
//���캯��
SpeechManager::SpeechManager()
{
	//��ʼ������
	this->initSpeech();
	//����ѡ��
	this->createSpeaker();
}

//չʾ�˵�
void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//�˳�����
void SpeechManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��Ա���Գ�ʼ��
void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->vVictory.clear();

	this->m_Index = 1;

	

}

//����ѡ��  ���+ѡ�֣�����+������
void SpeechManager::createSpeaker()
{
	//����
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		speaker s;
		//	s.m_Name ="ѡ��" + name[i];

		string name = "ѡ��";
		name += nameSeed[i];

		s.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			s.m_Score[i] = 0;
		}
		//s.m_Score[0] =s.m_Score[1]= 0;  ��Ҫд���������ں���ά��

		int id = 10001 + i;
		this->m_Speaker.insert(make_pair(id, s));
		this->v1.push_back(id);
	}

}

//��ǩ--�������б�Ŵ���˳��
void SpeechManager::startDraw()
{
	cout << "��" << this->m_Index << "����ѡ�����ڳ�ǩ" << endl;
	cout << "-----------------------------------" << endl;
	cout << "��ǩ���ݽ�˳������:" << endl;
	//ͨ��indexѡȡ��ͬ��������
	if (this->m_Index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}

	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-----------------------------------" << endl;
	system("pause");
	cout << endl;
}

//��������
void SpeechManager::speech()
{
	/*for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
	{
		map<int, speaker>::iterator it0;
		it0 = this->m_Speaker.find(*it);
		it0->second.m_Score
	}*/

	cout << "---------------��" << this->m_Index << "�ֱ�����ʽ��ʼ------------------" << endl;

	vector<int>v_Src;//������Ա����

	if (this->m_Index == 1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}
	deque<double>scores;//��ųɼ�
	multimap<double, int, greater<double>>groupScore;//�ֳ����˱���С��

	int num = 0;//��¼����
	//����������
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//���
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			scores.push_back(score);
		}
		sort(scores.begin(), scores.end(), greater<double>());
		scores.pop_back();//ɾ����ͷ�
		scores.pop_front();//ɾ����߷�
		//��ʼΪ0.f
		double ave = accumulate(scores.begin(), scores.end(), 0.f)/scores.size();//��ȡƽ����
		scores.clear();//��ȡƽ���ֺ���շ�������

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = ave;

		groupScore.insert(make_pair(ave, *it));

		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С���������:" << endl;
			//�������������飬��ͨ��[]ȡ����������Ϣ
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���:" << it->second << " "
					<< "����:" << this->m_Speaker[it->second].m_Name << " "
					<< "�ɼ�:" << it->first << endl;

			}
			//ȡǰ�����ӽ�����������---��������

			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end()&&count<3; it++,count++)
			{
				if (this->m_Index == 1)
				{
					this->v2.push_back(it->second);
				}
				else
				{
					this->vVictory.push_back(it->second);
				}

			}

			groupScore.clear();
		}
	}
	cout << "---------------��" << this->m_Index << "�ֱ�����ʽ����------------------" << endl;
	system("pause");

}
//��ʾ������������ս��
void SpeechManager::showScore()
{
	cout << "---------------��" << this->m_Index << "�ֱ����������------------------" << endl;
	//������forѭ�������ٴ�����
	vector<int>v;
	if (this->m_Index == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->vVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ��:" << *it << "����:" << this->m_Speaker[*it].m_Name << "�÷�:" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;

	}
	cout << endl;
	system("pause");
	system("cls");
	
	/*if (this->m_Index == 1) this->m_Index = 2;
	else this->m_Index = 1;*/
}

//�����ʤѡ��
void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);

	for (vector<int>::iterator it = this->vVictory.begin(); it != this->vVictory.end(); it++)
	{
		ofs << *it << ","
			<< this->m_Speaker[*it].m_Name << ","
			<< this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	ofs.close();

	cout << "��¼�Ѿ�����" << endl;
}

//��ʼ����
void SpeechManager::startSpeech()
{
	//��һ�ֱ���
	//1.��ǩ
	startDraw();
	//2.����
	this->speech();
	//3.��ʾ�������
	this->showScore();
	//�ڶ��ֱ���
	this->m_Index++;//�ı������󣬽���ʱҪ��Ϊ1
	//1.��ǩ
	startDraw();
	//2.����
	this->speech();
	//3.��ʾ���ս��
	this->showScore();
	//4.�������
	this->saveRecord();
	cout << "���������ϣ�" << endl;

	system("pause");
	system("cls");
}

//��ȡ��¼
void SpeechManager::loadRecord()
{

	ifstream ifs;
	ifs.open("speech.csv", ios::in);
	if (ifs.is_open())
	{
		char ch;
		ifs >> ch;
		if (ifs.eof()) this->fileIsEmpty = true;
		else
		{
			this->fileIsEmpty = false;

			ifs.putback(ch);
		}
	}
    else this->fileIsEmpty = true;

	string date;
	//δ���

}


//�������� 
SpeechManager::~SpeechManager()
{

}
