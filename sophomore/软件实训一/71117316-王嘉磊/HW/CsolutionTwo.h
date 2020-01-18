#pragma once

// 此派生类中包含选择排序

#ifndef SOLUTIONTWO_H
#define SOLUTIONTWO_H

#include "CsolutionOne.h"

#define selectionSort 2

class solutionTwo : public solutionOne
{
	DECLARE_MESSAGE_MAP();

public:
	// 选择排序
	static void sSort(int*, int);
};

#endif 
