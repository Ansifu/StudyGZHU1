#include<iostream>
using namespace std;
#include<ctime>
#include<algorithm>
/*该程序通过抽象图形类派生出二维类和三维类，进而派生出具体的形状，
本程序的目的是要求出这些形状的名字，面积（表面积）以及体积*/ 

//抽象图形类
class Shape
{
public:
	//获取名称
	virtual string getN() = 0;
	//求面积
	virtual double getS() = 0;
	//求体积
	virtual double getV() = 0;


};
//二维类
class TwoDimShape :virtual public Shape
{
public:
	//重写求体积函数
	double getV() { return 0; };//二维图形体积一定为0



};

//三维类
class ThreeDimShape :virtual public Shape
{

};

//圆类
class circle :public TwoDimShape
{
public:
	//构造
	circle()
	{
		//随机生成其半径
		m_radius = rand() % 10 + 1;
	}
	//获取名称
	string getN()
	{
		string name = "circle";
		return name;
	}
	//获取面积
	double getS()
	{
		double s = 3.14 * m_radius * m_radius;
		return s;
	}

private:
	int m_radius;//半径
};

//矩形类
class rectangle :public TwoDimShape
{
public:
	//构造
	rectangle()
	{
		m_length = rand() % 10 + 1;
		m_width = rand() % 10 + 1;
	}
	//获取名称
	string getN()
	{
		string name = "rectangle";
		return name;
	}
	//获取面积
	double getS()
	{
		double s = m_length * m_width;
		return s;
	}

private:
	int m_length;//长
	int m_width;//宽
};

//三角形类
class triangle :public TwoDimShape
{
public:
	//构造
	triangle()
	{
		do
		{
			m_a = rand() % 10 + 1;
			m_b = rand() % 10 + 1;
			m_c = rand() % 10 + 1;
		} 
		while (2 * max({ m_a, m_b, m_c }) >= m_a + m_b + m_c);//检测是否满足形成三角形的条件
	}
	//获取名称
	string getN()
	{
		string name = "triangle";
		return name;
	}
	//获取面积
	double getS()
	{
		double p = (m_a + m_b + m_c) / 2.f;//注意不要使两个int数运算，否则p只能为int
		double s =sqrt(p*(p-m_a)*(p-m_b)*(p-m_c));
		return s;
	}

private:
	//三边
	int m_a;
	int m_b;
	int m_c;
};

//球体
class globe :public ThreeDimShape
{
public:
	//构造
	globe()
	{
		m_radius = rand() % 10 + 1;
	}
	//获取名称
	string getN()
	{
		string name = "globe";
		return name;
	}
	//获取表面积
	double getS()
	{
		double s = 4*3.14*m_radius * m_radius;
		return s;
	}
	//获取体积
	double getV()
	{
		double v = 4 * 3.14 * m_radius * m_radius * m_radius / 3;
		return v;
	}

private:
	int m_radius;//半径
};

//立方体类
class cube :public ThreeDimShape
{
public:
	//构造
	cube()
	{
		this->m_length = rand() % 10 + 1;	
		this->m_width = rand() % 10 + 1;
		this->m_height = rand() % 10 + 1;
	}
	//获取名称
	string getN()
	{
		string name = "cube";
		return name;
	}
	//获取面积
	double getS()
	{
		double s = 2*m_length*m_width+2*m_length*m_height+2*m_width*m_height;
		return s;
	}
	//获取体积
	double getV()
	{
		double v = m_length*m_width*m_height;
		return v;
	}

private:
	int m_length;//长
	int m_width;//宽
	int m_height;//高
};

//测试函数--求出名称、面积、体积
void test(Shape*testShape)
{
	string name = testShape->getN();
	double s = testShape->getS();
	double v = testShape->getV();

	cout << "该形状的名称为:" << name 
		<< "\t（表）面积为:" << s 
		<< "\t体积为:" << v << endl;
}
int main()
{
	srand((unsigned int)time(NULL));
    //进行测试

	//测试圆类
	circle c1;
	test(&c1);

	//测试矩形类
	rectangle r1;
	test(&r1);

	//测试三角形类
	triangle t1;
	test(&t1);

	//测试球类
	globe g1;
	test(&g1);

	//测试立方体类
	cube cu;
	test(&cu);

	return 0;
}