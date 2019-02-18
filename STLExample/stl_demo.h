#pragma once
#ifndef STL_DEMO_H
#define STL_DEMO_H

#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <time.h>
#include <stdlib.h>
#include <set>

using std::string;
using std::ifstream;

class StlDemo
{
public:
	StlDemo();
	~StlDemo();
	string RandChar(int len);
	void VectorDemo();
	void SetDemo();
private:

};

#endif // !STL_DEMO_H

