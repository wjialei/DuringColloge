#include"DblList.h"

void main()
{
	DblList my;
	DblList list;

	for (int i = 0; i < 5; i++)
	{
		DblListNode *myNode = new DblListNode(i);
		my.Insert(myNode, my.getFirst());
	}

	for (int i = 3; i < 6; i++)
	{
		DblListNode *listNode = new DblListNode(i);
		list.Insert(listNode, list.getFirst());
	}

	cout << "Create list1 and add 43210 to it...\n"
		<< "Now print list1:\n";
	my.print();
	cout << endl;
	cout << "\nCreate list2 and add 543 to it...\n"
		<< "Now print list2:\n";
	list.print();
	cout << endl;

	cout << "\nComposing:\n\n"
		<< "Now list1:\n";
	my.Concatenate(list);
	my.print();
	cout << endl;
	cout << "List2:";
	list.print();
	cout << endl;

	while (1);
}
