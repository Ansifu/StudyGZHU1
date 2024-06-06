#include<iostream>
using namespace std;
#include<ctime>
#include<algorithm>
/*�ó���ͨ������ͼ������������ά�����ά�࣬�����������������״��
�������Ŀ����Ҫ�����Щ��״�����֣��������������Լ����*/ 

//����ͼ����
class Shape
{
public:
	//��ȡ����
	virtual string getN() = 0;
	//�����
	virtual double getS() = 0;
	//�����
	virtual double getV() = 0;


};
//��ά��
class TwoDimShape :virtual public Shape
{
public:
	//��д���������
	double getV() { return 0; };//��άͼ�����һ��Ϊ0



};

//��ά��
class ThreeDimShape :virtual public Shape
{

};

//Բ��
class circle :public TwoDimShape
{
public:
	//����
	circle()
	{
		//���������뾶
		m_radius = rand() % 10 + 1;
	}
	//��ȡ����
	string getN()
	{
		string name = "circle";
		return name;
	}
	//��ȡ���
	double getS()
	{
		double s = 3.14 * m_radius * m_radius;
		return s;
	}

private:
	int m_radius;//�뾶
};

//������
class rectangle :public TwoDimShape
{
public:
	//����
	rectangle()
	{
		m_length = rand() % 10 + 1;
		m_width = rand() % 10 + 1;
	}
	//��ȡ����
	string getN()
	{
		string name = "rectangle";
		return name;
	}
	//��ȡ���
	double getS()
	{
		double s = m_length * m_width;
		return s;
	}

private:
	int m_length;//��
	int m_width;//��
};

//��������
class triangle :public TwoDimShape
{
public:
	//����
	triangle()
	{
		do
		{
			m_a = rand() % 10 + 1;
			m_b = rand() % 10 + 1;
			m_c = rand() % 10 + 1;
		} 
		while (2 * max({ m_a, m_b, m_c }) >= m_a + m_b + m_c);//����Ƿ������γ������ε�����
	}
	//��ȡ����
	string getN()
	{
		string name = "triangle";
		return name;
	}
	//��ȡ���
	double getS()
	{
		double p = (m_a + m_b + m_c) / 2.f;//ע�ⲻҪʹ����int�����㣬����pֻ��Ϊint
		double s =sqrt(p*(p-m_a)*(p-m_b)*(p-m_c));
		return s;
	}

private:
	//����
	int m_a;
	int m_b;
	int m_c;
};

//����
class globe :public ThreeDimShape
{
public:
	//����
	globe()
	{
		m_radius = rand() % 10 + 1;
	}
	//��ȡ����
	string getN()
	{
		string name = "globe";
		return name;
	}
	//��ȡ�����
	double getS()
	{
		double s = 4*3.14*m_radius * m_radius;
		return s;
	}
	//��ȡ���
	double getV()
	{
		double v = 4 * 3.14 * m_radius * m_radius * m_radius / 3;
		return v;
	}

private:
	int m_radius;//�뾶
};

//��������
class cube :public ThreeDimShape
{
public:
	//����
	cube()
	{
		this->m_length = rand() % 10 + 1;	
		this->m_width = rand() % 10 + 1;
		this->m_height = rand() % 10 + 1;
	}
	//��ȡ����
	string getN()
	{
		string name = "cube";
		return name;
	}
	//��ȡ���
	double getS()
	{
		double s = 2*m_length*m_width+2*m_length*m_height+2*m_width*m_height;
		return s;
	}
	//��ȡ���
	double getV()
	{
		double v = m_length*m_width*m_height;
		return v;
	}

private:
	int m_length;//��
	int m_width;//��
	int m_height;//��
};

//���Ժ���--������ơ���������
void test(Shape*testShape)
{
	string name = testShape->getN();
	double s = testShape->getS();
	double v = testShape->getV();

	cout << "����״������Ϊ:" << name 
		<< "\t�������Ϊ:" << s 
		<< "\t���Ϊ:" << v << endl;
}
int main()
{
	srand((unsigned int)time(NULL));
    //���в���

	//����Բ��
	circle c1;
	test(&c1);

	//���Ծ�����
	rectangle r1;
	test(&r1);

	//������������
	triangle t1;
	test(&t1);

	//��������
	globe g1;
	test(&g1);

	//������������
	cube cu;
	test(&cu);

	return 0;
}