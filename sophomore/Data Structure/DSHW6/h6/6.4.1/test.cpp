#include "STP.h"

void main() {
	init();

	ShortestPath(source);

	for (int i = 0; i < v_num1; ++i) {
		showPath(i);
		cout << "   the length of the path is " << dist[i] << endl;
	}

	for (int i = 0; i < v_num1; ++i)
		delete[]matrix[i];
	delete[]matrix;

	while (1);

}
