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


//1.用户交互
//2.控制比赛流程
//3.文件读写

//管理类
class SpeechManager
{
public:
	//构造函数
	SpeechManager();

	//展示菜单
	void show_Menu();
	
	//成员属性初始化
	void initSpeech();

	//创建选手
	void createSpeaker();

	//抽签--将容器中编号打乱顺序
	void startDraw();

	//比赛函数
	void speech();
	//开始比赛
	void startSpeech();

	

	//退出功能
	void ExitSystem();

		//析构函数
	~SpeechManager();
	
	//成员属性
	//保存第一轮选手编号
	vector<int>v1;
	
	//第一轮晋级选手编号容器
	vector<int>v2;

	//胜出前三选手编号
	vector<int>vVictory;

	//存放选手编号及对应选手容器
	map<int, speaker>m_Speaker;

	//存放比赛轮数
	int m_Index;
};