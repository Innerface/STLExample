#pragma once
#ifndef MYSQL_DEMO_H
#define MYSQL_DEMO_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <WinSock.h>  //һ��Ҫ�������������winsock2.h
#include <Windows.h>
#include "mysql.h"

class MysqlDemo
{
public:
	MysqlDemo();
	~MysqlDemo();
	bool ConnectDatabase();     //��������
	void FreeConnect();
	bool QueryDatabase1();  //��ѯ1
	bool QueryDatabase2();  //��ѯ2
	bool InsertData();
	bool ModifyData();
	bool DeleteData();
private:

};

#endif // !MYSQL_DEMO_H
