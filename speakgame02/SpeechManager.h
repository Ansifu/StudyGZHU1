#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include"speaker.h"
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>
#include<string>


//1.�û�����
//2.���Ʊ�������
//3.�ļ���д

//������
class SpeechManager
{
public:
	//���캯��
	SpeechManager();

	//չʾ�˵�
	void show_Menu();
	
	//��Ա���Գ�ʼ��
	void initSpeech();

	//����ѡ��
	void createSpeaker();

	//��ǩ--�������б�Ŵ���˳��
	void startDraw();

	//��������
	void speech();

	//��ʾ�������
	void showScore();

	//�����ʤѡ��
	void saveRecord();

	//��ʼ����
	void startSpeech();

	//��ȡ��¼
	void loadRecord();

	//�˳�����
	void ExitSystem();

		//��������
	~SpeechManager();
	
	//��Ա����
	//�����һ��ѡ�ֱ��
	vector<int>v1;
	
	//��һ�ֽ���ѡ�ֱ������
	vector<int>v2;

	//ʤ��ǰ��ѡ�ֱ��
	vector<int>vVictory;

	//���ѡ�ֱ�ż���Ӧѡ������
	map<int, speaker>m_Speaker;

	//��ű�������
	int m_Index;


	//��ȡ������س�Ա
	
	//�ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//����ÿ����Ϣ
	map<int, vector<string>>m_Record;//int--����  ��string���鱣��ÿ�����Ϣ
};