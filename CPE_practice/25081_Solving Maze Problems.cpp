#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <utility>
#include <algorithm>

#define PI atan(1) * 4
#define ll long long int
#define ull unsigned long long
using namespace std;

struct dot {
	int x;
	int y;

};

dot start, destination;
char maze[10][10];
bool was_here[10][10];
bool correct_path[10][10];

bool recursive_find_path(int x, int y) {
	if (x == destination.x && y == destination.y) {
		correct_path[x][y] = true;
		return true;
	}
	if (maze[x][y] == '#' || was_here[x][y]) {
		return false;
	}

	was_here[x][y] = true;

	if (x != 0) {					//test up edge
		if (recursive_find_path(x - 1, y)) {
			correct_path[x][y] = true;
			return true;
		}
	}
	if (x != 9) {					//test down edge
		if (recursive_find_path(x + 1, y)) {
			correct_path[x][y] = true;
			return true;
		}
	}
	if (y != 0) {					//test left edge
		if (recursive_find_path(x, y - 1)) {
			correct_path[x][y] = true;
			return true;
		}
	}

	if (y != 9) {						//test right edge
		if (recursive_find_path(x, y + 1)) {
			correct_path[x][y] = true;
			return true;

		}
	}

	return false;

}

int main() {

	//ofstream output;
	//output.open("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'S') {
				start.x = i;
				start.y = j;
			}
			if (maze[i][j] == 'G') {
				destination.x = i;
				destination.y = j;
			}
		}
	}

	if (recursive_find_path(start.x, start.y)) {
		for (int i = 0; i < 10; i++) {
			if (i != 0) {
				cout << '\n';
			}
			for (int j = 0; j < 10; j++) {
				if (correct_path[i][j]) {
					cout << '+';
				}
				else {
					cout << maze[i][j];
				}
			}
		}
		cout << '\n';
	}
	else {
		cout << "No solution" << '\n';
	}
	//output.close();
	return 0;
}