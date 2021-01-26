#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int v, t;
	while (cin >> v) {

		cin >> t;
		cout << 2 * v * t << '\n';
	}
	return 0;
}