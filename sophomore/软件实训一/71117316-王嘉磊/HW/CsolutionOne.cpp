#include "CsolutionOne.h"

BEGIN_MESSAGE_MAP(solutionOne, cmdTarget)
	ON_MESSAGE(bubbleSort, bSort)
END_MESSAGE_MAP()

void solutionOne::bSort(int *arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
			if (arr[j] > arr[j + 1])
			{
				// ���н���
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
	}

	cout << "����������Ϊ��\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}