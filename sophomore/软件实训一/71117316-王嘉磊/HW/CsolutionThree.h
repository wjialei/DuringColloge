#pragma once

// 此派生类中包含快速排序

#ifndef SOLUTIONTHREE_H
#define SOLUTIONTHREE_H

#include "CsolutionTwo.h"

#define quickSort 3

class solutionThree : public solutionTwo
{
	DECLARE_MESSAGE_MAP();

public:
	// 快速排序
	static void qSort(int*, int, int);
	// 输出结果
	static void CqSort(int*, int);
};

#endif
