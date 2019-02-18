// STLExample.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <io.h>
#include "stl_demo.h"
#include <winsock.h>
#include "stdio.h"

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

int main()
{
    std::cout << "Hello World!\n"; 
	system("pause");
	//testQueue();
	StlDemo stl;
	stl.VectorDemo();

	return 0;
}