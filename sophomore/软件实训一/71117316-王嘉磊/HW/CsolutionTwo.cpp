#include "CsolutionTwo.h"

BEGIN_MESSAGE_MAP(solutionTwo, solutionOne)
	ON_MESSAGE(selectionSort, sSort)
END_MESSAGE_MAP()

void solutionTwo::sSort(int*arr, int size)
{
	int a, temp;

	for (int i = 0; i < size - 1; i++)
	{
		a = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[a] < arr[j])
			{
				a = j;
			}
		}

		temp = arr[a];
		arr[a] = arr[i];
		arr[i] = temp;
	}

	cout << "排序后的数组为：\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}