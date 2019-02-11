// STLExample.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <io.h>
#include "md5.h"

using namespace std;

///<summary>
/// 功能:字符串转字符
/// 作者:YuYuE
/// 日期:2019-01-08
///</summary>   
char* string2char(string str) {
	int nStrLength = str.length();
	char chStr[255];
	int i;
	for (i = 0; i < nStrLength; i++)
		chStr[i] = str[i];
	chStr[i] = '\0';
	return chStr;
}

int testString() {
	string s1;//初始化字符串，空字符串
	string s2 = s1; //拷贝初始化，深拷贝字符串
	string s3 = "I am Yasuo"; //直接初始化，s3存了字符串
	string s4(10, 'a'); //s4存的字符串是aaaaaaaaaa
	string s5(s4); //拷贝初始化，深拷贝字符串
	string s6("I am Ali"); //直接初始化
	string s7 = string(6, 'c'); //拷贝初始化，cccccc

	//string的各种操作
	string s8 = s3 + s6;//将两个字符串合并成一个
	s3 = s6;//用一个字符串来替代另一个字符串的对用元素

	cin >> s1;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;
	cout << s8 << endl;
	cout << "s7 size = " << s7.size() << endl; //字符串长度，不包括结束符
	cout << (s2.empty() ? "This string is empty" : "This string is not empty") << endl;

	system("pause");
	return 0;
}

template <typename T>
void showvector(vector<T> v)
{
	for (vector<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it;
	}
	cout << endl;
}
int testVector() {
	vector<string> v6 = { "hi","my","name","is","lee" };
	v6.resize(3);  //重新调整vector容量大小
	showvector(v6);

	vector<int> v5 = { 1,2,3,4,5 }; //列表初始化,注意使用的是花括号
	cout << v5.front() << endl; //访问第一个元素
	cout << v5.back() << endl; //访问最后一个元素

	showvector(v5);
	v5.pop_back(); //删除最后一个元素
	showvector(v5);
	v5.push_back(6); //加入一个元素并把它放在最后
	showvector(v5);
	v5.insert(v5.begin() + 1, 9); //在第二个位置插入新元素
	showvector(v5);
	v5.erase(v5.begin() + 3);  //删除第四个元素
	showvector(v5);
	v5.insert(v5.begin() + 1, 7, 8); //连续插入7个8
	showvector(v5);
	v5.clear(); //清除所有内容
	showvector(v5);

	system("pause");
	return 0;
}

bool isOdd(int a) {
	return (a % 2 == 1);
}

int testVector2() {
	vector<int> vec;
	vector<int>::iterator it, it2;
	for (int i = 0; i < 10; i++) {
		int a;
		cin >> a;
		vec.push_back(a);
	}
	cout << "输入要移除的数 ";
	int n;
	cin >> n;
	it = remove(vec.begin(), vec.end(), n); /*将移除n后的vector的迭代器的最后值
											复制给it*/
	for (it2 = vec.begin(); it2 != it; it2++) {
		cout << *it2 << " ";
	}
	cout << endl;
	cout << "紧接着移除奇数" << endl;
	it2 = it; /*这一步将我们上一步所得的vector传递下来*/
	it = remove_if(vec.begin(), it2, isOdd);
	for (it2 = vec.begin(); it2 != it; it2++) {
		cout << *it2 << " ";
	}
	return 0;
}

template <typename T>
void showset(set<T> v)
{
	for (set<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it;
	}
	cout << endl;
}

int testSet()
{
	set<int> s1{ 9,8,1,2,3,4,5,5,5,6,7,7 }; //自动排序，从小到大,剔除相同项
	showset(s1);
	set<string> s2{ "hello","sysy","school","hello" }; //字典序排序
	showset(s2);
	s1.insert(9); //有这个值了，do nothing
	showset(s1);
	s2.insert("aaa"); //没有这个字符串，添加并且排序
	showset(s2);

	system("pause");
	return 0;
}

template <typename T>
void showlist(list<T> v)
{
	for (list<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it;
	}
	cout << endl;
}

int testList()
{
	list<int> l1{ 1,2,3,4,5,5,6,7,7 };
	showlist(l1);
	list<double> l2;
	list<char> l3(10);
	list<int> l4(5, 10); //将元素都初始化为10
	showlist(l4);

	system("pause");
	return 0;
}

void showmap(map<string, int> v)
{
	for (map<string, int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << it->first << "  " << it->second << endl;  //注意用法，不是用*it来访问了。first表示的是key，second存的是value
	}
	cout << endl;
}

int testMap()
{
	map<string, int> m1; //<>里的第一个参数表示key的类型,第二个参数表示value的类型
	m1["Kobe"] = 100;
	m1["James"] = 99;
	m1["Curry"] = 98;

	string s("Jordan");
	m1[s] = 90;

	cout << m1["Kobe"] << endl;
	cout << m1["Jordan"] << endl;
	cout << m1["Durant"] << endl; //不存在这个key，就显示0

	m1.erase("Curry");//通过关键字来删除
	showmap(m1);
	m1.insert(pair<string, int>("Harris", 89)); //也可以通过insert函数来实现增加元素
	showmap(m1);
	m1.clear(); //清空全部

	system("pause");
	return 0;
}

int testStack() {

	// 创建堆栈对象
	stack<int> s;
	// 元素入栈
	s.push(3);
	s.push(19);
	s.push(23);
	s.push(36);
	s.push(50);
	s.push(4);

	// 元素依次出栈
	while (!s.empty())
	{
		// 打印栈顶元素，打印出：4 50 36 23 19 3
		cout << s.top() << endl;
		// 出栈
		s.pop();
	}

	system("pause");
	return 0;
}


#define STACK_SIZE  100   // 堆栈最大容量
int testListStack() {

	// 用双向链表作堆栈的底层结构
	stack<int, list<int> >   s;
	// 堆栈未满，元素才能入栈
	if (s.size() < STACK_SIZE)
		s.push(68);
	if (s.size() < STACK_SIZE)
		s.push(1);
	if (s.size() < STACK_SIZE)
		s.push(17);
	// 元素出栈
	while (!s.empty())
	{
		// 打印 17 1 68
		cout << s.top() << endl;
		s.pop();
	}

	system("pause");
	return 0;
}

void clearQueue(queue<int>&q)
{
	queue<int>empty;
	swap(empty, q);
}

int testQueue()
{
	queue<int>q;
	q.push(1);                //在队列末尾依次插入1 2 3 
	q.push(2);
	q.push(3);
	int u = q.back();            //返回队列中最后一个元素 
	cout << "队列最后一个元素为：" << u << endl;
	int v = q.front();        //返回队列中第一个元素 
	cout << "队列第一个元素为:" << v << endl;
	q.pop();                //删除第一个元素 
	v = q.front();
	cout << "队列第一个元素为：" << v << endl;
	int size = q.size();                //size返回元素个数 
	cout << "队列中存在" << size << "个元素" << endl;
	cout << "判断队列是否为空，空输出1 否则输出1：" << endl;
	int flag = q.empty();            //判断队列是否为空，为空返回1，否则返回0 
	cout << flag << endl;
	//情况queue的三种方法    
	/*    q=queue<int>();*/

	/*    while(!q.empty())
			q.pop();*/

	clearQueue(q);                //queue中没有clear操作，用函数定义clear函数，使用swap 
	cout << q.empty() << endl;

	system("pause");
	return 0;
}

int testDeque() {
	deque<int>q;
	for (int i = 0; i < 100; i++) q.push_back(i);
	printf("size1:%d\n", q.size());
	q.push_front(-1);
	printf("q[0]:%d\tsize2:%d\n", q.at(0), q.size());
	q.pop_front();
	printf("q[0]:%d\tsize3:%d\n", q.at(0), q.size());
	q.resize(0);
	printf("q.empty():%d\n", q.empty());

	system("pause");
	return 0;
}

int main()
{
    std::cout << "Hello World!\n"; 
	system("pause");
	testQueue();
	return 0;
}