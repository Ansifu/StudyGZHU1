#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>

class student
{
public:
	//¼��ɼ�
	void inputGrade();
	//��ȡ�ɼ�
	pair<int, double> outputGrade();
private:
	map<int, double>m_grade;
};
