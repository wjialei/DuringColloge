#include "CsolutionThree.h"

BEGIN_MESSAGE_MAP(solutionThree, solutionTwo)
	ON_MESSAGE(quickSort, CqSort)
END_MESSAGE_MAP()

// 实现排序
void solutionThree::qSort(int *arr, int l, int element)
{
	if (l < element)
	{
		int i = l, j = element, x = arr[l];
		while (i < j)
		{
			while (i < j && arr[j] >= x)
				j--;
			if (i < j)
				arr[i++] = arr[j];
			while (i < j && arr[i] < x)
				i++;
			if (i < j)
				arr[j--] = arr[i];
		}
		arr[i] = x;
		qSort(arr, l, i - 1);
		qSort(arr, i + 1, element);
	}
}

// 实现输出
void solutionThree::CqSort(int arr[], int size)
{
	// 先排序
	qSort(arr, 0, size - 1);
	// 再输出
	cout << "排序后的数组为：\n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}