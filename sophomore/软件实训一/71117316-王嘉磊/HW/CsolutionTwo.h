#pragma once

// ���������а���ѡ������

#ifndef SOLUTIONTWO_H
#define SOLUTIONTWO_H

#include "CsolutionOne.h"

#define selectionSort 2

class solutionTwo : public solutionOne
{
	DECLARE_MESSAGE_MAP();

public:
	// ѡ������
	static void sSort(int*, int);
};

#endif 
