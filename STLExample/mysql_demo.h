#pragma once
#ifndef MYSQL_DEMO_H
#define MYSQL_DEMO_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <WinSock.h>  //一定要包含这个，或者winsock2.h
#include <Windows.h>
#include "mysql.h"

class MysqlDemo
{
public:
	MysqlDemo();
	~MysqlDemo();
	bool ConnectDatabase();     //函数声明
	void FreeConnect();
	bool QueryDatabase1();  //查询1
	bool QueryDatabase2();  //查询2
	bool InsertData();
	bool ModifyData();
	bool DeleteData();
private:

};

#endif // !MYSQL_DEMO_H
