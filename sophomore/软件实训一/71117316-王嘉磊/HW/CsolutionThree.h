#pragma once

// ���������а�����������

#ifndef SOLUTIONTHREE_H
#define SOLUTIONTHREE_H

#include "CsolutionTwo.h"

#define quickSort 3

class solutionThree : public solutionTwo
{
	DECLARE_MESSAGE_MAP();

public:
	// ��������
	static void qSort(int*, int, int);
	// ������
	static void CqSort(int*, int);
};

#endif
