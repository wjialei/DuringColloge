#pragma once

// ���������а���ð������

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
	// ð������
	static void bSort(int*, int);
};

#endif
