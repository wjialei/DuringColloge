#include "CsolutionThree.h"

int main()
{
	solutionThree obj1;

	int *arr1;
	int size;
	unsigned choice;

	cout << "���������������е����ָ���" << endl;
	cin >> size;

	cout << "���������������е�����" << endl;
	arr1 = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arr1[i];
	}

	cout << "��ѡ���������򷽷���\n" << "\t����'1'����ð������\n" << "\t����'2'����ѡ������\n" << "\t����'3'�����������\n";
	cin >> choice;

	obj1.check(choice, arr1, size);
	while (1);
	return 0;
}