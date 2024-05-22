#include<iostream>
using namespace std;

class Shape
{
public:
	virtual string getN() = 0;
	virtual double getS() = 0;
	virtual double getV() = 0;

};

class TwoDimShape :public Shape
{
public:
	double getV() { return 0; };



};

class ThreeDimShape :public Shape
{

};

class circle :public TwoDimShape
{
public:
	circle()
	{
		m_radius = rand() % 10 + 1;
	}
	string getN()
	{
		string name = "circle";
		return name;
	}
	double getS()
	{
		double s = 3.14 * m_radius * m_radius;
		return s;
	}

private:
	int m_radius;
};

class rectangle :public TwoDimShape
{
public:
	rectangle()
	{
		m_length = rand() % 10 + 1;
		m_width = rand() % 10 + 1;
	}
	string getN()
	{
		string name = "rectangle";
		return name;
	}
	double getS()
	{
		double s = 3.14 * m_length * m_width;
		return s;
	}

private:
	int m_length;
	int m_width;
};
class triangle :public TwoDimShape
{
public:
	triangle()
	{
		do
		{
			m_a = rand() % 10 + 1;
			m_b = rand() % 10 + 1;
			m_c = rand() % 10 + 1;
		} 
		while (2 * max(m_a, m_b, m_c) >= m_a + m_b + m_c);
	}
	string getN()
	{
		string name = "triangle";
		return name;
	}
	double getS()
	{
		double p = (m_a + m_b + m_c) / 2;
		double s =sqrt(p*(p-m_a)*(p-m_b)*(p-m_c));
		return s;
	}

private:
	int m_a;
	int m_b;
	int m_c;
};


class globe :public ThreeDimShape
{
public:
	globe()
	{
		m_radius = rand() % 10 + 1;
	}
	string getN()
	{
		string name = "globe";
		return name;
	}
	double getS()
	{
		double s = 4*3.14*m_radius * m_radius;
		return s;
	}
	double getV()
	{
		double v = 4 * 3.14 * m_radius * m_radius * m_radius / 3;
		return v;
	}

private:
	int m_radius;
};

class cube :public ThreeDimShape
{
public:
	cube()
	{
		//Î´Íê³É
	}
	string getN()
	{
		string name = "cube";
		return name;
	}
	double getS()
	{
		double s = 2*m_length*m_width+2*m_length*m_height+2*m_width*m_height;
		return s;
	}
	double getV()
	{
		double v = m_length*m_width*m_height;
		return v;
	}

private:
	int m_length;
	int m_width;
	int m_height;
};

int main()
{

}