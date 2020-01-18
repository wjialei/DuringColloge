#pragma once
#ifndef STP_H
#define STP_H


#include <iostream>
#include <stack>

using namespace std;


#define LARGE 10000

bool *visited;
int *dist;
int v_num1 = 0;
int e_num1 = 0;
int **matrix;
int source;
int *path;
bool isHasNegative = false;
int minNegative = LARGE;

int Choose() {
	int min = LARGE;
	int r;
	for (int i = 0; i < v_num1; ++i) {
		if (visited[i] == false && dist[i] <= min) {
			min = dist[i];
			r = i;
		}
	}

	return r;
}

void ShortestPath(const int v) {
	//³õÊ¼»¯dist
	for (int i = 0; i < v_num1; ++i) {
		if (matrix[v][i] < LARGE&&i != v) {
			dist[i] = matrix[v][i];
			path[i] = v;
		}
		else {
			dist[i] = matrix[v][i];
			path[i] = -1;
		}

	}

	visited[v] = true;

	for (int i = 0; i < v_num1 - 1; ++i) {
		int u = Choose();
		visited[u] = true;
		for (int w = 0; w < v_num1; ++w)
			if (!visited[w] && dist[u] + matrix[u][w] < dist[w]) {
				dist[w] = dist[u] + matrix[u][w];
				path[w] = u;
			}

	}

}

int cnt;

void showPath(int v) {
	stack<int> s;
	while (v != source) {
		s.push(v);
		v = path[v];
	}
	s.push(v);
	cnt = s.size() - 1;
	//dist[v] -= cnt*minNegative;

	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}



void init() {
	cout << "Olease input the number of vertexs:";
	cin >> v_num1;
	cout << "Please input the number of edges:";
	cin >> e_num1;
	matrix = new int *[v_num1];
	for (int i = 0; i < v_num1; ++i)
		matrix[i] = new int[v_num1];
	for (int i = 0; i < v_num1; ++i)
		for (int j = 0; j < v_num1; ++j)
			matrix[i][j] = LARGE;
	cout << "please input the edge like 1 2 100" << endl;
	for (int i = 0; i < e_num1; ++i) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		if (w < 0) {
			isHasNegative = true;
			if (w < minNegative)
				minNegative = w;
		}
		matrix[v1][v2] = w;
	}
	for (int i = 0; i < v_num1; ++i)
		matrix[i][i] = 0;

	if (isHasNegative) {
		minNegative = -minNegative;
		for (int i = 0; i < v_num1; ++i)
			for (int j = 0; j < v_num1; ++j) {
				if (matrix[i][j] != 0 && matrix[i][j] < LARGE)
					matrix[i][j] += minNegative;
			}
	}

	visited = new bool[v_num1];
	fill(visited, visited + v_num1, false);

	dist = new int[v_num1];
	path = new int[v_num1];


	cout << "input the source vertex:";
	cin >> source;
}


#endif
