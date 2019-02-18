#include "pch.h"
#include "stl_demo.h"

using namespace std;

StlDemo::StlDemo()
{
}

StlDemo::~StlDemo()
{
}

string StlDemo::RandChar(int len = 16)
{
	string sChar;
	for (int i = 1; i <= len; i++)
	{
		int x, s;								//x��ʾ����ַ���ascii�� ��s��ʾ����ַ��Ĵ�Сд
		s = rand() % 2;							//���ʹsΪ1��0��Ϊ1���Ǵ�д��Ϊ0����Сд
		if (s == 1)								//���s=1
			x = rand() % ('Z' - 'A' + 1) + 'A'; //��x��Ϊ��д��ĸ��ascii��
		else
			x = rand() % ('z' - 'a' + 1) + 'a'; //���s=0��x��ΪСд��ĸ��ascii��
		sChar.push_back(x);						//��xת��Ϊ�ַ����
	}
	return sChar;
}

void StlDemo::VectorDemo()
{
	vector<int> int_vector;
	vector<double> double_vector;
	vector<string> string_vector;

	for (int i = 0; i < 36; i++)
	{
		int_vector.push_back(rand());
	}

	for (int j = 0; j < 24; j++)
	{
		double_vector.push_back(j * 1.23);
	}

	for (int k = 0; k < 18; k++)
	{
		string_vector.push_back(StlDemo::RandChar());
	}

	int size;
	size = int_vector.size();
	for (int i = 0; i < size; i++)
	{
		cout << int_vector[i] << "\t";
	}
	cout << endl;
	size = double_vector.size();
	for (int j = 0; j < size; j++)
	{
		cout << double_vector[j] << "\t";
	}
	cout << endl;
	size = string_vector.size();
	for (int k = 0; k < size; k++)
	{
		cout << string_vector[k] << "\t";
	}
	cout << endl;
}

void StlDemo::SetDemo()
{
	set<int> int_set;
	set<double> double_set;
	set<string> string_set;
	int size;

	for (int i = 0; i < 5; i++)
	{
		int_set.insert(rand());
	}

	for (int j = 0; j < 9; j++)
	{
		string_set.insert(StlDemo::RandChar());
	}

	size = int_set.size();
	cout << "int_set Ԫ�ظ�����" << size << endl;
	int first = *int_set.begin();
	cout << "int_set ��һ��Ԫ�أ�" << first << endl;
	int_set.erase(first);
	cout << "int_set ��һ��Ԫ�أ�" << *int_set.begin() << endl;
	cout << "int_set ���һ��Ԫ�أ�" << *int_set.end() << endl;
	size = string_set.size();
	cout << "string_set Ԫ�ظ�����" << size << endl;
	cout << "string_set ��һ��Ԫ�أ�" << *string_set.begin() << endl;
	//cout << "string_set ���һ��Ԫ�أ�" << *string_set.end() << endl;
}