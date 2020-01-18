#pragma once

// 此派生类中包含冒泡排序

#ifndef SOLUTIONONE_H
#define SOLUTIONONE_H

#include "CcmdTarget.h"

#include <iostream>
using namespace std;

#define bubbleSort 1

class solutionOne : public cmdTarget
{
	DECLARE_MESSAGE_MAP();

public:
	// 冒泡排序
	static void bSort(int*, int);
};

#endif
