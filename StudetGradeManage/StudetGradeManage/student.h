#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>

class student
{
public:
	//录入成绩
	void inputGrade();
	//读取成绩
	pair<int, double> outputGrade();
private:
	map<int, double>m_grade;
};
