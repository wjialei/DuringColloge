#include "CsolutionThree.h"

int main()
{
	solutionThree obj1;

	int *arr1;
	int size;
	unsigned choice;

	cout << "请输入您所需排列的数字个数" << endl;
	cin >> size;

	cout << "请输入您所需排列的数字" << endl;
	arr1 = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arr1[i];
	}

	cout << "请选择您的排序方法：\n" << "\t输入'1'代表冒泡排序\n" << "\t输入'2'代表选择排序\n" << "\t输入'3'代表快速排序\n";
	cin >> choice;

	obj1.check(choice, arr1, size);
	while (1);
	return 0;
}