#include"SpeechManager.h"
//构造函数
SpeechManager::SpeechManager()
{
	//初始化容器
	this->initSpeech();
	//创建选手
	this->createSpeaker();
}

//展示菜单
void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

//退出功能
void SpeechManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//成员属性初始化
void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictory.clear();
	this->vVictory.clear();

	this->m_Index = 1;

	

}

//创建选手  编号+选手（姓名+分数）
void SpeechManager::createSpeaker()
{
	//姓名
	string nameSeed = "ABCDEFGHIJKL";

	for (int i = 0; i < nameSeed.size(); i++)
	{
		speaker s;
		//	s.m_Name ="选手" + name[i];

		string name = "选手";
		name += nameSeed[i];

		s.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			s.m_Score[i] = 0;
		}
		//s.m_Score[0] =s.m_Score[1]= 0;  不要写死，不利于后期维护

		int id = 10001 + i;
		this->m_Speaker.insert(make_pair(id, s));
		this->v1.push_back(id);
	}

}

//抽签--将容器中编号打乱顺序
void SpeechManager::startDraw()
{
	cout << "第" << this->m_Index << "比赛选手正在抽签" << endl;
	cout << "-----------------------------------" << endl;
	cout << "抽签后演讲顺序如下:" << endl;
	//通过index选取不同容器打乱
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

//比赛函数
void SpeechManager::speech()
{
	/*for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
	{
		map<int, speaker>::iterator it0;
		it0 = this->m_Speaker.find(*it);
		it0->second.m_Score
	}*/

	cout << "---------------第" << this->m_Index << "轮比赛正式开始------------------" << endl;

	vector<int>v_Src;//比赛人员容器

	if (this->m_Index == 1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}
	deque<double>scores;//存放成绩
	multimap<double, int, greater<double>>groupScore;//分成六人比赛小组

	int num = 0;//记录人数
	//遍历比赛组
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		//打分
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			scores.push_back(score);
		}
		sort(scores.begin(), scores.end(), greater<double>());
		scores.pop_back();//删除最低分
		scores.pop_front();//删除最高分
		//起始为0.f
		double ave = accumulate(scores.begin(), scores.end(), 0.f)/scores.size();//获取平均分
		scores.clear();//获取平均分后清空分数数组

		this->m_Speaker[*it].m_Score[this->m_Index - 1] = ave;

		groupScore.insert(make_pair(ave, *it));

		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次:" << endl;
			//遍历比赛六人组，并通过[]取出姓名等信息
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号:" << it->second << " "
					<< "姓名:" << this->m_Speaker[it->second].m_Name << " "
					<< "成绩:" << it->first << endl;

			}
			//取前三名扔进决赛组或获奖组---分组讨论

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
	cout << "---------------第" << this->m_Index << "轮比赛正式结束------------------" << endl;
	system("pause");

}
//显示晋级结果或最终结果
void SpeechManager::showScore()
{
	cout << "---------------第" << this->m_Index << "轮比赛结果如下------------------" << endl;
	//避免多次for循环，减少代码量
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
		cout << "选手编号:" << *it << "姓名:" << this->m_Speaker[*it].m_Name << "得分:" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;

	}
	cout << endl;
	system("pause");
	system("cls");
	
	/*if (this->m_Index == 1) this->m_Index = 2;
	else this->m_Index = 1;*/
}

//保存获胜选手
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

	cout << "记录已经保存" << endl;
}

//开始比赛
void SpeechManager::startSpeech()
{
	//第一轮比赛
	//1.抽签
	startDraw();
	//2.比赛
	this->speech();
	//3.显示晋级结果
	this->showScore();
	//第二轮比赛
	this->m_Index++;//改变轮数后，结束时要置为1
	//1.抽签
	startDraw();
	//2.比赛
	this->speech();
	//3.显示最终结果
	this->showScore();
	//4.保存分数
	this->saveRecord();
	cout << "本届比赛完毕！" << endl;

	system("pause");
	system("cls");
}

//读取记录
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
	//未完成

}


//析构函数 
SpeechManager::~SpeechManager()
{

}
